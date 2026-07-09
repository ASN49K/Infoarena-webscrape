#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    int r=a%b;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,eu,a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        eu=euclid(a,b);
        fout<<eu<<'\n';
    }
    return 0;
}
