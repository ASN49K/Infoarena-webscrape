#include<fstream>
using namespace std;
int x[100],y[100],n,m,i;
int lcs[100][100],max;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
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
       g<<x[k]<<' ';}
     else
        {if (lcs[k][h]==lcs[k-1][h])
         afiseaza_solutie_max(k-1,h);
         else if (lcs[k][h]==lcs[k][h-1])
         afiseaza_solutie_max(k,h-1);
     }
}

int main(){

f>>n>>m;
for(int i=1;i<=n;i++) f>>x[i];
for(i=1;i<=m;i++) f>>y[i];
rezolva();
g<<lcs[n][m]<<'\n';
afiseaza_solutie_max(n,m);
return 0;
}
