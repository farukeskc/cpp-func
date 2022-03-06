#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Element {
	public:
		int i, j, x;
};

class Sparse {
	private:
		int m, n, num;
		Element *e;
	public:
		Sparse(int m, int n, int num) {
			this->m=m;
			this->n=n;
			this->num=num;
			e = new Element[this->num];
		}
	~Sparse(){
		delete [] e;
	}
	
	istream & operator>>(istream &is, Sparse &s);
	ostream & operator<<(ostream &os, Sparse &s);
	
};
	void read() {
		cout<<"Enter all elements"<<endl;
		for(int i = 0 ; i < num ; i++) {
			cin>>e[i].i>>e[i].j>>e[i].x;
		}
	}
	
	void display() {
		int k=0;
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if (e[k].i == i && e[k].j == j) {
					cout<<e[k].x<<' ';
				}
				else {
					cout<<"0 ";
				}
			}
			cout<<endl;
		}
	}
};

void create(Sparse *s) {
	
}

int main(int argc, char** argv) {
	
	Sparse s1(5,5,5);
	s1.read();
	s1.display();
		
	return 0;
}
