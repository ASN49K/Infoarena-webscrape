#include <iostream>
#include <fstream>
using namespace std;
int grid[1024][1024];
void lcs(int a[1024],int b[1024],int n,int m){
    int i,j;
    for(i=0;i<=n;i++)
        grid[i][0]=0;
    for(j=0;j<=m;j++)
        grid[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                grid[i][j]=grid[i-1][j-1] + 1;
            else
                if(grid[i-1][j]>=grid[i][j-1])
                    grid[i][j]=grid[i-1][j];
                else
                    grid[i][j]=grid[i][j-1];
}
void compunere(int sub[1024],int &k,int a[1024],int b[1024],int i,int j){
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            sub[k++]=a[i];
            i--;
            j--;
        }
        else{
            if(grid[i-1][j]>=grid[i][j-1])
                i--;
            else if(grid[i][j-1]>grid[i-1][j])
                j--;
        }
    }
    k--;
}
int main(){
    int a[1024],b[1024],n,m,i,j,sub[1024],k=1;
    ifstream f("cmlsc.in");
    ofstream o("cmlsc.out");
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    lcs(a,b,n,m);
    o<<grid[n][m]<<'\n';
    compunere(sub,k,a,b,n,m);
    for(i=k;i>=1;i--)
        o<<sub[i]<<" ";
    f.close();
    o.close();
    return 0;
}
