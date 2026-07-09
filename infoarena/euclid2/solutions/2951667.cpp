#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in.txt");
ofstream g("euclid2.out.txt");
int gcd(long long int a ,long long int b){
    if(b!=0) gcd(b,b%a);
    else return a;
}
int main(){
    long long int t;
    f >> t;
    while(t--){
        long long int a , b;
        f  >> a >> b;
        g << gcd(a,b) << endl;
    }


}