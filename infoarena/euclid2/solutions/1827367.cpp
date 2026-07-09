#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long T,a,b,r;
int main()
{
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;a=b;b=r;
        }
        fout<<a<<endl;
    }
    return 0;
}
