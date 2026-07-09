#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    while(b!=0)
    {
        int r;
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b,n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }

    return 0;
}
