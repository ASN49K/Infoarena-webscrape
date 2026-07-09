#include <fstream>
#define in "euclid2.in"
#define out "euclid2.out"

using namespace std;

ifstream fin(in);
ofstream fout(out);

inline int cmmdc(int a,int b)
{
    if(b == 0) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int n,a,b;
    fin>>n;
    while(n--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }

    fin.close(); fout.close();
    return 0;
}
