#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1050],b[1050],c[1050],n,m;
int mat[1050][1050];

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    for(int i=1;i<=m;i++){
        f>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(b[j]==a[i])mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
        }
    }
    int i=n,j=m;
    while(i>0&&j>0){
        if(a[i]==b[j]){c[++c[0]]=a[i];j--;i--;}
        else if(mat[i-1][j]>mat[i][j-1])i--;
        else j--;
    }
    for(i=c[0];i>=1;i--)g<<c[i]<<" ";
    return 0;
}
