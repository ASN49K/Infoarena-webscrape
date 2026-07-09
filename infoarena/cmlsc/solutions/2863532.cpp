#include <fstream>
using namespace std;
int v1[1024];
int v2[256];
int l[256];
int urm[256];
int v3[256];
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
    int m,n,x, ok=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        v1[i]=x;
        if(!v3[x]) v3[x]=1;
    }
    for(int j=1;j<=n;j++)
    {
        cin>>x;
        if(v3[x]) v2[j]=x;
    }
    for(int j=n;j>=1;j--)
    {
        if(v2[j]){
            l[j]=1;
            for(int i=j+1;i<=n;i++)
            {
                ok=0;
                for(int k=1;k<=n;k++)
                {
                    if(v1[k]==v2[j]){
                        for(int k2=1;k2<=n;k2++)
                            if(v1[k2]==v2[i] && k<k2){
                                ok=1;
                                break;
                            }
                    }
                    if(ok) break;
                }
                if(ok)
                    if(l[j]<=l[i])
                    {
                        l[j]=l[i]+1;
                        urm[j]=i;
                    }
            }
        }
    }
    int pmax=1;
    for(int i=2;i<=n;i++)
        if(l[pmax]<l[i]) pmax=i;
    cout<<l[pmax]<<endl;
    cout<<v2[pmax]<<" ";
    while(urm[pmax])
    {
        cout<<v2[urm[pmax]]<<" ";
        pmax=urm[pmax];
    }
    return 0;

}