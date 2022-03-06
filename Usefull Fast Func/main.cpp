#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int power(int x, int y)
{
     
    // Initialize answer
    int res = 1;
     
    // Check till the number becomes zero
    while (y)
    {
         
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
             
        // y = y/2
        y = y >> 1;
         
        // Change x to x^2
        x = (x * x);
    }
    return res;
}


int main(int argc, char** argv) {
	cout<<power(2,8)<<endl;
	int k = 6;
	k=1<<k;
	cout<<k;
	return 0;
}
