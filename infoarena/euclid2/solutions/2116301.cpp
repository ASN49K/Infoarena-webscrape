#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, x ,y;

int euclid(int a, int b){

    int r = a % b;
    while(r){

        a = b;
        b = r;
        r = a % b;
    }
    return b ;
}

int main(){

    f >> T;

    for(int i = 1; i <= T; i++){

        f >> x >> y;
        g << euclid(x, y) << '\n';
    }

    return 0;
}
