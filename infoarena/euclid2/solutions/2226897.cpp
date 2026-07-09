#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int N, A, B;

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    int i;

    f >> N;

    for(i = 0; i < N; i++)
    {
        f >> A >> B;
        g << cmmdc(A, B) << endl;
    }

    return 0;
}
