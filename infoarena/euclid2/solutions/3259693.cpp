#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input ("euclid2.in");
    ofstream output ("euclid2.out");

    int n;
    input >> n;

    int a,b, t;
    for(int i = 1; i <= n; i++){
        input >> a >> b;

        while(b != 0){
            t = b;
            b = a % b;
            a = t;
        }
        output << a << '\n';
    }
    return 0;
}
