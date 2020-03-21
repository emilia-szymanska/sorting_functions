#include <iostream>

int main()
{
	int n;
	
	std::cin >> n;
	
	int *tablica = new int [n];
	
	for (int i = 0; i < n; i++) std::cin >> tablica[i];
	
	for (int i = 0; i < n - 1; i++) 
	{
		if(tablica[i] > tablica[i+1])
		{
			delete [] tablica;
			return 1;
		}
	}	
	
	delete [] tablica;

	return 0;
}	
