#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in")
ofstream fout("euclid2.out")
int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    int x, y, n;
    fin>>n;
    while(n!=0)
    {
        fin>>x>>y;
        fout<<cmmdc(x, y)<<endl;
        n--;
    }
    return 0;
}
