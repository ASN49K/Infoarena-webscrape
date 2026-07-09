#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
        int a , b, T, rest;
        fin >> T;
        for(int i = 1; i<=T ; i++)
        {
            fin >> a >> b;
        while(b)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
            fout << a << endl;
        }
        return 0;
}
