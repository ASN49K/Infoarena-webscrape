#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b, r, T;
    fin>>T;
    while (T){
        fin>>a>>b;
        while (b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
        T--;
    }
    return 0;
}
