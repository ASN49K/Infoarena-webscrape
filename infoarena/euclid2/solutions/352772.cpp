#include<fstream.h>
#include<iostream.h>

int main()
{
int i,a,b,n,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 while(b){
			 r=a%b;
			 a=b;
			 b=r;
			 }
		 fout<<a<<endl;
		 }
fin.close();
fout.close();
return 0;
}
