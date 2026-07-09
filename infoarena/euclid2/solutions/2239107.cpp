#include <iostream>
#include <fstream>
using namespace std;
int t;
int cmmdc(int a,int b)
{
    int c;
    while (b>0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{int i,a,b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for (i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    out.close();
    in.close();
    return 0;
}
