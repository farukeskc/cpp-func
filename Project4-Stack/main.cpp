#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
};

class Stack{
	private:
		Node *top;
	public:
		Stack(){this->top=NULL;}
		void Push(int x);
		int Pop();
		void Display();
};

void Stack::Push(int x){
	Node *t=new Node;
	if(t==NULL)
		cout<<"Stack is Full"<<endl;
	else {
		t->data = x;
		t->next = this->top;
		top = t;
	}
}

int Stack::Pop() {
	int x = -1;
	if(this->top == NULL) {
		cout<<"Stack is Empty"<<endl;
	}
	else {
		x =  top->data;
		Node *t = top;
		top = top->next;
		delete t;
	}
	return x;
}

void Stack::Display() {
	Node *p = top;
	while(p != NULL){
		cout<<p->data<<' ';
		p=p->next;
	}
}

int main(int argc, char** argv) {
	Stack st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Pop();AAAAAAAAAAAAAA
	st.Display();
	return 0;
}
