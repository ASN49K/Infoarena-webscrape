#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else b-=a;
    }
    return a;
}
int main()
{
    int n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        int k,m;
        fin>>k>>m;
        fout<<euclid(k,m);
        fout<<'\n';
    }
    return 0;
}

