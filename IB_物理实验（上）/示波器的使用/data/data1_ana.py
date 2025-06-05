import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 直接从文件读取数据
data = pd.read_csv("data1.csv")

# 创建图形 - 竖向排列，提高分辨率
fig, axes = plt.subplots(3, 1, figsize=(8, 18), dpi=300)

# 处理每组数据
for i in range(3):
    # 获取数据
    freq_khz = data.iloc[i]['频率/kHz']
    v_pp = data.iloc[i]['$V_{p-p}$/V']
    period_ms = data.iloc[i]['T/ms']

    # 计算振幅
    amplitude = v_pp / 2

    # 生成一个完整周期的正弦波
    t = np.linspace(0, period_ms, 1000)
    y = amplitude * np.sin(2 * np.pi * t / period_ms)

    # 绘制正弦波 - 使用黑色线条增加对比度
    ax = axes[i]
    ax.plot(t, y, 'k-', linewidth=2.5)

    # 添加参考线
    ax.axhline(y=0, color='k', linestyle='-', alpha=0.4)
    ax.axvline(x=0, color='k', linestyle='-', alpha=0.4)

    # 标记关键点 - 使用黑色填充圆点
    key_times = [0, period_ms/4, period_ms/2, 3*period_ms/4, period_ms]
    key_voltages = [0, amplitude, 0, -amplitude, 0]

    ax.plot(key_times, key_voltages, 'ko', markersize=6)

    # 标注关键点
    for j, (x, y) in enumerate(zip(key_times, key_voltages)):
        if j < len(key_times) - 1:  # 不标注最后一个点
            ax.annotate(f'({x:.2f}, {y:.2f})',
                       xy=(x, y),
                       xytext=(x, y + (amplitude*0.2 if y <= 0 else -amplitude*0.2)),
                       fontsize=8,
                       ha='center',
                       bbox=dict(boxstyle="round", fc="white", ec="black", alpha=0.9),
                       arrowprops=dict(arrowstyle="->", color="black"))

    # 设置标题和标签，包含频率、Vpp和周期T的信息
    ax.set_title(f'频率 = {freq_khz} kHz，$V_{{pp}}$ = {v_pp} V，T = {period_ms} ms', fontsize=12)
    ax.set_xlabel('时间 (ms)', fontsize=10)
    ax.set_ylabel('电压 (V)', fontsize=10)

    # 设置坐标轴范围
    ax.set_xlim(-period_ms*0.05, period_ms*1.05)
    ax.set_ylim(-amplitude*1.5, amplitude*1.5)

    # 添加黑色网格线
    ax.grid(True, linestyle='--', alpha=0.4, color='black')

    # 设置为正方形
    width = period_ms*1.1
    height = amplitude*3
    ax.set_aspect(width/height)

# plt.suptitle('示波器Y-t模式下的正弦电压波形', fontsize=16)
plt.tight_layout()
plt.subplots_adjust(hspace=0.4)  # 增加子图之间的垂直间距
plt.show()