#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N,M,a[1100],b[1100],best[1100][1100],rez[1100];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    cin>>M>>N;
    for(int i=1;i<=M;++i)
        cin>>a[i];
    for(int i=1;i<=N;++i)
        cin>>b[i];

    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
    {
        if(a[i]==b[j])
            best[i][j]=best[i-1][j-1]+1;
        else
            best[i][j]=max(best[i-1][j],best[i][j-1]);
    }

    int k = best[M][N];
    cout<<k<<endl;

    int i=M,j=N;
    while(i)
    {
        if(a[i]==b[j])
        {
            rez[k]=a[i];
            --i;
            --j;
            --k;
        }
        else if(best[i-1][j] < best[i][j-1])
            --i;
        else
            --j;
    }

    for(int i=1;i<=best[M][N];++i)
        cout<<rez[i]<<" ";

    return 0;
}
