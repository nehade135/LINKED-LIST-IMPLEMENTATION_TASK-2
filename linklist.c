#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
node *start = NULL;
void create_list(int n);
void traversal_list();
void insert_at_beg();
void insert_at_end();
void insert_at_after();
void insert_at_before();
void delete_first_node();
void delete_last_node();
void delete_before_node();
void delete_after_node();

int main() {
    int n, ch;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    create_list(n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete before a node\n");
        printf("8. Delete after a node\n");
        printf("9. Traverse list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_at_beg();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_after();
                break;
            case 4:
                insert_at_before();
                break;
            case 5:
                delete_first_node();
                break;
            case 6:
                delete_last_node();
                break;
            case 7:
                delete_before_node();
                break;
            case 8:
                delete_after_node();
                break;
            case 9:
                traversal_list();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void create_list(int n) {
	int i;
    for (i=0;i<n;i++) {
        node *temp = (node*)malloc(sizeof(node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            node *ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}


void traversal_list() {
    node *ptr = start;
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insert_at_beg() {
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = start;
    start = temp;
}


void insert_at_end() {
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node *ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}


void insert_at_after() {
    int num;
    printf("Enter the value after which to insert: ");
    scanf("%d", &num);

    node *ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found.\n");
        return;
    }

    node *temp = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = ptr->next;
    ptr->next = temp;
}


void insert_at_before() {
    int num;
    printf("Enter the value before which to insert: ");
    scanf("%d", &num);

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (start->data == num) {
        insert_at_beg();
        return;
    }

    node *ptr = start, *preptr = NULL;
    while (ptr != NULL && ptr->data != num) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found.\n");
        return;
    }

    node *temp = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = ptr;
    preptr->next = temp;
}


void delete_first_node() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *temp = start;
    start = start->next;
    free(temp);
    printf("First node deleted.\n");
}


void delete_last_node() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Last node deleted.\n");
        return;
    }

    node *ptr = start, *preptr = NULL;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    printf("Last node deleted.\n");
}


void delete_before_node() {
    int num;
    printf("Enter the value before which to delete: ");
    scanf("%d", &num);

    if (start == NULL || start->next == NULL) {
        printf("Insufficient nodes to perform this operation.\n");
        return;
    }

    node *ptr = start, *preptr = NULL, *prepreptr = NULL;
    while (ptr != NULL && ptr->data != num) {
        prepreptr = preptr;
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL || preptr == NULL) {
        printf("Node not found or no node before it.\n");
        return;
    }

    if (prepreptr == NULL) {
        start = ptr;
    } else {
        prepreptr->next = ptr;
    }
    free(preptr);
    printf("Node deleted.\n");
}


void delete_after_node() {
    int num;
    printf("Enter the value after which to delete: ");
    scanf("%d", &num);

    node *ptr = start;
    while (ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("Node not found or no node after it.\n");
        return;
    }

    node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("Node deleted.\n");
}
