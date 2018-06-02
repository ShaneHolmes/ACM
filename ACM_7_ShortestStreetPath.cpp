/*描述
一个街区有很多住户，街区的街道只能为东西、南北两种方向。住户只可以沿着街道行走。
各个街道之间的间隔相等。用(x,y)来表示住户坐在的街区。例如（4,20），表示用户在东西
方向第4个街道，南北方向第20个街道。现在要建一个邮局，使得各个住户到邮局的距离之和
最少。求现在这个邮局应该建在那个地方使得所有住户距离之和最小；
输入
第一行一个整数n<20，表示有n组测试数据，下面是n组数据;
每组第一行一个整数m<20,表示本组有m个住户，下面的m行每行有两个整数0<x,y<100，表示某
个用户所在街区的坐标。m行后是新一组的数据；
输出
每组数据输出到邮局最小的距离和，回车结束；
样例输入
2
3
1 1
2 1
1 2
5
2 9 
5 20
11 9
1 1
1 20
样例输出
2
44
解题思路：分东西方向（x轴）和南北方向（y轴）考虑，到邮局最小的距离和为各个数据的x，y
距离邮局坐标的x，y坐标的距离之和,而邮局坐标为住户x，y的中位数*/
#include<iostream>
#include<cmath>
#define MAX_n 20
#define MAX_m 20
#define MAX_x 100
#define MAX_y 100
using namespace std;
struct Point
{
	int x;
	int y;
};
int min_Distant(struct Point *p,int m);
int get_PosterX(struct Point *p, int m);
int get_PosterY(struct Point *p, int m);
void sort_PosterX(struct Point *p, int m);
void sort_PosterY(struct Point *p, int m);
int main()
{
	int n;
	cin >> n;
	if (!(n > 0 && n < MAX_n))//参数合法性
	{
		return -1;
	}
	while (n--)
	{
		int m;
		cin >> m;
		if (!(m > 0 && m < MAX_m))
		{
			return -1;
		}
		Point p[20];
		int i = 0;
		for (i = 0;i < m;i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		cout<<min_Distant(p,m)<<endl;
	}
	system("pause");
	return 0;
}

int min_Distant(struct Point *p, int m)
{
	int i;
	int min_distant = 0;
	sort_PosterX(p, m);
	sort_PosterY(p, m);
	int poster_x = get_PosterX(p,m), poster_y = get_PosterY(p,m);
	
	for (i = 0;i < m;i++)
	{
		min_distant+=(abs(p[i].x - poster_x) + abs(p[i].y - poster_y));
	}
	return min_distant;
}

void sort_PosterX(struct Point *p, int m)
{
	for (int i = 0;i < m - 1;i++)
	{
		for (int j = 0;j < m - i - 1;j++)
		{
			if (p[j].x < p[j + 1].x)
			{
				int temp = p[j].x;
				p[j].x = p[j + 1].x;
				p[j + 1].x = temp;
			}
		}
	}
}

void sort_PosterY(struct Point *p, int m)
{
	for (int i = 0;i < m - 1;i++)
	{
		for (int j = 0;j < m - i - 1;j++)
		{
			if (p[j].y < p[j + 1].y)
			{
				int temp = p[j].y;
				p[j].y = p[j + 1].y;
				p[j + 1].y = temp;
			}
		}
	}
}

int get_PosterX(struct Point *p, int m)
{
	int poster_x=0;
	poster_x = p[m  / 2].x;
	return poster_x;
}

int get_PosterY(struct Point *p, int m)
{
	int poster_y = 0;
	poster_y = p[m / 2].y;
	return poster_y;
}

