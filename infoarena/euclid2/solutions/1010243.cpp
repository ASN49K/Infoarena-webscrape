#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long a, b, T;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else cmmdc(b, a%b);
}

int main()
{
    fin>>T;
    for (int i=0; i<T; i++)
    {
        fin>>a;
        fin>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
