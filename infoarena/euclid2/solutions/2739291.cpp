#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int teste,n,m,r[100],p=0;
    fin>>teste;
    while(teste!=0)
    {
        fin>>n>>m;
        while(n!=m)
            if(n>m)
                n-=m;
            else
                m-=n;
        r[p++]=n;
        teste--;
    }
    for(int i=0;i<p;++i)
        fout<<r[i]<<endl;
    return 0;
}
