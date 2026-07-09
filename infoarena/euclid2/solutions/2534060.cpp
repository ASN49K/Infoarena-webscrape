#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid.out");

int n,a,b,c;

int main()
{
    fin >> n;
    for(;n;--n)
    {
        fin >> a >> b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout << a << '\n';
    }
    return 0;
}
