#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define mod 1000000007

using namespace std;

int Perm(long long n, long long k) {
	
	long long mult = 1, destination = n - k;
	
	while(n > destination) {
		mult *= n;
		n--;
	}
	
	return mult;
}

int main(int argc, char** argv) {
	cout<<Perm(10,4)<<endl;
	int k = 42;
	cout<<(k&1);
	return 0;
}
