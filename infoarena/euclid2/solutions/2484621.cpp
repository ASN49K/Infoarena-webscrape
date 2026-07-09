#include <fstream>
using namespace std;
int n;
long long a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;

        while(b)
        {
            int  r=a%b;
            a=b;
            b=r;
        }
fout<<a<<"\n";
    }




}
