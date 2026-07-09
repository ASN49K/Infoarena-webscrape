#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N,M,a[1100],b[1100],best[1100][1100];
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

    cout<<best[M][N]<<endl;

    int k=1;
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
        {
           if(best[i][j]==k)
           {
               cout<<a[i]<<" ";
               ++k;
           }
        }

    return 0;
}
