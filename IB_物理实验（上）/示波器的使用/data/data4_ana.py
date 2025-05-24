import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.optimize import curve_fit


# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取数据
data = pd.read_csv('data4.csv')  # 假设数据保存在rc_data.csv文件中

# 定义RC电路理论函数
def rc_curve(f, R, C, U0):
    """
    RC电路频率响应理论曲线
    U = U0 * (2πfRC) / sqrt(1 + (2πfRC)^2)
    """
    omega = 2 * np.pi * f * 1e3  # 转换为角频率(rad/s)，输入f单位为kHz
    return U0 * (omega * R * 1e3 * C) / np.sqrt(1 + (omega * R * 1e3 * C)**2)  # R单位转换为欧姆

# 曲线拟合
popt, pcov = curve_fit(rc_curve,
                      data['频率/kHz'],
                      data['电压U/V'],
                      p0=[1, 1e-6, 10],  # 初始猜测值：R=1kΩ, C=1μF, U0=10V
                      bounds=([0.1, 1e-9, 5], [10, 1e-4, 15]))  # 参数范围

# 计算拟合曲线的理论值
f_fit = np.logspace(1, 4, 500)  # 10Hz到10kHz的对数空间
U_fit = rc_curve(f_fit, *popt)

# 计算截止频率
fc = 1 / (2 * np.pi * popt[0] * 1e3 * popt[1])  # 单位kHz
fc_Hz = fc * 1e3  # 转换为Hz

# 创建图形
plt.figure(figsize=(12, 7))
plt.style.use('seaborn-v0_8-poster')  # 使用更美观的样式

# 绘制实验数据点
plt.scatter(data['频率/kHz'], data['电压U/V'],
           color='red', s=100, zorder=5, label='实验数据')

# 绘制拟合曲线
plt.semilogx(f_fit, U_fit, 'b-', linewidth=2.5,
            label=f'理论曲线(R={popt[0]:.1f}kΩ, C={popt[1]*1e6:.1f}μF)')

# 标注截止频率
plt.axvline(fc, color='green', linestyle='--', linewidth=1.5)
plt.text(fc*1.2, popt[2]*0.4,
        f'截止频率$f_c$={fc:.1f}kHz\n({fc_Hz:.0f}Hz)',
        fontsize=12, color='green')

# 添加理论说明框
textstr = '\n'.join((
    r'理论模型:',
    r'$U = U_0 \cdot \frac{2\pi fRC}{\sqrt{1+(2\pi fRC)^2}}$',
    r'',
    f'拟合参数:',
    f'R = {popt[0]:.2f} kΩ',
    f'C = {popt[1]*1e6:.2f} μF',
    f'U₀ = {popt[2]:.2f} V'))
props = dict(boxstyle='round', facecolor='white', alpha=0.8)
plt.text(0.02, 0.98, textstr, transform=plt.gca().transAxes,
        fontsize=12, verticalalignment='top', bbox=props)

# 设置图形属性
plt.title('RC电路频率响应特性 (电阻R=1kΩ)', fontsize=16, pad=20)
plt.xlabel('频率 (kHz)', fontsize=14)
plt.ylabel('输出电压 U (V)', fontsize=14)
plt.grid(True, which='both', linestyle='--', alpha=0.6)
plt.legend(fontsize=12, loc='lower right')

# 设置坐标轴范围
plt.xlim(10, 3000)
plt.ylim(0, 10.5)

# 显示图形
plt.tight_layout()
plt.show()