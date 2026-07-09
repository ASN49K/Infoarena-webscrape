#include <iostream>
#include <fstream>
#define maxim(a,b) ((a>b)? a : b )
#define max_count 1024
using namespace std;

int m,n,a[max_count],b[max_count],dp[max_count][max_count],sequence[max_count],k;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>m>>n;
    for(int i = 1; i<=m ;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(a[i] == b[j])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = maxim(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=m,j=n;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            sequence[k++] = a[i];
            i--;j--;
        }
        else
            if(dp[i-1][j] < dp[i][j-1])
                j--;
            else
                i--;
    }

    fout<< k<<'\n';
    for(int i = k-1;i>=0;i--){
        fout<<sequence[i]<< " ";
        cout<<sequence[i]<< " ";
    }
}
