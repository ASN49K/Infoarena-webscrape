#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T, n, m;
    fin>>T;
    for(int i=0; i<T; i++)
    {
        fin>>m>>n;
        while(m != 0)
        {
            int r = n % m;
            n = m;
            m = r;
        }
        fout<<n<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
