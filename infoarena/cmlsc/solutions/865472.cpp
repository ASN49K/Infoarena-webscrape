#include <iostream>
#include <fstream>

using namespace std;

short x[1024],y[1024],sol[1024],n,m;
short lcs[1024][1024],max;

void rezolva(){
for(int k=1;k<=n;k++)
   for(int h=1;h<=m;h++)
      if(x[k]==y[h]) lcs[k][h]=1+lcs[k-1][h-1];
      else
      if (lcs[k-1][h]>lcs[k][h-1]) lcs[k][h]=lcs[k-1][h];
      else lcs[k][h]=lcs[k][h-1];
}
short c = 0;
short contor = 0;
void afiseaza(int k,int h){
if(lcs[k][h])
     if(x[k]==y[h])
       {
           afiseaza(k-1,h-1);
            sol[contor]=x[k];
            contor++;
            c++;
       }
     else
     {
        if (lcs[k][h]==lcs[k-1][h])
         afiseaza(k-1,h);
         else if (lcs[k][h]==lcs[k][h-1])
         afiseaza(k,h-1);
     }
}

int main(){
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(int i=1;i<=n;i++) f>>x[i];
for(int i=1;i<=m;i++) f>>y[i];
rezolva();
afiseaza(n,m);
g<<c<<"\n";
for(int i=0;i<contor;i++)
{
    g<<sol[i]<<" ";
}
return 0;
}
