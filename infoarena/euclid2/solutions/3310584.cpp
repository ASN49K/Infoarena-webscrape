#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, x, y, r;
    fin>>n;
    while(n--){
        fin>>x>>y;
        if(x<y) swap(x,y);
        do{
            r = x%y;
            x=y;
            y=r;
        }while(y>0);
        fout<<x<<"\n";
    }
}
