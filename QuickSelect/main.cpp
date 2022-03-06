#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int QuickSelect(int *arr, int size, int k) {
	swap(arr[size-1], arr[rand() % size]);
	int ind=0;
	for(int i = 0 ; i < size-1 ; i++) {
		if(arr[i] <= arr[size-1]) {
			swap(arr[i], arr[ind++]);
		}
	}
	swap( arr[size-1], arr[ind]);
	
	if(ind == k-1) {
		return arr[ind];
	} else if(ind > k-1) {
		QuickSelect(arr, ind, k);
	} else {
		QuickSelect(arr + ind + 1, size - ind -1, k - ind - 1);
	}
}

int main(int argc, char** argv) {
	int A[5] = {2,0,1,4,9};
	cout<<QuickSelect(A,5,5);
	return 0;
}
