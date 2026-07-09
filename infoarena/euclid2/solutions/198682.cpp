#include <fstream>
using namespace std;
long cmmdc(long a,long b)
{
     if (a==0) return b;
     else return cmmdc(b%a,a);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,i;
    fin>>n;
    long a,b;
    for (i=0;i<n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
fin.close();
fout.close();
}
