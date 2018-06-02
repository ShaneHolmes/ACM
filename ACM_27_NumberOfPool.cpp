/*
水池数目
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，
这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。
输入
第一行输入一个整数N，表示共有N组测试数据
每一组数据都是先输入该地图的行数m(0<m<100)与列数n(0<n<100)，然后，输入接下来的m行每行输入n个数，表示此
处有水还是没水（1表示此处是水池，0表示此处是地面）
输出
输出该地图中水池的个数。
要注意，每个水池的旁边（上下左右四个位置）如果还是水池的话的话，它们可以看做是同一个水池。
样例输入
2
3 4
1 0 0 0 
0 0 1 1
1 1 1 0
5 5
1 1 1 1 0
0 0 1 0 1
0 0 0 0 0
1 1 1 0 0
0 0 1 1 1
样例输出
2
3
*/
#include <stdio.h>
#define N 102
#define M 102
int map[N][M]={0};
void search(int i,int j)
{
    if(map[i][j-1]) { map[i][j-1]=0; search(i,j-1); }
    if(map[i][j+1]) { map[i][j+1]=0; search(i,j+1); }
    if(map[i-1][j]) { map[i-1][j]=0; search(i-1,j); }
    if(map[i+1][j]) { map[i+1][j]=0; search(i+1,j); }
}
int main()
{
    int t,n,m;
    int i,j,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m); count=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(map[i][j])   { count++; map[i][j]=0; search(i,j); }
        printf("%d\n",count);
    }
    return 0;
}
