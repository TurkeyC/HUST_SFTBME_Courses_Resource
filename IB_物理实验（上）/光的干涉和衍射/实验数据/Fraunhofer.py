import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import font_manager
import matplotlib as mpl

# 更可靠的中文字体配置
mpl.rc('font', family='Arial Unicode MS')  # 通常支持更多Unicode字符
plt.rcParams['axes.unicode_minus'] = False

# 实验参数保持不变
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

# 创建更密集的理论曲线点
# x_dense = np.linspace(np.min(x_relative), np.max(x_relative), 1000)
# theta_dense = np.arctan(x_dense / distance)
# u_dense = (np.pi * a * np.sin(theta_dense)) / wavelength
# theoretical_intensity_dense = (np.sin(u_dense) / u_dense)**2
# theoretical_intensity_dense[np.abs(u_dense) < 1e-10] = 1

# 绘制图形
plt.figure(figsize=(10, 6))
plt.plot(x_relative*1e3, relative_intensity, 'bo-', label='实验数据', markersize=3)
# plt.plot(x_dense*1e3, theoretical_intensity_dense, 'r-', label='理论曲线')
plt.xlabel('相对位置 (mm)')
plt.ylabel('相对光强 (I/I0)')  # 使用普通字符而非Unicode下标
plt.title('夫琅和费单缝衍射相对光强分布曲线')
plt.legend()
plt.grid(True)

# # 标记暗纹与次极大位置
# first_dark = (wavelength * distance / a) * 1e3
# first_secondary_max = 1.43 * wavelength * distance / a * 1e3
# plt.axvline(first_dark, color='g', linestyle=':', label='一级暗纹理论位置')
# plt.axvline(-first_dark, color='g', linestyle=':')
# plt.axvline(first_secondary_max, color='m', linestyle=':', label='次极大理论位置')
# plt.axvline(-first_secondary_max, color='m', linestyle=':')

plt.legend()
plt.tight_layout()
plt.show()

# 安全地计算中央明纹宽度
# 确保不为空序列
if center_idx > 0:
    first_min_left_idx = np.argmin(relative_intensity[:center_idx])
else:
    first_min_left_idx = 0  # 安全值

first_min_right_idx = center_idx + np.argmin(relative_intensity[center_idx:])
exp_dark_width = x[first_min_right_idx] - x[first_min_left_idx]

# 理论中央明纹宽度
theo_dark_width = 2 * wavelength * distance / a * 1e3

print(f"实验测得中央明纹宽度: {exp_dark_width:.3f} mm")
print(f"理论中央明纹宽度: {theo_dark_width:.3f} mm")
print(f"相对误差: {abs(exp_dark_width-theo_dark_width)/theo_dark_width*100:.2f}%")

# 安全地计算一级次极大位置和强度
if first_min_left_idx > 0:  # 只有当序列非空时才计算
    first_max_left_idx = np.argmax(relative_intensity[:first_min_left_idx])
    exp_secondary_pos_left = x[first_max_left_idx] - x_center
    exp_secondary_intensity_left = relative_intensity[first_max_left_idx]
    print(f"\n实验测得左侧一级次极大位置: {exp_secondary_pos_left:.3f} mm")
    print(f"实验测得左侧一级次极大相对光强: {exp_secondary_intensity_left:.3f}")

# 计算右侧次极大
if first_min_right_idx > center_idx:  # 确保切片非空
    slice_to_search = relative_intensity[center_idx:first_min_right_idx]
    if len(slice_to_search) > 0:  # 额外检查
        max_idx_in_slice = np.argmax(slice_to_search)
        first_max_right_idx = center_idx + max_idx_in_slice
        exp_secondary_pos_right = x[first_max_right_idx] - x_center
        exp_secondary_intensity_right = relative_intensity[first_max_right_idx]
        print(f"实验测得右侧一级次极大位置: {exp_secondary_pos_right:.3f} mm")
        print(f"实验测得右侧一级次极大相对光强: {exp_secondary_intensity_right:.3f}")

# print(f"理论一级次极大位置: {first_secondary_max:.3f} mm")
print(f"理论一级次极大相对光强: 0.047")