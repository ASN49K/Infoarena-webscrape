#include <fstream>
using namespace std;
int n,m,i,j,x,c,smax,y,t;
int divz(int a, int b){
    int r = 0;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin >> t;
    for(i =1 ; i <=t; i++){
        cin >> x >> y;
        cout << divz(x,y) << "\n";
    }
}
