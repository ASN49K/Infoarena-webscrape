#include <fstream>
using namespace std;
int main()
{
    int t,a,b,r;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        t--;
        fout<<a<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
