#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long int a,b,d;
int cm()
{
    in>>a>>b;
    d=min(a,b);
    while(a!=b)
    {
        if(a>b)a=a-b;
        else b=b-a;
    }
    if(a>=1)out<<a<<"\n";
    else out<<0<<"\n";
}
int main()
{
    int T,i;
    in>>T;
    for(i=1;i<=T;i++)
        cm();
    in.close();
    out.close();
    return 0;
}
