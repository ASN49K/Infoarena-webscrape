#include <fstream>
#include <cstdio>
using namespace std;
int m,n,i,v[1000],x[1000],ma,j,a[100][100],l,c,nr,ics,igrec,mx,ok,nu,k,w[1000];
int main(){
    freopen("cmlsc.in","r",stdin);
    ofstream g ("cmlsc.out");
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
        for(i=1;i<=m;i++)
        scanf("%d",&x[i]);
        ma=0;
        for(i=1;i<=n;i++){
        if(v[i]==x[1])ma++;
        a[i][1]=ma;}
        ma=0;
        for(i=1;i<=n;i++)
            for(j=2;j<=m;j++){
                if(v[i]==x[j])a[i][j]=a[i-1][j-1]+1;
                else
                if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
                else a[i][j]=a[i][j-1];}
                    //g<<a[n][m];
                    //g<<'\n';
                    l=n;
                    c=m;
                    nu=a[l][c];
                    g<<a[l][c]<<'\n';
                    k++;
                    w[k]=v[l];nr=2;
                    while(nr<=nu){
                            ics=a[l-1][c];
                    igrec=a[l][c-1];
                    if(ics>igrec){mx=ics;ok=1;}
                    else
                        if(ics<igrec){mx=igrec;ok=2;}
                        else mx=ics;
                   if(mx<a[l][c]){c--;l--;}
                   else
                   if(ok==1)l--;
                   else c--;
                   if(v[l]==x[c]){k++;w[k]=v[l];nr++;}}
                   for(i=k;i>=1;i--)
                    g<<w[i]<<" ";
                    return 0;}
