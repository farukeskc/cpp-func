#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class LinkedList {
	private:
		Node *first;
	public:
		LinkedList(){first=NULL;};
		LinkedList(int A[], int n);
		~LinkedList();
		void Display();
		bool IsSorted();
		void ReverseList();
		void Insert(int index, int x);
		int Length();
		int MiddleElement();
};

LinkedList::LinkedList(int A[], int n) {
	Node *t, *last;
	this->first = new Node;
	this->first->data = A[0];
	this->first->next = NULL;
	last = first;
	
	for(int i = 1 ; i < n ; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

LinkedList::~LinkedList(){
	Node *p=first;
 	while(first){
 		first=first->next;
 		delete p;
 		p=first;
 	}
}

void LinkedList::Display(){
	Node *p = first;
	while(p) {
		cout<<p->data<<' ';
		p = p->next;
	}
	cout<<endl;
}

void LinkedList::Insert(int index, int x){
	Node *p = first;
	
	Node *t = new Node;
	
	t->data=x;
	t->next=NULL;
	
	for(int i = 0 ; i < index-1 ; i++) {
		p = p->next;
	}
	
	t->next = p->next;
	p->next = t;
}

bool LinkedList::IsSorted(){
	Node *p = first;
	Node *q = NULL;
	
	while(true) {
		q = p;
		p = p->next;
		if(p != NULL) {
			if(q->data > p->data) {
				return false;
			}
		} else {
			return true;
		}
	}	
}

int LinkedList::Length(){
	Node *p = first;
	int len=0;
	while(p) {
		len++;
		p = p->next;
	}
	return len;
}

void LinkedList::ReverseList(){
	Node *r = NULL, *q = NULL;
	Node *p = first;
	while(p != NULL){
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

int LinkedList::MiddleElement(){
	Node *q = first, *p = first;
	while(p) {
		p=p->next;
		if(p) p=p->next;
		else return q->data; 
		q = q->next;
	}
	return q->data;
}

int main(int argc, char** argv) {
	int A[]={11,22,33,44,55,66};
	LinkedList L1(A, 6);
	
	L1.Insert(6, 77);
	
	L1.Display();
	
	L1.ReverseList();
	
	L1.Display();
	
	cout<<"Middle Element of Linked List: "<<L1.MiddleElement()<<endl;
	
	//cout<<L1.Length()<<endl;
	
	//cout<<L1.IsSorted()<<endl;
	
	return 0;
}
