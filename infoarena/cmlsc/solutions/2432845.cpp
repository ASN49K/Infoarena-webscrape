#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main() {
    short lengthOfFirst, lengthOfSecond;
    cin >> lengthOfFirst >> lengthOfSecond;

    vector<int> first;
    for (int i = 1; i <= lengthOfFirst; i++) {
        int a;
        cin >> a;
        first.push_back(a);
    }

    vector<int> second;
    for (int i = 1; i <= lengthOfSecond; i++) {
        int a;
        cin >> a;
        second.push_back(a);
    }

    vector<int> commSubs;
    for (int i = 0; i < lengthOfFirst; i++) {
        for (int j = 0; j < lengthOfSecond && i < lengthOfFirst; j++) {
            if (first[i] == second[j]) {
                commSubs.push_back(first[i]);
                i++, j++;
            }
        }
    }
    cout << commSubs.size() << '\n';

    for (int i = 0; i < commSubs.size(); i++)
    {
        cout << commSubs[i] << " ";
    }
}
