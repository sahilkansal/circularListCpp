#include"Header.h"
#include<iostream>

using namespace std;

struct point{
	int x;
	int y;
};
node::node(int dat, node *lk){
	data = dat;
	next = lk;
}


list::list(){
	head = 0;
}

void list::insert_node_circ(int da){
	node *ptr = new node(da, head);
	if (head == 0){
		head = ptr;
		head->next = head;
	}
	//ptr->next = head;
	else{
		node *curr = head;
		while (curr->next != head)
			curr = curr->next;
		curr->next = ptr;
	}
}


void list::insert_node(int da){
	node *ptr = new node(da, 0);
	if (head == 0){
		head = ptr;
	}
	else{
		node *curr = head;
		while (curr->next != 0)
			curr=curr->next;
		curr->next = ptr;
	}
}


void list::delete_node_circ(){
	node *curr = head;
	if (head == 0){
		cout << "list is empty";
	}
	else if (head->next == head){
		int info = head->data;
		head = 0;
		cout << "deleted node info : " << info << endl;
	}
	else{
		while (curr->next->next != head)
			curr = curr->next;
		int info = curr->next->data;
		curr->next = head;
		cout << "deleted node info: " << info << endl;
	}
}


void list::delete_node(){
	node *curr = head;
	if (head == 0){ 
		cout << "list is empty"; 
	}
	else if (head->next == 0){ 
		int info = head->data; 
		head = 0; 
		cout << "deleted node info : " << info<<endl;
	}
	else{
		while (curr->next->next != 0)
			curr = curr->next;
		int info = curr->next->data;
		curr->next = 0;
		cout << "deleted node info: " << info<<endl;
	}
}

void list::traverse_circ(){
	node *curr = head;
	cout << "linklist elements are: " << curr->data << endl;
	curr = curr->next;
	while (curr != head){
		cout << "linklist elements are: " << curr->data << endl;
		curr = curr->next;
	}
}


void list::traverse(){
	node *curr = head;
	while (curr != 0){
		cout << "linklist elements are: "<<curr->data<<endl;
		curr = curr->next;
	}
}

void list::delete_parti_node(int dat){
	node *curr = head;
	node *prv = head;
	//if (head == 0){ cout << "list is " }
	if (curr!=0&&curr->data == dat){
		head = head->next;
	}
	else{
		while ((curr != 0 && curr->data != dat)){
			//cout << curr->data;
			prv = curr;
			curr = curr->next;
		}
	}
	if (curr == 0){ cout << "not element of list"<<endl; }
	else
		prv->next = curr->next;
}

void list::add_after_parti_node(int dat, int pos){
	node *curr = head;
	//node *temp = head;
	node *ptr = new node(dat, 0);
	if (pos == 0){
		ptr->next = head;
		head = ptr;
	}
	else{
		int flag = 0;
		while ((curr != 0)){
			//cout << curr->data;
			//prv = curr;
			if (curr->data == pos){
				flag++;
				ptr->next = curr->next;
				curr->next = ptr;
				//curr = curr->next;
			}
			curr = curr->next;
		}
		if (flag == 0){
			cout << pos<<"  "   <<"node not existed"<<endl;
		}
	}
}

void list::list_length(){
	int count = 0;
	node *curr = head;
	if (head == 0){ cout << "list is empty"; }
	else{
		while (curr->next != 0){
			count++;
			curr = curr->next;
		}
		cout << "length of list is :" << count + 1;
	}
}
void list::swap(int a, int b){
	node *prevx=NULL,*currx = head;
	while (currx->data != a){
		prevx = currx;
		currx = currx->next;
	}
	node *prevy = NULL, *curry = head;
	while (curry->data != b){
		prevy = curry;
		curry = curry->next;
	}
	if (prevx == NULL){
		head = curry;
	}
	else{
		prevx->next = curry;
	}
	if (currx == prevy){
		prevx->next = curry;
		//curry->next = currx;
	}
	//prevx->next = curry;
	node *temp = curry->next;
	curry->next = currx->next;
	prevy->next = currx;
	currx->next = temp;
	//cout << prevx->next<<"  "<<currx<<endl;
}


void check_circ(list *ptr){
	node*head = ptr->get_head();
	node*curr = head;
	while (curr->next != NULL&&curr->next != head)
		curr = curr->next;
	if (curr->next == head)
		cout << "circular link list" << endl;
	else
		cout << "not a circular link list" << endl;
}