#define __USE_FILES__
#ifdef __USE_FILES__
#include <fstream>
std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");
#else
#include <iostream>
std::istream& in = std::cin;
std::ostream& out = std::cout;
#endif

// directive preprocesate
#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <math.h>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

// declaratie functii
ll cmmdc(ll, ll);

// declaratii variablile
ll n;

int main()
{
    in >> n;
    while (n--) {
        ll a, b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
    return 0;
}

ll cmmdc(ll n1, ll n2) {
    if (n2 == 0)
        return n1;
    return cmmdc(n2, n1 % n2);
}
