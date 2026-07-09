#include <fstream>

using namespace std;

 ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

int main()
{

        int a , b, T, rest;
        fin >> T;
        for(int i = 1; i<=T ; i++)
        {
            fin >> a >> b;
        while(b != 0)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
            fout << a <<"\n";
        }
        return 0;
}
