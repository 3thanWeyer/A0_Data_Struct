#include "ll.h"
#include <cstddef>
#include <iostream>

void insertNode(node *&head, int index, int data) {
  node *newNode = new node;
  newNode->data = data;
  newNode->next = nullptr;

  if (index == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    node *walker = head;
    int wIndex = 0;
    while (walker != NULL && wIndex < index - 1) {
      walker = walker->next;
      wIndex++;
    }
    if (walker == nullptr) {
      cout << "Index is too large, can't insert" << endl;
      return;
    } else {
      newNode->next = walker->next;
      walker->next = newNode;
    }
  }
}

void deleteNode(node *&head, int index) {
  // empty list Check
  if (head == NULL) {
    cout << "List is Empty" << endl;
    return;
  }

  // Check if were are deleting at index 0 and handle accordingly
  node *walker = head, *replaceNode;
  if (index == 0) {
    head = head->next;
    free(walker);
    return;
  }
  // Handle other index deletions
  else {
    for (int i = 1; i <= index - 1; i++) {
      if (!walker || !walker->next) {
        cout << "Specified index is too large!" << endl;
        return;
      } else {
        walker = walker->next;
      }
    }
  }

  // replace node and free memory
  replaceNode = walker->next;
  walker->next = walker->next->next;
  free(replaceNode);
  return;
}

void displayList(node *head) {
  node *walker = head;

  while (walker != nullptr) {
    cout << walker->data << " ";
    walker = walker->next;
  }
  cout << endl;
}

node *searchNode(node *head, int key) {
  node *walker = head;
  while (walker != NULL) {
    if (walker->data == key) {
      return walker;
    }
    walker = walker->next;
  }
  return nullptr;
}

void reverseList(node *&head) {
  node *walker = head;
  node *previous_node = nullptr;
  node *next_node;

  while (walker != nullptr) {
    next_node = walker->next;     // next pointer
    walker->next = previous_node; // reverse current

    // iterate through list
    previous_node = walker;
    walker = next_node;
  }

  // change the head value to the reverse lists head
  head = previous_node;
  return;
}
