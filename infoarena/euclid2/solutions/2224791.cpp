#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    cin >> n;
    int a, b;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b;
        int r;
        while(b > 0){
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << "\n";
    }
    return 0;
}
