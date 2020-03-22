#include "quick_sort.hh"

int main()
{
	int n;
	
	cin >> n;
	
	int *tablica = new int [n];
	
	for (int i = 0; i < n; i++) cin >> tablica[i];

	sorting_function(tablica, 0, n-1);
	
	cout << n << endl;
	for (int i = 0; i < n; i++) cout << tablica[i] << " ";
	cout<<endl;

	delete [] tablica;

	return 0;

}




