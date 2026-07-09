#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n, t, x;
int main()
{
    fin>>t;
    for(int i=0;i<t;++i)
    {
        fin>>n;
        int sumx=0;
        for(int j=0;j<n;++j)
        {
            fin>>x;
            sumx=sumx ^ x;
        }
        if(sumx==0)
            fout<<"NU\n";
        else fout<<"DA\n";
    }
    return 0;
}
