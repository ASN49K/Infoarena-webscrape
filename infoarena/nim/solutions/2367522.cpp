#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;

void nim(){
    fin>>t;
    for(int i=1; i<=t; i++){
        int nr;
        fin>>nr;
        int sum=0;
        for(int j=1; j<=nr; j++){
            int a;
            fin>>a;
            sum^=a;
        }
        if(sum) fout<<"DA\n";
        else fout<<"NU\n";
    }
}

int main()
{
    nim();
}
