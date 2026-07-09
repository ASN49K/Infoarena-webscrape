#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");


int* cmlsc (int lungime1, int lungime2, int* vector1, int* vector2,
		   int* lungimeMax) {

    *lungimeMax = 0;

    int* vectorMax;
    int* vectorCur;

    int lungimeCur = 0;;
    int pos1 = 0, pos2 = 0;
    int first = 1;

    while(pos1 != lungime1) {
		if (vector1[pos1] == vector2[pos2]) {
			if (first == 1) {
				vectorCur = vector1 + pos1;
				first = 0;
			}
			lungimeCur++;
			pos1++;
			pos2++;

		} else {
			if (lungimeCur > *lungimeMax) {
				vectorMax = vectorCur;
				*lungimeMax = lungimeCur;
			}
			lungimeCur = 0;
			if(first == 0) {
				pos2 = 0;
				first = 1;
			} else {
				if (pos2 == lungime2 - 1) {
					pos2 = 0;
					pos1++;
				} else {
					pos2++;
				}

			}
		}

    }

	if (lungimeCur > *lungimeMax) {
		vectorMax = vectorCur;
		*lungimeMax = lungimeCur;
    }


    return vectorMax;
}



int main() {

    int lungime1;
    int lungime2;
    in >> lungime1;
    in >> lungime2;

    int* vector1 = new int[lungime1];
    int* vector2 = new int[lungime2];

    int i;
    for (i = 0; i < lungime1; i++) {
        in >> vector1[i];
    }
    for (i = 0; i < lungime2; i++) {
        in >> vector2[i];
    }


    int lungimeMax;
    int* vectorMaxMain;

    vectorMaxMain = cmlsc(lungime1, lungime2, vector1, vector2, &lungimeMax);

    out << lungimeMax << "\n";
    for (i = 0; i < lungimeMax - 1; i++) {
		out << vectorMaxMain[i] << " ";
    }
    out << vectorMaxMain[lungimeMax - 1] << "\n";

    return 0;
}
