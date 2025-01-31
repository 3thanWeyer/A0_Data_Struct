#include "doubll.h"
#include <cstddef>
#include <iostream>

void insertNode(node *&head, int index, int data) {
  node *newNode = new node;
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (index == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    node *walker = head;
    int walker_index = 0;

    while (walker != NULL && walker_index < index - 1) {
      walker = walker->next;
      walker->prev = walker;
      walker_index++;
    }

    if (walker == nullptr) {
      cout << "Error: Index to Large. . ." << endl;
      return;
    } else {
      newNode->prev = walker;
      newNode->next = walker->next;
      walker->next = newNode;
    }

    if (newNode->next != NULL)
      newNode->next->prev = newNode;
  }
}

void deleteNode(node *&head, int index) {
  // empty list Check
  if (head == NULL) {
    cout << "List is Empty" << endl;
    return;
  }

  node *walker = head;
  for (int i = 0; i < index; i++) {
    if (!walker)
      return;
    else {
      walker = walker->next;
    }
  }

  // replace node and free memory
  if (walker->prev)
    walker->prev->next = walker->next; // checks if current's prev is not null
  if (walker->next)
    walker->next->prev = walker->prev; // checks if current's next is not null
  if (head == walker)
    head = walker->next; // prevents from head pointing to nothing
}

void displayList(node *head) {
  node *walker = head;

  while (walker != nullptr) {
    cout << walker->data << " ";
    walker = walker->next;
  }
  cout << endl;
}
