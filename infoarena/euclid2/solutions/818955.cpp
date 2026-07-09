#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int e(int a, int b)
{
    if (!b) return a;
    return e(b, a%b);
}

int main (void)
{
    int n,a,b;
    in>>n;
    for( ; n; --n)
    {
        in>>a>>b;
        out<<e(a,b)<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
