#include<iostream>
#include<fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int main()
{
    int i,j,m,n,nr,k,x[1024],y[1024],s[1024];
    nr= 0 ;
    int aux=0;
    k= 0 ;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>x[i];
    for(i=1;i<=n;i++)
        f>>y[i];
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            if(x[i]==y[j])
            {nr++;k++;s[k]=x[i];}
        for(i=1;i<=k;i++)
                if(s[i]>s[i+1])
            {
                aux=s[i];
                s[i]=s[i+1];
                s[i+1]=aux;
            }
            o<<nr<<endl;
            for(i=1;i<=k;i++)
                o<<s[i]<<" ";
}
