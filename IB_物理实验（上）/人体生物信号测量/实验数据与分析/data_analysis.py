import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
import matplotlib as mpl

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False    # 用来正常显示负号

# 1. 绘制听阈曲线
def plot_hearing_threshold():
    # 读取数据
    data = pd.read_csv('./data1.csv')

    # 提取频率和测量值
    frequencies = data['频率/Hz']
    thresholds = data['$L_t$/dB']

    # 计算频率的常用对数
    log_frequencies = np.log10(frequencies)

    # 创建图形
    fig, ax = plt.subplots(figsize=(5, 7))

    # 绘制听阈曲线
    ax.plot(log_frequencies, thresholds, 'o-', color='blue', markersize=6, linewidth=1.5)

    # 在每个数据点上标注声强级值
    for i, threshold in enumerate(thresholds):
        ax.annotate(f"{threshold}", (log_frequencies[i], thresholds[i]),
                    textcoords="offset points", xytext=(0, 10),
                    ha='center', fontsize=9)

    # 设置横坐标刻度为对应的频率
    tick_locations = log_frequencies
    tick_labels = [str(int(freq)) for freq in frequencies]
    ax.set_xticks(tick_locations)
    ax.set_xticklabels(tick_labels, rotation=45)

    # 添加网格线和标签
    ax.grid(True, linestyle='--', alpha=0.7)
    ax.set_xlabel('频率/Hz (对数刻度)')
    ax.set_ylabel('声强级/dB')
    ax.set_title('人耳听阈曲线')

    # 保存图形
    plt.tight_layout()
    plt.savefig('hearing_threshold_curve.png', dpi=300)
    plt.close()

# 2. 绘制压力传感器特性曲线
def plot_pressure_sensor():
    # 读取数据
    data = pd.read_csv('./data2.csv')

    # 提取压强和电压数据
    pressure_kpa = data['压强/kPa']
    voltage_mv = data['电压/mV']

    # 创建图形
    fig, ax = plt.subplots(figsize=(6, 9))

    # 绘制散点图
    ax.scatter(pressure_kpa, voltage_mv, color='red', s=50)

    # 进行线性拟合
    slope, intercept, r_value, p_value, std_err = stats.linregress(pressure_kpa, voltage_mv)

    # 绘制拟合直线
    x_line = np.linspace(min(pressure_kpa), max(pressure_kpa), 100)
    y_line = slope * x_line + intercept
    ax.plot(x_line, y_line, 'b-', linewidth=2)

    # 添加网格线和标签
    ax.grid(True, linestyle='--', alpha=0.7)
    ax.set_xlabel('压强 P/kPa')
    ax.set_ylabel('输出电压 U/mV')
    ax.set_title('气体压力传感器特性曲线')

    # 添加拟合方程和相关系数
    equation = f"U = {slope:.3f} × P + {intercept:.3f}"
    ax.text(0.05, 0.95, equation, transform=ax.transAxes, fontsize=12,
            verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))
    ax.text(0.05, 0.88, f"相关系数 $R^2$ = {r_value**2:.4f}", transform=ax.transAxes,
            fontsize=12, verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))
    ax.text(0.05, 0.81, f"灵敏度 = {slope:.3f} mV/kPa", transform=ax.transAxes,
            fontsize=12, verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

    # 保存图形
    plt.tight_layout()
    plt.savefig('pressure_sensor_curve.png', dpi=300)
    plt.close()

# 3. 绘制人体皮肤阻抗频率特性曲线
def plot_skin_impedance():
    # 读取数据
    data = pd.read_csv('./data3.csv')

    # 提取频率和阻抗数据
    frequencies = data['f/Hz']
    impedances = data['Z/$\Omega$']
    log_frequencies = data['lgf']

    # 创建图形
    fig, ax = plt.subplots(figsize=(8, 8))

    # 绘制阻抗-频率曲线
    ax.semilogx(frequencies, impedances, 'o-', markersize=6, linewidth=1.5)

    # 添加网格线和标签
    ax.grid(True, linestyle='--', alpha=0.7)
    ax.set_xlabel('频率 f/Hz (对数刻度)')
    ax.set_ylabel('阻抗 Z/Ω')
    ax.set_title('人体皮肤阻抗频率特性曲线')

    # 设置x轴刻度
    ax.set_xscale('log')

    # 保存图形
    plt.tight_layout()
    plt.savefig('skin_impedance_curve.png', dpi=300)
    plt.close()

if __name__ == "__main__":
    # 依次绘制三个图表
    plot_hearing_threshold()
    plot_pressure_sensor()
    plot_skin_impedance()
    print("图表绘制完成!")