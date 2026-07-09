#include <iostream>
#include <fstream>

using namespace std;

int n;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    out << a << "\n";
}

int main()
{
    in >> n;
    int a, b;
    for(int i = 1; i<=n;++i){
        in >> a >> b;
        cmmdc(a, b);
    }
}
