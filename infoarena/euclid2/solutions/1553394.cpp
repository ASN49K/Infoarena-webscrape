#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int lines;
    in>>lines;
    while(lines--)
    {
        int a,b;
        in>>a>>b;
        out<<__gcd(a,b);
    }
    return 0;
}
