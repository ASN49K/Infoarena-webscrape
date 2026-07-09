using namespace std;
#include<fstream>
ifstream eu("nim.in");
ofstream tu("nim.out");
int main()
{
	int T,N,S,val,i;
	eu>>T;
	while(T--)
	{
		eu>>N;
		S=0;
		for(i=1;i<=N;i++)
		{
			eu>>val;
			S=S^val;
		}
		if(S==0)
			tu<<"NU"<<"\n";
		else
			tu<<"DA"<<"\n";
	}
	return 0;
}
