#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid1.txt");
ofstream g("euclid2.txt");
int main(){
    int x,y,i,z,r;
    f>>x;
    for(i=1;i<=x;i++){
        f>>y>>z;
        while(z){
            r=y%z;
            y=z;
            z=r;
        }
        g<<y<<endl;
    }
return 0;}
