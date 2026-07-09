// @RomoCoder
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int A[1025], B[1025];
int DP[1025][1025];

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;

    scanf("%d %d", &n, &m);    
    int i, j, k;
    
    //read
    for (i = 0; i < n; ++i) scanf("%d", &A[i+1]);    
    for (i = 0; i < m; ++i) scanf("%d", &B[i+1]);
    
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) 
    {
        DP[i][j] = DP[i-1][j-1] + (A[i] == B[j]);
        DP[i][j] = max(DP[i][j], max(DP[i-1][j], DP[i][j-1]));

    }
    printf("%d\n", DP[n][m]);
    
    //get the solution
    vector<int> v;
    i = n, j = m;
    while (i != 0 && j != 0) 
    {
          if (A[i] == B[j]) {v.push_back(A[i]);--i; --j; continue;}
          if (DP[i-1][j] > DP[i][j-1]) --i;
          else --j;
    }
    for (i = v.size() - 1; i > 0; --i) printf("%d ", v[i]);
    if (v.size() != 0) printf("%d\n", v[0]);
    return 0;    
}
//RomoCoder in Action Again!
