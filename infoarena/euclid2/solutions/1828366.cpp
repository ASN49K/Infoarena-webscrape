#include<fstream>
#include<iostream>
using namespace std;
int n;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b);
    }
}
