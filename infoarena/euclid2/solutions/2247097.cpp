#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if (b==0) return a;
    else
        euclid(b,a%b);
}
int main()
{
    int n,x,y;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<endl;
    }
    return 0;
}
