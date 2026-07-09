#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M, N, A[256], B[256], lcs[101][101], k, h, i;
void rezolva(){
for(k=1;k<=M;k++)
   for(h=1;h<=N;h++)
      if(A[k]==B[h])
         lcs[k][h]=1+lcs[k-1][h-1];
      else if(lcs[k-1][h]>lcs[k][h-1])
                lcs[k][h]=lcs[k-1][h];
            else lcs[k][h]=lcs[k][h-1];}
void afiseaza_sol_max(int k, int h){
   if(lcs[k][h])
      if(A[k]==B[h]){
        afiseaza_sol_max(k-1,h-1);
            g<<A[k]<<" ";}
else {
if(lcs[k][h]==lcs[k-1][h])
afiseaza_sol_max(k-1,h);
else if(lcs[k][h]==lcs[k][h-1])
   afiseaza_sol_max(k,h-1);}
}
int main()
{f>>M>>N;
for(i=1;i<=M;i++)
 f>>A[i];
for(i=1;i<=N;i++)
 f>>B[i];
rezolva();
afiseaza_sol_max(N,M);
f.close();
g.close();
return 0;
}
