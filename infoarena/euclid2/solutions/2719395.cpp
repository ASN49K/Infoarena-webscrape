#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long t , a , b;

int main(){
    fin>>t;
    while(t){
                fin>>a>>b;
                if(a<b)
                    swap(a,b);
                while(b!=0){
                    int d=a%b;
                    a=b;
                    b=d;
                }
        fout<<a<<endl;
        t--;
    }


    return 0;
}
