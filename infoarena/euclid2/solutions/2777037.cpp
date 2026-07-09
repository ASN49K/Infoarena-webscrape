#include <fstream>

using namespace std;

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

uint16_t a, b, i, n;

int main()
{
    fin >> n;
    while (n != 0){
        fin >> a;
        fin >> b;

        for(i = min(a,b); i >= 2; i--){
            if((a % i == 0) && (b % i == 0)){
                break;
            }
        }
        fout << i << endl;
        n--;
    }

    return 0;
}
