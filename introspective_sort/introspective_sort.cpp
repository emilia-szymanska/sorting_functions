template <typename T>
T * heapsort (T * tab, unsigned int index_left, unsigned int index_right)
{		
	unsigned int length = index_right - index_left + 1;
	Heap<T>kopczyk = Heap<T>(length);
	
	for(unsigned int i = index_left; i <= index_right; i++) 
	{
		kopczyk.addToHeap(tab[i]);
	}
	
	for(unsigned int i = index_right; i >= index_left; i--)
	{
		tab[i] = kopczyk.seeRoot();		
		kopczyk.takeFromHeap();
		if(i == 0) break; 	//due to unsigned int
	}
	
	return tab;
	
}

template <typename T>
int quicksort_partition (T *tab, unsigned int index_left, unsigned int index_right)
{
	T middle_value;
	
	unsigned int  middle_index = (index_left + index_right) / 2; 

	if (index_left < index_right) middle_value = tab[middle_index];

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

	return partition_index;
}


template <typename T>
T * insertion_sort (T *tab, unsigned int index_left, unsigned int index_right)
{
	int tmp, j;
	int length = index_right - index_left + 1;
	for(int i = 0; i < length; i++)
	{
		tmp = tab[i];
		j = i - 1;
		while(j >= 0 && tab[j] > tmp)
		{
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = tmp;
	}
	return tab;	
}	


template <typename T>
T * sorting_function (T *tab, unsigned int index_left, unsigned int index_right, int recursion)
{
	int p_index;
	if(recursion <= 0)
	{
		heapsort(tab, index_left, index_right);
		return tab;
	}
	p_index = quicksort_partition(tab, index_left, index_right);

	if(p_index - index_left > 9) 
	{
		if(p_index == 0) sorting_function(tab, index_left, p_index, recursion - 1);
		else sorting_function(tab, index_left, p_index - 1, recursion - 1);
	}	
        if(index_right - p_index > 9) sorting_function(tab, p_index + 1, index_right, recursion - 1);	

	return tab;
}

template <typename T>
void introsort (T *tab, unsigned int length)
{
	sorting_function(tab, 0, length - 1, log2(length));
	insertion_sort(tab, 0, length - 1);
}	


