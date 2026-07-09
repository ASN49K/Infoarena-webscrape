#include<fstream>

using namespace std;

FILE*in;
ofstream out("euclid2.out");

unsigned int T;
unsigned long A, B;

unsigned long euclid(unsigned long a, unsigned long b)
{
    if (!b)
        return a;
    else
        return euclid(b, a%b);
}

int main()
{
    in=fopen("euclid2.in", "r");
    fscanf(in, "%d", &T);

    for (int i=1; i<=T; i++)
    {
        fscanf(in, "%d%d", &A, &B);
        out<<euclid(A, B)<<'\n';
    }

    return 0;
}
