#include<iostream>
using namespace std;
int cmmdc( int a, int b)
{
    if(b==0)
    return a;
    else
    return cmmdc(a,a%b);}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    cout<<cmmdc(a,b);
    system("PAUSE");
    return 0;}
