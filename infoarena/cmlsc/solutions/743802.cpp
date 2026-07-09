# include <iostream>
using namespace std;
int c[100][100],a[100],b[100],i,j,m,n;
int max(int x, int y)
{if(x>y) return x; 
return y;}

void afisez(int i, int j)
{
     if(i>=1 && j>=1)
    if(c[i][j]==max(c[i-1][j],c[i][j-1])+1)
           {afisez(i-1,j-1);
           cout<<a[i]<<" ";
           }
 else 
       if(c[i-1][j]>c[i][j-1])
                afisez(i-1,j);
else 
      afisez(i,j-1);}

int main()
{
    cout<<"n-"; cin>>n;
    for(i=1;i<=n;i++)
    {cout<<"a["<<i<<"]="; cin>>a[i];}
    
    cout<<"m-"; cin>>m;
    for(i=1;i<=m;i++)
    {cout<<"b["<<j<<"]="; cin>>b[i];}
    
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {if(a[i]==b[j])
    c[i][j]=c[i-1][j-1]+1;
    else
     c[i][j]=max(c[i-1][j],c[i][j-1]);
     
cout<<c[n][m]<<" " ;}

afisez(n,m);

system("pause");
return 0;}
