#include <fstream>

using namespace std;
int main()
{
    ifstream fin (" euclid2.in");
    ofstream fout (" euclid2.out");
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
        fout << cmmmc <<  "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
