#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int ma(int A,int B)
{
    if(A>B)
    return A;
    return B;
}
int a[1025],b[1025],i,nr,t,v[1025],j,M,x,y,n,m[1025][1025],maxim;
int main ()
{
    f>>n>>M;
    for(i=1;i<=n;++i)
    f>>a[i];
    for(i=1;i<=M;++i)
    f>>b[i];
    for(i=1;i<=n;++i)
    for(j=1;j<=M;++j)
    {
    if(a[i]==b[j])
    m[i][j]=m[i-1][j-1]+1;
    else
    m[i][j]=ma(m[i-1][j],m[i][j-1]);
    if(m[i][j]>maxim&&a[i]==b[j])
    {
        maxim=m[i][j];
        x=i;
        y=j;
    }
    }
    while(m[x][y])
    {
        if(a[x]==b[y])
        v[++t]=a[x];
        if(a[x]==b[y])
        {
            --x; --y;
        }
        else
        {
            if(m[x-1][y]>m[y-1][x]&&(x-1))
                --x;
            else
            --y;
        }
    }
    g<<t<<"\n";
    for(i=t;i>=1;--i)
    g<<v[i]<<" ";
    return 0;
}
