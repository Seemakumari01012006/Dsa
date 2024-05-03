#include<stdio.h>
#include<stdlib.h>

//Define the structure of a node
struct Node{
    int data;
    struct Node* prev;
    struct Node*next;
};

//function to create of a node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}
//function to inserta node at the beginning of the list
void insertAtBeginning(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head==NULL){
        newNode->next = newNode;
    }
     else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node inserted at the beginning successfully.\n");
}

// Function to insert a node at a specific position in the list
void insertAtSpecific(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    int currentPosition = 1;
    while (temp != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at position %d successfully.\n", position);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at the end successfully.\n");
}

// Function to delete a node from the beginning of the list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}

// Function to delete a node from a specific position in the list
void deleteAtSpecific(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
        return;
    }
    int currentPosition = 1;
    while (temp != NULL && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node deleted from position %d successfully.\n", position);
}

// Function to delete a node from the end of the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
    printf("Node deleted from the end successfully.\n");
}

// Function to search for a node with a given data value
void search(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to display the contents of the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at specific position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at specific position\n");
        printf("6. Delete at end\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtSpecific(&head, data, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtSpecific(&head, position);
                break;
            case 6:
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 8:
                display(head);
                break;
            case 9:
                freeList(head);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
// what is disadvantage of array?
// we can not store multiple data type in array.
//and array has fixed size
//what is structure?
//struture is a usre difined data type were we can store multiple data type.
// with the help of struct keyboard

