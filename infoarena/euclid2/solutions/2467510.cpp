#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T;
    fin>>T;
    int n , m;
    for(int i=1;i<=T;i++){
        fin >> n >> m;
        while(m != 0)
        {
            int r = n % m;
            n = m;
            m = r;
        }
        fout << n <<"\n";
    }
    return 0;
}
