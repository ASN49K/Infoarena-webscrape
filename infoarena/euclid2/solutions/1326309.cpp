#include <fstream>
using namespace std;
fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);

int euclid(int n, int m)
{
    if(m==0) return n;
    euclid(m, n%m);
}
int main()
{
    int n;
    fin>>n;
    for(int i=1; i<=n; i++){
        int x, y;
        fin>>x>>y;
        fout<<euclid(x, y)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
