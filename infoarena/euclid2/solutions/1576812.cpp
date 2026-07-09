#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
    fin.close();
    fout.close();
    return 0;
}
