#include<fstream>
using namespace std;
ofstream out("cmlsc.out");
ifstream in("cmlsc.in");
int x[1029],y[1029],n,m;
int mat[1029][1029];


void rezolva(){
for(int k=1;k<=n;k++)
   for(int h=1;h<=m;h++)
      if(x[k]==y[h]) mat[k][h]=1+mat[k-1][h-1];
      else
      if (mat[k-1][h]>mat[k][h-1]) mat[k][h]=mat[k-1][h];
      else mat[k][h]=mat[k][h-1];
}
      
void afisare(int k,int h){

	if(mat[k][h])
     if(x[k]==y[h])
       {afisare(k-1,h-1);
       out<<x[k]<<' ';}
     else
        {if (mat[k][h]==mat[k-1][h]) 
         afisare(k-1,h);
         else if (mat[k][h]==mat[k][h-1]) 
         afisare(k,h-1);
     }
}

int main(){
	int i,j,maxx=0;

in>>n>>m;
for(i=1;i<=n;i++) in>>x[i];
for(i=1;i<=m;i++) in>>y[i];
rezolva();
out<<mat[n][m]<<"\n";		
afisare(n,m);
return 0;
}