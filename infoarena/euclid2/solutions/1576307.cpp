#include <fstream>

using namespace std;
int main()
{
    ifstream fin ("suma.in");
    ofstream fout ("suma.out");
    int t, a, r , b, cmmmc, i, p;

    fin >> t;
    for (i=1; i<=t; i++)
    {
        fin >> a>> b;
        p=a*b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cmmmc=p/a;
        fout << cmmmc;
    }
    fin.close();
    fout.close();
    return 0;
}
