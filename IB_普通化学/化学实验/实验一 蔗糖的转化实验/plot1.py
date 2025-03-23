import pandas as pd
import matplotlib.pyplot as plt
import os

# 实验参数设置
alpha_inf = -3.899  # 终态旋光度
csv_path = "data/sucrose_data.CSV"  # CSV文件路径（根据实际情况修改）


def plot_alpha_vs_time(csv_path, alpha_inf):
    try:
        # 读取CSV数据（假设无表头，两列数据）
        df = pd.read_csv(csv_path, header=None, names=["alpha_t", "t"])

        # 数据预处理：按时间排序
        df = df.sort_values("t")

        # 绘制图像
        plt.figure(figsize=(10, 6))

        # 绘制实验数据点（散点图）
        plt.scatter(
            df["t"], df["alpha_t"],
            color="blue", label="Data Points", zorder=10
        )

        # 绘制数据点连线（折线图）
        plt.plot(
            df["t"], df["alpha_t"],
            color="green", linestyle="--", linewidth=1,
            label="Data Trend Line"
        )

        # 标注终态旋光度 α_∞
        plt.axhline(
            y=alpha_inf, color="red", linestyle=":",
            label=f"Final Specific Rotation α_∞ = {alpha_inf}°"
        )

        # 图表格式设置
        plt.title("Sucrose Conversion Reaction Specific Rotation Changes Over Time", fontsize=14)
        plt.xlabel("Time t (min)", fontsize=12)
        plt.ylabel("Specific Rotation α_t (°)", fontsize=12)
        plt.grid(True, alpha=0.3)
        plt.legend(loc="upper right")

        # 保存图表
        plt.savefig("alpha_vs_time.png", dpi=300, bbox_inches="tight")
        plt.show()

        print("图表已保存为 alpha_vs_time.png")

    except FileNotFoundError:
        print(f"错误：找不到文件 {csv_path}")
    except Exception as e:
        print(f"发生错误：{str(e)}")


if __name__ == "__main__":
    # 检查文件是否存在
    if os.path.exists(csv_path):
        plot_alpha_vs_time(csv_path, alpha_inf)
    else:
        print(f"错误：文件 {csv_path} 不存在")