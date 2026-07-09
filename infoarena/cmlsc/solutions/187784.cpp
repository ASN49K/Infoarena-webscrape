#include<fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int d[1024][1024],s[1024],p,i,k;
int max(int d[1024][1024])
{ 
    if(d[i-1][k]>d[i][k-1])
                                          return d[i-1][k];
                                          else
                                          return d[i][k-1];
                                          }
int main ()
{
    
    int n,m;
    fin>>n>>m;
    int a[n],b[m];
    for(i=1;i<=n;i++)
    fin>>a[i];
    for(i=1;i<=m;i++)
    fin>>b[i];
    for(i=1;i<=n;i++)
    {
                     for(k=1;k<=m;k++)
                     {
                                      if(a[i]==b[k])
                                      d[i][k]=1+d[i-1][k-1];
                                      else
                                      d[i][k]=max(d);    
                                          }}
     for (i=n,k=m;i;)   
        if (a[i]==b[k])   
            {s[++p]=a[i];
            --i;
            --k;
            }  
        else if (d[i-1][k]<d[i][k-1])   
            --k;   
        else  
            --i;  
            fout<<p<<"\n";
          for(i=p;i>=1;i--)
          fout<<s[i]<<" ";
          fout<<"\n";
        //  for(i=1;i<=n;i++)
        // { for(k=1;k<=m;k++)
        // fout<<d[i][k]<<" ";
        // fout<<"\n";
         //}
          return 0;
}
