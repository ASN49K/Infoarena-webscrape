#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b;
    in >> n;
    for(int i=1;i<=n;i++){
        in >> a >> b;
        while(a!=0){
            if(b>a){
                int c=a;
                a=b;
                b=c;
            }
            a%=b;
        }
        out << b << '\n';
    }
}
