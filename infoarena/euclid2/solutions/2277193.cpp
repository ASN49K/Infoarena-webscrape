#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,x,y,aux;

int main(){
    for(fin>>n;n;n--){
        fin>>x>>y;
        while(y!=0){
            aux=x%y;
            x=y;
            y=aux;
        }
        fout<<x<<"\n";
    }

    return 0;
}
