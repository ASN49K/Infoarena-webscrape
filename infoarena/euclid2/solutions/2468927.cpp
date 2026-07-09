#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
    while(a != b)
        if(a < b) b-=a;
        else a -= b;
    return a;
}

int main(){
    int t,mat[100001][2];
    in>>t;
    for(int i = 0; i < t; i++)
    for(int j = 0; j < 2; j++){
        in>>mat[i][j];
        if(j == 1) out<<cmmdc(mat[i][0] , mat[i][1])<<"\n";
    }
}
