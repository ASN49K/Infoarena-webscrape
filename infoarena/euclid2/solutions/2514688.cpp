#include <fstream>

using namespace std;

struct euclid {int a, b;} v[100000];

int cmmdc(int a, int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T;
    fin >> T;

    for(int i = 0; i < T; i++)
    {
        fin >> v[i].a >> v[i].b;
        fout << cmmdc(v[i].a, v[i].b) << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
