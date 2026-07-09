#include <fstream>


using std::ifstream;
using std::endl;
using std::ofstream;
using std::max; using std::min;

int cmmdc(int a, int b)
{
    if (a % b == 0) return b;
    if ( b == 0 ) return a;
    if ( b == 1 ) return 1;
    return cmmdc(b, a % b);
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("euclid2.in");
    out.open("euclid2.out");

    int N;
    in >> N;
    for (int i = 0; i < N; ++i)
    {
        int a,b;
        in >> a >> b;
        out << cmmdc(max(a,b), min(a,b)) << endl;
    }
    in.close();
    out.close();
    return 0;
}
