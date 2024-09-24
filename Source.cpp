#include<iostream>
#include<string>

using namespace std;

class Stack {
private:
	int top;
	char* items;
	int capacity;
public:
	Stack(int n);
	~Stack();
	bool isEmpty();
	bool isFull();
	void Push(int newItem);
	char Pop();
	void display();

};
Stack::Stack(int n) {
	capacity = n;
	items = new char[n];
	top = -1;
}
Stack::~Stack(){
	delete[] items;
}
bool Stack::isEmpty() {
	return (top == -1);
}
bool Stack::isFull() {
	return (top == capacity - 1);
}
void Stack::Push(int newItem) {
	if (isFull()) {
		cout << "STACK OVERFLOW" << endl;
		exit(1);
	}
	top++;
	items[top] = newItem;
}
char Stack::Pop() {
	if (isEmpty()) {
		cout << "STACK UNDERFLOW" << endl;
		exit(1);
	}
	char popVal = items[top];
	items[top] = 0;
	top--;
	cout << popVal;
	return popVal;
}
void Stack::display() {
	for (int i = top; i >= 0; i--) {
		cout << items[i]<<endl;
	}
}

int main() {
	string palindrome;
	string temp="";
	Stack newStack(100);
	cout << "Enter a string" << endl;
	getline(cin, palindrome);
	for (int i = 0; i < palindrome.length(); i++) {
		newStack.Push(palindrome[i]);
	}
	cout << "\nReversed String: ";
	while (!newStack.isEmpty()) {
		temp+=newStack.Pop();
	}
	if (palindrome == temp) {
		cout << "\nString is a palindrome";
	}
	else {
		cout << "\nString is not a palindrome";
	}
	return 0;
}