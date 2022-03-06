#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Node {
	public:
		Node *lchild;
		int data;
		Node *rchild;
};

Node *root = NULL;

Node* Insert(Node *root, int key){
	Node *t=root;
	Node *r = NULL, *p;
	if(root == NULL) {
		p = new Node;
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return root;;
	}
	while(t!=NULL) {
		r = t;
		if(key > t->data) {
			t = t->rchild;
		}
		else if(key < t->data) {
			t = t->lchild;
		}
		else {
			return NULL;
		}
	}
	p = new Node;
	p->data = key;
	p->lchild = p->rchild = NULL;
	if(key < r->data) r->lchild = p;
	else r->rchild = p; 
}

void Inorder(Node *p) {
	if(p){
 		Inorder(p->lchild);
 		cout<<p->data<<' ';
 		Inorder(p->rchild);
 	}
}

int Height(Node *p){
	int x,y;
	if(p == NULL) return 0;
	x=Height(p->lchild);
	y=Height(p->rchild);
	return x+y+1;
}

Node* InPre(Node *p) {
	while(p && p->rchild != NULL) {
		p=p->rchild;
	}
	return p;
}

Node* InSucc(Node *p) {
	while(p && p->lchild != NULL) {
		p=p->lchild;
	}
	return p;
}

Node* Delete(Node *p, int key) {
	Node *q;
	if(p == NULL) {
		return NULL;
	}
	if(p->lchild==NULL && p->rchild==NULL){
		if(p==root){
			root = NULL;
		}
		delete(p);
		return NULL;
	}
	
	if(key < p->data) {
		p->lchild = Delete(p->lchild, key);
	} else if(key > p->data) {
		p->rchild = Delete(p->rchild, key);
	} else {
		if(Height(p->lchild) > Height(p->rchild)) {
			q=InPre(p->lchild);
			p->data = q->data;
			p->lchild=Delete(p->lchild, q->data);
		} else {
			q=InSucc(p->rchild);
			p->data = q->data;
			p->rchild=Delete(p->rchild, q->data);
		}
	}
}

int main(int argc, char** argv) {
	root = Insert(root, 20);
	Insert(root, 30);
	Insert(root, 10);
	Insert(root, 15);
	Delete(root, 30);
	Inorder(root);
	return 0;
}
