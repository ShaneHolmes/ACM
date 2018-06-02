/*
ASCII码排序
时间限制：3000 ms  |  内存限制：65535 KB
难度：2
描述
输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。
输入
第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
输出
对于每组输入数据，输出一行，字符中间用一个空格分开。
样例输入
2
qwe
asd
样例输出
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
