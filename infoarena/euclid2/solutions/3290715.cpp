// 31032025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int a, int b) {
    if (b == 0) return a;
    return euclid(b, a % b);
}
int n;
int main()
{
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
}