#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r, T;
    fin >> T;
    for(int i = 0;i<T;i++){
        fin >> a; fin >> b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << endl;
    }
    return 0;
}
