#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int v) {
        val = v;
        next = prev = nullptr;
    }
    Node(int v, Node *nxt, Node* prv) {
        val = v;
        next = nxt;
        prev = prv;
    }
    Node() {
        next = prev = nullptr;
    }
};

class LinkedList {
    private:
        Node *head = nullptr;

    public:
        void push_head(int x) {
            if (head == nullptr) {
                head = new Node(x);
                head->next = head;
                head->prev = head;
                return;
            }
            Node *last = head->prev;
            Node *newNode = new Node(x, head, last);

            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }

        void push_back(int x) {
            if (head == nullptr) {
                head = new Node(x);
                head->next = head;
                head->prev = head;
                return;
            }
            Node *last = head->prev;
            Node *newNode = new Node(x, head, last);
            last->next = newNode;
            head->prev = newNode;
        }

        Node* remove_head() {
            if (head == nullptr) return nullptr;
            if (head->next == head) { // only one node
                Node* removed = head;
                head = nullptr;
                return removed;
            }
            Node *removed = head;
            Node *last = head->prev;
            head = head->next;
            head->prev = last;
            last->next = head;
            return removed;
        }

        Node* remove_back() {
            if (head == nullptr) return nullptr;
            if (head->next == head) { // only one node
                Node* removed = head;
                head = nullptr;
                return removed;
            }
            Node *removed = head->prev;
            Node *prev = removed->prev;
            prev->next = head;
            head->prev = prev;
            return removed;
        }

        void print() {
            if (head == nullptr) return;
            Node *temp = head;
            do {
                cout << temp->val;
                temp = temp->next;
                if (temp != head) cout << "<->";
            } while (temp != head);
            cout << endl;
        }
};

int main() {
    LinkedList *linkedList = new LinkedList();
    linkedList->push_head(10);
    linkedList->push_head(20);
    linkedList->push_back(50);
    linkedList->print();  // 20<->10<->50

    cout << "Removed Back: " << linkedList->remove_back()->val << endl;
    linkedList->print();  // 20<->10

    linkedList->push_back(30);
    linkedList->push_back(40);
    linkedList->print();  // 20<->10<->30<->40

    cout << "Removed Head: " << linkedList->remove_head()->val << endl;
    linkedList->print();  // 10<->30<->40
}
