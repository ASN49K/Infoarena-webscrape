#include <fstream>


using std::ifstream;
using std::endl;
using std::ofstream;
using std::max; using std::min;

int cmmdc(int a, int b)
{
    if ( b == 0 ) return a;
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
    int a,b;
    for (int i = 0; i < N; ++i)
    {
        in >> a >> b;
        out << cmmdc(a,b) << endl;
    }
    in.close();
    out.close();
    return 0;
}
