#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x, y, T;

int main(){
    fin >> T;
    for(int i=0; i<T; i++){
        fin >> x >> y;
        if(y>x)
            swap(x,y);
        while(y!=0){
            int r=x%y;
            x=y;
            y=r;
        }
        fout << x << "\n";
    }
}
