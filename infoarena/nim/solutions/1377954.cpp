#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,p1,k,castigator,p2;
int main()
{
    fin>>k;
    while(k)
    {
        fin>>p1;
        castigator=0;
        k--;
        while(p1)
        {
            fin>>p2;
            castigator=castigator^p2;
            p1--;
        }
        if(castigator) fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
}
