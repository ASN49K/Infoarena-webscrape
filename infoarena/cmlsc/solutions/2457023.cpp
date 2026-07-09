#include <iostream>
#include <fstream>
#define maxim(a,b) (a>b)?a:b
using namespace std;
int n,m,a[1024],b[1024],LCS[1024][1024]{},sol[1024],index=0;
int main()
{ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

fin>>m>>n;
for(int i=1;i<=m;i++){
   fin>>a[i];
}
for(int i=1;i<=n;i++){
   fin>>b[i];
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(a[i]==b[j]){
            LCS[i][j]=LCS[i-1][j-1]+1;
        }else
        LCS[i][j]=maxim(LCS[i-1][j],LCS[i][j-1]);
    }
}
int i=m,j=n;
while(i>0&&j>0){
    if(a[i]==b[j]){
        sol[++index]=a[i];
        i--;
        j--;
    }else
    if(LCS[i-1][j]>LCS[i][j-1]){
        i--;
    }else
    j--;
}
fout<<index<<"\n";
for(i=index;i>0;i--){
    fout<<sol[i]<<" ";
}
   fin.close();
   fout.close();
    return 0;
}
