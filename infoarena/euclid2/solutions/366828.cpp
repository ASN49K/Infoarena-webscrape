#include <fstream>
using namespace std;
int T, A, B;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a % b);
}

int main(void)
{
    ifstream cit("euclid2.in");
    ofstream scr("euclid2.out");


    for (; T; --T)
    {
        cit>>A,B;
        scr<<euclid(A, B);
    }        

    return 0;
}

