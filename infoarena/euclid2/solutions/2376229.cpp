#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int x;
    int a,b,rest;
    fin>>x;
    for(int i=0;i<=x;i++){
        fin >> a >> b;
        while(b!=0){
            rest=a%b;
            a=b;
            b=rest;
        }
        fout << a << "/n";
    }
    fin.close();
    fout.close();
    return 0;

}
