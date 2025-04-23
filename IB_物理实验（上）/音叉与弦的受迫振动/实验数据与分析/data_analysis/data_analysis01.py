import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置黑体
plt.rcParams['axes.unicode_minus'] = False     # 解决负号显示问题

# 读取数据
data = pd.read_csv('sheet1_f-u.csv')

# 创建表格
print("表1 音叉的速度-幅频特性实验数据表格")
print("----------------------------------")
print(data.to_string(index=False, header=True, justify='center'))
print("----------------------------------")

# 绘制图形
plt.figure(figsize=(10, 6))
# 添加散点图显示实验数据点
plt.scatter(data['f(Hz)'], data['U(v)'], color='blue', s=30, label='实验数据点')
# 添加平滑曲线
plt.plot(data['f(Hz)'], data['U(v)'], 'b-', label='U-f关系曲线')
plt.xlabel('频率 f (Hz)')
plt.ylabel('电压 U (V)')
plt.title('图1 U-f 关系曲线')
plt.grid(True)

# 找到共振频率和最大电压
max_voltage_index = data['U(v)'].idxmax()
f0 = data.loc[max_voltage_index, 'f(Hz)']
Umax = data.loc[max_voltage_index, 'U(v)']
U_half = Umax / np.sqrt(2)

plt.plot(f0, Umax, 'ro', label=f'共振频率 $f_0$={f0:.3f}Hz')
plt.axhline(y=U_half, color='g', linestyle='--', label=f'半功率值 $Umax/√2$={U_half:.3f}V')

# 寻找半功率点的更精确方法
# 创建更密集的频率点进行插值
f_dense = np.linspace(data['f(Hz)'].min(), data['f(Hz)'].max(), 1000)
# 使用 scipy 的插值函数创建平滑曲线
from scipy.interpolate import interp1d
curve_fit = interp1d(data['f(Hz)'], data['U(v)'], kind='cubic')
U_dense = curve_fit(f_dense)

# 左侧半功率点
left_indices = (f_dense < f0)
left_diff = np.abs(curve_fit(f_dense[left_indices]) - U_half)
f1 = f_dense[left_indices][np.argmin(left_diff)]

# 右侧半功率点
right_indices = (f_dense > f0)
right_diff = np.abs(curve_fit(f_dense[right_indices]) - U_half)
f2 = f_dense[right_indices][np.argmin(right_diff)]

# 在图上标注半功率点
plt.plot(f1, U_half, 'go', markersize=8, label=f'$f_1$={f1:.3f}Hz')
plt.plot(f2, U_half, 'go', markersize=8, label=f'$f_2$={f2:.3f}Hz')

# 计算锐度(Q值)
delta_f = f2 - f1
Q = f0 / delta_f

plt.legend()
plt.show()

# 输出计算结果
print(f"\n计算结果:")
print(f"共振频率 f0 = {f0:.3f} Hz")
print(f"半功率点 f1 = {f1:.3f} Hz")
print(f"半功率点 f2 = {f2:.3f} Hz")
print(f"带宽 Δf = f2 - f1 = {delta_f:.3f} Hz")
print(f"锐度 Q = f0/Δf = {Q:.3f}")