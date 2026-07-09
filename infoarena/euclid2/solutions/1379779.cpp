#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b;
int euclid(int a, int b){
    if (a==b) return a;
        else
            return euclid(b, a%b);
}

int main()
{ int t;
    fin>>t;
    for (int i=1; i<=t; i++){
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
        }
    return 0;
}
