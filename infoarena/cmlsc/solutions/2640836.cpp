#include <bits/stdc++.h>
using namespace std;

int m, n, A[1030], B[1030], dp[1030][1030] ;
pair <int, int> M[1030][1030];
vector <int> rasp;

void fast ()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int main()
{
    fast();
    freopen("cmlsc.in","r", stdin);
    freopen("cmlsc.out","w", stdout);

    cin >> m >> n;

    for (int i=1; i<=m; i++)
        cin >> A[i];

    for (int i=1; i<=n; i++)
        cin >> B[i];


    for (int i=0; i<=m; i++)
        dp[i][0]=0;

    for (int i=0; i<=n; i++)
        dp[0][i]=0;

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            if (A[i]==B[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                M[i][j].first=i-1;
                M[i][j].second=j-1;
                /// alternativa: M[i][j]={i-1,j-1};
            }

            else
            {
                dp[i][j]= max (dp[i-1][j],dp[i][j-1]);
                if (dp[i-1][j]>dp[i][j-1])
                {
                    M[i][j].first=i-1;
                    M[i][j].second=j;
                }
                else if (dp[i-1][j]==dp[i][j-1])
                {
                    M[i][j].first=i-1;
                    M[i][j].second=j;
                }
                else
                {
                    M[i][j].first=i;
                    M[i][j].second=j-1;
                }
            }

        }

        int nowI=m;
        int nowJ=n;

        while (nowI!=0 && nowJ!=0)
        {
            if (nowI!=M[nowI][nowJ].first && nowJ!=M[nowI][nowJ].second)
            {
                rasp.push_back(A[nowI]);
            }
            int cnowI=nowI;
            nowI=M[nowI][nowJ].first;
            nowJ=M[cnowI][nowJ].second;
        }

    /*for (int i=1; i<=m; i++, cout << '\n')
        for (int j=1; j<=n; j++)
            cout << M[i][j].first << "," << M[i][j].second << " ";
    */

    reverse(rasp.begin(), rasp.end());

    cout << rasp.size() << '\n';

    for (int i=0; i<(int)rasp.size(); i++)
        cout << rasp[i] << " ";

    return 0;
}
