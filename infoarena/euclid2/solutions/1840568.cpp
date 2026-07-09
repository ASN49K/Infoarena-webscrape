#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int T,a,b,i,cd,r;
    fin>>T;
    for(i=1; i<=T; i++)
    {
        fin>>a;
        fin>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout << b << '\n' ;

    }

    fin.close();
    fout.close();
    return 0;
}
