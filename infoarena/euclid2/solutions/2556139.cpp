#include<fstream>
using namespace std;
int main ()
{
    fstream f("euclid2.in", ios::in), g("euclid2.out", ios::out);
    unsigned long long int a,b,r;
    unsigned short int T,i;
    f>>T;
    for (i=1; i<=T; i++){
        f>>a>>b;
            while (b!=0){
                r=a%b;
                a=b;
                b=r;
            }
            g<<a<<endl;
    }
    return 0;
}
