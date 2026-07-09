#include <bits/stdc++.h>

using namespace std;

// const int TOTAL_ROUNDS = 16;
// /*
// *
// 1. Target x Duct tape T   - 1 3
// 2. Duct tape x Velcro 2   - 3 2
// 3. Foam T x Target        - 4 1
// 4. Velcro 3 x Duct tape T - 5 3
// 5. Target x Velcro 2      - 1 2
// 6. Velcro 2 x Foam T
// 7. Velcro 3 x Target
// 8. Foam T x Velcro 3
//  */
// int roomOneChoices[20];
// int roomTwoChoices[20];
//
// void printToy(int toy) {
//     if (toy == 1) cout << "Target";
//     if (toy == 2) cout << "Velcro 2";
//     if (toy == 3) cout << "Ductal tape T";
//     if (toy == 4) cout << "Foam T";
//     if (toy == 5) cout << "Velcro 3";
// }
//
// const int TOTAL_TOYS = 5;
// int toysAvailable[6] = {0, 8, 6, 6, 6, 6};
// int toysAvailableMidPoint[6] = {0, 4, 3, 3, 3, 3};
//
// // 1 - Target
// // 2 si 3 - nu au voie impreuna
// // 4 si 5 - nu au voie impreuna
// // 1 mereu la trial impar - DONE
// // un obiect tre sa isi alterneze mereu partea - DONE
// // un obiect nu are voie in 3 trials consecutive - DONE
// bool checkConsecutive(int currentRound, int currentToy) {
//     int contor = 0;
//     for (int i = 1; i <= currentRound; ++i) {
//         if (roomOneChoices[i] == currentToy or roomTwoChoices[i] == currentToy) {
//             contor++;
//         }
//         if (i - 4 >= 1 and (roomOneChoices[i - 4] == currentToy or roomTwoChoices[i - 4] == currentToy)) {
//             contor--;
//         }
//         if (contor == 3) return false;
//     }
//     return true;
// }
//
// bool checkAlternative(int currentRound, int currentToy) {
//     int lastSide = 0;
//     for (int i = 1; i <= currentRound; ++i) {
//         if (roomOneChoices[i] == currentToy) {
//             if (lastSide == 1) return false;
//             lastSide = 1;
//         }
//         if (roomTwoChoices[i] == currentToy) {
//             if (lastSide == 2) return false;
//             lastSide = 2;
//         }
//     }
//     return true;
// }
//
// bool validateSoFar(int currentRound) {
//     vector <int> lastUsage(TOTAL_TOYS + 1, 0);
//
//     for (int i = 1; i <= TOTAL_TOYS; ++i) {
//         if (!checkConsecutive(currentRound, i)) {
//             return false;
//         }
//         if (!checkAlternative(currentRound, i)) {
//             return false;
//         }
//     }
//     for (int i = 1; i <= currentRound; ++i) {
//         if (roomOneChoices[i] == 1 or roomTwoChoices[i] == 1) {
//             if (i % 2 == 0) return false;
//         } else {
//             if (i % 2 == 1) return false;
//         }
//         if (roomOneChoices[i] + roomTwoChoices[i] == 7) return false;
//     }
//     return true;
// }
//
// int frequencies[10][10];
//
// void backtracking(int currentRound) {
//     if (!validateSoFar(currentRound - 1)) return;
//     if (currentRound == TOTAL_ROUNDS + 1) {
//         for (int i = 1; i <= TOTAL_ROUNDS; ++i) {
//             cout << "Trial " << i << ":\n";
//             cout << "Room 1: ";
//             printToy(roomOneChoices[i]);
//             cout << " / Room 2: ";
//             printToy(roomTwoChoices[i]);
//             cout << endl;
//             cout << endl;
//         }
//         exit(0);
//     }
//
//     for (int i = 1; i <= TOTAL_TOYS; ++i) {
//         if (toysAvailable[i] <= 0) continue;
//         if (currentRound <= TOTAL_ROUNDS / 2 and toysAvailableMidPoint[i] <= 0) continue;
//
//         for (int j = 1; j <= TOTAL_TOYS; ++j) {
//             if (toysAvailable[j] <= 0 or i == j) continue;
//             if (currentRound <= TOTAL_ROUNDS / 2 and toysAvailableMidPoint[j] <= 0) continue;
//             if (currentRound <= TOTAL_ROUNDS / 2 and frequencies[i][j] > 0) continue;
//             if (frequencies[i][j] > 1) continue;
//
//             roomOneChoices[currentRound] = i;
//             roomTwoChoices[currentRound] = j;
//
//             toysAvailable[i] -= 1;
//             toysAvailable[j] -= 1;
//             toysAvailableMidPoint[i] -= 1;
//             toysAvailableMidPoint[j] -= 1;
//             frequencies[i][j] += 1;
//             frequencies[j][i] += 1;
//
//             backtracking(currentRound + 1);
//
//             frequencies[i][j] -= 1;
//             frequencies[j][i] -= 1;
//             toysAvailable[i] += 1;
//             toysAvailable[j] += 1;
//             toysAvailableMidPoint[i] += 1;
//             toysAvailableMidPoint[j] += 1;
//         }
//     }
// }

int dp[1100][1100];
int a[1100], b[1100];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    vector <int> answer;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int currentI = n;
    int currentJ = m;

    while (currentI > 0 && currentJ > 0) {
        if (a[currentI] == b[currentJ]) {
            answer.push_back(a[currentI]);
            currentI--;
            currentJ--;
        } else if (dp[currentI - 1][currentJ] > dp[currentI][currentJ - 1]) {
            currentI--;
        } else {
            currentJ--;
        }
    }
    cout << answer.size() << '\n';
    reverse(answer.begin(), answer.end());
    for (auto x : answer) {
        cout << x << ' ';
    }
    return 0;
}