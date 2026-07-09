#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i;
pair <int,int> v[100005];
int euclid(int a,int b)
{
    int aux;
    while(b!=0)
    {
        aux=b;
        b=b%a;
        a=aux;
    }
    return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>v[i].first>>v[i].second;
        fout<<euclid(v[i].first, v[i].second)<<'\n';
    }
    return 0;
}
