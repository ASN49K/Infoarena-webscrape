#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,i,n,r;
int main()
{   fin>>n;
    for(i=1;i<=n;i++)
    {   fin>>a>>b;
        while(b)
        {   r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
	fout.close();
	return 0;
}
