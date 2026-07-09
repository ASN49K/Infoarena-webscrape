#include <iostream>
using namespace std;
int x[100],y[100],n,m,i,nr;
int lcs[100][100],maxim;

void rezolva()
{ for(int k=1;k<=n;k++)
for(int h=1;h<=m;h++)
if(x[k]==y[h]) lcs[k][h]=1+lcs[k-1][h-1];
 else if (lcs[k-1][h]>lcs[k][h-1]) lcs[k][h]=lcs[k-1][h];
 else lcs[k][h]=lcs[k][h-1]; }

void afiseaza_solutie_max(int k,int h)
{ if(lcs[k][h])
if(x[k]==y[h])
{afiseaza_solutie_max(k-1,h-1);
cout<<x[k]<<" ";
nr++;}
else
{if (lcs[k][h]==lcs[k-1][h])
afiseaza_solutie_max(k-1,h);
else if (lcs[k][h]==lcs[k][h-1])
afiseaza_solutie_max(k,h-1);      } }
int main()
{
 cin>>n;
cin>>m;
for(i=1;i<=n;i++)
cin>>x[i];
for(i=1;i<=m;i++)
cin>>y[i];
cout<<nr<<endl;
rezolva(); afiseaza_solutie_max(n,m);
return 0; }
