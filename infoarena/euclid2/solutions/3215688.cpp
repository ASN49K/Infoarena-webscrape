#include <fstream>


using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b){
    while(b!=0){
        int aux = a%b;
        a=b;
        b=aux;
    }
    return a;
}

int main(){
    int a,b;
    fin>>a>>b;
    if(a<b)
        swap(a,b);
    fout<<euclid(a,b);

    return 0;
}
