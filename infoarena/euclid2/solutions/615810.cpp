#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if (a%b==0)
        return b;
    else
        return euclid (b, a%b);
}

int main()
{
    ifstream in("euclid2.in");
    int n;
    in >> n;
    ofstream out("euclid2.out");
    for (int t1, t2, i = 0; i < n; ++i)
    {
        in >> t1 >> t2;
        out << euclid (t1, t2) << endl;
    }
    in.close();
    out.close();
    return 0;
}
