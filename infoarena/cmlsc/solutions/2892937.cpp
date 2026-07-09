#include <bits/stdc++.h>
using namespace std;
int **d;

void read_input(vector<int> &a, vector<int> &b, string filename_in) {
    ifstream in(filename_in);

    size_t len;

    in >> len;
    a.resize(len);
    in >> len;
    b.resize(len);

    for(size_t i = 0; i < a.size(); i++)
        in >> a[i];

    for(size_t i = 0; i < b.size(); i++)
        in >> b[i];

    in.close();
}

vector<int> solve_dp(vector<int> &a, vector<int> &b) {
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    // Compute DP Array
    for(size_t i = 0; i < a.size(); i++)
        for(size_t j = 0; j < b.size(); j++) {
            if(a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }

    // Get length of maximum subset
    int max_len = dp.back().back();

    vector<int> res(max_len);
    size_t res_pos = res.size();

    // Get subset
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i >= 0 && j >= 0) {
        if(a[i] == b[j]) {
            res[--res_pos] = a[i];
            i--;
            j--;
        } else if(dp[i + 1][j] > dp[i][j + 1]) {
            j--;
        } else {
            i--;
        }
    }

    return res;
}

bool is_subset(vector<int> &subset, vector<int> &arr) {
    size_t subset_pos = 0;
    size_t arr_pos = 0;

    while(subset_pos < subset.size()) {
        if(arr_pos == arr.size())
            return false;

        if(arr[arr_pos] == subset[subset_pos])
            subset_pos++;

        arr_pos++;
    }

    return true;
}
void BKT_helper(
    vector<int> &a, // original a
    vector<int> &b, // original b
    vector<int> &best, // best subset
    vector<int> &crt, // current subset
    size_t a_pos = 0 // current a position
) {
    if(a_pos == a.size()) {
        if(is_subset(crt, b) && crt.size() > best.size())
            best = crt;

        return;
    }

    BKT_helper(
        a,
        b,
        best,
        crt,
        a_pos + 1
    );

    crt.push_back(a[a_pos]);

    BKT_helper(
        a,
        b,
        best,
        crt,
        a_pos + 1
    );

    crt.pop_back();
}
vector<int> solve_BKT(vector<int> &a, vector<int> &b) {
    vector<int> res = {};

    vector<int> accum = {};
    BKT_helper(a, b, res, accum);

    return res;
}

void write_output(vector<int> &res, string filename_out) {
    ofstream out(filename_out);

    out << res.size() << '\n';
    for(int x : res)
        out << x << ' ';

    out.close();
}

int main() {
    vector<int> a, b;
    read_input(a, b, "cmlsc.in");

    vector<int> res = solve_BKT(a, b);

    write_output(res, "cmlsc.out");

    return 0;
}
