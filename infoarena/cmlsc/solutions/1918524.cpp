#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,v[1025][1025],a[1025],b[1025];
void citire ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
}
void matrice()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            v[i][j]=max(v[i][j-1],max(v[i-1][j],v[i-1][j-1]+(a[i]==b[j])));
}
void afisare ()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";}
}
void det()
{
    int s[1025];
    int i=n,j=m,k=0;
    while(v[i][j]!=0)
    {
        if(a[i]==b[j])
            s[++k]=a[i],i--,j--;
        else
            if(v[i][j-1]>v[i-1][j])
                j--;
            else
                i--;
    }
    for(int i=k;i>=1;i--)
        cout<<s[i]<<" ";
}
int main ()
{
    citire();
    matrice();
   // afisare();
    cout<<v[n][m]<<"\n";
    det();
    return 0;
}

