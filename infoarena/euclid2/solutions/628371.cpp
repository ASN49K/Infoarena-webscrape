#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
int euclid(int a,int b){
     int r;
     while (b!=0) {
     r=a%b;
     a=b;
     b=r;
     }
     return a;
}
int main(char *argv[])
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,x,y;
    f >> n;
    for (int i=1;i<=n;i++){
        f >> x;
        f >> y;
        g << euclid(x,y)<<endl;  
    }
    return EXIT_SUCCESS;
}
