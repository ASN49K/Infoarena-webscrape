#include <fstream>

using namespace std;

int Euclid(int a, int b)
{
    if (!b) return a;
    return Euclid(b, a%b);    
}

int main()
{
    int T, i, x1, x2;
    
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    fin >> T;
    for (i = 1; i <= T; i++)    
    {
        fin >> x1 >> x2;
        if (x1 < x2) swap(x1, x2);
        fout << Euclid(x1, x2) << "\n";
    }
    
    fin.close();
    fout.close();
}
