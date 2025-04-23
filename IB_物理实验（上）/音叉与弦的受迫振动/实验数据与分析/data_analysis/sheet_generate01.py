import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 读取数据
data = pd.read_csv('sheet1_f-u.csv')

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 创建图形
fig, ax = plt.subplots(figsize=(12, len(data) * 0.5))  # 根据数据行数调整高度
ax.axis('tight')
ax.axis('off')

# 创建表格
table = ax.table(cellText=data.values,
                colLabels=data.columns,
                cellLoc='center',
                loc='center',
                colColours=['#e6e6e6'] * len(data.columns))

# 设置表格样式
table.auto_set_font_size(False)
table.set_fontsize(9)
table.scale(1.2, 1.8)  # 调整单元格大小

# 设置单元格样式
for cell in table._cells:
    table._cells[cell].set_edgecolor('black')  # 设置边框颜色
    if cell[0] == 0:  # 表头行
        table._cells[cell].set_facecolor('#c6e2ff')  # 设置表头背景色
        table._cells[cell].set_text_props(weight='bold')  # 设置表头文字加粗
    else:  # 数据行
        table._cells[cell].set_facecolor('white')  # 设置数据行背景色

# 设置标题
plt.title('表1 音叉的速度-幅频特性实验数据表格', y=1.05, fontsize=14)

# 保存为图片
plt.savefig('音叉实验数据表格.png', dpi=300, bbox_inches='tight')
plt.show()