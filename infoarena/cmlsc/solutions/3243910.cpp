#include <fstream>
#include <vector>

int main()
{
    std::ifstream in("cmlsc.in");
    int lenA; in >> lenA;
    int lenB; in >> lenB;

    std::vector A(lenA, 0);
    for(int i = 0; i < lenA; i++)
        in >> A[i];

    std::vector B(lenB, 0);
    for(int i = 0; i < lenB; i++)
        in >> B[i];
    in.close();

    std::vector dp(lenA + 1, std::vector(lenB + 1, 0));
    for(int i = 1; i <= lenA; i++)
        for(int j = 1; j <= lenB; j++)
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

    std::ofstream out("cmlsc.out");
    out << dp[lenA][lenB] << '\n';

    int i = lenA, j = lenB;
    std::vector<int> result;
    while(i > 0 && j > 0)
        if(A[i - 1] == B[j - 1])
        {
            result.push_back(A[i - 1]);
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;

    for(i = result.size() - 1; i >= 0; i--)
        out << result[i] << ' ';

    out.close();
    return 0;
}
