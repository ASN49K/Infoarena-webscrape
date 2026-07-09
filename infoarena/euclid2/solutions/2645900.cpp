#include <fstream>
using namespace std;
int main()
{
    int T, a, b, i, r;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> T;
    int v[100000], j = 0;
    for (i = T; i > 0; i--)
    {
        in >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
            v[j] = a;
            j++;
    }
    for (j = 0; j < T; j++)
        out << v[j] << endl;
}