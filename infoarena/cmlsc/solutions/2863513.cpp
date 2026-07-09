#include <fstream>
using namespace std;
int v1[1024];
int v2[256];
int l[256];
int urm[256];
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
void afisare(int a[], int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int m,n,x,maxx=0,minn=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(maxx<x) maxx=x;
        if(v1[x]==0) v1[x]=i;
    }
    maxx=0;
    for(int j=1;j<=n;j++)
    {
        cin>>x;
        if(v1[x]){
            v2[x]=j;
            if(maxx<x) maxx=x;
            if(minn>x) minn=x;
        }
    }
    for(int j=maxx;j>=minn;j--)
    {
        if(v2[j]){
            l[j]=1;
            for(int i=j+1;i<=maxx;i++)
                if(v2[j]<v2[i] && v1[j]<v1[i] && l[j]<=l[i]){
                    l[j]=l[i]+1;
                    urm[j]=i;
                }
        }
    }
    int pmax=minn;
    for(int i=minn+1;i<=maxx;i++)
        if(l[pmax]<l[i]) pmax=i;
    cout<<l[pmax]<<endl;
    cout<<pmax<<" ";
    while(urm[pmax])
    {
        cout<<urm[pmax]<<" ";
        pmax=urm[pmax];
    }
    return 0;

}