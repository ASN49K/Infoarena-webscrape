#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
long euclid(long a,long b){
     long r;
     while (b!=0) {
     r=a%b;
     a=b;
     b=r;
     }
     return a;
}
int main(int argc, char *argv[])
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long n,x,y;
    
    f >> n;
    for (long i=1;i<=n;i++){
        f >> x;
        f >> y;
        g << euclid(x,y)<<endl;  
    }
    f.close();
    g.close();
    return EXIT_SUCCESS;
}
