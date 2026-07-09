#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream gi("cmlsc.out");
int a[1050];
int b[1050];
int lb,la;
int mat[1000][1000];
int maxim(int a,int b,int c,int d)
{
  if(a>=b && a>=c && a>=d)
        return a;
  else if(b>=a && b>=c && b>=d)
    return b;
  else if(c>=a && c>=b && c>=d)
    return c;
  else
    return d;
}
void debug()
{
    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<" \n";
    }
}
void citire()
{
   f>>la>>lb;
   for(int i=0;i<la;i++)
   {
       f>>a[i];
   }
   for(int i=0;i<lb;i++)
   {
       f>>b[i];
   }
   for(int i=0;i<la;i++)
   {
       for(int j=0;j<lb;j++)
       {
           if(a[i]==b[j])
           {
               mat[i][j]=maxim(mat[i][j],mat[i-1][j],mat[i][j-1],mat[i-1][j-1])+1;
           }
           else
           mat[i][j]=maxim(mat[i][j],mat[i-1][j],mat[i][j-1],mat[i-1][j-1]);

      }
   }
   //debug();
   int c[1000],k=0;
  gi<<mat[la-1][lb-1]<<"\n";
    for(int i=la-1;i>=0;i--)
    {
        if(mat[i][lb-1]>mat[i-1][lb-1])
            {c[k]=a[i];
            k++;
            }
    }
    for(int i=k-1;i>=0;i--)
    {
        gi<<c[i]<<" ";
    }

}

int main()
{
    citire();
    return 0;
}
