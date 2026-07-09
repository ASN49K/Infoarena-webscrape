#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("input.in");
    ofstream output("output.out");
    int T;
    input >> T;
    int a, b, temp;

    while (input>>a) {
        input >> b;
        while (b != 0){
            temp = a;
            a = b;
            b = temp%b;
        }
        output << a << endl;
    }

    return 0;
}
