#include <iostream>

using namespace std;
ifstream in( "euclid2.in");
ofstream out("euclid2.out");
int e( int a, int b)
{
    int r;
   while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n, a, b;
    in>>n;
    while( n)
    {
        in>>a>>b;
        out<<e( a,b )<<'\n';
        n--;
    }
    return 0;
}
