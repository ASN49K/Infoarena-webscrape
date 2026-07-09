#include<fstream>
using namespace std;
int main()
{int t,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
int c[t];
for(i=1;i<=(t+t);i++)
	fin>>c[i];
for(i=1;i<(t+t);i=i+2)
	while(c[i]!=c[i+1])
		if(c[i]>c[i+1])
			c[i]-=c[i+1];
		else
			c[i+1]-=c[i];
for(i=1;i<t+t;i=i+2)
	fout<<a[i]
return 0;
}

