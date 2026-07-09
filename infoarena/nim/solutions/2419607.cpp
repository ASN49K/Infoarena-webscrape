//ALEX ENACHE

#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

//#include <iostream>
#include <fstream>
ifstream cin ("nim.in");ofstream cout ("nim.out");



int main() {

    //freopen("input", "r", stdin);freopen("output", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(10) << fixed;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(time(nullptr));

    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        int nr , now = 0;
        for (int i=1; i<=n; i++){
            cin>>nr;
            now ^= nr;
        }
        if (now == 0){
            cout<<"NU"<<'\n';
        }
        else{
            cout<<"DA"<<'\n';
        }
    }


    return 0;
}