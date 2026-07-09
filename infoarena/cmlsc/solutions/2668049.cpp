#include <bits/stdc++.h>

#define IO                    \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);              \
    cout.tie(NULL)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define CF_FILE   \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)

#define PB_FILE(nm) \
    freopen(nm ".in", "r", stdin); \
    freopen(nm ".out", "w", stdout)


// vector, pair in/output
template<class T>
std::istream& operator>>(std::istream& stream, vector<T> &v) { for (T& t: v) { stream >> t; } return stream; }

template <class T>
std::ostream& operator<<(std::ostream& stream, const vector<T> &v) { for (const T& t : v) { stream << t << ' '; } return stream; } 

template <class T, class U>
std::istream& operator>>(std::istream& stream, pair<T, U>& p) { return stream >> p.first >> p.second; }

template <class T, class U>
std::ostream& operator<<(std::ostream& stream, const pair<T, U>& p) { return stream << p.first << ' ' << p.second << ' '; }
// ---


// Input series of values using C++
template<typename T>
void read(T& t) { cin >> t; }

template<typename T, typename... TArgs>
void read(T& t, TArgs&&... args) {
    read(t);
    read(forward<TArgs>(args)...);
}
// ---

// Input series of values using C
template <typename T>
void readc(T& t);

template<>
void readc(int& v) {
    scanf("%d", &v);
}

template<>
void readc(char& v) {
    scanf(" %c", &v); // remove white space before %c if you want to include whitespaces
}

template<>
void readc(long long& v) {
    scanf("%lld", &v);
}

template<>
void readc(float& v) {
    scanf("%f", &v);
}

template<>
void readc(double& v) {
    scanf("%lf", &v);
}

template<size_t sz>
void readc(char (&str)[sz]) { // for stack allocated string
    scanf("%s", str);
}

template<>
void readc(char*& str) {
    scanf("%s", str);
}

template<typename E, typename U>
void readc(pair<E, U>& v) {
    readc(v.first); readc(v.second);
}

template<typename E>
void readc(vector<E>& v) {
    for (E& e : v) readc(e);
}

template<typename T, typename... TArgs>
void readc(T& t, TArgs&&... args) {
    readc(t);
    readc(forward<TArgs>(args)...);
}
// ---

// Output series of values using C
template <typename T>
void printc(T t);

template<>
void printc(int v) {
    printf("%d ", v);
}

template<>
void printc(char v) {
    printf("%c ", v); // remove whitespace if you want them conected
}

template<>
void printc(long long v) {
    printf("%lld ", v);
}

template<>
void printc(float v) {
    printf("%f ", v);
}

template<>
void printc(double v) {
    printf("%lf ", v);
}

template<>
void printc<char *>(char *str) {
    printf("%s ", str);
}

template<>
void printc<const char *>(const char *str) {
    printf("%s ", str);
}

template<typename E, typename U>
void printc(const pair<E, U>& v) {
    printc(v.first); printc(v.second);
}

template<typename E>
void printc(const vector<E>& v) {
    for (const E& e : v) printc(e);
}

template<typename T, typename... TArgs>
void printc(const T& t, TArgs&&... args) {
    printc(t);
    printc(forward<TArgs>(args)...);
}
// ---

// Debug multiple expressions on the same line
template <typename T>
void __DEBUG_BASE(const T& t) {
    cout << t;
}

template <typename T, typename... TArgs>
void __DEBUG_BASE(const T& t, TArgs&&... args) {
    __DEBUG_BASE(t);
    cout << ", ";
    __DEBUG_BASE(forward<TArgs>(args)...);
}

template <typename... TArgs>
void __DEBUG_IMPL(TArgs&&... args) {
    __DEBUG_BASE(forward<TArgs>(args)...);
    // + formating....
}

// use this
#define debug(...) cout << "[" << (#__VA_ARGS__) << "] = "; __DEBUG_IMPL(__VA_ARGS__); cout << endl
// ---



array<char, 5> VOWELS = {'a','e','i','o','u'};
bool isvowel(char ch) { return find(VOWELS.begin(), VOWELS.end(), ch) != VOWELS.end(); };
bool isupper(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool islower(char ch) { return ch >= 'a' && ch <= 'z'; }




int main()
{
    IO;
    // CF_FLIE;
    PB_FILE("cmlsc");

    const int mxN = 102;
    int a[mxN]{};
    int b[mxN]{};
    int n, m;

    int dp[mxN][mxN]{};
    int seq[mxN]{};

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int len = dp[n][m];
    int k = len - 1, i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            seq[k--] = a[i];
            i--;j--;
        } else if (dp[i-1][j] < dp[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }

    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", seq[i]);
    }
}
