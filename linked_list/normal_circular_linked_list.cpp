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

            if (head == nullptr) {
                head = newNode;
                head->next = newNode;
                return;
            }

            Node *last = head;
            while(last->next != head) {
                last = last->next;
            }
            head = newNode;
            last->next = head;
        }

        void push_back(int x) {
            Node *last = head;
            Node *newNode = new Node(x, head);
            while(last->next != head) {
                last = last->next;
            }
            last->next = newNode;
        }

        Node* remove_head() {
            if(head == nullptr)
                return nullptr;
            Node *removed = head;
            Node *last = head;
            while(last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            return removed;
        }

        Node* remove_back() {
            if(head == nullptr)
                return nullptr;
            Node *prev = head;
            Node *removed = head;
            while(removed->next != head) {
                prev = removed;
                removed = removed->next;
            }
            prev->next = head;
            return removed;
        }

        void print() {
            if (head == nullptr) return;
            Node *temp = head;
            do {
                cout << temp->val;
                temp = temp->next;
                if (temp != head) cout << "->";  // only add arrow if not back at start
            } while (temp != head);

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