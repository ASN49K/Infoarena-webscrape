#include <iostream>

using namespace std;

int main()
{
    int n, a[1000], b[1000], R;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i] >> b[i];
    }
    for( int i = 1; i <= n; i++ ){
        while( b[i] != 0 ){
            R = a[i] % b[i];
            a[i] = b[i];
            b[i] = R;
        }
        cout << a[i] << endl;
    }
}
