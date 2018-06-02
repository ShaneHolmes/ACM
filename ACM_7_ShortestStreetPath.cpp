/*����
һ�������кܶ�ס���������Ľֵ�ֻ��Ϊ�������ϱ����ַ���ס��ֻ�������Žֵ����ߡ�
�����ֵ�֮��ļ����ȡ���(x,y)����ʾס�����ڵĽ��������磨4,20������ʾ�û��ڶ���
�����4���ֵ����ϱ������20���ֵ�������Ҫ��һ���ʾ֣�ʹ�ø���ס�����ʾֵľ���֮��
���١�����������ʾ�Ӧ�ý����Ǹ��ط�ʹ������ס������֮����С��
����
��һ��һ������n<20����ʾ��n��������ݣ�������n������;
ÿ���һ��һ������m<20,��ʾ������m��ס���������m��ÿ������������0<x,y<100����ʾĳ
���û����ڽ��������ꡣm�к�����һ������ݣ�
���
ÿ������������ʾ���С�ľ���ͣ��س�������
��������
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
�������
2
44
����˼·���ֶ�������x�ᣩ���ϱ�����y�ᣩ���ǣ����ʾ���С�ľ����Ϊ�������ݵ�x��y
�����ʾ������x��y����ľ���֮��,���ʾ�����Ϊס��x��y����λ��*/
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
	if (!(n > 0 && n < MAX_n))//�����Ϸ���
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

