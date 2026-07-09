#include <bits/stdc++.h>

#define nmax 1026

using namespace std;

struct nod
{
    int val=-1,sum=0;
    nod* prev;
};

nod d[nmax][nmax];

int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,a[nmax],b[nmax];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j].sum=d[i-1][j-1].sum+1;
                d[i][j].val=a[i];
                d[i][j].prev=&d[i-1][j-1];
            }
            else
            {
                if(d[i-1][j].sum>d[i][j-1].sum)
                {
                    d[i][j]=d[i-1][j];
                }
                else
                {
                    d[i][j]=d[i][j-1];
                }
            }
        }
    }

    vector<int>ans;

    nod next=d[n][m];
    int s=d[n][m].sum;
    while(next.val!=-1)
    {
        ans.push_back(next.val);
        next=*next.prev;
    }
    cout<<s<<'\n';
    for(int i=s-1;i>=0;i--)
        cout<<ans[i]<<' ';




    return 0;
}
