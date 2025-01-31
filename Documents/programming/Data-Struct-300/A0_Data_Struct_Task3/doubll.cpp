#include "doubll.h"
#include <cstddef>
#include <cstdlib>
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

  node *walker = head, *temp;

  if (index == 0) {
    head = walker->next;
    free(walker);
    return;
  }

  for (int i = index; i >= 1; i--) {
    temp = walker;
    walker = walker->next;
    walker->prev = temp;
  }

  if (walker == nullptr) {
    cout << "Error: Overflow" << endl;
    return;
  }

  // pointer check cases
  if (walker->prev != nullptr) {
    walker->prev->next = walker->next;
  }
  if (walker->next != nullptr) {
    walker->next->prev = walker->prev;
  }
  if (head == walker) {
    head = walker->next;
  }
  free(walker);
}

void displayList(node *head) {
  node *walker = head;

  while (walker != nullptr) {
    cout << walker->data << " ";
    walker = walker->next;
  }
  cout << endl;
}
