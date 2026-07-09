#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;

    for(int i = 1; i <= n; i++){
        int a, b, r;
        fin >> a >> b;
        while(b != 0){
            r = a%b;
            a = b;
            b = r;
        }

        fout << a << "\n";

    }

    return 0;
}
