#include <iostream>
#include <string>
using namespace std;

// Define Employee node structure (Doubly Linked List)
struct Employee {
  int id;
  string name;
  float salary;
  Employee *prev;
  Employee *next;
};

// Function to create a new Employee node
Employee *createEmployee(int id, string name, float salary) {
  Employee *newNode = new Employee;
  newNode->id = id;
  newNode->name = name;
  newNode->salary = salary;
  newNode->prev = nullptr;
  newNode->next = nullptr;
  return newNode;
}

// Insert at the front of doubly linked list
void insertAtFront(Employee *&head, int id, string name, float salary) {
  Employee *newNode = createEmployee(id, name, salary);
  if (head == nullptr) {
    head = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Delete from end of doubly linked list
void deleteAtEnd(Employee *&head) {
  if (head == nullptr) {
    cout << "List is empty, nothing to delete." << endl;
    return;
  }

  Employee *temp = head;

  // Traverse to last node
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  if (temp->prev == nullptr) {
    // Only one node
    head = nullptr;
  } else {
    temp->prev->next = nullptr;
  }

  cout << "Deleted Employee: ID=" << temp->id << ", Name=" << temp->name
       << ", Salary=" << temp->salary << endl;

  delete temp;
}

// Display the employee list
void display(Employee *head) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  cout << "Employee List:" << endl;
  Employee *temp = head;
  while (temp != nullptr) {
    cout << "ID: " << temp->id << ", Name: " << temp->name
         << ", Salary: " << temp->salary << endl;
    temp = temp->next;
  }
}

int main() {
  Employee *head = nullptr;

  insertAtFront(head, 1, "Elon", 50000);
  insertAtFront(head, 2, "Namo", 60000);
  display(head);

  deleteAtEnd(head);
  display(head);

  deleteAtEnd(head);
  display(head);
  cout << "Adity Gupta CST789" << endl;
  return 0;
}
