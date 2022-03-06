#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Node{
	public:
		Node *prev;
		int data;
		Node *next;
};

class DoublyLinkedList{
	private:
		Node *first;
	public:
		DoublyLinkedList(){first = NULL;};
		DoublyLinkedList(int A[], int  n);
		~DoublyLinkedList();
		void Display();
		void Reverse();
};

DoublyLinkedList::DoublyLinkedList(int A[], int n){
	this->first = new Node;
	this->first->prev = NULL;
	this->first->data = A[0];
	this->first->next = NULL;
	Node *p = first, *t;
	for(int i = 1 ; i < n ; i++) {
		t = new Node;
		t->prev = p;
		t->data = A[i];
		t->next = NULL;
		p->next = t;
		p=t;	
	}
}

DoublyLinkedList::~DoublyLinkedList() {
	Node *p=first;
 	while(first){
 		first=first->next;
 		delete p;
 		p=first;
 	}
}

void DoublyLinkedList::Reverse(){
	Node *temp, *p = first, *last;
	while(p) {
		last=p;
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
	}
	first=last;
}

void DoublyLinkedList::Display(){
	Node *p = first, *last;
	while(p != NULL) {
		cout<<p->data<<' ';
		last = p;
		p=p->next;
	}
	p=last->prev;
	while(p != NULL){
		cout<<p->data<<' ';
		p=p->prev;
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	int A[]={11,22,33,44,55};
	DoublyLinkedList L1(A, 5);
	L1.Display();
	L1.	Reverse();
	L1.Display();
	return 0;
}
