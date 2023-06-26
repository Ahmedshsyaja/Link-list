#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
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
		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->data = value;
			current_ptr->next = temp;
			temp->next = head;
		}
		return  temp;
	}
	void Insert_At_Begin(node *NODE,int data) {
		node *temp = current_ptr;
		node* temp2 = head;
		node*temp3 = new node;
		temp3->data = data;
		temp = temp->next;
		temp->next = temp3;
		head = temp3;
		temp3->next = temp2;
	}
	void Inser_At_Last(node *NODE, int data) {
		node *temp = current_ptr;
		node*temp3 = new node;
		temp3->data = data;
		temp = temp->next;
		temp->next = temp3;
		temp3->next = head;

	}
	void Print() {
		cout << "Your Data is ";
		cout << endl;
		node*temp = head;
		cout << temp->data;
		temp = temp->next;
		while (temp != head) {
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
};
int main() {
	node* NODE = NULL;
	double_llist a;
	for (int i = 0; i < 6; i++) {
		NODE = a.insert_at_begin(i, NODE);
	}
	a.Print();
	cout << endl;
	cout << "Your Data after insertion at the Begin";
	a.Insert_At_Begin(NODE, 5);
	a.Print();
	cout << "Your Data after insertion at the last";
	cout << endl;
	a.Inser_At_Last(NODE, 100);
	a.Print();
	system("pause");
	return 0;
	return 0;
}
