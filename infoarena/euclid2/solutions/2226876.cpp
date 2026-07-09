#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc(int a, int b)
{
    if (!b) return a;
    if (a > b) return cmmdc(a-b, b);
    return cmmdc(a, b-a);
}

int main()
{
    int N, A, B;
    int i;

    f >> N;

    for(i = 0; i < N; i++)
    {
        f >> A >> B;
        g << cmmdc(A, B) << endl;
    }

    return 0;
}
