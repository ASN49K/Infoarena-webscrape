#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int lines;
    int a,b;
    in>>lines;
    for(int i=0;i<lines;++i)
    {
        in>>a>>b;
        out<<__gcd(a,b)<<endl;
    }
    return 0;
}
