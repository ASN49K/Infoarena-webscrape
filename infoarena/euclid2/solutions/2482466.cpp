#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int cmmdc(int x, int y)
{
    int s;
    while(y)
    {
        s=x%y;
        x=y;
        y=s;
    }
    return x;
}
int main()
{
    fin>>n;
    while(n)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
        n--;
    }

}
