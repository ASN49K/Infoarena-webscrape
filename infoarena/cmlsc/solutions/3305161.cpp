#include <fstream>

#define MAXLENGTH 1024


int cmlsc(int *arr1, int n, int *arr2, int m)
{
    int dp[MAXLENGTH];
    int prev, prev_text1;

    dp[0] = arr1[0] == arr2[0];

    for (int i = 1; i < n; ++i)
        if (arr1[i] == arr2[0])
            dp[i] = 1;
        else
            dp[i] = dp[i - 1];

    for (int j = 1; j < m; ++j) {
        prev = dp[0];

        if (arr1[0] == arr2[j])
            dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            prev_text1 = dp[i];

            if (arr1[i] == arr2[j]) {
                dp[i] = prev + 1;
            } else {
                if (prev_text1 < dp[i - 1])
                    dp[i] = dp[i - 1];
                else
                    dp[i] = prev_text1;
            }

            prev = prev_text1;
        }
    }

    return dp[n - 1];
}

int main()
{
    int n, m;
    int arr1[MAXLENGTH], arr2[MAXLENGTH];

    std::ifstream fin("cmlsc.in");

    fin >> n >> m;

    for (int i = 0; i < n; ++i)
        fin >> arr1[i];

    for (int i = 0; i < m; ++i)
        fin >> arr2[i];

    fin.close();

    std::ofstream fout("cmlsc.out");

    fout << cmlsc(arr1, n, arr2, m) << '\n';

    fout.close();

    return 0;
}
