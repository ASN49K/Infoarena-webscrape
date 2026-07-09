#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <functional>
#include <cstdint>
#include <thread>
#include <limits>
#include <cassert>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <regex>
#include <future>

std::ofstream g{ "cmlsc.out" };

std::array<std::int16_t, 1025> A;
std::array<std::int16_t, 1025> B;

int size_A{ 0 };
int size_B{ 0 };

enum directions : std::int8_t
{
    UP = 0,
    LEFT,
    DIAG
};

// B.size() rows 
// A.size() columns
// sizes[size_B][size_A] == seq_size
std::array<std::array<std::int16_t, 1025>, 1025> sizes;
// B.size() rows
// B.size() cols
std::array<std::array<directions, 1025>, 1025> direction;

int seq_size{ 0 };

directions get_direction_when_numbers_different(
    std::int16_t const t_i, std::int16_t const t_j
)
{
    if(sizes[t_i - 1][t_j] >= sizes[t_i][t_j - 1]) {
        return UP;
    }
    
    return LEFT;
}

// where did the cell value come from?
void decide(std::int16_t const t_i, std::int16_t const t_j) 
{
    if(A[t_j] == B[t_i]) {
        sizes[t_i][t_j] = 1 + sizes[t_i - 1][t_j - 1]; 
        direction[t_i][t_j] = DIAG;
    }
    else {
        sizes[t_i][t_j] = std::max(sizes[t_i - 1][t_j], sizes[t_i][t_j - 1]);
        direction[t_i][t_j] = get_direction_when_numbers_different(t_i, t_j);
    }
}

void read()
{
    std::ifstream f{ "cmlsc.in" };

    f >> size_A >> size_B;

    int i{ 0 };
    int j{ 0 };

    for(i = 1; i <= size_A; ++i) {
        f >> A[i];
    }

    for(j = 1; j <= size_B; ++j) {
        f >> B[j];
    }
}

void print_solution()
{
    g << seq_size << '\n';

    int i{ size_B };
    int j{ size_A };

    std::array<std::int16_t, 1024> seq_number;
    int index{ 0 };

    while(i >= 0 && j >= 0) {
        switch(direction[i][j]) {
            case UP:
                --i;
                break;
            case LEFT:
                --j;
                break;
            case DIAG:
                seq_number[index++] = B[i];
                --i;
                --j;
                break;
        }
    }

    for(int k = index - 1; k >= 0; --k) { 
        g << seq_number[k] << ' ';
    }

    g << '\n';
}

void solve()
{
    for(int i = 1; i <= size_B; ++i) {
        for(int j = 1; j <= size_A; ++j) {
            decide(i, j);
        }
    }

    seq_size = sizes[size_B][size_A];

    print_solution();
}

int main()
{
    read();
    solve();
    return 0;
}

