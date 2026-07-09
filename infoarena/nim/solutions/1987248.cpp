#include <fstream>

using namespace std;

int n, t;

int main()
{
    ifstream fin ("nim.in");
    ofstream fout ("nim.out");
    fin >> t;
    while(t--){
        int s = 0;
        fin >> n;
        while(n--){
            int x;
            fin >> x;
            s ^= x;
        }
        if(s > 0)
            fout << "DA\n";
        else fout << "NU\n";
    }
    fin.close();
    fout.close();
    return 0;
}
