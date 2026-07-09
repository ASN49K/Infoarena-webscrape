#include <bits/stdc++.h>
using namespace std;
ifstream in   ("euclid2.in");
ofstream out ("euclid2.out");
int a,b,i,k;
int alg (int a,int b)
{
    int aux;
    if (a>b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    do
    {
        aux=a%b;
        a=b;
        b=aux;
    } while (aux!=0);
    return a;
}
int main ()
{
    in>>k;
    for (i=1;i<=k;i++)
    {
        in>>a>>b;
        out<<alg(a,b)<<endl;
    }
    return 0;
}
