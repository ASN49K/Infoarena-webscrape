#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, c, d;
    fin >> a >> b;
    while(b)
    {
        d=a%b;
        c=b;
        b=d;
        a=c;
    }
    fout << a;

}
