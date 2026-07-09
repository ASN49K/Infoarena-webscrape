#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
void citire()
{
    fin>>n;
    int x,y;
    for(int i=0;i<n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
}
int main()
{
    citire();
    return 0;
}
