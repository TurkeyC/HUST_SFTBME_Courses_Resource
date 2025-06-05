import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取CSV数据
data = pd.read_csv("data4.csv")
frequency = data['频率/Hz']
voltage = data['电压U/V']

# 创建更密集的频率点以获得平滑曲线（使用线性间隔）
x_dense = np.linspace(min(frequency), max(frequency), 1000)

# 定义RC电路的频率响应函数
def rc_circuit(f, R_kohm, C_uf, U0):
    # R单位是kΩ, C单位是μF
    R = R_kohm * 1000  # 转换为欧姆
    C = C_uf * 1e-6    # 转换为法拉
    return U0 * (2*np.pi*f*R*C) / np.sqrt(1 + (2*np.pi*f*R*C)**2)

# 使用curve_fit进行参数拟合
popt, pcov = curve_fit(rc_circuit, frequency, voltage, p0=[1, 1, 10])

# 创建图形
plt.figure(figsize=(10, 6), dpi=100)

# 绘制原始数据点
plt.scatter(frequency, voltage, color='red', marker='o', s=50, label='实验数据')

# 绘制拟合曲线
plt.plot(x_dense, rc_circuit(x_dense, *popt), 'b-', linewidth=2, label='拟合曲线')

# 添加拟合参数文本
textstr = '\n'.join((
    r'$U = U_0 \cdot \frac{2\pi fRC}{\sqrt{1+(2\pi fRC)^2}}$',
    r'',
    f'拟合参数:',
    f'R = {popt[0]:.2f} kΩ',
    f'C = {popt[1]*1e6:.2f} μF',
    f'U0 = {popt[2]:.2f} V'))
props = dict(boxstyle='round', facecolor='white', alpha=0.8)
plt.text(0.98, 0.02, textstr, transform=plt.gca().transAxes,
        fontsize=12, verticalalignment='bottom', horizontalalignment='right', bbox=props)

# 设置图形属性
plt.title('分析测量信号频率与输出电压之间的关系 (电阻R=1kΩ, Vpp=10.00V)', fontsize=16, pad=20)
plt.xlabel('频率 (Hz)', fontsize=14)
plt.ylabel('输出电压 U (V)', fontsize=14)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=12, loc='upper left')

# 设置坐标轴范围
plt.xlim(0, 2100)
plt.ylim(0, 10.5)

# 显示图形
plt.tight_layout()
plt.show()