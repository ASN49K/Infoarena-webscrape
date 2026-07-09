#include<fstream>
#include<iostream>
using namespace std;

int maxim(int a,int b,int c)
{
  if (a>=b && a>=c) return a;
  if (b>=a && b>=c) return b;
  if (c>=a && c>=b) return c;
  return 0;
}

int main(int nrarg, char* arg[])
{
  ifstream f;
  ofstream g;
  f.open("cmlsc.in",ios::in);
  g.open("cmlsc.out",ios::out);
  int na,nb;
  f>>na;
  f>>nb;
  int a[1024],b[1024];
  for(int i=0;i<na;i++) f>>a[i];
  for(int i=0;i<nb;i++) f>>b[i];

  int c[1024][1024];
  if (a[0]==b[0]) c[0][0]=1; else c[0][0]=0;
  for(int i=1;i<na;i++) if (a[i]==b[0]) c[i][0]=1; else c[i][0]=c[i-1][0];
  for(int i=1;i<nb;i++) if (a[0]==b[i]) c[0][i]=1; else c[0][i]=c[0][i-1];
  for(int i=1;i<na;i++)
     for(int j=1;j<nb;j++)
       { 
        if (a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=maxim(c[i-1][j],c[i-1][j-1],c[i][j-1]);
       }

  int max=c[na-1][nb-1];
  g<<max<<"\n";

  int s[1024];
  int i=na-1,j=nb-1;
  while (max>0)
   {
     if (a[i]==b[j])  {max--;s[max]=a[i];i--;j--;}
     else 
       {
         if (c[i][j]==c[i-1][j]) i--; 
           else if (c[i][j]==c[i][j-1]) j--;
               else {i--;j--;}
        }
   }
  for(i=0;i<c[na-1][nb-1];i++) g<<s[i]<<" ";
  f.close();
  g.close();
}
