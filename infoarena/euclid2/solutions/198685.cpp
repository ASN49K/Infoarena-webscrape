#include <fstream>
using namespace std;
int cmmdc(int a,int b)
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
    int a,b;
    for (i=0;i<n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
