#include "List.h"

/*

class List {
private:
	Node* head;
	Node* cur;
	Node* before;
	int numofData;
public:
	List();
	bool LFisrt(int* pdata);
	bool LNext(int* pdata);
	void Insert(int data);
	int remove();
};  

*/

List::List() {
	head = new Node;
	head->next = nullptr;
	cur = nullptr;
	before = nullptr;
	numofData = 0;
}

void List::Insert(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head->next;
	head->next = newNode;
	numofData++;
}

bool List::LFisrt(int* pdata) {
	if (head->next == nullptr)
		return false;
	else {
		before = head;
		cur = head->next;
		*pdata = cur->data;
		return true;
	}
}

bool List::LNext(int* pdata) {
	if (cur->next == nullptr)
		return false;
	else {
		before = cur;
		cur = cur->next;
		*pdata = cur->data;
		return true;
	}
}

int List::remove() {   //remove�� ���ÿ� �ι� �� �� ������ ������ remove�� LNext���� ������ ����Ǿ�� ��
	Node* tmp = cur;
	int tmpdata = cur->data;
	before->next = cur->next;
	cur = before;
	delete tmp;
	numofData--;
	return tmpdata;
}