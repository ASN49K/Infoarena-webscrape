#include <fstream>

using namespace std;
ifstream in( "euclid2.in");
ofstream out("euclid2.out");
int e( int a, int b)
{
    while(a != b)
    {
        if( a>b)
            a=a-b;
        if( b>a)
            b=b-a;
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
