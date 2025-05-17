import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import font_manager
import matplotlib as mpl
from scipy.signal import savgol_filter
from scipy import interpolate
from scipy.optimize import curve_fit

# 更可靠的中文字体配置
mpl.rc('font', family='Arial Unicode MS')
plt.rcParams['axes.unicode_minus'] = False

# 设置全局字体大小
plt.rcParams.update({
    'font.size': 14,          # 基本字体大小
    'axes.titlesize': 16,     # 标题字体大小
    'axes.labelsize': 14,     # 坐标轴标签字体大小
    'xtick.labelsize': 12,    # x轴刻度标签字体大小
    'ytick.labelsize': 12,    # y轴刻度标签字体大小
    'legend.fontsize': 12,    # 图例字体大小
})

# 实验参数
wavelength = 632.8e-9
f = 80e-3
a = 100e-6
distance = 167e-3

# 读取实验数据
data = pd.read_csv('raw_data.csv')
x = data['x'].values
i = data['i'].values

# 计算相对光强
i0 = np.max(i)
relative_intensity = i / i0

# 找到中央极大值位置
center_idx = np.argmax(i)
x_center = x[center_idx]
x_relative = x - x_center

# 平滑处理方法选择（可以将不需要的方法注释掉）
use_savgol = True  # Savitzky-Golay滤波（推荐）
use_moving_avg = False  # 移动平均
use_interp = True  # 插值
use_curve_fit = False  # 拟合理论模型

# 1. Savitzky-Golay滤波平滑处理
if use_savgol:
    window_size = 7  # 窗口大小，需为奇数
    poly_order = 2  # 多项式阶数
    savgol_smoothed = savgol_filter(relative_intensity, window_size, poly_order)

# 2. 移动平均平滑处理
if use_moving_avg:
    window_size = 5  # 窗口大小


    # 移动平均函数
    def moving_average(data, window):
        weights = np.ones(window) / window
        return np.convolve(data, weights, mode='same')


    ma_smoothed = moving_average(relative_intensity, window_size)

# 3. 插值法平滑处理
if use_interp:
    # 创建插值函数
    f_interp = interpolate.interp1d(x_relative, relative_intensity, kind='cubic')
    # 生成密集的x点
    x_interp = np.linspace(np.min(x_relative), np.max(x_relative), 300)
    # 计算插值后的y值
    y_interp = f_interp(x_interp)

# 4. 理论模型拟合
if use_curve_fit:
    # 定义单缝衍射理论函数
    def diffraction_model(x, amplitude, center, width_factor):
        # 计算归一化后的u值
        theta = (x - center) / distance
        u = np.pi * width_factor * np.sin(theta) / wavelength
        # 处理零点
        result = np.ones_like(u)
        mask = np.abs(u) > 1e-10
        result[mask] = (np.sin(u[mask]) / u[mask]) ** 2
        return amplitude * result


    # 初始猜测参数 [振幅, 中心位置, 缝宽调整因子]
    p0 = [1.0, x_center, a]

    try:
        # 拟合数据
        params, _ = curve_fit(diffraction_model, x, relative_intensity, p0=p0)

        # 使用拟合参数创建平滑曲线
        x_fit = np.linspace(np.min(x), np.max(x), 300)
        y_fit = diffraction_model(x_fit, *params)

        print(f"拟合后参数: 振幅={params[0]:.3f}, 中心={params[1]:.3f}, 缝宽因子={params[2] * 1e6:.1f}μm")
    except RuntimeError:
        print("曲线拟合失败，请尝试调整初始参数")
        use_curve_fit = False

# 绘图
plt.figure(figsize=(10, 6))  # 减小图形尺寸，调整宽高比

# 原始数据
plt.plot(x_relative * 1e3, relative_intensity, 'bo', label='原始实验数据', markersize=5, alpha=0.7)

# 绘制各种平滑后的曲线
# if use_savgol:
#     plt.plot(x_relative * 1e3, savgol_smoothed, 'r-', label='Savitzky-Golay滤波', linewidth=2)

if use_moving_avg:
    plt.plot(x_relative * 1e3, ma_smoothed, 'g-', label='移动平均', linewidth=2.5)

if use_interp:
    plt.plot(x_interp * 1e3, y_interp, 'm-', label='拟合曲线', linewidth=2.5)

if use_curve_fit:
    plt.plot((x_fit - x_center) * 1e3, y_fit, 'c-', label='理论模型拟合', linewidth=2.5)

# 图表设置
plt.xlabel('相对位置 (mm)', fontsize=14)
plt.ylabel('相对光强 (I / $I_0$)', fontsize=14)
plt.title('夫琅和费单缝衍射相对光强分布曲线', fontsize=16, pad=10)
plt.legend(fontsize=12, loc='best')
plt.grid(True, alpha=0.3, linestyle='--')

# 调整边距，确保标签不被裁剪
plt.tight_layout(pad=2.0)

# 添加这行可以改善显示效果
plt.gcf().subplots_adjust(left=0.12, right=0.95, bottom=0.12, top=0.92)

plt.show()

# 安全地计算中央明纹宽度
if center_idx > 0:
    first_min_left_idx = np.argmin(relative_intensity[:center_idx])
else:
    first_min_left_idx = 0

first_min_right_idx = center_idx + np.argmin(relative_intensity[center_idx:])
exp_dark_width = x[first_min_right_idx] - x[first_min_left_idx]

# 理论中央明纹宽度
theo_dark_width = 2 * wavelength * distance / a * 1e3

print(f"实验测得中央明纹宽度: {exp_dark_width:.3f} mm")
print(f"理论中央明纹宽度: {theo_dark_width:.3f} mm")
print(f"相对误差: {abs(exp_dark_width - theo_dark_width) / theo_dark_width * 100:.2f}%")
