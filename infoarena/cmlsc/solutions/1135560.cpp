#include<fstream>
#include <iostream>
using namespace std;
int x[100],y[100],n,i,j,m;
int lcs[100][100],max;
int sol[1000],big;

void rezolva(){
for(int k=1;k<=n;k++)
   for(int h=1;h<=m;h++)
      if(x[k]==y[h]) lcs[k][h]=1+lcs[k-1][h-1];
      else
      if (lcs[k-1][h]>lcs[k][h-1]) lcs[k][h]=lcs[k-1][h];
      else lcs[k][h]=lcs[k][h-1];
}

void afiseaza_solutie_max(int k,int h){
if(lcs[k][h])
     if(x[k]==y[h])
       {afiseaza_solutie_max(k-1,h-1);
       sol[++big]=x[k];}
     else
        {if (lcs[k][h]==lcs[k-1][h])
         afiseaza_solutie_max(k-1,h);
         else if (lcs[k][h]==lcs[k][h-1])
         afiseaza_solutie_max(k,h-1);
     }
}

int main(){
ifstream f("cmlsc.in",ios::in);
ofstream g("cmlsc.out");
f>>n>>m;
for(int i=1;i<=n;i++) f>>x[i];
for(i=1;i<=m;i++) f>>y[i];
f.close();     // citirea !
rezolva();
afiseaza_solutie_max(n,m);
g<<big<<endl;
for(i=1;i<=big;i++) g<< sol[i] << " " ;
g.close();return 0;
}
