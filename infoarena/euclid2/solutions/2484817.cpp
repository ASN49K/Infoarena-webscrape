#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){

int n,x,y,rest;

fin>>n;

for(int i=1;i<=n;i++){
    fin>>x>>y;

    while(y){
        rest=x%y;
        x=y;
        y=rest;

    }
    fout<<x<<"\n";


}



}
