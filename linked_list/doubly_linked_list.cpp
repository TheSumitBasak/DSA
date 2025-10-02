#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    };
    Node(int v, Node *next, Node *prev) {
        val = v;
        next = next;
        prev = prev;
    };
    Node() {
        next = nullptr;
        prev = nullptr;
    };
};

class LinkedList {
    private:
        Node *head = nullptr;
    
    public:
        void push_head(int x) {
            Node *newNode = new Node(x, head, nullptr);
            if(head != nullptr)
            head->prev = newNode;
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
            newNode->prev = temp;
        }

        Node* remove_head() {
            if(head == nullptr)
                return nullptr;
            Node *removed = head;
            head = head->next;
            head->prev = nullptr;
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
                cout << temp->val << (temp->next != nullptr ? "<->" : "");
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList *linkedList = new LinkedList();
    linkedList->push_head(10);
    linkedList->push_head(20);
    linkedList->push_back(50);
    linkedList->print();
    cout << "Removed Back: " << linkedList->remove_back()->val << endl;
    linkedList->print();
    linkedList->push_back(30);
    linkedList->push_back(40);
    linkedList->print();
    cout << "Removed Head: " << linkedList->remove_head()->val << endl;
    linkedList->print();
}