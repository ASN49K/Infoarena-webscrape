#include <iostream>
#include <fstream>
using namespace std;
int s[1027][1027];

int maxim ( int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int a[1025], b[1025],i,n,j,m;
    ifstream fin("cmlsc.in");
    ofstream fout ("cmlsc.out");
     fin>>n>>m;
     for(i=1;i<=n;i++)
        fin>>a[i];
     for(i=1;i<=m;i++)
        fin>>b[i];
      for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
      {if(a[i]==b[j])
             s[i][j]=s[i-1][j-1]+1;
        else
            s[i][j]=maxim(s[i-1][j],s[i][j-1]);
      }
      fout<<s[n][m]<<" ";

      i=n;
      j=m;
      int smax[500],k=0;
      while(i!=0&&j!=0)
      {
          if(a[i]!=b[j])
            {
               if(s[i-1][j]<s[i][j-1])
                  j--;
               else
                i--;

            }
          else
          {

              smax[++k]=a[i];
              i--;
              j--;

          }

      }
      fout<<"\n";
      for(i=k;i>0;i--)
        fout<<smax[i]<<" ";

    return 0;
}
