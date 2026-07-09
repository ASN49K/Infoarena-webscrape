#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b, c = 1;
int main()
{
    fin>>T;
    for(int i = 0; i<T; i++){
        if(a<b){
            c = a;
            a = b;
            b = c;
        }
        fin>>a>>b;
        while(b!=0){
            c = a%b;
            a = b;
            b = c;
        }
        fout<<a<<'\n';
    }
    return 0;
}
