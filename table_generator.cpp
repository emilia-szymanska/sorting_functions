#include <iostream>

//argv[1] - ziarno losowosci; argv[2] - ile liczb
int main(int argc, char **argv)
{
	if(argc < 3) 
		return 1;
	srand(atoi(argv[1]));
	
	std::cout << atoi(argv[2]) << std::endl; //jaki rozmiar tablicy

	for (int i = 0; i < atoi(argv[2]); i++)
	{
		std::cout << rand()%2000000 - 1000000 << " "; //liczby od -100 do 100 jako tablica
		
	}

	return 0;
}
