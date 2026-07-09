
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int dp1[200005], dp2[200005];
int previ[200005];
int aux[200005];
int main()
{
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    int ras=0, pozf=0;
    for(int i=1; i<=n; i++)
    {
        int max1=0, rasf=0, poz=0, pozi;
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                if(max1+1>dp2[j])
                {
                    dp2[j]=max1+1;
                    previ[j]=poz;
                }
                if(dp2[j]>rasf)
                {
                    rasf=dp2[j];
                    pozi=j;
                }
            }
            if(dp2[j]>max1)
            {
                max1=dp2[j];
                poz=j;
            }
        }
        dp1[i]=rasf;
        if(dp1[i]>ras)
        {
            ras=dp1[i];
            pozf=pozi;
        }
    }
    cout << ras << '\n';
    int cnt=0;
    while(pozf!=0)
    {
        aux[++cnt]=pozf;
        pozf=previ[pozf];
    }
    for(int i=cnt; i>=1; i--)
        cout << b[aux[i]] << ' ';
    return 0;
}

