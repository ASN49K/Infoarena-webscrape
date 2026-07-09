#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a%b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T, a, b;
    in>>T;
    for (int i=1;i<=T;i++)
    {
        in>>a>>b;
        out<<euclid(a, b)<<endl;
    }
    return 0;
}
