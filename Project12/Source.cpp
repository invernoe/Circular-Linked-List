#include <iostream>
using namespace std;

struct node {
	int key;
	struct node* next = NULL;
};

struct list {
	node* head = NULL;
};

int getListSize(list &L) {
	int count = 1;
	node x = *L.head;

	if (L.head == NULL)
		return 0;

	while (x.next != L.head) {
		x = *x.next;
		count++;
	}
	return count;
}

void insert(list &L, node &x) {
	node* last;
	if (L.head == NULL) {
		L.head = &x;
		x.next = L.head;
	}
	else {
		last = L.head;
		int count = 0;
		while (count < getListSize(L) - 1) {
			last = (*last).next;
			count++;
		}
		x.next = L.head;
		L.head = &x;
		(*last).next = L.head;
	}
}

node search(list &L, int val) {
	node x = *L.head;
	if (x.key == val)
		return x;
	x = *x.next;
	while (&x != L.head && x.key != val) {
		x = *x.next;
	}
	return x;
}

void deleteNode(list &L, node &x) {
	node y = *L.head;

	if (&x == L.head) {
		int count = 0;
		while (count < getListSize(L) - 1)
			y = *y.next;
		L.head = x.next;
		y.next = L.head;
	}
	else {
		while (y.next != &x)
			y = *y.next;
		y.next = x.next;
	}
}

void showList(list &L) {
	node x = *L.head;
	for (int i = 0; i < getListSize(L); i++)
	{
		cout << x.key << "\t";
		x = *x.next;
	}
	cout << endl;
}

int main() {
	list L;
	node a[4];
	for (int i = 0; i < 4; i++)
	{
		a[i].key = i;
		insert(L, a[i]);
	}
	showList(L);
	system("pause");
}