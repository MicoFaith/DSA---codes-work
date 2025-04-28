#include<iostream>
using namespace std;

class Student {
public:
    int code;
    string name;
    string school;
    int age;
    Student* next;

    
    Student() {}

   
    Student(int c, string nm, string sch, int a) {
        code = c;
        name = nm;
        school = sch;
        age = a;
        next = NULL;
    }
};


void display(Student* head) {
    while (head != NULL) {
        cout << head->code << " -> " << head->name << " -> " << head->school << " -> " << head->age << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


Student* addAtHead(Student* head, int code, string name, string school, int age) {
    Student* newNode = new Student(code, name, school, age);
    
    newNode->next = head;
    head = newNode;
    
    return head;
}


Student* addAtTail(Student* head, int code, string name, string school, int age) {
    Student* newNode = new Student(code, name, school, age);

  
    if (head == NULL) {
        head = newNode;
    } else {
       
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

    
        temp->next = newNode;
    }

    return head;
}

int main() {
  
    Student* s1 = new Student(10, "Mary", "RCA", 12);
    Student* s2 = new Student(20, "Paul", "RCA", 15);
    Student* s3 = new Student(30, "Paulo", "RCA", 16);
    Student* s4 = new Student(40, "John", "RCA", 17);

 
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;


s1 = addAtHead(s1, 50,"Mico", "RCA", 13);
    s1 = addAtTail(s1, 60, "Isimbi", "RCA", 12);
    
 
    display(s1);

    return 0;
}

