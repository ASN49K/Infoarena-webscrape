#include <iostream>
#include <fstream>

using namespace std;

ifstream f_read("cmlsc.in");
ofstream f_write("cmlsc.out");

int table[1030][1030],a[1030],b[1030],best[1030];
int n,m,k;

int main()
{
    f_read >>n>>m;
    for(int i=1;i<=n;++i){
        f_read >>a[i];
    }
    for(int i=1;i<=m;++i){
        f_read >>b[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                table[i][j]=table[i-1][j-1]+1;
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    f_write <<table[n][m]<<"\n";
    for(int i=n,j=m; i && j;){
        if(a[i]==b[j]){
            best[++k]=a[i];
            --i;
            --j;
        }
        if(table[i][j]==table[i-1][j-1]){
            --i;
            --j;
        }
        else{
            if(table[i][j]==table[i][j-1]){
                --j;
            }
            else{
                if(table[i][j]==table[i-1][j]){
                    --i;
                }
            }
        }
    }
    for(int i=k;i>0;--i){
        f_write <<best[i]<<" ";
    }
    return 0;
}
