import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import linregress
import os

# 实验参数设置
alpha_inf = -3.899  # 终态旋光度
csv_path = "data/sucrose_data.CSV"  # CSV文件路径（根据实际情况修改）


def process_data(csv_path, alpha_inf):
    try:
        # 读取CSV数据（假设无表头，两列数据）
        df = pd.read_csv(csv_path, header=None, names=["alpha_t", "t"])

        # 数据预处理
        df["alpha_diff"] = df["alpha_t"] - alpha_inf

        # 过滤无效数据（α_t必须 > α_∞）
        valid_data = df[df["alpha_diff"] > 0].copy()
        if len(valid_data) < len(df):
            print(f"警告：发现 {len(df) - len(valid_data)} 个无效数据点（α_t ≤ α_∞），已自动过滤")

        # 计算自然对数
        valid_data["ln_diff"] = np.log(valid_data["alpha_diff"])

        # 线性拟合
        slope, intercept, r_value, _, std_err = linregress(
            valid_data["t"], valid_data["ln_diff"]
        )
        k = -slope
        t_half = 0.693 / k

        # 绘制图表
        plt.figure(figsize=(10, 6))
        plt.scatter(
            valid_data["t"], valid_data["ln_diff"],
            color="blue", label="Data", zorder=10
        )

        # 拟合直线
        fit_x = np.linspace(valid_data["t"].min(), valid_data["t"].max(), 100)
        fit_y = slope * fit_x + intercept
        plt.plot(
            fit_x, fit_y, "r--",
            label=f"Linear Regression\nSlope = {slope:.4f} ± {std_err:.4f}\nR² = {r_value ** 2:.4f}"
        )

        # 图表格式设置
        plt.title("Kinetic Analysis of Sucrose Conversion Reaction", fontsize=14)
        plt.xlabel("Time t (min)", fontsize=12)
        plt.ylabel("ln(α_t - α_∞)", fontsize=12)
        plt.grid(True, alpha=0.3)
        plt.legend(loc="best")

        # 保存图表
        plt.savefig("kinetic_fit.png", dpi=300, bbox_inches="tight")
        plt.show()

        # 输出结果
        print("\n====== 实验结果 ======")
        print(f"速率常数 k = {k:.4f} ± {std_err:.4f} min⁻¹")
        print(f"半衰期 t₁/₂ = {t_half:.2f} 分钟")
        print(f"拟合优度 R² = {r_value ** 2:.4f}")

    except FileNotFoundError:
        print(f"错误：找不到文件 {csv_path}")
    except Exception as e:
        print(f"发生错误：{str(e)}")


if __name__ == "__main__":
    # 检查文件是否存在
    if os.path.exists(csv_path):
        process_data(csv_path, alpha_inf)
    else:
        print(f"错误：文件 {csv_path} 不存在")