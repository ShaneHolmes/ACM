/*����
�����кܶ೤���Σ�ÿһ�������ζ���һ����ţ������ſ����ظ�����֪����������εĿ�ͳ�����š�������
��������������Ҫ����һ�·�ʽ����Ĭ����������Ǵ�С���󣩣�
1.���ձ�Ŵ�С��������
2.���ڱ����ȵĳ����Σ����ճ����εĳ�����
3.�����źͳ�����ͬ�����ճ����εĿ�����
4.�����š���������ͬ����ֻ����һ����������������,ɾ������ĳ����Σ�����ź�����ָ����ʽ��ʾ���еĳ����Σ�
����
��һ����һ������ 0<n<10000,��ʾ��������n��������ݣ�ÿһ���һ����һ������ 0<m<1000����ʾ��m�������Σ�������
m�У�ÿһ���������� ����һ������ʾ�����εı�ţ��ڶ����͵�������ֵ��ı�ʾ������ֵС�ı�ʾ�����˵������һ��
�����Σ�����Լ���������Ŷ�С��10000����
���
˳�����ÿ�����ݵ����з��������ĳ����ε� ��� �� ��
��������
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
�������
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
	/*for (i = 0;i < m;i++)//���Դ���
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