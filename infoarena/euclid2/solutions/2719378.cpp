#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long t , a , b;

int main(){
    fin>>t;
    for(int i=1 ; i<=t ; i++){
                fin>>a>>b;
                while(b!=0){
                    int d=a%b;
                    a=b;
                    b=d;
                }
        fout<<a<<endl;
    }


    return 0;
}
