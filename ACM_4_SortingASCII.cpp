/*
ASCII������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
���������ַ��������ظ����󣬰����ַ���ASCII���С�����˳������������ַ���
����
��һ������һ����N,��ʾ��N��������ݡ������N������������ݣ�ÿ���������ݶ���ռһ�У��������ַ���ɣ�֮���޿ո�
���
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
��������
2
qwe
asd
�������
e q w
a d s
*/
#include <iostream>


using namespace std;
void sort_Ascii(char a, char b, char c)
{
    char t1 = a, t2 = b, t3 = c, t;
    if(t1 > t2)
    {
        t = t1;
        t1 = t2;
        t2 = t;
    }
    if(t3 > t2)
        cout << t1 << " " << t2 << " " << t3 << endl;
    else if(t3 < t1)
        cout << t3 << " " << t1 << " " << t2 << endl;
    else
        cout << t1 << " " << t3 << " " << t2 << endl;
}
int main()
{
    int n;
    cin >> n;
    while(n >= 1)
    {
        char a, b, c;
        cin >> a >> b >> c;
        sort_Ascii(a, b, c);
        n --;
    }
    return 0;
}
