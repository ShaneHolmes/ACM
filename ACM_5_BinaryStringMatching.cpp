/*
Binary String Matching
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
Given two strings A and B, whose alphabet consist only ��0�� and ��1��. Your task is only to tell how many times 
does A appear as a substring of B? For example, the text string B is ��1001110110�� while the pattern string A is
 ��11��, you should output 3, because the pattern A appeared at the posit
����
The first line consist only one integer N, indicates N cases follows. In each case, there are two lines, the first
 line gives the string A, length (A) <= 10, and the second line gives the string B, length (B) <= 1000. And it is 
 guaranteed that B is always longer than A.
���
For each case, output a single line consist a single integer, tells how many times do B appears as a substring of A.
��������
3
11
1001110110
101
110010010010001
1010
110100010101011 
�������
3
0
3 
*/
# include<stdio.h>
# include<string.h>

int main(void)
{
    char s1[1001],s2[11];
    int i,j,num,t,n,m;
    scanf("%d%*c",&t);//%*c������������֮���õĻس������߿ո�(����һ���ַ�),������֮��ĵ�һ���ַ�,���� gets(s2);�����س�, gets(s1);���������s2 
    while(t--)
    {
        num = 0;
        gets(s2);
        gets(s1);
        n = strlen(s1);
        m = strlen(s2);
        for(i=0;i<=n-m;i++)
        {
            if(s1[i] == s2[0])
            {
                for(j=1;j<m;j++)
                    if(s1[i+j]!=s2[j])
                        break;
                if(j>=m)
                    num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

