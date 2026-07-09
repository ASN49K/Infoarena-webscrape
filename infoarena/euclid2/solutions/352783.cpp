#include<fstream.h>

int cmmdc(int a,int b)
{
int r;
while(b){
	r=a%b;
	a=b;
	b=r;
	}
return a;
}

int main()
{
int i,a,b,n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++){
		 fin>>a>>b;
		 fout<<cmmdc(a,b)<<"\n";
		 }
fin.close();
fout.close();
return 0;
}
