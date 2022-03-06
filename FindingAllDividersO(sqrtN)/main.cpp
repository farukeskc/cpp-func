#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

vector<int> findDividers(int n){
	vector<int> factors;
	for(int i = 2 ; i * i <= n ; i++) {
		if(n%i == 0) {
			factors.push_back(i);
			factors.push_back(n/i);
		}
	}
	return factors;
}

int main(int argc, char** argv) {
	
	vector<int> results = findDividers(25); 
	
	for(int i = 0 ; i < results.size() ; i++) {
		cout<<results.at(i)<<' ';
	}
	
	return 0;
}
