#include <iostream>

using namespace std;
int Euclid(int x , int y){
    if(x == 0)
        return y;
    else return Euclid(y%x, x);
}

int main()
{
    int n , a , b;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        cout << Euclid(a , b) << endl;
    }
    return 0;
}
