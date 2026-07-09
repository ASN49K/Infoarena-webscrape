
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, v[100000],k;

int Euclid(int a, int b)
{
    int r;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;

    }
    return a;
}

int main()
{
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
       fin >> a >> b;
        v[k++] = Euclid(a, b);
    }
    for(int i = 0; i < k; i++)
      fout << v[i] << '\n';
    return 0;
}
