#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * input函数用于棋盘的输入
 * @param n: 行数
 * @param m: 列数
 * @param chess: 棋盘
 * @param mark: 标记
 */
void input(int n, int m, int **chess, int **mark)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &chess[i][j]);
            mark[i][j] = 0;
        }

    }
}

/*
 * output函数用于棋盘的输出
 * @param n: 行数
 * @param m: 列数
 * @param chess: 棋盘
 */
void output(int n, int m, int **chess)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}

/*
 * markfunc函数用于遍历行判断并标记出连续的棋子
 * @param n: 行数
 * @param m: 列数
 * @param chess: 棋盘
 * @param mark: 标记
 */
void markfunc(int n, int m, int **chess, int **mark)
{
    int cons, count;
    //对行进行判断
    for(int i = 0; i < n; i++)
    {
        count = 0; //重置计数
        for(int j = 0; j < m; j++)
        {
            //判断此时计数是否大于等于3
            if(count >= 3)
            {
                //判断是否为最后一个,并且当前值与连续值相等
                if(j == m-1 && chess[i][j] == cons)
                {
                    for(int k = j; k > j-count; k--)
                    {
                        mark[i][k-1] = 1; //标记
                    }
                    mark[i][j]=1;
                }

                //判断是否当前值与连续值不相等
                else if(chess[i][j] != cons)
                {
                    cons = chess[i][j]; //连续值赋给cons
                    for(int k = j; k > j-count; k--)
                    {
                        mark[i][k-1] = 1; //标记
                    }
                    count = 0; //重置计数
                }
            }


            //判断如果在第一个,那么取该值为连续值,并计数为1
            if(j == 0)
            {
                cons = chess[i][j];
                count = 1;
            }
            //否则,将判断该值是否与前一个值相等
            else
            {
                //如果相等,计数加一
                if(chess[i][j] == chess[i][j-1]) count++;
                //否则,将当前值赋给连续值,并重置计数为1
                else
                {
                    cons = chess[i][j];
                    count = 1;
                }
            }

            //对特殊情况打补丁
            if(j == m-1 && chess[i][j] == cons && count == 3)
            {
                for(int k = j; k > j-count; k--)
                {
                    mark[i][k] = 1; //标记
                }
                //mark[i][j]=1;
            }
        }
    }
}

/*
 * markfcon函数用于遍历列判断并标记出连续的棋子
 * @param n: 列数
 * @param m: 行数
 * @param chess: 棋盘
 * @param mark: 标记
 */
void markfcon(int n, int m, int **chess, int **mark)
{
    int cons, count;
    //对列进行判断
    for(int i = 0; i < n; i++)
    {
        count = 0; //重置计数
        for(int j = 0; j < m; j++)
        {
            //判断此时计数是否大于等于3
            if(count >= 3)
            {
                //判断是否为最后一个,并且当前值与连续值相等
                if(j == m-1 && chess[j][i] == cons)
                {
                    for(int k = j; k > j-count; k--)
                    {
                        mark[k-1][i] = 1; //标记
                    }
                    mark[j][i]=1;
                }

                //判断是否当前值与连续值不相等
                else if(chess[j][i] != cons)
                {
                    cons = chess[j][i]; //连续值赋给cons
                    for(int k = j; k > j-count; k--)
                    {
                        mark[k-1][i] = 1; //标记
                    }
                    count = 0; //重置计数
                }
            }


            //判断如果在第一个,那么取该值为连续值,并计数为1
            if(j == 0)
            {
                cons = chess[j][i];
                count = 1;
            }
            //否则,将判断该值是否与前一个值相等
            else
            {
                //如果相等,计数加一
                if(chess[j][i] == chess[j-1][i]) count++;
                //否则,将当前值赋给连续值,并重置计数为1
                else
                {
                    cons = chess[j][i];
                    count = 1;
                }
            }

            //对特殊情况打补丁
            if(j == m-1 && chess[j][i] == cons && count == 3)
            {
                for(int k = j; k > j-count; k--)
                {
                    mark[k][i] = 1; //标记
                }

            }
        }
    }
}


/*
 * examine函数用于判断并赋零
 * @param n: 行数
 * @param m: 列数
 * @param chess: 棋盘
 * @param mark: 标记
 */
void examine(int n, int m, int **chess, int **mark)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(mark[i][j] == 1) chess[i][j] = 0;
        }
}



int main()
{

    int n, m; //对n行m列进行定义

    scanf("%d %d", &n, &m); //输入n和m以确定棋盘大小

    int **chess= (int **)malloc(n * sizeof(int *)); //设置一个二维指针来表示棋盘动态分配行

    int **mark= (int **)malloc(n * sizeof(int *)); //设置一个二维指针来表示标记动态分配行

    for (int i = 0; i < n; i++) {chess[i] = (int *)malloc(m * sizeof(int));} //动态分配列
    for (int i = 0; i < n; i++) {mark[i] = (int *)malloc(m * sizeof(int));}

    input(n,m,chess,mark); //利用input函数输入棋盘

    markfunc(n,m,chess,mark);//遍历行标记连续的棋子
    markfcon(m,n,chess,mark);//遍历列标记连续的棋子
    examine(n,m,chess,mark);//利用examine函数将mark为1的chess赋零

    output(n,m,chess);//利用output函数输出棋盘

    return 0;
}