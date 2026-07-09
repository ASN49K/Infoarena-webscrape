#include<fstream.h>
#include<iostream.h>
int main()
{
long i,a,b,n,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 while(a && b){
			      if(a>b)a=a%b;
			      else b=b%a;
			      }
		 if(!b)fout<<a<<endl;
		 else fout<<b<<endl;
		 }
fin.close();
fout.close();
return 0;
}
