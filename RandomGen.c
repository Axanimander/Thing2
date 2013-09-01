  #include "Core.h"
 
int Randomly(int max)
 {
	srand(clock());
	return (int)rand() % max;
}
 
int getrand(int max, int min) //Generates a random number from 1 to int max 
 {
	int x = 0;
	int Random;
	
	if(max < min)
	{
		int temp;
		temp = max;
		max = min;
		min = temp;
	}
		for(;;)
		{
			x = clock();
			Random = Randomly(max);
			if(clock() != x)
			{
				Random = Randomly(max);
				
				refresh();
				
				if(Random >= min)
				{
					return Random;
				}
			
			}
		}
}
