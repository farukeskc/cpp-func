#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Node {
	public:
		Node *lchild;
		int data;
		Node *rchild;
};

class Queue{
	private:
		int front;
		int rear;
		int size;
		Node **Q;
	public:
		Queue(){
			front = rear = -1;
			size = 10;
			Q = new Node*[size];
		}
		Queue(int size){
			front = rear = -1;
			this->size = size;
			Q = new Node*[this->size];
		};
		void enqueue(Node* x);
		Node* dequeue();
		bool isEmpty(){
			return front == rear;
		}
		void Display();
};

void Queue::enqueue(Node* x){
	if(rear==size-1) {
		cout<<"Queue is Full"<<endl;
	} else {
		rear++;
		Q[rear] = x;
	}
}

Node* Queue::dequeue(){
	Node* x = NULL;
	if(front == rear) {
		cout<<"Queue is Empty"<<endl;
	} else {
		x=Q[front+1];
		front++;
	}
	return x;
}

void Queue::Display(){
	for(int i = front+1 ; i <= rear ; i++){
		cout<<Q[i];;
	}
	cout<<endl;
}

class Tree{
	public:
		Node *root;
		Tree() {
			root = NULL;
		}
		void CreateTree();
		void Preorder(Node *p);
		void Postorder(Node *p);
		void Inorder(Node *p);
		void Levelorder(Node *p);
		int Height(Node *p);
};

void Tree::CreateTree(){
	Node *p, *t;
	int x;
	Queue q(100);
	
	cout<<"Enter root value ";
	cin>>x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);
	
	while(!q.isEmpty()) {
		p=q.dequeue();
		cout<<"Enter the data of left child of "<<p->data<<' ';
		cin>>x;
		if(x!=-1){
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}
		cout<<"Enter the data of right child of "<<p->data<<' ';
		cin>>x;
		if(x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}

void Tree::Preorder(Node *p) {
	if(p) {
		cout<<p->data<<' ';
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Tree::Inorder(Node *p) {
	if(p) {
		Inorder(p->lchild);
		cout<<p->data<<' ';
		Inorder(p->rchild);
	}
}

void Tree::Postorder(Node *p) {
	if(p) {
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout<<p->data<<' ';
	}
}

int Tree::Height(Node *p) {
	int x =0, y = 0;
	if(root == 0) {
		return 0;
	}
	x = Height(root->lchild);
	y = Height(root->rchild);
	if(x > y){
		return x+1;
	}
	else {
		return y+1;
	}
}

void Tree::Levelorder(Node *p) {
	Queue q(100);
	
	cout<<root->data<<' ';
	q.enqueue(root);
	
	while(!q.isEmpty()) {
		root = q.dequeue();
		if(root->lchild) {
			cout<<root->lchild->data<<' ';
			q.enqueue(root->lchild);
		}
		if(root->rchild) {
			cout<<root->rchild->data<<' ';
			q.enqueue(root->rchild);
		}
	}
}

int main(int argc, char** argv) {
	
	Tree t;
	
	t.CreateTree();
	t.Preorder(t.root);
	cout<<endl;
	t.Inorder(t.root);
	cout<<endl;
	t.Postorder(t.root);
	cout<<endl;
	t.Levelorder(t.root);
	
	return 0;
}
