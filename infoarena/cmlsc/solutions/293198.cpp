#include<fstream.h>
ifstream intrare("cmlsc.in");
ofstream iesire("cmlsc.out");
int a[1025],b[1025];
int n,m;
int sol[1025][1025];
void citeste()
{
     intrare>>n>>m;
     int i;
     for(i=1;i<=n;i++)intrare>>a[i];
     for(i=1;i<=m;i++)intrare>>b[i];
}
int minim(int i,int j)
{
    if(i>j)return j;
    return i;
}
int maxim(int i,int j)
{
    if(i>j)return i;
    return j;
}
int main()
{
    citeste();
    int i,j;
    for(i=1;i<=n;i++)
    {
     for(j=1;j<=m;j++)
     {
            if(a[i]==b[j])
            {
                     sol[i][j]=minim(sol[i-1][j],sol[i][j-1])+1;
            }
            else
            {
                 sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
            }
     }
    }
    iesire<<sol[n][m]<<"\n";
    i=n;j=m;int k=sol[n][m];
    while(k>0)
    {
              while(sol[i-1][j]>=k)
              {i--;}
              while(sol[i][j-1]>=k)
              {j--;}
              sol[0][k]=a[i];
              k--;
    }
    for(i=1;i<=sol[n][m];i++)
    iesire<<sol[0][i]<<" ";

    
    
    return 0;
}
    
