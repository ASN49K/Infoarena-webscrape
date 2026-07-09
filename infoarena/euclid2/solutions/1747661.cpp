#include <fstream>
using namespace std;


ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{

    int t;
    int a, b;
    fin >> t;
    for(int i = 0; i < t;  i++){
        fin >> a >> b;
        while(a != b && a != 0 && b != 0)
        {
            if( a > b)
                a = a % b;
            else b = b % a;
        }
        if( a == 0)
            fout << b << "\n";
        else fout << a << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
