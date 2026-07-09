using namespace std;
#include<fstream>
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
int T,N,S;
fin>>T;
while(T--)
{
fin>>N;S=0;
for(int i=1;i<=N;i++)
	{
	int X;
	fin>>X;
	S^=X;
	}
if(S)
	fout<<"DA\n";
else
	fout<<"NU\n";
}
return 0;
}