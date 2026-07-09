#include <iostream>
#include <vector>
#define max(a,b) (a>b?a:b)
#define NMAX 1100

using namespace std;

int n,m,i,j;
int a[NMAX],b[NMAX];
int DP[NMAX][NMAX],last[NMAX][NMAX];

int main()
{
    //freopen("cmlsc.in","r",stdin);
    //freopen("cmlsc.out","w",stdout);

    cin>>n>>m;
    //primul sir
    for(i=1;i<=n;++i) cin>>a[i];
    //al doilea sir
    for(j=1;j<=m;++j) cin>>b[j];

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            //algoritmul din Cormen
            if(a[i] == b[j])
            {
                DP[i][j]=DP[i-1][j-1]+1;
                last[i][j]=1;
            }
            else if(DP[i-1][j] > DP[i][j-1])
            {
                DP[i][j]=DP[i-1][j];
                last[i][j]=2;
            }
            else
            {
                DP[i][j]=DP[i][j-1];
                last[i][j]=3;
            }
        }

    //afisare lungime
    cout<<DP[n][m]<<endl;
    //afisare subsir, parcurg matricea de la sfarsit spre inceput
    i=n;j=m;
    vector<int>sol;
    while(i >= 1 && j>=1)
    {
        if(last[i][j] == 1)
        {
            sol.push_back(a[i]);
            --i;--j;
        }
        else if (last[i][j] == 2) --i;
            else --j;
    }
    for(i=sol.size()-1;i>=0;--i) cout<<sol[i];
    return 0;
}
