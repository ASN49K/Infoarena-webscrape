#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,A,B;

int CMMDC(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin>>T;

    while(T--)
    {
        fin>>A>>B;
        fout<<CMMDC(A,B)<<"\n";
    }

    return 0;
}
