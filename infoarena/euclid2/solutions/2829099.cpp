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

// declaratii variablile
ll n;

int main()
{
    in >> n;
    while (n--) {
        ll a, b, rest;
        in >> a >> b;
        while (b != 0) {
            rest = a % b;
            a = b;
            b = rest;
        }
        out << a << '\n';
    }
    return 0;
}