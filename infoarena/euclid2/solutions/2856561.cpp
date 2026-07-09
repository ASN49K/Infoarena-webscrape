#include <iostream>
#include <fstream>

int cmmdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return cmmdc(b, a % b);
}

int main(int argc, char *argv[])
{
  std::fstream in;
  in.open("euclid2.in", std::ios::in);
  if (!in.is_open()) {
    std::cerr << "File has not been open." << std::endl;
  }

  int T;
  in >> T;

  std::fstream out;
  out.open("euclid2.out", std::ios::out);

  int A, B;
  for (int i = 0; i < T; i++) {
    in >> A >> B;
    out << cmmdc(A, B) << '\n';
  }

  in.close();
  out.close();
  return 0;
}
