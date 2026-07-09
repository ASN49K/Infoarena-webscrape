#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
   if(b == 0)
        return a;
   return cmmdc(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t;
    in >> t;
    int a, b;
    for(int i = 1; i <= t; ++i)
    {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }

    in.close();
    out.close();
    return 0;
}
