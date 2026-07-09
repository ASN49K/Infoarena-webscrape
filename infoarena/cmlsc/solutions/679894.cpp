#include<fstream.h>
#include<math.h>
#include<iostream.h>
int max (int a,int b)
{   if (a>=b) return a;
    else      return b;
}
int main ()
{
    ifstream f("cmlsc.in");
    short n,m,v1[1025],v2[1025],a[1025][1025],rez[1025];
    int i,j,l,c,nr=0;
    f>>n;
    f>>m;
    cout<<n<<" "<<m<<endl;
    for (i= 1 ; i<= n ; i ++)
        f>>v1[i];
    for (i= 1 ; i<= m ; i ++)
        f>>v2[i];
    f.close();
    for (i=0;i<=1025; i ++)
        for (j=0;j<=1025;j++)
            a[i][j]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v1[i]==v2[j])
               a[i][j]=a[i-1][j-1]+1;          
            else
               a[i][j]=max(a[i][j-1],max(a[i-1][j-1],a[i-1][j])); 
    ofstream g("cmlsc.out");
    i=n;j=m;
    g<<a[i][j]<<endl;
    while (a[i][j]!=0)
    {
    if (v1[i]==v2[j])
       {nr++; rez[nr]=v1[i];}
    if (a[i-1][j]>=a[i][j-1])
       i--;
    else
       j--;    
    }
    for (i=nr;i>=1;i--)
        g<<rez[i]<<" ";
    g.close();
}
