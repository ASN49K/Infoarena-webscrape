#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input ("euclid2.in");
    ofstream output ("euclid2.out");

    int n;
    input >> n;

    int a,b;
    for(int i = 1; i <= n; i++){
        input >> a >> b;

        if (a > b){
            a = a - b;
        }
        else if (b > a){
            b = b - a;
        }
        else {
            output << a << '\n';
        }
    }
    return 0;
}
