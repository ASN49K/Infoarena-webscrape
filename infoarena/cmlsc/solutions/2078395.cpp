#include <fstream>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int n,m,v[1025],fr[257];
void afisare(int i,int p[])
{   while(i){
        g<<v[i]<<" "; i=p[i];
    }
}
void pb()
{   int p[1025]={0},l[1025]={0},maxl,maxi;
    p[m]=0;l[m]=1;
    for(int i=m-1;i>=1;i--)
    { for(int j=i+1;j<=m;j++)
            if(v[i]<v[j] && l[i]<l[j]){
                l[i]=l[j]+1; p[i]=j;
            }
        if(l[i]>maxl) maxl=l[i],maxi=i;
    } afisare(maxi,p);
}
int main()
{   f>>n>>m;
    for(int nr,i=1;i<=n;i++){ f>>nr; fr[nr]++; }
    { int k=0;
        for(int nr,i=1;i<=m;i++){
            f>>nr;
            if(fr[nr]){
                v[++k]=nr;
            }
        }
        m=k; } pb();
    return 0;
}
