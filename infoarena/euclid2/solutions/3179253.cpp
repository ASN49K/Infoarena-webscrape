#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
long long a,b;
int main()
{   fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {   long long r=a;
            a=b;
            b=r%b;
        }
        fout<<a<<'\n';
    }
    return 0;
}
