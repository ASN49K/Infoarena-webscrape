#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

void cm(int a,int b)
{
    int d=1,x=b+1;

    while(x>b)
    {
        d=a/b;
        x=a-d*b;
    }
    if(x!=0)
        cm(b,x);
    else out<<b<<"\n";
}
int main()
{
    int T,a,b,c,d;
    in>>T;
    for(int i=1;i<=T;i++)
    {
        in>>a>>b;
        c=max(a,b);
        d=min(a,b);
        cm(c,d);
    }
    return 0;
}
