

#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};
class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = nullptr;
	}

	void insertAtHead(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		cout << "Element Inserted At Head" << endl;
	}
	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
			cout << "Inserted at Tail" << endl;

		}	}
	void print() {
		Node* temp = head;
		
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "Null" << endl;
		if (head == nullptr) {
			cout << "Empty List" << endl;
		}
	}
	void searchByValue(int key) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == key) {
				flag = true;
				break; // We can also use return but it will exit the function without printing the following statements
			}
			temp = temp->next;
		}
		if (!flag) {
			cout << "Element Not Found" << endl;
		}
		else if (flag) {
			cout << "Element Has Been Found" << endl;
		}
	}
	void updateValue(int old,int updated) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == old) {
				temp->data = updated;
				flag = true;
				break; // We can also use return but it will exit the function without printing the following statements
			}
			temp = temp->next;
		}
		if (!flag) {
			cout << "The list Don't Contain  "<<old<<" <- Value " << endl;
		}
		else if (flag) {
			cout << "Element Has Been Updated" << endl;
		}
		// We can use return on this line as it will print the statement
	}
	void countNodes() {
		Node* temp = head;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
			
		}
		cout << "The number of nodes are  : " << count << endl;
	}
	void updateValueByIndex(int index, int val) {
		Node* temp = head;
		int count = 1;
		bool flag = false;
		while (temp != nullptr) {
			if (count == index) {
				cout << "The value which is about to be changed is " << temp->data << endl;
				temp->data = val;
				cout << "The value at Index " << index << "  was changed To  " << val << endl;
				flag = true;
				break;
			}
			temp = temp->next;
			count++;
		}
		
		if (!flag) {
			cout << "Out of RAnge index" << endl;

		}
	}

	void deleteNode(int val) {
	
		if (head == nullptr) {
			cout << "nothing to delete " << endl;
			return;
		}
		if (head->data==val) {
			Node* del = head;
			head = head->next;
			delete del;
			return;
		}
		Node* temp = head;
	
		while (temp->next!=nullptr &&temp->next->data != val) {

			temp = temp->next;
		
		}
		if (temp->next == nullptr) {
			cout << "Element Not Found To Delete." << endl;
			return; // Add this line
		}
		Node* toDel = temp->next;
		temp->next = temp->next->next;
		
		delete toDel;
	}
};
int main()
{
	LinkedList L;
	L.insertAtHead(10);
	L.insertAtHead(70);
	L.insertAtTail(5);
	L.insertAtTail(20);


	L.updateValue(20, 15); // update by value
	L.searchByValue(15);   // searching by value
	L.countNodes();       // Counting Nodes
	L.print();
	L.updateValueByIndex(3, 58);     // updating by index
	L.print();
	L.deleteNode(10);           // deleting node 
	L.print();




}
