#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc(int a, int b)
{
    while(a != b)
        if(a > b)
            a = a - b;
        else
            b = b - a;
    return a;
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
