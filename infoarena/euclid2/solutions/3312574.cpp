#include<iostream>
#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(long long a, long long b) {
while (b) {
   int x = a % b;
    a = b;
    b = x;
}
return a;
}
int main() {
long long n;
in >> n;

for (int i = 1; i <= n; ++i) {
    long long a, b;
    in >> a >> b;
    out << cmmdc(a, b) << endl;
}
return 0;}
