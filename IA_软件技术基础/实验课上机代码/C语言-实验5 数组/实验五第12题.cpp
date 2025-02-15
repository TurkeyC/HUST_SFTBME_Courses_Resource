#include <stdio.h>

int img[100][100];//定义二维数组img来存储迷宫图案
int path[100][100];//存储迷宫路径
int r, c;//定义迷宫的行数和列数
int count = 1;
/*
 * output函数用于输出迷宫路径
 */
void output()
{
    printf("%d\n",count);
    count ++;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", path[i][j]);
            if(j != c-1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * solution用于递归函数尝试所有可能的路径
 * @param x,y 当前位置的行号和列号
 */
void solution(int x, int y)
{
    //如果到达终点，则标记当前位置并输出路径
    if (x == r - 1 && y == c - 1)
    {
        path[x][y] = 1;
        output();
        //重置标记
        path[x][y] = 0;
        return;
    }

    if (x >= 0 && x < r && y >= 0 && y < c && img[x][y] == 1) //判断是否可以移动到(x,y)这个位置
    {
        path[x][y] = 1;
        img[x][y] = 0; //对已经访问过的位置标记为0，避免重复访问

        solution(x, y + 1);// 向右移动
        solution(x + 1, y);// 向下移动
        solution(x, y - 1);// 向左移动
        solution(x - 1, y);// 向上移动

        path[x][y] = 0; // 取消标记
        img[x][y] = 1; // 重置迷宫
    }
}


int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &img[i][j]);
        }
    }

    // 初始化路径矩阵为0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            path[i][j] = 0;
        }
    }

    solution(0, 0);
    return 0;
}
