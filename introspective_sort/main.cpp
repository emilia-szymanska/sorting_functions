#include "introspective_sort.hh"
#include <ctime>
#include <iomanip>

int main()
{
	int n;
	cin>>n;
	
	int *tablica = new int [n];
	
	for (int i = 0; i < n; i++) cin>>tablica[i];

	clock_t begin = clock();

	introsort(tablica, n);
	
	clock_t end = clock();


//	timing = (end - begin)/((double)CLOCKS_PER_SEC/1000);

//	cout << fixed << setprecision(5) << timing << endl;	
	

	cout<<n<<endl;
	for (int i = 0; i < n; i++) cout<<tablica[i]<<" ";
	cout<<endl;
	
	delete [] tablica;

	return 0;
}






