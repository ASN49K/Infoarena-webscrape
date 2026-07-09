#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int N,x,y,r,n;
int main(){
    fin>>N;
    for(n=1;n<=N;n++){
        fin>>x>>y;
        while(y!=0){
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}
