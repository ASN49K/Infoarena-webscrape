#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int div(int a, int b)
{
    if(a==b) return a;
    if(a>b) return div(a-b,b);
    else if(a<b) return div(a,b-a);
}
int main()
{
    int t,a,b;
    fin>>t;
    for(int i=1;i<=t;++i)
    {
    fin>>a>>b;
    fout<<div(a,b)<<"\n";
    }
    return 0;
}
