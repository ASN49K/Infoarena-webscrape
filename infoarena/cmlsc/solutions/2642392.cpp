#include <bits/stdc++.h>

#define MAX(a, b) a >= b ? a : b
#define MIN(a, b) a <= b ? a : b
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> nums;


void solve(){
    int M{}, N{};
    vector <int> result;
    fin >> M >> N;

    nums.resize(256, 0);
    int max = MAX(M, N);
    int min = MIN(M, N);

    while(max--){
        int x;
        fin >> x;
        nums[x]++;
    }

    while(min--){
        int x;
        fin >> x;
        if(nums[x]){
            result.push_back(x);
            nums[x]--;
        }
    }

    fout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++)
        fout << result[i] << " ";

    return;
}

int main(){

solve();

return 0;
}
