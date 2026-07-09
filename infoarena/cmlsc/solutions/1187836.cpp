#include<fstream>
using namespace std;
int x[1050],y[1050],n,m;
int lcs[1050][1050],max,pas[1050];
ofstream fout("cmlsc.out");
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
       pas[++pas[0]]=x[k];}
     else
        {if (lcs[k][h]==lcs[k-1][h])
         afiseaza_solutie_max(k-1,h);
         else if (lcs[k][h]==lcs[k][h-1])
         afiseaza_solutie_max(k,h-1);
     }
}

int main(){
ifstream f("cmlsc.in");
f>>n>>m;
int i;
for(int i=1;i<=n;i++) f>>x[i];
for(i=1;i<=m;i++) f>>y[i];
rezolva();
afiseaza_solutie_max(n,m);
fout<<pas[0]<<"\n";
for(i=1;i<=pas[0];i++) fout<<pas[i]<<" ";
}
