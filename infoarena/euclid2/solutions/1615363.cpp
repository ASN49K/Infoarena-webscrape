#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b,t;

int main()
{
    fin>>T;
    for(int i=1;i<=T;i++){
        fin>>a>>b;
        while(b){
            t=a%b;
            a=b;
            b=t;
        }

    fout<<a<<'\n';
    }
    return 0;
}
