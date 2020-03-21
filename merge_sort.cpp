#include <iostream>
using namespace std;

template <typename T>
T * sorting_function (T *tab, unsigned int index_left, unsigned int index_right)
{
	unsigned int index_middle;
	
	if (index_left < index_right) index_middle = (index_left + index_right) / 2;
	else return tab;

	sorting_function(tab, index_left, index_middle);
	sorting_function(tab, index_middle + 1, index_right);

	T *tab_tmp = new T [index_right - index_left + 1 ];
	
	unsigned int index_tmp = 0;
	unsigned int tmp_left = index_left;
	unsigned int tmp_right = index_middle + 1;

	while (tmp_left != index_middle + 1 || tmp_right != index_right + 1)
	{
		if (tmp_left == index_middle + 1)
		{
		       while(tmp_right != index_right + 1)
		       {
			       tab_tmp[index_tmp] = tab[tmp_right];
			       tmp_right++;
			       index_tmp++;
		       }
		}
	 	else if(tmp_right == index_right + 1)
		{
			while(tmp_left != index_middle + 1)
		        {
			       tab_tmp[index_tmp] = tab[tmp_left];
			       tmp_left++;
			       index_tmp++;
		        }
		}
		else
		{	
			if (tab[tmp_left] > tab[tmp_right]) 
			{
				tab_tmp[index_tmp] = tab[tmp_right];
			       	tmp_right++;
			}
			else
			{
				tab_tmp[index_tmp] = tab[tmp_left];
				tmp_left++;
			}
			index_tmp++;
		}	
	}


	index_tmp = 0;
	
	while(index_tmp != index_right - index_left + 1)
	{
		tab[index_left + index_tmp] = tab_tmp[index_tmp];
		index_tmp++;
	}		


	delete [] tab_tmp;
	
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






