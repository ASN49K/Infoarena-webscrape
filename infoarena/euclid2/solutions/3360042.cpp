#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, r;

int main()
{
    fin>>a>>b;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a;
    fin.close();
    fout.close();
    return 0;
}
