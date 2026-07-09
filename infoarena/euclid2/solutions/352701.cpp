#include<fstream.h>
int main()
{
long i,a,b,n,t,aux,j,d;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 if(a>b){
			aux=a;
			a=b;
			b=aux;
			}
		 for(j=1;j<=a;j++)if(a%j==0 && b%j==0)d=j;
		 fout<<d<<endl;
		 }
fin.close();
fout.close();
return 0;
}