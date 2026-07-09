#include <iostream>
#include <fstream>
using namespace std;

struct pct{
    int x,y;
};

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m,*v1,*v2,**dp;
    pct **tata;
    fin>>n>>m;
    v1 = new int[n];
    v2 = new int[m];
    dp = new int*[n];
    tata = new pct*[n];
    for(int i=0;i<n;i++){
            fin>>v1[i];
            dp[i] = new int[m];
            tata[i] = new pct[m];
    }
    for(int i=0;i<m;i++) fin>>v2[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = 0;
            tata[i][j].x = tata[i][j].y = -1;
        }
    }

    int maxi = -1,ind1 = -1 , ind2 = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x1=0,x2=0;
            if(i>0)x1 = dp[i-1][j];
            if(j>0)x2 = dp[i][j-1];
            int x3 = -1;
            if(v1[i]==v2[j]){
                x3=1;
                if(i>0 && j>0) x3 += dp[i-1][j-1];
            }
            dp[i][j] = max(x1,x2);
            dp[i][j] = max(dp[i][j],x3);
            if(dp[i][j]>maxi){
                maxi = dp[i][j];
                ind1 = i;
                ind2 = j;
            }
            if(dp[i][j]==x1){
                tata[i][j].x = i-1;
                tata[i][j].y = j;
            }else{
                if(dp[i][j]==x2){
                    tata[i][j].x = i;
                    tata[i][j].y = j-1;
                }else{
                    tata[i][j].x = i-1;
                    tata[i][j].y = j-1;
                }
            }
        }
    }
    int a = ind1;
    int b = ind2;
    fout<<maxi<<endl;

    int *rez,nr=0;
    rez = new int[maxi];
    while(a!=-1 && b!=-1){
        //cout<<a<<" "<<b<<" "<<endl;
        if(a-1==tata[a][b].x && b == tata[a][b].y) a--;
        else{
            if(a==tata[a][b].x && b - 1 == tata[a][b].y) b--;
            else{
                rez[nr]=v1[a];
                nr++;
                a--;
                b--;
            }
        }
    }

    for(int i=nr-1;i>=0;i--) fout<<rez[i]<<" ";

    return 0;
}
