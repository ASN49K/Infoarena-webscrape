#include <bits/stdc++.h>

using namespace std;
int n,x,y;

int euclid(int a, int b)
{
    int aux;
    if(b!=0 && a!=0)
    {
    while(b!=0)
    {
        aux=a;
        a=b;
        b=aux%b;
    }
    return a;
    }
    return 0;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
