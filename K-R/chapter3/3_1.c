#include <stdio.h>

int binSearch(int x, int v[], int n)
{
	int		low = 0;
	int		high = n - 1;
	int		mid = (low + high) / 2;

	while (low <= high && x != v[mid]){
		if (x < v[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	return (low <= high ? mid : -1);
}

int main(void)
{
	int		arr[100];
	int		i = 0;
	int		index = 0;

	for (i = 0; i < 100; i++){
		arr[i] = i * 2;
	}

	index = binSearch(198, arr, 100);

	printf("%d\n", index);

	return 0;
}