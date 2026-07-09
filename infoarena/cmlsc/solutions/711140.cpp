#include<fstream>
using namespace std;
ofstream out("cmlsc.out");
ifstream in("cmlsc.in");
int x[1029],y[1029],n,m;
int lcs[1029][1029],max=0;

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
       out<<x[k]<<' ';}
     else
        {if (lcs[k][h]==lcs[k-1][h]) 
         afiseaza_solutie_max(k-1,h);
         else if (lcs[k][h]==lcs[k][h-1]) 
         afiseaza_solutie_max(k,h-1);
     }
}

int main(){
	int i;

in>>n>>m;
for(i=1;i<=n;i++) in>>x[i];
for(i=1;i<=m;i++) in>>y[i];
rezolva();
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	{
		if (mat[i][j]>max) max=mat[i][j];
	}
}	
out<<max<<"\n";		
afiseaza_solutie_max(n,m);
return 0;
}