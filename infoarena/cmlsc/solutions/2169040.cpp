#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1024],b[1024],c[1024];
int main()
{
   int i,j,n,t=0,m,MAX=0;

   fin>>n>>m;
   for(i=1;i<=n;i++){
        fin>>a[i];
   }
   for(j=1;j<=m;j++){
        fin>>b[j];
   }

   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        if(a[i]==b[j]){
            MAX++;
            c[++t]=b[j];
        }
   }

   fout<<MAX<<"\n";
   for(i=1;i<=t;i++)
        fout<<c[i]<<" ";



    return 0;
}
