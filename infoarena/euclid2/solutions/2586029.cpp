#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("lgput.in");
    ofstream fout("lgput.out");
    long long N;
    long long P;
    fin>>N;
    fin>>P;
    long long inmultire = 1;
    for(int i=0;i<(P/2);i++){
      inmultire = inmultire*N;
      //inmultire = inmultire%1999999973;

    }
    //cout<<inmultire;
    if(P%2==1){
        fout<<(inmultire*inmultire*N)% 1999999973;
    }
    else{
        fout<<(inmultire*inmultire)% 1999999973;
    }

}
