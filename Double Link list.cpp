#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}
*start;
/*
Class Declaration
*/
class double_llist
{
private:
	node* head = NULL;
	node* current_ptr = NULL;
	int count;
public:
	node* insert_at_begin(int value, node* temp) {
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			head = temp;
			current_ptr = temp;
			temp->next = NULL;
			temp->prev = NULL;

		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->data = value;
			current_ptr->next = temp;
			temp->prev = current_ptr;
			temp->next = NULL;
		}
		return  temp;
	}
	void insert_after(int value, int position) {
		node* Temp = head;
		int counter = 0;
		node* temp2 = NULL;
		node* temp1 = new node;
		while (Temp != NULL) {
			if (position == 0) {
				temp1->data = value;
				temp1->prev = Temp;
				temp2 = Temp;
				temp2 = temp2->next;
				temp1->next = temp2;
				Temp->next = temp1;
				break;
			}
			if (count == position) {
				temp1->prev = Temp;
				temp2 = Temp;
				temp2 = temp2->next;
				temp1->data = value;
				temp1->next = temp2;
				Temp->next = temp1;
				break;
			}
			Temp = Temp->next;
			count = count + 1;
		}
	}
	void insert_at_end(int value) {
		node* temp = current_ptr;
		temp = temp->next;
		node* temp1 = new node;
		temp1->data = value;
		temp->next = temp1;
		temp1->prev = temp;
		temp1->next = NULL;
	};
	void delete_at_begin() {
		node* temp = head;
		temp = temp->next;
		delete head;
		head = temp;
		temp->prev = NULL;
	};
	void delete_before(int value) {
		node* Temp = head;
		node* temp2 = NULL;
		node* temp3 = NULL;
		while (Temp != NULL) {
			if (Temp->data == value) {
				temp3 = Temp;
				temp2 = Temp;
				temp2 = temp2->prev;
				temp3 = temp3->next;
				delete Temp;
				temp3->prev = temp2;
				temp2->next = temp3;
				break;
			}
			Temp = Temp->next;
		}
	};
	void delete_at_end() {
		node* temp = current_ptr;
		temp = temp->next;
		delete temp;
		current_ptr->next = NULL;
	};
	void display_dlist(node* Temp) {
		Temp = head;
		cout << "Your Data is ";
		cout << endl;
		while (Temp != NULL) {
			cout << Temp->data << " ";
			Temp = Temp->next;
		}

	}
	bool is_empty();
	double_llist()
	{
		head = NULL;
		current_ptr = NULL; //constructor for my class
		count = 0;
	}
	~double_llist() {
		current_ptr = head;
		while (current_ptr != NULL)
		{
			node* next = current_ptr->next;
			delete current_ptr;
			current_ptr = next;

		}
	}
};
int main() {
	node* NODE = NULL;
	double_llist a;
	for (int i = 0; i < 10; i++) {
		NODE = a.insert_at_begin(i, NODE);
	}
	a.display_dlist(NODE);
	cout << endl << "After inserting at 1st position " << endl;
	a.insert_after(100000, 1);
	a.display_dlist(NODE);
	cout << endl << "After inserting at last position " << endl;
	a.insert_at_end(100);
	a.display_dlist(NODE);
	cout << endl << "delete at 0 position" << endl;
	a.delete_at_begin();
	a.display_dlist(NODE);
	cout << endl << "delete at last position" << endl;
	a.delete_at_end();
	a.display_dlist(NODE);
	cout << endl << "delete at 5 position" << endl;
	a.delete_before(6);
	a.display_dlist(NODE);
	system("pause");
	return 0;
}
