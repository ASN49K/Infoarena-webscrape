#include<bits/stdc++.h>
using namespace std;

class input {
private:
    FILE* fin;
    char* t;
    int sp;

    char read()
    {
        if (sp == 10000)
        {
            fread(t, 1, 10000, fin);
            sp = 0;
            return t[sp++];
        }
        else
            return t[sp++];
    }
public:
    input(const char* name)
    {
        fin = fopen(name, "r");
        sp = 10000;
        t = new char[10000]();
    }

    void close()
    {
        fclose(fin);
    }

    void open(const char* name)
    {
        fin = fopen(name, "r");
        sp = 10000;
        t = new char[10000]();
    }

    input& operator >> (int& n)
    {
        char c = read();

        while (c == ' ' || c == '\n')
            c = read();

        n = 0;

        int sng = 1;

        if (c == '-')
            sng = -1, c = read();

        while (c != '\0' && isdigit(c))
            n = n * 10 + (c - '0'), c = read();

        n *= sng;

        return *this;
    }

    input& operator >> (char& s)
    {
        char c = read();

        while (c != '\0' && c == '\n')
            c = read();

        s = c;

        return *this;
    }

    input& operator >> (long long& n)
    {
        char c = read();

        while (c == ' ' || c == '\n')
            c = read();

        n = 0;

        int sng = 1;

        if (c == '-')
            sng = -1, c = read();

        while (c != '\0' && isdigit(c))
            n = n * 10 + (c - '0'), c = read();

        n *= sng;

        return *this;
    }

    void getline(string& s)
    {
        char c = read();
        s = "";

        while (c != '\0' && c != '\n')
            s += c, c = read();
    }

    input& operator >> (string& s)
    {
        char c;
        c = read();
        s = "";

        while (c == '\n' || c == ' ')
            c = read();

        while (c != '\n' && c != '\0' && c != ' ')
            s += c, c = read();

        return *this;
    }

    input& operator >> (char* s)
    {
        char c;
        c = read();
        int i = 0;

        while (c == '\n' || c == ' ')
            c = read();

        while (c != '\n' && c != '\0' && c != ' ')
            s[i++] = c, c = read();

        return *this;
    }
};
class output {
private:
    FILE* fout;
    char* t;
    int sp;

    void write(char c)
    {
        if (sp == 5000)
        {
            fwrite(t, 1, 5000, fout);
            sp = 0;
            t[sp++] = c;
        }
        else
            t[sp++] = c;
    }

public:
    output(const char* name)
    {
        fout = fopen(name, "w");
        sp = 0;
        t = new char[5000]();
    }
    ~output()
    {
        fwrite(t, 1, sp, fout);
    }

    output& operator << (int n)
    {
        if (n < 0)
        {
            write('-');
            n *= -1;
        }
        if (n <= 9)
            write(char(n + '0'));
        else
        {
            (*this) << (n / 10);
            write(char(n % 10 + '0'));
        }

        return *this;
    }

    output& operator << (char c)
    {
        write(c);

        return *this;
    }

    output& operator << (const char* s)
    {
        int i = 0;

        while (s[i] != '\0')
            write(s[i++]);

        return *this;
    }

    output& operator << (long long n)
    {
        if (n < 0)
        {
            write('-');
            n *= -1;
        }
        if (n < 10)
            write(char(n + '0'));
        else
        {
            (*this) << (n / 10);
            write(char(n % 10 + '0'));
        }

        return *this;
    }

    output& operator << (string s)
    {
        for (auto i : s)
            write(i);

        return *this;
    }

    void precizion(double x, int nr)
    {
        int p = floor(x);

        *this << p;

        if (nr == 0)
            return;

        write('.');

        for (int i = 1; i <= nr; i++)
        {
            x -= floor(x);
            x *= 10;

            write(int(x) + '0');
        }
    }
};

input fin("cmlsc.in");
output fout("cmlsc.out");

int n, m;

bool in(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

int main()
{
    int a[1025], b[1025];

    int** A = new int* [1025];

    int i, j;

    for (i = 0; i <= 1024; i++)
        A[i] = new int[1025]();

    fin >> n >> m;

    for (i = 1; i <= n; i++)
        fin >> a[i];

    for (i = 1; i <= m; i++)
        fin >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                A[i][j] = 1 + A[i - 1][j - 1];
            else
                A[i][j] = max(A[i - 1][j], A[i][j - 1]);

    i = n, j = m;
    vector<int> R;

    while (in(i, j))
    {
        if (a[i] == b[j])
            R.push_back(a[i]), i--, j--;
        else if (A[i][j - 1] < A[i - 1][j])
            i--;
        else
            j--;
    }

    fout << int(R.size()) << '\n';

    for (i = R.size() - 1; i >= 0; i--)
        fout << R[i] << ' ';
    
    return 0;
}