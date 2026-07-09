#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b;

inline int cmmdc(int a,int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int n;
    fin>>n;
    while(n--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }

    fin.close(); fout.close();
    return 0;
}
