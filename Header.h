struct node{
	int data;
	node *next;
	node(int, node *);
};

class list{
	node *head;
public:
	list();
	node*get_head()const{
		return head;
	}
	void insert_node_circ(int);
	void insert_node(int);
	void traverse();
	void traverse_circ();
	void list::add_after_parti_node(int,int);
	void list::list_length();
	void delete_parti_node(int);
	void delete_node_circ();
	void delete_node();
	void swap(int, int);
};

void check_circ(list *);