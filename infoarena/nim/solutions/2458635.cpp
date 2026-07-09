#include <bits/stdc++.h>

typedef long long ll ;
typedef long double ld ;

int main() {
        freopen("nim.in", "r", stdin) ;
        freopen("nim.out", "w", stdout) ;
        std::ios_base::sync_with_stdio(0) ;
        std::cin.tie(0) ;
        std::cout.tie(0) ;
        int te ;
        std::cin >> te ;
        while (te--) {
                int tot = 0 ;
                int n, grundy ;
                std::cin >> n ;
                for (int i = 1 ; i <= n ; i++) {
                        std::cin >> grundy ;
                        tot ^= grundy ;
                }
                if (tot != 0) std::cout << "DA\n" ;
                else std::cout << "NU\n" ;
    }
}
