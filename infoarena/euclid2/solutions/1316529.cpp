#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gasesteCMMDC(int a,int b){
    while(a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

void afiseazaCMMDC(int a,int b){
    fout<<gasesteCMMDC(a,b)<<endl;
}
int main()
{
   int a,b,t;

   fin>>t;

   for(int i = 1; i <= t; i++){
        fin>>a>>b;
        afiseazaCMMDC(a,b);
   }
    return 0;
}
