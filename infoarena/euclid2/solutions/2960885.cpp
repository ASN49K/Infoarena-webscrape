#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, first_number, second_number;

int euclid_algorithm(int first_input, int second_input) {
  while (second_input) {
    int rest = first_input % second_input;
    first_input = second_input;
    second_input = rest;
  }
  return first_input;
}

int main() {
    fin >> n;
    for (int i = 1; i <= n; ++i) {
      fin >> first_number >> second_number;
      fout << euclid_algorithm(first_number, second_number) << '\n';
    }
    return 0;
}