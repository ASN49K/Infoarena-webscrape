
#include <fstream>

const unsigned short MAX_LENGTH(1025);

unsigned short length_matrix [MAX_LENGTH] [MAX_LENGTH];

inline void largest_common_substring (unsigned short *v1, unsigned short v1_size, unsigned short *v2, unsigned short v2_size)
{
	unsigned short v1_iterator, v2_iterator;
	for (v1_iterator = 1 ; v1_iterator < v1_size ; ++v1_iterator)
		for (v2_iterator = 1 ; v2_iterator < v2_size ; ++v2_iterator)
			if (v1[v1_iterator] == v2[v2_iterator])
				length_matrix[v1_iterator][v2_iterator] = length_matrix[v1_iterator][v2_iterator - 1] + 1;
			else
				length_matrix[v1_iterator][v2_iterator] = (length_matrix[v1_iterator][v2_iterator - 1] < length_matrix[v1_iterator - 1][v2_iterator] ? length_matrix[v1_iterator - 1][v2_iterator] : length_matrix[v1_iterator][v2_iterator - 1]);
}

int main (void)
{
	unsigned short v1_size, v2_size;
	std::ifstream input("cmlsc.in");
	input >> v1_size >> v2_size;
	++v1_size;
	++v2_size;
	unsigned short *v1(new unsigned short [v1_size]);
	unsigned short *iterator(v1 + 1), *end(v1 + v1_size);
	do
	{
		input >> *iterator;
		++iterator;
	}
	while (iterator < end);
	unsigned short *v2(new unsigned short [v2_size]);
	iterator = v2 + 1;
	end = v2 + v2_size;
	do
	{
		input >> *iterator;
		++iterator;
	}
	while (iterator < end);
	input.close();
	largest_common_substring(v1,v1_size,v2,v2_size);
	--v1_size;
	--v2_size;
	unsigned short lcs_size(length_matrix[v1_size][v2_size]);
	unsigned short *substring(new unsigned short [lcs_size]);
	end = iterator = substring + lcs_size - 1;
	std::ofstream output("cmlsc.out");
	output << lcs_size << '\n';
	while (true)
	{
		if (v1[v1_size] == v2[v2_size])
		{
			*iterator = v1[v1_size];
			if (iterator == substring)
				break;
			--iterator;
			--v1_size;
			--v2_size;
		}
		else if (length_matrix[v1_size][v2_size] == length_matrix[v1_size - 1][v2_size])
			--v1_size;
		else
			--v2_size;
	}
	while (true)
	{
		output << *iterator;
		if (iterator == end)
			break;
		output.put(' ');
		++iterator;
	}
	output.put('\n');
	output.close();
	delete [ ] v1;
	delete [ ] v2;
	delete [ ] substring;
	return 0;
}

