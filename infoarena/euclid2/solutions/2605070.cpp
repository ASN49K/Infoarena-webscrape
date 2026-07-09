#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, r, T;

int main()
{
    fin>>T;
    for(int i=0;i<T;i++)
    {
        fin>>a>>b;
        while(a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<b<<'\n';
    }
    return 0;
}
