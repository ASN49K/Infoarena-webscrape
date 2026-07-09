#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T;

int GCD(int A,int B)
{
    if(!B)
        return A;
    return GCD(B,A%B);
}

int main()
{
    fin>>T;
    while(T--)
    {
        int A,B;
        fin>>A>>B;
        fout<<GCD(A,B)<<"\n";
    }
    return 0;
}
