using namespace std;
#include<fstream>
ifstream eu("nim.in");
ofstream tu("nim.out");
int T,N,S,X;
int main()
{
	eu>>T;
	while(T--)
	{
		eu>>N;
		S=0;
		for(int i=1;i<=N;i++)
		{
			eu>>X;
			S=S^X;
		}
		if(S==0)
			tu<<"NU"<<"\n";
		else
			tu<<"DA"<<"\n";
	}
	return 0;
}
