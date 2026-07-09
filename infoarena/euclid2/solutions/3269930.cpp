#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

struct Numar {
    int a, b;
};

int mare_mic(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}
int maxim(int x, int y, int min) {
    int max = 0;
    for (int i = 1; i < min; i++) {
        if (x % i == 0 && y % i == 0) {
            max = i;
        }
    }
    return max;
}

int main() {
    int n, x, y;
    cin >> n;
    Numar numar[n];
    for (int i = 0; i < n; i++) {
        cin >> numar[i].a >> numar[i].b;
        int min = mare_mic(numar[i].a, numar[i].b);
        int max = maxim(numar[i].a, numar[i].b, min);
        cout << max << endl;
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.