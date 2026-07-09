#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int A, int B)
{
    while(B)
    {
        int R = A % B;
        A = B;
        B = R;
    }

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
        fout<<GCD(A,B)<<"\n";
    }
    return 0;
}
