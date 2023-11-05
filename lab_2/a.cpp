#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int findNearest(int k) {
        if (!head) {
            return -1; // Handle the case when the list is empty.
        }

        int min_distance = abs(head->data - k);
        int min_position = 0;
        int position = 0;
        Node* current = head;
        Node* closestNode = head;

        while (current) {
            int distance = abs(current->data - k);
            if (distance < min_distance) {
                min_distance = distance;
                min_position = position;
                closestNode = current;
            }
            current = current->next;
            ++position;
        }

        return min_position;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList list;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.insert(value);
    }

    int k;
    cin >> k;

    int nearestIndex = list.findNearest(k);

    cout << nearestIndex << endl;

    return 0;
}
