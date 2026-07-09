#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int t;
    fin>>t;
    while(t--){
        int s=0, x, n;
        fin>>n;
        while(n--){
            fin>>x;
            s ^= x;
        }
        if(s) fout<<"DA\n";
        else fout<<"NU\n";
    }
    return 0;
}
