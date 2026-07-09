#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int a, b,nr;
    fin>>nr;
        while(nr!=0){
        fin >> a;
        fin >> b;
        while(a!=b){
            if(a>b)
                a=a-b;
            if(b>a)
                b=b-a;
        }
        nr--;
        fout<<a<<"\n";
    }
}
