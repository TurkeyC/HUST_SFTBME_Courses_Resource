import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from matplotlib.ticker import LogLocator

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文显示
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 实验数据
data = pd.DataFrame({
    '频率/kHz': [20, 35, 50, 70, 100, 150, 200, 350, 500, 700, 1000, 2000],
    '电压U/V': [1.19, 2.1, 2.925, 4, 5.2, 6.75, 7.55, 8.8, 9, 9.3, 9.4, 9.4]
})

# 固定参数
R = 1.0  # kΩ (1000Ω)
C = 10.0  # μF (10×10⁻⁶F)
U0 = 10.0  # V (输入电压峰峰值)

# RC电路理论响应函数
def rc_response(f):
    omega = 2 * np.pi * f * 1e3  # 角频率(rad/s)
    return U0 * (omega * R * 1e3 * C * 1e-6) / np.sqrt(1 + (omega * R * 1e3 * C * 1e-6)**2)

# 生成理论曲线数据
f_theory = np.logspace(np.log10(0.01), np.log10(3000), 500)  # 0.01kHz到3kHz
U_theory = rc_response(f_theory)

# 计算截止频率
fc = 1 / (2 * np.pi * R * 1e3 * C * 1e-6) / 1e3  # kHz
fc_Hz = fc * 1e3  # Hz

# 创建正方形图像
fig, ax = plt.subplots(figsize=(8, 8))

# 绘制理论曲线（红色实线）
ax.semilogx(f_theory, U_theory, 'r-', linewidth=2.5,
           label=f'理论曲线\n(R={R}kΩ, C={C}μF)')

# 绘制实验数据点（蓝色圆点）
ax.scatter(data['频率/kHz'], data['电压U/V'],
          color='blue', s=80, zorder=5,
          label='实验数据')

# 标注截止频率
ax.axvline(fc, color='green', linestyle=':', linewidth=2)
ax.text(fc*1.5, U0*0.3,
       f'截止频率\n$f_c$={fc:.3f}kHz\n({fc_Hz:.1f}Hz)',
       fontsize=10, color='green',
       bbox=dict(facecolor='white', alpha=0.8))

# 计算并显示误差
theoretical_values = rc_response(data['频率/kHz'])
errors = np.abs(data['电压U/V'] - theoretical_values) / theoretical_values * 100
avg_error = np.mean(errors)

# 添加信息框
info_text = '\n'.join((
    'RC高通滤波器频率响应',
    f'输入电压: {U0}V$_{{p-p}}$',
    f'电阻 R = {R}kΩ',
    f'电容 C = {C}μF',
    f'平均误差: {avg_error:.1f}%'))
ax.text(0.02, 0.98, info_text, transform=ax.transAxes,
       fontsize=11, verticalalignment='top',
       bbox=dict(facecolor='white', alpha=0.8))

# 设置图形属性
ax.set_title('RC电路频率响应特性', fontsize=14, pad=15)
ax.set_xlabel('频率 (kHz)', fontsize=12)
ax.set_ylabel('输出电压 U (V)', fontsize=12)
ax.grid(True, which='both', linestyle='--', alpha=0.6)
ax.legend(loc='lower right', fontsize=10)

# 设置坐标轴范围和刻度
ax.set_xlim(0.01, 3000)
ax.set_ylim(0, 10.5)
ax.xaxis.set_major_locator(LogLocator(numticks=10))  # 对数坐标刻度
ax.yaxis.set_major_locator(plt.MultipleLocator(1))  # 线性坐标每1V一个刻度

# 添加参考线
ax.axhline(U0, color='gray', linestyle='--', linewidth=1, alpha=0.5)
ax.text(0.1, U0+0.2, f'最大电压 {U0}V', fontsize=9, color='gray')

plt.tight_layout()
plt.show()