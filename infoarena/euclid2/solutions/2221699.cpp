#include <iostream>
#include <fstream>

using namespace std;

int solve(int a, int b) {
    if (b == 0)
        return a;

    return solve(b, a % b);
}

int main() {
    int number, first, second;
    int result;

    ifstream input("euclid2.in");
    ofstream output("euclid2.out");

    input >> number;

    for (int i = 0; i < number; i++) {
        input >> first >> second;
        result = solve(first, second);
        output << result << "\n";
    }


    input.close();
    output.close();

    return 0;
}