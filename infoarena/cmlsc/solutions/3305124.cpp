#include <iostream>

#define MAXLENGTH 1024


int main()
{
    int n, m;
    int first[MAXLENGTH];
    int second[MAXLENGTH];
    int length = 0;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        std::cin >> first[i];

    for (int i = 0; i < m; ++i)
        std::cin >> second[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0, found = false; j < m && !found; ++j) {
            if (second[j] == first[i]) {
                ++length;
                found = true;
            }
        }
    }
    
    std::cout << length << '\n';

    return 0;
}
