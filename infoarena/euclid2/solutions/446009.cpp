#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef long long op_t;

op_t cmmdc(op_t a, op_t b)
{
    while (b)
    {
        op_t temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int n;
    op_t a, b;

    ifstream fisIn("euclid2.in");
    ofstream fisOut("euclid2.out");

    fisIn >> n;
    while (n--)
    {
        fisIn >> a >> b;
        fisOut << cmmdc(a,b) << '\n';
    }
}
