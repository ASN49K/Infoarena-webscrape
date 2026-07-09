#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

struct euclid {int a, b;} v[100000];

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
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
