#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

//determina cel mai mic divizor comun al numerelor a si b
int cmmdc(int a, int b){
    int r;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n;
    int a,b;
    f>>n;
    while(n--){

        f >> a >> b;
        g << cmmdc(a,b) << "\n";
    }
    return 0;
}
