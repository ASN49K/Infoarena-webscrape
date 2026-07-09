#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned long long a[100000],b[100000],cmmdc[100000],j;
int T,i;
int main(){
	fin>>T;
	for(i=0;i<T;i++)
	{
	fin>>a[i]>>b[i];
	fout<<endl;
}
for(i=0;i<T;i++)
if(a[i]<b[i])
{
for(j=2;j<a[j];j++)
if(a[i]%j==0&&b[i]%j==0)
  cmmdc[i]=j;
}
else
{
for(j=2;j<b[j];j++)
if(a[i]%j==0&&b[i]%j==0)
  cmmdc[i]=j;
}
  for(i=0;i<T;i++)
  fout<<cmmdc[i]<<endl;	
	return 0;
}
