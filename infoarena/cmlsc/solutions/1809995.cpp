#include <bits/stdc++.h>
using namespace std;
const char* IN =  "cmlsc.in";
const char* OUT = "cmlsc.out";
const int Nmax = 1030;

namespace InputStream {
    FILE *in = fopen(IN,"r");
    int nextInt(){
        int aux;
        fscanf(in,"%d",&aux);
        return aux;
    }
};

namespace PrintStream {
    FILE *out = fopen(OUT,"w");
    void printInt(int nbr){
        fprintf(out,"%d ",nbr);
    }
    void endline(){
        fprintf(out,"\n");
    }
}

namespace Algorithm {
    int dp[Nmax][Nmax];

    void getGCS(int n,int m,int a[Nmax],int b[Nmax]){
        vector <int> ans;
        for (int i=0;i<=Nmax;++i)
            dp[i][0] = dp[0][i] = 0;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                dp[i][j] = (a[i]==b[j]) ? dp[i-1][j-1] + 1 : max (dp[i-1][j],dp[i][j-1]);
        PrintStream::printInt(dp[n][m]);
        PrintStream::endline();
        for (int i=n, j=m ; i>0 && j>0 ; ) {
            if (a[i]==b[j]) {
                    ans.push_back(a[i]);
                    --i;
                    --j;
            }
            else {
                if (dp[i-1][j] > dp[i][j-1]) --i;
                        else --j;
            }
        }
        for (int i = ans.size()-1;i>=0;--i)
            PrintStream::printInt(ans[i]);
    }
}

int a[Nmax],b[Nmax];
int main(void){
    int n = InputStream::nextInt();
    int m = InputStream::nextInt();
    for (int i=1;i<=n;++i){
        a[i] = InputStream::nextInt();
    }
    for (int j=1;j<=m;++j){
        b[j] = InputStream::nextInt();
    }
    Algorithm::getGCS(n,m,a,b);
    return 0;
}
