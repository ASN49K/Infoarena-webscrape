#include<fstream>
#include<sstream>
#include<string>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,t;
string s;
istringstream i;
int main()
{
	getline(f,l),i(l),i>>t;
	while(t--)
	{
		getline(f,l);
		i(l);
		i>>a>>b;
        for(;r=a%b;a=b,b=r);
        g<<b<<'\n';
    }
}
