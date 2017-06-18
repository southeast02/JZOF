#include <iostream>
#include <queue>

using namespace std;

class Stack2{
public:
	void push(char ch){
		if(!queue1.empty() || queue2.empty()){
			queue1.push(ch);
		} else {
			queue2.push(ch);
		}
	}

	char pop(){
		char value;
		int size;

		if(queue1.empty() && queue2.empty()){
			cout << "empty stack, wrong operation." << endl;
			return 128;
		}

		if(!queue1.empty()){
			size = queue1.size() - 1;

			for(int i=0; i<size; i++){
				value = queue1.front();
				queue1.pop();
				queue2.push(value);
			}
			value = queue1.front();
			queue1.pop(); // queue.front() doesn't delete the tail item
			return value;
		}

		size = queue2.size() - 1;

		for(int i=0; i<size; i++){
			value = queue2.front();
			queue2.pop();
			queue1.push(value);
		}
		value = queue2.front();
		queue2.pop();// queue.front() doesn't delete the tail item
		return value;
	}

private:
	queue<char> queue1;
	queue<char> queue2;
};

int main()
{
	Stack2 stack;

	stack.push('a');
	stack.push('b');

	cout << stack.pop() << '\t';
	stack.push('c');
	stack.push('1');
	cout << stack.pop() << '\t';
	cout << stack.pop() << '\t';
	return 0;
}

/**
 * output:
 * b	1	c
 * */
