#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int, int);

int main()
{
    int i, n, a, b;
    
    fin>> n;
    for (i=1; i<=n; i++)
    {
        fin>> a>> b;
        fout<< euclid(a, b)<<'\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a%b);
}