#include <fstream>


using std::ifstream;
using std::endl;
using std::ofstream;

int cmmdc(int a, int b)
{
    int r;
    do
    {
      r = a % b;
      a = b;
      b = r;
    } while (r != 0);
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int N;
    in >> N;
    int a,b;
    while (N)
    {
        in >> a >> b;
        out << cmmdc(a,b) << endl;
        N--;
    }
    in.close();
    out.close();
    return 0;
}
