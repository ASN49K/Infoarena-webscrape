#include <iostream>

using namespace std;

#include <algorithm>
void ordonare(int a[], int n, int st, int dr){
    sort(a + st, a + dr);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
}