#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int t;
    fin >> t;
    while (t--)
    {
        int a,b,r=0;
        fin >> a >> b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << '\n';
    }
}
