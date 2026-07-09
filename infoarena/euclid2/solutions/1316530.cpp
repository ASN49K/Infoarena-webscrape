#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gasesteCMMDC(int a,int b){
    int r;

    while(b){
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

void afiseazaCMMDC(int a,int b){
    fout<<gasesteCMMDC(a,b)<<endl;
}

int main()
{
    unsigned int a,b,t;

    fin>>t;

    for(int i = 1 ; i <= t ; i++){
        fin>>a>>b;

        afiseazaCMMDC(a,b);
    }

    return 0;
}
