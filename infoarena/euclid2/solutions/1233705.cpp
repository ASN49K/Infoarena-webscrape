#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cm(int a,int b,int d)
{
    if(a%d==0 && b%d==0) return d;
    else return cm(a,b,d-1);
}
int main()
{
    int T,a,b,d,i;
    in>>T;
    for(i=1;i<=T;i++)
    {
        in>>a>>b;
        d=min(a,b);
        out<<cm(a,b,d)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
