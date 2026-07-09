#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int T, i;
long int a, b;

int main()
{
    fin >> T;
    for (i=1; i<=T; i++)
    {
        fin >> a >> b;
        if (a==0 || b==0)
            a = 0;
        else
            while (b!=0)
        {
            int r = a%b;
            a=b;
            b=r;
        }
        fout << a << endl;
    }
     fin.close();
     fout.close();
    return 0;
}
