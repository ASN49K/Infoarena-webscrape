#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int maxim(int a, int b){
    return a > b ? a : b;
}

int main()
{
    ifstream fr("cmlsc.in");
    short int m, n;
    int *a = new int[m];
    int *b = new int[n];

    fr >> m >> n;

    for(int i = 0; i < m; ++i)
        fr >> a[i];
    for(int i = 0; i < n; ++i)
        fr >> b[i];

    fr.close();

    int **dp = new int *[m+1];
    for(int i = 0; i <= m; ++i){
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; ++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = maxim(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[m][n];
    int *v = new int[len];
    int i = m, j = n;
    while(i && j) {
        if(a[i-1] == b[j-1]){
            v[len-1] = a[i-1];
            --i;--j;--len;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            --i;
        else
            --j;
    }
    delete[] a; delete[] b;

    ofstream fw("cmlsc.out");
    int k = dp[m][n];
    fw << k << '\n';
    for(int i = 0; i < k; ++i)
        fw << v[i] << ' ';

    delete[] v;
    fw.close();
    return 0;
}
