#include <iostream>
#include <fstream>
using namespace std;

long long cmmdc(long long a , long long b){
long long temp;
    while( b != 0 ){
        temp = a % b;
        a = b;
        b = temp;}
 return a;


}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int numarperechi;
    f>>numarperechi;
    for(int i=0; i<numarperechi; i++){
        long long a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
        }


    return 0;
}
