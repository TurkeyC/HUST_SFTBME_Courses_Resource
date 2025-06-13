import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei', 'FangSong']  # 支持中文
plt.rcParams['axes.unicode_minus'] = False  # 正常显示负号
plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.size'] = 16

# 输入实验数据（直接使用您提供的数据）
L_cm = np.array([41.670, 47.206, 53.553])  # 单位：cm
T_30 = np.array([39.248, 41.847, 44.479])  # 单位：s (30个周期的总时间)

# 转换为标准单位并计算单周期
L = L_cm / 100  # 转换为米(m)
T = T_30 / 30   # 计算单周期(s)

# 估算周期误差（假设误差主要来源于计时器分辨率）
# 若无直接测量误差，可考虑以下两种方法：
# 方法1：使用仪器标称误差（如光电门通常为0.001s）
# 方法2：用多次测量的标准差（若只有单次测量，建议用方法1）
T_err = 0.001  # 示例：假设光电门分辨率为0.001s（需根据实际仪器调整）
T_squared_err = 2 * T * T_err  # 误差传递

# 线性拟合
slope, intercept, r_value, p_value, std_err = stats.linregress(L, T**2)

# 计算重力加速度
g = 4 * np.pi**2 / slope
g_err = g * (std_err / slope)  # 误差传递

# 生成拟合线
fit_x = np.linspace(min(L), max(L), 100)
fit_y = slope * fit_x + intercept

# 绘图设置
plt.figure(figsize=(8, 8), dpi=200)  # 设置为正方形比例，提升分辨率
plt.errorbar(L, T**2, xerr=None, yerr=T_squared_err,
             fmt='o', color='royalblue', markersize=8,
             capsize=5, label='实验数据')

plt.plot(fit_x, fit_y, 'r--',
         label=f'拟合直线: $T^2$ = {slope:.3f}L + {intercept:.3f}\n$R^2$={r_value**2:.4f}')

plt.xlabel('摆长 L (m)', fontsize=12)
plt.ylabel('周期平方 $T^2$ ($s^2$)', fontsize=12)
plt.title('单摆实验: $L-T^2$ 关系图', fontsize=14)
plt.grid(True, linestyle='--', alpha=0.5)
plt.legend()

# 标注重力加速度结果
plt.annotate(f'$g = {g:.3f} \pm {g_err:.3f}\, m/s^2$\n'
             f'武汉参考值: 9.794 $m/s^2$\n'
             f'相对误差: {abs(g-9.794)/9.794*100:.2f}%',
             xy=(0.6, 0.2), xycoords='axes fraction',
             bbox=dict(boxstyle='round', fc='w'))

plt.tight_layout()
# 移除坐标轴比例设置，保证输出图片为正方形
# plt.gca().set_aspect('equal', adjustable='box')
plt.savefig('square.png', dpi=200)  # 保存为正方形图片
plt.show()

# 控制台输出
print("===== 拟合结果 =====")
print(f"斜率 k = {slope:.4f} ± {std_err:.4f} s²/m")
print(f"重力加速度 g = {g:.3f} ± {g_err:.3f} m/s²")
print(f"截距 b = {intercept:.4f} s² (理论期望值: 0)")
print(f"相关系数 R² = {r_value**2:.4f}")