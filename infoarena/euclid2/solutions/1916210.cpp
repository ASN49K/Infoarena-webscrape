#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,a,b,i;
int rez(int a, int b)
{
    if(b==0)return a;
    else rez(b, a%b);
}
int main()
{
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<rez(a,b)<<'\n';
    }
    return 0;
}
