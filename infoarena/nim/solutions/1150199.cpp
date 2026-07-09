#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int T,N,S,x;

int main()
{
	f>>T;
	for(int ii=1;ii<=T;++ii)
	{
	    f>>N;
	    S=0;
	    for(int i=1;i<=N;++i)
            f>>x , S^=x;
        if(S>0)g<<"DA"<<'\n';
          else g<<"NU"<<'\n';
	}
    f.close();g.close();
	return 0;
}
