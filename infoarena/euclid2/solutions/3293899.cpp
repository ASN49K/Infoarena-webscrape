#include <fstream>
#include <vector>
using namespace std;

ifstream cin("prim.in");
ofstream cout("prim.out");

const int LIMIT = 1e6;  

int main() {
    int n;
    cin >> n;
    

    vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;  
    
    for (int i = 2; i * i <= LIMIT; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
    

    vector<int> prime;
    for (int i = 2; i <= LIMIT; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }

    cout << prime[n - 1] << endl;

    return 0;
}
