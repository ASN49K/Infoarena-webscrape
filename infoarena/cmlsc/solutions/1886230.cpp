#include <iostream>
#include <fstream>
using namespace std;
int a[1025],b[1025],c[1025][1025],n,m,st[1025];
void citire()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(int i=1; i<=n; i++)
    {
        f>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        f>>b[i];
    }
}
int maxim(int x,int y)
{
    if(x>y)
        return x;
    else return y;
}
void program()
{

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
            {
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
            }

}
void afisare()
{
    ofstream g("cmlsc.out");
    int max=c[n][m]+1,ii=0,li=n,co=m;
    g<<c[n][m]<<endl;
   while(li>0 && co>0 && max>0)
   {
       if(a[li]==b[co])
       {
           st[ii++]=a[li];
           li--;
           co--;
       }
       else
        if(c[li-1][co]>c[li][co-1])
        li--;
       else co--;
   }
        for(int i=ii-1;i>=0;i--)
            g<<st[i]<<" ";
}
int main()
{
    citire();
    program();
    afisare();
    return 0;
}
