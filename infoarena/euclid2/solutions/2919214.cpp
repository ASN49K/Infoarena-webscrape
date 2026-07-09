#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){

int n, x, y;
f>>n;

for(int i=0; i<n; i++){
    f>>x>>y;
    while(y){
        int rest = x%y;
        x = y;
        y = rest;
    }
    g << x << "\n";
}
return 0;

}
