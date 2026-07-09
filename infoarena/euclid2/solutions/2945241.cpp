#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a , b , n;

void cmmdc(int a , int b){
    int r;
    while(b){
        r = a%b;
        a=b;
        b=r;
    }
    cout << a << '\n';
}

int main()
{
    cin >> n;

    while(n--){
        cin >> a >> b;

        cmmdc(a,b);
    }

    return 0;
}
