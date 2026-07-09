#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
int arr[2][1030];
int sol[1030][1030];
vector <int> solutions;

int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[0][i];
    for (int i = 1; i <= m; i++)
        cin >> arr[1][i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sol[i][j] = max(sol[i - 1][j - 1] + bool(arr[0][i] == arr[1][j]),
                    max(sol[i - 1][j], sol[i][j - 1]));

    for (int i = n, j = m; i && j; )
        if (arr[0][i] == arr[1][j]) {
            solutions.push_back(arr[0][i]);
            i--;
            j--;
        }
        else if (sol[i][j - 1] > sol[i - 1][j])
            j--;
        else i--;

    cout << solutions.size() << "\n";
    for (int i = solutions.size() - 1; i >= 0; i--)
        cout << solutions[i] << " ";

    return 0;
}

