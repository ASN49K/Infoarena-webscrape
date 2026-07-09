#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b,r;
int main()
{
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
        while(b)
        {
           r=a;
           a=b;
           b=b%r;
        }
        fout<<a<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
