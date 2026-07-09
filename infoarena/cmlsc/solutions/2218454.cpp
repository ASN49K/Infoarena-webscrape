#include <fstream>

using namespace std;

int main()
{
    int a,b,v[1024],c[1024],d[1024];
    int i,j,l,m=0,n=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>a>>b;
    for(i=0;i<a;i++)f>>v[i];
    for(j=0;j<b;j++)f>>c[j];
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        if(v[i]==c[j])
        {
        n=0;
        for(l=0;l<m;l++)if((v[i]==d[l])||(d[l]>v[i]))n++;
        if(n==0){
         m++;
         d[m-1]=v[i];
        }
        }
    g<<m<<"\n";
    for(i=0;i<m;i++)g<<d[i]<<' ';
    return 0;
}
