#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin;
ofstream fout;

string x = "";
string y = "";

string LCS (string x, string y) {
    if (x.length() == 0 || y.length() == 0)
        return "";
    if (x[x.length() - 1] == y[y.length() - 1])
        return LCS (*(new string(x, 0, x.length() - 1)), *(new string(y, 0, y.length() - 1))) + x[x.length() - 1];

    string a = LCS (*(new string(x, 0, x.length() - 1)), y);
    string b = LCS (x, *(new string(y, 0, y.length() - 1)));
    return a.length() > b.length() ? a : b;
}

int main (int argc, char** argv) {

    fin.open ("cmlsc.in", ifstream::in);
    fout.open ("cmlsc.out", ofstream::out);

    int n, m;
    char c;
    string res;

    fin >> n >> m;
    for (int i = 0; i < n; i ++) {
        fin >> c;
        x += c;
    }
    for (int i = 0; i < m; i ++) {
        fin >> c;
        y += c;
    }
    // cout << x << " " << y << endl;

    res =  LCS (x, y);
    fout << res.length() << endl;
    fout << res;

    fin.close();
    fout.close();
}
