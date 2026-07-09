#include <fstream>
#include <iostream>
#include <array>

int main() {
  // Deschidem fișierul și în caz de succes, continuăm cu restul
  // operațiilor de citire.
  std::ifstream inFile;
  inFile.open("cmlsc.in", std::ios::in);

  if (inFile.is_open()) {
    // Pot fi maxim NMAX = 1024 elemente în fiecare vector.
    const unsigned int NMAX = 1024;

    // Numărul de elemente din vectorul A, respectiv vectorul B.
    unsigned int neA, neB;
    inFile >> neA >> neB;

    // Creăm vectorii cu vectorii naturale A și B care vor stoca
    // secvențele date.
    std::array<unsigned int, NMAX> A, B;

    // Acum că am citit cîte elemente sînt în fiecare din vectori, citim
    // respectivele elemente.
    for (size_t poz = 1; poz <= neA; poz++)
      inFile >> A[poz];
    for (size_t poz = 1; poz <= neB; poz++)
      inFile >> B[poz];

    // Deschidem fișierul output și în caz că am reușit să-l deschidem,
    // continuăm cu restul operațiilor.
    std::ofstream outFile;
    outFile.open("cmlsc.out", std::ios::out);
    if (outFile.is_open()) {
      // Aici este matricea care ține toate elementele
      std::array<std::array<unsigned int, NMAX>, NMAX> sol;
      for (int i = 0; i <= neA; i++) {
        for (int j = 0; j <= neB; j++)
          sol[i][j] = 0;
      }

      // Creăm matricea necesară pentru CMLSC
      for (size_t rand = 1; rand <= neA; rand++) {
        for (size_t coloana = 1; coloana <= neB; coloana++) {
          if (A[rand] == B[coloana])
            sol[rand][coloana] = 1 + sol[rand - 1][coloana - 1];
          else
            sol[rand][coloana] =
                std::max(sol[rand - 1][coloana], sol[rand][coloana - 1]);
        }
      }

      unsigned int lungimeCMLSC = 0;
      std::array<unsigned int, NMAX> celMaiLungSubsirComun = {0};

      for (size_t i = neA, j = neB ; i;) {
        if (A[i] == B[j]) {
          celMaiLungSubsirComun[++lungimeCMLSC] = A[i];
          --i;
          --j;
        } else if (sol[i - 1][j] < sol[i][j - 1])
          --j;
        else
          --i;
      }

      outFile << lungimeCMLSC << '\n';
      for (int i = lungimeCMLSC; i; --i) 
        outFile << celMaiLungSubsirComun[i] << " ";

      outFile.close();

    } else
      std::cout << "Nu s-a putut scrie in fisier!" << std::endl;
    inFile.close();
  } else
    std::cout << "Nu s-a putut deschide fisierul!" << std::endl;
  return 0;
}