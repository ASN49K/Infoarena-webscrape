#include <iostream>
#include <fstream>

using namespace std;

int t,a,b,d;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("euclid2.in");
    fout.open("euclid2.out");

    fin >> t;

    for (int i=0; i<t; i++){
        fin >> a;
        fin >> b;
        while (b){
            int r=a%b;
            a=b;
            b=r;
        }
        fout << a << endl;
    }
    return 0;
}
