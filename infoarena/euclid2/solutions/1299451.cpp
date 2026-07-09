#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GGT(int A, int B)
{
    if(B)
        return GGT(B,A%B);
    return A;
}

int main()
{
    int T;
    fin>>T;
    while(T--)
    {
        int A,B;
        fin>>A>>B;
        fout<<GGT(A,B)<<"\n";
    }
    return 0;
}
