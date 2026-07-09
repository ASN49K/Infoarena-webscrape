#include <iostream>
#include <fstream>

std :: ifstream fin("euclid2.in");
std :: ofstream fout("euclid2.out");

int cmmdc(int x, int y);

int main (){

    int n, v[200000];

    fin>>n;

    for(int i=0; i<n*2; i++){
        fin>>v[i];
    }

    for(int i=0; i<n*2; i+=2){
        fout<<cmmdc(v[i], v[i+1])<<'\n';
    }

    return 0;
}

int cmmdc(int x, int y){

    while(y!=0){

        int r=x%y;
        x=y;
        y=r;
    }
    return x;

}