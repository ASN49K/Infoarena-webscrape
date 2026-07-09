#include<iostream>
using namespace std;

int cmmdc(int a,int b)
{
    int r = a % b;
    while(r != 0)
    {
         a = b;
         b = r;
         r = a % b;   
    }
    return b;
}

int main(void)
{
    cout<<cmmdc(10,15);
    system("pause");
    return 0;
}
