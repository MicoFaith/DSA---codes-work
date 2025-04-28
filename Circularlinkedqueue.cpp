#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (front == NULL) { // If queue is empty
            front = rear = newNode;
            rear->next = front; // Making it circular
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circularity
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        if (front == rear) { // If only one node
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // Maintain circularity
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Circular Queue: ";
    q.display();

    q.dequeue();
    cout << "After Dequeue: ";
    q.display();

    return 0;
}

