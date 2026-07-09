#include<fstream.h>
#include<iostream.h>
int main()
{
long i,a,b,n,aux;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 while(b!=a){
			    if(b>a)b=b-a;
			    if(a>b)a=a-b;
			    }
		 fout<<b<<endl;
		 }
fin.close();
fout.close();
return 0;
}
