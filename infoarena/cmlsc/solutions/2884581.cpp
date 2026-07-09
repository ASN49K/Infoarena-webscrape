#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
FILE *fin=fopen("cmlsc.in", "r");
FILE *fout=fopen("cmlsc.out", "w");
int a[1030], b[1030], dp[1030][1030];
vector <int> sir;
int main()
{
    int n, m;
    fscanf(fin, "%d%d", &n, &m);
    for (int i=1; i<=n; i++) fscanf(fin, "%d", &a[i]);
    for (int i=1; i<=m; i++) fscanf(fin, "%d", &b[i]);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    for (int i=n, j=m; i; ) {
        if (a[i]==b[j]) {
            sir.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j]<dp[i][j-1])
            j--;
        else i--;
        //cout<<i<<" "<<j<<endl;
    }
    fprintf(fout, "%d%c", sir.size(), '\n');
    for (int i=sir.size()-1; i>=0; i--)
        fprintf(fout, "%d%c", sir[i], ' ');
    return 0;
}
