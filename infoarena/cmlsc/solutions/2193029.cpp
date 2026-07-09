#include <iostream>
#include <fstream>
#include <unordered_set>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int s1, s2;
int sir1[20], sir2[20];

void read() {

	fin >> s1 >> s2;
	for (int i = 1; i <= s1; i++) {
		fin >> sir1[i];
	}
	for (int i = 1; i <= s2; i++) {
		fin >> sir2[i];
	}

}


int main()
{
	read();
	int result[20];
	int index = 0;

	int length = 0;
	for (int i = 1; i <= s1; i++) {

		for (int j = 1; j <= s2; j++) {
			if (sir1[i] == sir2[j]) {
				length++;
				result[index] = sir1[i];
				index++;
				break;
			}
		}
	}
	fout << length << '\n';
	for (int k = 0; k < sizeof(result) / sizeof(result[0]); k++) {
		if (result[k] > 0)
			fout << result[k] << " ";
	}


	system("pause");
	return 0;
}