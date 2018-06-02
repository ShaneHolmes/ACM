/*描述
现在有很多长方形，每一个长方形都有一个编号，这个编号可以重复；还知道这个长方形的宽和长，编号、长、宽
都是整数；现在要求按照一下方式排序（默认排序规则都是从小到大）；
1.按照编号从小到大排序
2.对于编号相等的长方形，按照长方形的长排序；
3.如果编号和长都相同，按照长方形的宽排序；
4.如果编号、长、宽都相同，就只保留一个长方形用于排序,删除多余的长方形；最后排好序按照指定格式显示所有的长方形；
输入
第一行有一个整数 0<n<10000,表示接下来有n组测试数据；每一组第一行有一个整数 0<m<1000，表示有m个长方形；接下来
m行，每一行有三个数 ，第一个数表示长方形的编号，第二个和第三个数值大的表示长，数值小的表示宽，相等说明这是一个
正方形（数据约定长宽与编号都小于10000）；
输出
顺序输出每组数据的所有符合条件的长方形的 编号 长 宽
样例输入
1
8
1 1 1
1 1 1
1 1 2
1 2 1
1 2 2
2 1 1
2 1 2
2 2 1
样例输出
1 1 1
1 2 1
1 2 2
2 1 1
2 2 1*/
#include<iostream>
#define MAX_n 10000
#define MAX_m 1000
#define MAX_IdSide 10000
using namespace std;
struct Rectangle
{
	int id;
	int length;
	int width;
};
void getRectangles(Rectangle *r, int i);
void printRectangle(Rectangle *r, int m);
extern int counts = 0;
int main()
{
	int n;
	cin >> n;
	if (n<0 || n>MAX_n)
	{
		return -1;
	}
	while (n--)
	{
		int m;
		cin >> m;
		if (m<0 || m>MAX_m)
		{
			return -1;
		}
		int i = 0;
		Rectangle r[MAX_m];
		while (i < m)
		{
			getRectangles(r, i);
			if (r[i].id > MAX_IdSide||r[i].length > MAX_IdSide || r[i].width > MAX_IdSide||r[i].length<0||r[i].width<0)
			{
				return -1;
			}
			i++;
		}
		printRectangle(r, m);
	}
	system("pause");
	return 0;
}

void getRectangles(Rectangle *r, int i)
{
	int id, length, width;
	cin >> id >> length >> width;
	if (length < width)
	{
		int temp= length;
		length = width;
		width = temp;
	}
	bool flag = false;
	for (int j = 0;j < i;j++)
	{
		if (id == r[j].id&&length == r[j].length&&width == r[j].width)
		{
			flag = true;
			r[i].id = r[i].length = r[i].width = 0;
			break;
		}
	}
	if (!flag)
	{
		r[i].id = id;
		r[i].length = length;
		r[i].width = width;
		counts++;
	}
	
}

void printRectangle(Rectangle *r, int m)
{
	int i ,j;
	/*for (i = 0;i < m;i++)//调试错误
	{
		cout << r[i].id << " " << r[i].length << " " << r[i].width << endl;

	}*/
	while (counts)
	{
     for (i=0;i < m;i++)
	{
        
		if (r[i].id == 0 && r[i].length == 0 && r[i].width == 0)
		{
			continue;
		}
		bool flag = true;
		for (j=0;j < m ;j++)
		{
			if ((r[j].id == 0 && r[j].length == 0 && r[j].width == 0)||i==j)
			{
				continue;
			}

			if (r[i].id > r[j].id)
			{
				flag = false;
				break;
			}
			else if(r[i].id ==r[j].id&&r[i].length > r[j].length)
			{
				flag = false;
				break;
			}
			else if (r[i].id == r[j].id&&r[i].length == r[j].length &&r[i].width > r[j].width)
			{
				flag = false;
				break;
			}
			else
			{

			}
		}
		if (flag)
		{
			cout << r[i].id << " " << r[i].length << " " << r[i].width << endl;
			r[i].id = 0;
			r[i].length = 0;
			r[i].width = 0;
			counts--;
		}
	}
	}
	
}