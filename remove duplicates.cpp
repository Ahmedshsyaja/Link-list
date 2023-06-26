#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}
*start;
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
		return temp;
	}
	void Same() {

		int count=0;
		bool k = true;
		node* temp = head;
		node* temp1 = head;
		node* temp2 = NULL;
		node* temp3 = NULL;
		int same;
		while (temp != NULL) {
			if (temp == NULL) {
				break;
			}
			same = temp->data;
			temp1 = head;
				while (temp1!=NULL) {
					if (temp->data == temp1->data) {
						count = count + 1;
					}
						if (temp1->data == same && count > 1) {
							temp2 = temp1;
							temp3 = temp1;
							temp3 = temp3->prev;
							temp2 = temp2->next;
							temp3->next = temp2;
							if (temp2 == NULL) {
								k = false;
								delete temp1;
								count = 0;
								break;
							}
							temp2->prev = temp3;
							delete temp1;
							count = 0;
							break;
						}
					
					else {
						
						temp1 = temp1->next;
					}
			}
				if (k == false) {
					break;
				}
				count = 0;
				temp = temp->next;
					if (temp == NULL) {
						break;
					}
		}
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
			if (counter == position) {
				temp1->prev = Temp;
				temp2 = Temp;
				temp2 = temp2->next;
				temp1->data = value;
				temp1->next = temp2;
				Temp->next = temp1;
				break;
			}
			Temp = Temp->next;
			counter = counter + 1;
		}
	}
	node* insert_at_end(int value, node* NODE) {
		node* temp = new node;
		temp->data = value;
		NODE->next = temp;
		temp->prev = NODE;
		temp->next = NULL;
		return temp;
	};
	void delete_at_begin() {
		node* temp = head;
		if (temp->next == NULL) {
			delete temp;
			return;
		}
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
	node* delete_at_end(node* NODE) {
		node* temp = NODE;
		temp = temp->prev;
		delete NODE;
		temp->next = NULL;
		return temp;
	};
	void display_dlist(node* Temp) {
		Temp = head;
		cout << "Your Data is ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		while (Temp != NULL) {
			cout << Temp->data << " ";
			Temp = Temp->next;
		}
		cout << endl;
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
	
	
	NODE = a.insert_at_begin(1, NODE);
	NODE = a.insert_at_begin(2, NODE);
	NODE = a.insert_at_begin(5, NODE);
	NODE = a.insert_at_begin(3, NODE);
	NODE = a.insert_at_begin(4, NODE);
	NODE = a.insert_at_begin(5, NODE);
	NODE = a.insert_at_begin(3, NODE);
	NODE = a.insert_at_begin(1, NODE);
	NODE = a.insert_at_begin(2, NODE);
	NODE = a.insert_at_begin(2, NODE);
	a.display_dlist(NODE);
	a.Same();
	a.display_dlist(NODE);
	system("pause");
	return 0;
}
