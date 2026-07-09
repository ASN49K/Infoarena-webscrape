#include <fstream>

using namespace std;
int Euclid(int x , int y){
    if(x == 0)
        return y;
    else return Euclid(y%x, x);
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n , a , b ,r;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
       cout<< Euclid(a,b);
    }

    return 0;
}
