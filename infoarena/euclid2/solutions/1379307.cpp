#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, i, a, b, r;
int main(){
    fin>>T;
    for(i=1;i<=T;i++){
        fin>>a>>b;
        r=a%b;
        while(r){
            a=b;
            b=r;
            r=a%b;




        }
        fout<<b<<'\n';


    }




    return 0;
    }
