#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1030],B[1030],i,m,n,j;
stack<int>ST;

int maxim(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    fin>>m>>n;
    for(i=1;i<=m;++i)fin>>A[i];
    for(i=1;i<=n;++i)fin>>B[i];

     int L[m+1][n+1],i,j;
    for(i=0;i<=m;++i)
        for(j=0;j<=n;++j)
    {
        if(i==0 || j==0)
            L[i][j]=0;
        else
            if(A[i]==B[j])
                L[i][j]=L[i-1][j-1]+1;
        else
            L[i][j]=maxim(L[i-1][j],L[i][j-1]);
    }
    fout<<L[m][n]<<'\n';

    i=m;j=n;
    while(i>0 && j>0)
    {
        if(A[i]==B[j])
        {
            ST.push(A[i]);
            --i;--j;
        }
        else
            if(L[i-1][j]>L[i][j-1])--i;
            else --j;
    }

    while(!ST.empty())
    {
        fout<<ST.top()<<' ';
        ST.pop();
    }
    return 0;
}
