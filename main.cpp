#include<iostream>
#include"Header.h"
using namespace std;

int main(){
	list ll;
	ll.insert_node(1);
	ll.insert_node(2);
	ll.insert_node(3);
	ll.insert_node(4);
	ll.insert_node(6);
	//ll.delete_node();
	ll.add_after_parti_node(5, 4);
	//ll.delete_node();
	ll.delete_parti_node(4);
	ll.traverse();
	//ll.swap(3, 5);
	cout << "=====================" << endl;
	ll.traverse();
	ll.list_length();


	list ll1;
	ll1.insert_node_circ(2);
	ll1.insert_node_circ(4);
	ll1.insert_node_circ(7);
    ll1.insert_node_circ(1);
    ll1.insert_node_circ(9);
    ll1.insert_node_circ(10);
//	ll1.delete_node_circ();
	ll1.traverse_circ();

	check_circ(&ll1);
	cin.get();
}