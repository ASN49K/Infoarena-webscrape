#include <fstream>
using namespace std;
int t , a , b ,d;
int main(){

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(int i=1 ; i<=t ; i++){
                fin>>a>>b;
                while(b!=0){
                    d=a%b;
                    a=b;
                    b=d;
                }
        fout<<a<<endl;
    }


    return 0;
}

