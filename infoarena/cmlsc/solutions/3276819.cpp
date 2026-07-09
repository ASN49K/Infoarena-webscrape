#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];

int main() {
    int n, m, I, J;
    fin>>n>>m;
    int A[n+1], B[m+1];
    for(int i=1; i<=n; i++)
        fin>>A[i];
    for(int j=1; j<=m; j++)
        fin>>B[j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<int> rezolvare;
    I=n;
    J=m;
    while(I>0 && J>0)
    {
        if(A[I]==B[J])
        {
            rezolvare.push_back(A[I]);
            I--;
            J--;
        }
        else
        {
            if(dp[I-1][J]>dp[I][J-1])
                I--;
            else
                J--;
        }
    }
    reverse(rezolvare.begin(), rezolvare.end());
    fout<<dp[n][m]<<"\n";
    for(auto i : rezolvare)
        fout<<i<<" ";
    return 0;
}
