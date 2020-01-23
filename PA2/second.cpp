#include "second.h"
#include <vector>
#include <cmath>

second::second(int *d, int s){
	// Insert constructor here...
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = d[i];

	return;
}

int second::getSecond(void){
	int sec = 0x7FFFFFFF;
	// Insert source code for finding the second smallest item here...
	// find min value
	int min = data[0];
	for (int i = 1; i < size; i++)
		if (min > data[i])
			min = data[i];

	int matchSize = size;
	int index = -1;
	std::vector<int> candidate;

	do
	{
		index = -1;
		for (int i = 0; i < matchSize; i = i + 2)
		{
			index = index + 1;
			if (i + 1 >= matchSize)
			{
				data[index] = data[i];
				continue;
			}

			if(data[i] > data[i+1])
			{
				if (data[i + 1] == min)
				{
					candidate.push_back(data[i]);
				}
				data[index] = data[i + 1];
			}
			else
			{
				if(data[i] == min)
				{
					candidate.push_back(data[i + 1]);
				}
				data[index] = data[i];
			}
		}

		matchSize = matchSize / 2 + (matchSize % 2);
	} while (matchSize != 1);

	for (int i = 0; i < candidate.size();i++)
		if(candidate[i] < sec)
			sec = candidate[i];

	return sec;
}
