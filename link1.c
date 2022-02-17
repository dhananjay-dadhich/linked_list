// Linked list operations 

#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node* link;
};

// Insert at the beginning
void insertAtBeginning(struct Node** first, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = new_data;

  new_node->link = (*first);

  (*first) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->link = prev_node->link;
  prev_node->link = new_node;
}

// Insert the the end
void insertAtEnd(struct Node** first, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *first;

  new_node->data = new_data;
  new_node->link = NULL;

  if (*first == NULL) {
  *first = new_node;
  return;
  }

  while (last->link != NULL) last = last->link;

  last->link = new_node;
  return;
}

void deleteNode(struct Node** first, int key) {
  struct Node *temp = *first, *prev;

  if (temp != NULL && temp->data == key) {
  *first = temp->link;
  free(temp);
  return;
  }

  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->link;
  }

  if (temp == NULL) return;

  prev->link = temp->link;

  free(temp);
}

int searchNode(struct Node** first, int key) {
  struct Node* current = *first;

  while (current != NULL) {
  if (current->data == key) return 1;
  current = current->link;
  }
  return 0;
}

void sortLinkedList(struct Node** first) {
  struct Node *current = *first, *index = NULL;
  int temp;

  if (first == NULL) {
  return;
  } else {
  while (current != NULL) {
   
    index = current->link;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->link;
    }
    current = current->link;
  }
  }
}

void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->link;
  }
}

int main() {
  struct Node* first = NULL;

  insertAtEnd(&first, 1);
  insertAtBeginning(&first, 2);
  insertAtBeginning(&first, 3);
  insertAtEnd(&first, 4);
  insertAfter(first->link, 5);

  printf("Linked list: ");
  printList(first);

  printf("\nAfter deleting an element: ");
  deleteNode(&first, 3);
  printList(first);

  int item_to_find = 3;
  if (searchNode(&first, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&first);
  printf("\nSorted List: ");
  printList(first);
}
