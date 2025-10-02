#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int v) {
        val = v;
        next = nullptr;
    };
    Node(int v, Node *nxt) {
        val = v;
        next = nxt;
    };
    Node() {
        next = nullptr;
    };
};

class LinkedList {
    private:
        Node *head = nullptr;
    
    public:
        void push_head(int x) {
            Node *newNode = new Node(x, head);
            head = newNode;
        }

        void push_back(int x) {
            Node *temp = head;
            Node *newNode = new Node(x);
            if (temp == nullptr) {
                head = newNode;
                return;
            }
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        Node* remove_head() {
            if(head == nullptr)
                return nullptr;
            Node *removed = head;
            head = head->next;
            return removed;
        }

        Node* remove_back() {
            if(head == nullptr)
                return nullptr;
            Node *prev = head;
            Node *removed = head;
            while(removed->next != nullptr) {
                prev = removed;
                removed = removed->next;
            }
            prev->next = nullptr;
            return removed;
        }

        void print() {
            Node *temp = head;
            if(temp == nullptr)
                return;
            while (temp != nullptr) {
                cout << temp->val << (temp->next != nullptr ? "->" : "");
                temp = temp->next;
            }
            cout << endl;
        }

        int get_head() {
            if(head == nullptr)
                return -1;
            return head->val;
        }
};

class Stack {
    private:
        LinkedList* linkedList;
    
    public:
    Stack() {
        linkedList = new LinkedList();
    }

    void push(int val) {
        linkedList->push_head(val);
    }

    int pop() {
        Node* removed = linkedList->remove_head();
        return removed->val;
    }

    int peek() {
        return linkedList->get_head();
    }

    void print() {
        linkedList->print();
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
    stack->print();
}