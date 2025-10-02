#include<iostream>
#include<vector>

using namespace std;

class Stack {
    private:
        vector<int> stack;
    
    public:
    void push(int val) {
        stack.push_back(val);
    }

    int pop() {
        int val = stack[stack.size() - 1];
        stack.pop_back();
        return val;
    }

    int peek() {
        return stack[stack.size() - 1];
    }

    int search(int x) {
        int size = stack.size();
        for (int i = 0; i < size; i++)
            if(stack[i] == x)
                return i;
        return -1;
    }

    void print() {
        int size = stack.size();
        for (int i = 0; i < size; i++)
                cout << stack[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack *stack = new Stack();
    stack->push(9);
    stack->push(4);
    cout << "Pop: " << stack->pop() << endl;
    cout << "Peek: " << stack->peek() << endl;
    stack->push(17);
    stack->push(7);
    cout << "Search 17: " << stack->search(17) << endl;
    cout << "Search 4: " << stack->search(4) << endl;
    stack->print();
}