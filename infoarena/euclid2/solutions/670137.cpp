#include<iostream>
#include<fstream>

using namespace std;
	
 ifstream F("euclid2.in");
 ofstream G("euclid2.out");

void calcul()
	{int A, B, R;
	 F>>A>>B;
		while(B)
		{R=A%B;
		 A=B;
		 B=R;
		}
     G<<A<<"\n";
	}

int main()
{int N,I;
 
 F>>N;
 for(I=0; I<N; ++I)
	calcul();

	return 0;
}
