#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b;
int T,i;
int euclid(int a, int b){
	int j,cmmdc;
if(a<b)
{
for(j=2;j<a;j++)
if(a%j==0&&b%j==0)
  cmmdc=j;
}
else
{
for(j=2;j<b;j++)
if(a%j==0&&b%j==0)
  cmmdc=j;
}
return cmmdc;
	
};
int main(){
	fin>>T;
	for(i=0;i<T;i++)
	{
	fin>>a>>b;
	fout<<euclid(a,b)<<endl;
}


	return 0;
}
