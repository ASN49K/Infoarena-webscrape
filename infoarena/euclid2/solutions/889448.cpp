#include <iostream>
#include <fstream>

using namespace std;

int T, A, B;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a%b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>T;
    for(; T; --T)
    {
        in>>A>>B;
        out<<euclid(A,B)<<"\n";
    }
        return 0;
}
