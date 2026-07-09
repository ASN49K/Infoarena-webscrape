#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n;

void euclid ();

int main()
{
    euclid();
    return 0;
}

void euclid ()
{
    int i, a, b, c;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        c=a%b;
        while (c)
        {
            a=b;
            b=c;
            c=a%b;
        }
        fout<<b<<'\n';
    }
    fout.close();
}
