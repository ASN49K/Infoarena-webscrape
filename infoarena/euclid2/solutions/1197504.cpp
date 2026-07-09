#include <fstream>
using namespace std;

int main()
{
    int T, i;
    long long a, b, r;

    ifstream infile("euclid2.in");
    ofstream outfile("euclid2.out");

    infile >> T;
    for (i = 0; i < T; i++)
    {
        infile >> a >> b;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        outfile << a << endl;
    }
    outfile.close();
}
