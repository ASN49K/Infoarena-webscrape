// https://www.infoarena.ro/problema/cmlsc
#include <iostream>
#include <fstream>
#include <vector>

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

    T& operator()(unsigned row, unsigned col)
    {
        if (row >= m_rows || col >= m_cols)
            throw std::overflow_error("Vector2D subscript out of bounds");
        return m_data[m_cols * row + col];
    }
    T operator()(unsigned row, unsigned col) const
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
    auto empty = std::make_pair(0, 0);

    Vector2D<std::pair<int, int>> dp(m + 1, n + 1);
    dp(0, 0) = dp(0, 1) = dp(1, 0) = empty;
    if (vm[0] == vn[0])
        dp(1, 1) = { 1, 1 };
    else
        dp(1, 1) = empty;

    for (int i = 2; i <= m; ++i)
        if (dp(i - 1, 1) == empty && vm[i - 1] == vn[0])
            dp(i, 1) = { i, 1 };
        else
            dp(i, 1) = dp(i - 1, 1);

    for (int j = 2; j <= n; ++j)
        if (dp(1, j - 1) == empty && vm[0] == vn[j - 1])
            dp(1, j) = { 1, j };
        else
            dp(1, j) = dp(1, j - 1);

    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= n; ++j)
            if (dp(i - 1, j) == std::make_pair(i - 1, j))
                dp(i, j) = dp(i - 1, j);
            else if (dp(i, j - 1) == std::make_pair(i, j - 1))
                dp(i, j) = dp(i, j - 1);
            else if (vm[i - 1] == vn[j - 1])
                dp(i, j) = std::make_pair(i, j);
            else
                dp(i, j) = dp(i, j - 1);

    int  len{};
    auto last_pair = dp(m, n);
    while (last_pair != empty) {
        vsol[len++] = vm[last_pair.first - 1];
        last_pair   = dp(last_pair.first - 1, last_pair.second - 1);
    }

    for (int i = 0; i < len / 2; ++i)
        std::swap(vsol[i], vsol[len - i - 1]);

    return len;
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