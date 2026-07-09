#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
using namespace std;
 
#ifdef INFOARENA
#define TEST 0
#else
#define TEST 1
#endif

class LongestCommonSubsequence {
public:
    LongestCommonSubsequence(const vector<int>& first,
                             const vector<int>& second) : first_(first), 
                             second_(second) {}

    void Calculate() {
        vector<vector<int>> cost(first_.size()+1, vector<int>(second_.size()+1, 0));
        for (int i = 0; i < first_.size(); ++i) 
        for (int j = 0; j < second_.size(); ++j) {
            if (first_[i] == second_[j]) {
                cost[i+1][j+1] = cost[i][j] + 1;
            } else {
                cost[i+1][j+1] = max(cost[i+1][j], cost[i][j+1]);
            }
        }
        cost_ = cost[first_.size()][second_.size()];
        int r = first_.size(), c = second_.size();
        while (r > 0 && c > 0) {
            if (first_[r-1] == second_[c-1]) {
                solution_.push_back(first_[r-1]);
                r--;
                c--;
            } else {
                if (cost[r-1][c-1] >= cost[r-1][c] &&
                    cost[r-1][c-1] >= cost[r][c-1]) {
                    r--;
                    c--;
                } else
                if (cost[r-1][c] >= cost[r][c-1] &&
                    cost[r-1][c] >= cost[r-1][c-1]) {
                    r--;
                } else {
                    c--;
                }
            }
        }
        reverse(solution_.begin(), solution_.end());
    }
    int GetResult() {
        return cost_;
    }
    const vector<int>& GetSolution() {
        return solution_;
    } 
private:
    vector<int> first_;
    vector<int> second_;
    int cost_;
    vector<int> solution_;
};
 
int main() {

    vector<int> first;
    vector<int> second;

    if (TEST) {
        first = vector<int>({1,7,3,9,8});
        second = vector<int>({7,5,8});
    } else {
        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);
        
        int num_values_first, num_values_second;
        scanf("%d %d", &num_values_first, &num_values_second);
        first.resize(num_values_first);
        second.resize(num_values_second);
        for (int i = 0; i < num_values_first; ++i) {
            scanf("%d", &first[i]);
        }
        for (int i = 0; i < num_values_second; ++i) {
            scanf("%d", &second[i]);
        }
    }

    LongestCommonSubsequence *lcms = new LongestCommonSubsequence(first, second);
    lcms->Calculate();
    printf("%d\n", lcms->GetResult());
    for (int x : lcms->GetSolution()) {
        printf("%d ", x);
    }
    return 0;

}