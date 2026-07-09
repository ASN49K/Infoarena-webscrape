#include <fstream>

using namespace std ;

fstream fin ( "euclid2.in" , ios::in ) , fout ( "euclid2.out" , ios::out ) ;

long long CMMDC ( long long PrimulNumar , long long AlDoileaNumar )
{
	long long Auxiliar ;

	if ( AlDoileaNumar == 0 )
		AlDoileaNumar = PrimulNumar ;
	else
	{
		Auxiliar = PrimulNumar % AlDoileaNumar ;

		while ( Auxiliar != 0 )
		{
			PrimulNumar = AlDoileaNumar ;
			AlDoileaNumar = Auxiliar ;
			Auxiliar = PrimulNumar % AlDoileaNumar ;
		}
	}

	if ( AlDoileaNumar == 1 )
		return 0 ;
	else
		return AlDoileaNumar ;
}

int main ()
{
	int NumarPerechi ;
	long long PrimulNumar , AlDoileaNumar ;

	fin >> NumarPerechi ;

	for ( int i = 0 ; i < NumarPerechi ; i++ )
	{
		fin >> PrimulNumar >> AlDoileaNumar ;
		fout << CMMDC ( PrimulNumar , AlDoileaNumar ) ; 
	}
	return 0 ;
}