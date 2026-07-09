#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid.out");
int r;
int a , b,n,i;
int main()
{   fin >>n;
    for (i=1;i<=n;i++)
    {
    fin >> a >> b ;

    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout << a << endl;
    }
    return 0;
}
