#include <iostream>
#include <stack>

using namespace std;

class Queue2{
public:
	void append_element(char ch){
		stack1.push(ch);
	}

	bool is_queen_empty(){
		return (stack1.empty() && stack2.empty());
	}

	char delete_element(){
		char value;

		if (is_queen_empty()){
			cout << "empty queen! wrong operation";
			return 128;
		}

		if(stack2.empty()){
			while(!stack1.empty()){
				value = stack1.top();
				stack2.push(value);
				stack1.pop();
			}
		}

		value = stack2.top();
		stack2.pop();
		return value;
	}

private:
	stack<char> stack1;
	stack<char> stack2;
};

int main()
{
	Queue2 queue;
	char ch;

	queue.append_element('a');
	queue.append_element('b');
	queue.append_element('c');

	cout << queue.delete_element() << '\t';

	queue.append_element('b');
	queue.append_element('c');

	cout << queue.delete_element() << '\t';
	cout << queue.delete_element() << '\t';
	cout << queue.delete_element() << '\t';
	cout << queue.delete_element() << '\t';
	return 0;
}

/**
 * output:
 * a	b	c	b	c
 * */
