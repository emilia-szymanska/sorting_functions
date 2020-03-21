#include <iostream>
using namespace std;

template <typename T>
T * sorting_function (T *tab, unsigned int index_left, unsigned int index_right)
{
	T middle_value;
	
	unsigned int  middle_index = (index_left + index_right) / 2; 

	if (index_left < index_right) middle_value = tab[middle_index];
	else return tab;


	T *tab_tmp = new T [index_right - index_left + 1 ];
	unsigned int tmp_left = index_left;
	unsigned int tmp_right = index_right;
	
	for (unsigned int index_tmp = index_left; index_tmp <= index_right; index_tmp++)	
	{
		if(index_tmp == middle_index) continue;
		if(tab[index_tmp] > middle_value) 
		{
			tab_tmp[tmp_right - index_left] = tab[index_tmp];
			tmp_right--;
		}
		else
		{
			tab_tmp[tmp_left - index_left] = tab[index_tmp];
			tmp_left++;
		}	
	}

	unsigned int partition_index = tmp_left;
	tab_tmp[partition_index - index_left] = middle_value;

	for(unsigned int i = index_left; i <= index_right; i++)
	{
		tab[i] = tab_tmp[i - index_left];
	}

	delete [] tab_tmp;

	//wywolanie sortowania bez wartosci pod partition_index, ktora juz stoi na dobrym miejscu
	if(partition_index == 0) sorting_function(tab, index_left, partition_index); //zeby nie wywalilo uinta -1 na duza wartosc
	else sorting_function(tab, index_left, partition_index - 1);
	sorting_function(tab, partition_index + 1, index_right);

	return tab;
}


int main()
{
	int n;
	
	cin>>n;
	
	int *tablica = new int [n];
	
	for (int i = 0; i < n; i++) cin>>tablica[i];
	
	sorting_function(tablica, 0, n-1);
	
	cout<<n<<endl;
	for (int i = 0; i < n; i++) cout<<tablica[i]<<" ";
	cout<<endl;
	
	delete [] tablica;

	return 0;
}






