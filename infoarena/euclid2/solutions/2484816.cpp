#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){

int n,x,y;

fin>>n;

for(int i=1;i<=n;i++){
    fin>>x>>y;

    while(y!=0){
        x=y;
        y=x%y;

    }
    fout<<x<<"\n";


}



}
