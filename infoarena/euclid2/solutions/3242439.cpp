#include <fstream>


using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a ,int b){
    while(b){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int n;
    fin>>n;
    while(n--){
        int a,b;
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }

    return 0;
}
