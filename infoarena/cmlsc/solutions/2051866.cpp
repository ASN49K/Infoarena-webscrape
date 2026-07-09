#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],l[1025][1025],c[1025],n,m,i,j,k;
int main()
{
fin>>n>>m;
for(i=1;i<=n;i++)
    fin>>a[i];
for(i=1;i<=m;i++)
    fin>>b[i];
for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if(a[i]==b[j])
            l[i][j]=l[i-1][j-1]+1;
        else
        l[i][j]=max(l[i-1][j],l[i][j-1]);
    }
}
i--;
j--;
fout<<l[n][m]<<"\n";
while(i>=1 && j>=1){
        if(a[i]==b[j]){
            k=k+1;
            c[k]=a[i];
            i--;
            j--;
        }
        else{
            if(l[i-1][j]>l[i][j-1])
                i--;
        else
           j--;
    }
    }
    for(int g=k;g>=1;g--){
        fout<<c[g]<<" ";
    }
return 0;
}
