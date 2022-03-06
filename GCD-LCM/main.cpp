#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int CalculateGCD(long long n, long long m) {
	if(n == 0)
		return m;
	return CalculateGCD(n%m, n);
}

int CalculateLCM(long long n, long long m){
	return n * m / CalculateGCD(n,m);
}

int main(int argc, char** argv) {
	cout<<CalculateGCD(12,8);
	return 0;
}
