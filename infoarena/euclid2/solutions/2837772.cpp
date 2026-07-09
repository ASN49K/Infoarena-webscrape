#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(unsigned int a, unsigned int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    unsigned int x, y, n;
    fin>>n;
    while(n!=0)
    {
        fin>>x>>y;
        fout<<cmmdc(x, y)<<'\n';
        n--;
    }
    return 0;
}
