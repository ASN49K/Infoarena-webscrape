#include <fstream>
#include <iostream>
using namespace std;

int A[101][101];

int main()
{
    ifstream cin("joc5.in");
    ofstream cout("joc5.out");
    int N;
    cin >> N;
    while(N) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                cin >> A[i][j];
            }
        }
        int sum = 0;
        for(int i = 1; i <= N; ++i)
            sum = (sum ^ A[i][i]);
        if(sum)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
        cin >> N;
    }
    return 0;
}
