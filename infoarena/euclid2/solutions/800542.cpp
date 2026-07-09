#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int a, b, n, min;

    in >> n;

while(n>0){

    in >> a >> b;

    while(a!=0)
        if(a<b){
            min=a;
            a=b%a;
            b=min;
        }
        else{
            min=b;
            a=a%b;
            b=min;
        }

    out << b << "\n";
n--;
}
    return 0;
}
