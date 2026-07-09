#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,a,b,r;
    in>>n;
    while(n!=0){
        in>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
        n--;
    }
    return 0;
}
