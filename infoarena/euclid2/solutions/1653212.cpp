#include <iostream>
#include <fstream>
using namespace std;

fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
void euclid(int a,int b){
    int r = a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    fout << b << "\n";
}

int main()
{
    int n;
    fin >> n;
    FOR(i,1,n){
        int x,y;
        fin >> x >> y;
        euclid(x,y);
    }
    fin.close();
    fout.close();
    return 0;
}
