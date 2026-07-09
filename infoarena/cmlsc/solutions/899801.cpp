#include<fstream>
#include<algorithm>
using namespace std;
int a[1025],b[1025],i,nrel,x,n,m,y,ok,pos,k;

int binc(int pos)
{
    int mid,dr,st,ok;
    dr=m;
    st=1;
    pos=-1;
    ok=0;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(a[mid]==x) {ok=1; st=dr+1;}
        else if(a[mid]>x) dr=mid-1;
        else st=mid+1;
    }
    return ok;
}

int main ()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++)
    f>>a[i];
    sort(a,a+m+1);
    //g<<m<<" ";
    for(i=1;i<=n;i++)
    {
        f>>x;
        //g<<binc(pos)<<" ";
        if(binc(pos)==1)
        {
          nrel++;
          b[nrel]=x;
        }
    }
    g<<nrel<<"\n";
    for(i=1;i<=nrel;i++)
    g<<b[i]<<" ";

    return 0;
}
