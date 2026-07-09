#include<fstream>
using namespace std;

int n,x,y;

inline int GCD(int a,int b)
{
    if (!b) return a;
    else return GCD(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<GCD(x,y)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
