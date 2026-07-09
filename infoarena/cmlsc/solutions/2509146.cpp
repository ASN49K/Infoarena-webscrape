#include <iostream>
#include <fstream>

#define NMAX 1024

using namespace std;

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[NMAX],b[NMAX],v[NMAX][NMAX];

void citire(int n,int *v)
{
    for(int i=0;i<n;++i)
        f>>v[i];
}

void LCS()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        if(a[i]==b[j])
            v[i+1][j+1]=v[i][j]+1;
        else
            v[i+1][j+1]=max(v[i+1][j],v[i][j+1]);

}


int main()
{
    f>>n>>m;
    citire(n,a);
    citire(m,b);
    LCS();
    g<<v[n][m]<<'\n';
    int i=n,j=m,res[NMAX],k=0;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            res[k++]=a[i-1];
            --i;
            --j;
        }
        else
            if(v[i-1][j]==v[i][j])
                --i;
            else
                --j;
    }

    for(i=k-1;i>=0;--i)
        g<<res[i]<<' ';


    return 0;
}
