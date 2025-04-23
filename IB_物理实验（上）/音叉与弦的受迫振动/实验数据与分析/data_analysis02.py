import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置黑体
plt.rcParams['axes.unicode_minus'] = False     # 解决负号显示问题

# 读取数据
data = pd.read_csv('sheet2_m-f-u.csv')

# 预处理质量数据：将"59x2"这样的格式转换为数值
data['m_x(g)'] = data['m_x(g)'].str.replace('x2', '').astype(float) * 2

# 创建表格
print("表2 音叉的共振频率f与所加质量mx之间关系")
print("----------------------------------------")
print(data.to_string(index=False, header=True, justify='center'))
print("----------------------------------------")

# 绘制图形
plt.figure(figsize=(10, 6))
plt.plot(data['m_x(g)'], data['1/f^2(ms^2)'], 'bo-', label='实验数据点')

# 进行线性回归
slope, intercept, r_value, p_value, std_err = stats.linregress(data['m_x(g)'], data['1/f^2(ms^2)'])
regression_line = slope * data['m_x(g)'] + intercept

plt.plot(data['m_x(g)'], regression_line, 'r--',
         label=f'线性拟合: y={slope:.5f}x+{intercept:.3f}\n$R²$={r_value**2:.4f}')

plt.xlabel('附加质量 $m_x (g)$')
plt.ylabel('$1/f^2$ $(ms^2)$')
plt.title('图2 音叉$1/f²$与所加质量$m_x$的关系图')
plt.grid(True)
plt.legend()

# 显示图形
plt.show()

# 输出回归分析结果
print("\n线性回归分析结果:")
print(f"斜率: {slope:.5f} ms²/g")
print(f"截距: {intercept:.3f} ms²")
print(f"相关系数 R: {r_value:.4f}")
print(f"R平方值: {r_value**2:.4f}")
print(f"标准误差: {std_err:.5f}")
print(f"p值: {p_value:.5f}")

# 判断线性关系
if r_value**2 > 0.95:
    print("\n结论: 1/f²与mx之间存在显著的线性关系 (R² > 0.95)")
else:
    print("\n结论: 1/f²与mx之间的线性关系不显著 (R² ≤ 0.95)")