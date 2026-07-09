#include<fstream.h>
#include<iostream.h>

int main()
{
int i,a,b,n,aux;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 while(b){
			 if(a>b){
				aux=a;
				a=b;
				b=aux;
				}
			 b=b%a;
			 }
		 fout<<a<<endl;
		 }
fin.close();
fout.close();
return 0;
}
