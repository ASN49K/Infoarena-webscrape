#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    int n;
    fin >> n;

    for(int i = 1; i <= n; i++){
        int a, b;
        fin >> a >> b;

        fout << cmmdc(a,b) << "\n";
    }

    return 0;
}
