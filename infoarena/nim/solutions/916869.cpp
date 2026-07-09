#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int T,N,S,x;
int main()
{
    fin>>T;
    for(int i=0;i<T;++i)
    {
        fin>>N;
        S=0;
        for(int j=0;j<N;++j)
            {
            fin>>x;
            S^=x;
            }
        if(!S)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    fin.close();
    fout.close();
    return 0;
}