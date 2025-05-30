#include <iostream>
using namespace std;


class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    Queue() : head(NULL), tail(NULL), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int ele) {
        Node* n = new Node(ele);
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int front() {
        if (isEmpty()) {
            return 0;
        }
        return head->data;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.display();

cout<<q.front()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<< q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    q.enqueue(60);
    q.enqueue(70);
  q.display();
  q.dequeue();
  q.dequeue();
    cout<< q.front() << endl;
    cout << q.getSize() << endl;
    
    while(!q.isEmpty()){
    	cout<<q.front()<<endl;
    	q.dequeue();
	}
    cout << q.getSize() << endl;
    cout<< q.isEmpty() << endl;
    return 0;
}

