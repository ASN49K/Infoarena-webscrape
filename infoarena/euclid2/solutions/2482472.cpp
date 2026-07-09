#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int cmmdc(int x, int y)
{
    if(y)
        return cmmdc(y, x%y);
    else return x;
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
