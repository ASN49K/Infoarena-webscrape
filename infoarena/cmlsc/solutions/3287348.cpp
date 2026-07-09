// https://www.infoarena.ro/problema/cmlsc
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

struct dp_info
{
    int i, j, len;

    dp_info& operator=(dp_info other) noexcept
    {
        std::swap(i, other.i);
        std::swap(j, other.j);
        std::swap(len, other.len);
        return *this;
    }

    bool is_empty() const
    {
        return i == 0 && j == 0;
    }

    friend bool operator<(const dp_info& lhs, const dp_info& rhs)
    {
        return lhs.len < rhs.len;
    }
};

template <class T>
class Vector2D
{
public:
    Vector2D(unsigned rows, unsigned cols) : m_rows(rows), m_cols(cols)
    {
        if (rows == 0 || cols == 0)
            throw std::underflow_error("Vector2D dimensions cannot be 0");
        m_data = new T[m_rows * m_cols];
    }
    ~Vector2D()
    {
        delete[] m_data;
    }

    inline T& operator()(unsigned row, unsigned col)
    {
        if (row >= m_rows || col >= m_cols)
            throw std::overflow_error("Vector2D subscript out of bounds");
        return m_data[m_cols * row + col];
    }
    inline T operator()(unsigned row, unsigned col) const
    {
        if (row >= m_rows || col >= m_cols)
            throw std::overflow_error("Vector2D subscript out of bounds");
        return m_data[m_cols * row + col];
    }

private:
    unsigned m_rows{};
    unsigned m_cols{};

    T* m_data;
};

int cmlsc(int vm[], int m, int vn[], int n, int vsol[])
{
    auto empty = dp_info{ 0, 0, 0 };

    Vector2D<dp_info> dp(m + 1, n + 1);
    dp(0, 0) = dp(0, 1) = dp(1, 0) = empty;
    if (vm[0] == vn[0])
        dp(1, 1) = { 1, 1, 1 };
    else
        dp(1, 1) = empty;

    for (int i = 2; i <= m; ++i)
        if (dp(i - 1, 1).is_empty() && vm[i - 1] == vn[0])
            dp(i, 1) = { i, 1, 1 };
        else
            dp(i, 1) = dp(i - 1, 1);

    for (int j = 2; j <= n; ++j)
        if (dp(1, j - 1).is_empty() && vm[0] == vn[j - 1])
            dp(1, j) = { 1, j };
        else
            dp(1, j) = dp(1, j - 1);

    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= n; ++j) {
            bool first_cond  = dp(i - 1, j).j == j;
            bool second_cond = dp(i, j - 1).i == i;
            if (first_cond && second_cond) {
                if (dp(i - 1, j).len < dp(i, j - 1).len)
                    dp(i, j) = dp(i, j - 1);
                else
                    dp(i, j) = dp(i - 1, j);
            }
            else if (first_cond)
                dp(i, j) = dp(i - 1, j);
            else if (second_cond)
                dp(i, j) = dp(i, j - 1);
            else if (vm[i - 1] == vn[j - 1])
                dp(i, j) = { i, j, dp(i - 1, j - 1).len + 1 };
            else
                dp(i, j) = dp(i - 1, j - 1);
        }

    int  len      = dp(m, n).len;
    auto last_pos = dp(m, n);
    while (!last_pos.is_empty()) {
        vsol[--len] = vm[last_pos.i - 1];
        last_pos    = dp(last_pos.i - 1, last_pos.j - 1);
    }

    return dp(m, n).len;
}

int main()
{
    try {
        std::ifstream in("cmlsc.in");
        std::ofstream out("cmlsc.out");

        if (!in.is_open())
            throw std::runtime_error("input file not found");

        int m, n;
        in >> m >> n;

        int vm[1025], vn[1025];
        for (int i = 0; i < m; ++i)
            in >> vm[i];
        for (int i = 0; i < n; ++i)
            in >> vn[i];

        int sol_len, vsol[1025];
        sol_len = cmlsc(vm, m, vn, n, vsol);
        out << sol_len << '\n';
        for (int i = 0; i < sol_len; ++i)
            out << vsol[i] << ' ';
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }
}