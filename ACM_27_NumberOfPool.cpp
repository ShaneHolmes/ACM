/*
ˮ����Ŀ
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
��������ѧԺУ԰����һЩС�Ӻ�һЩ���������ڣ����ǰ�����ͨһ����ˮ�أ�������һ������ѧУ��ĳ���ĵ�ͼ��
�����ͼ�Ͻ���ʶ�˴˴��Ƿ���ˮ�أ����ڣ�����������ˣ����ü��������õ�ͼ�й��м���ˮ�ء�
����
��һ������һ������N����ʾ����N���������
ÿһ�����ݶ���������õ�ͼ������m(0<m<100)������n(0<n<100)��Ȼ�������������m��ÿ������n��������ʾ��
����ˮ����ûˮ��1��ʾ�˴���ˮ�أ�0��ʾ�˴��ǵ��棩
���
����õ�ͼ��ˮ�صĸ�����
Ҫע�⣬ÿ��ˮ�ص��Աߣ����������ĸ�λ�ã��������ˮ�صĻ��Ļ������ǿ��Կ�����ͬһ��ˮ�ء�
��������
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
�������
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