#include "splashkit.h"
#include <iostream>
using namespace std;
struct Node { 
   int data; 
   struct Node *next;
   struct Node *prev;
}; 

struct List {
    int len;
    struct Node *head_list;
    struct Node *tail_list;
};

void set_prev(List *currList){
    struct Node *ptr;
    struct Node *ptr_next;
    ptr = currList->head_list;
    ptr_next = ptr->next;
    while (ptr_next != NULL){
        ptr_next ->prev = ptr;
        ptr = ptr_next;
        ptr_next = ptr_next ->next;
    }
}

void insert_node(int new_data, List *currList){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = currList->head_list; 
    currList->head_list = new_node;
    currList->len++;
    if (currList -> len >= 1){
        struct Node *ptr = currList->head_list;
        for (int i = 1; i < currList ->len; i++){
            ptr = ptr->next;
        }
        currList -> tail_list = ptr;
    }
    set_prev(currList);
}


void display_list_new(List *currList){
    struct Node* ptr;
    ptr = currList->head_list;
    while (ptr != NULL) {
        if (ptr -> next != NULL){
            write(to_string(ptr->data));
            write(" -> ");
        } else {
            write_line(to_string(ptr->data));
        }
        ptr = ptr -> next;
    }
}

List create_list(){
    struct List *result = (struct List*)malloc(sizeof(struct List));
    result -> head_list = NULL;
    result -> tail_list = NULL;
    return *result;
}

void delete_head(List *currList){
    struct Node *ptr = currList -> head_list;
    currList -> head_list = currList -> head_list -> next;
    currList -> head_list ->prev = NULL;
    ptr -> next = NULL;
    ptr -> data = NULL;
    free(ptr);
    currList -> len--;
}

void delete_tail(List *currList){
    struct Node *ptr = currList -> tail_list;
    currList -> tail_list = currList -> tail_list -> prev;
    currList -> tail_list ->next = NULL;
    ptr -> prev = NULL;
    ptr -> data = NULL;
    free(ptr);
    currList -> len--;
}

void delete_nodes(List *currList){
    struct Node *ptr = currList ->head_list;
    while (currList != 0) {
        if (currList ->len != 1){
            while (ptr != NULL){
                if (currList->head_list->next != NULL){
                    currList->head_list = currList->head_list->next;
                } if (ptr != currList->head_list){
                    free(ptr->prev);
                    currList ->len--;
                }
                ptr = ptr -> next;
            }
        } else if (currList ->len == 1){
            currList ->head_list = NULL;
            currList ->tail_list = NULL;
            free(ptr);
            currList ->len--;
        }
    }
}

void delete_node(List *currList, int target){
    int counter = 0, head_count = 0, tail_count = 0;
    struct Node *ptr = currList -> head_list;
    while (ptr != NULL){
        if (ptr -> data == target){
            counter++;
            if (ptr == currList ->head_list){
                head_count++;
            }
            if (ptr == currList -> tail_list){
                tail_count++;
            }
        }
        ptr = ptr ->next;
    }
    if (counter != 0) {
        if (head_count == 0 && tail_count == 0) {
            struct Node *temp1;
            struct Node *temp2;
            ptr = currList -> head_list;
            while (ptr != NULL){
                if (ptr -> data == target){
                    temp1 = ptr -> prev;
                    temp2 = ptr -> next;
                    break;
                }
                ptr = ptr ->next;
            }
            ptr -> next = NULL;
            ptr -> prev = NULL;
            free(ptr);
            temp1 ->next = temp2;
            temp2 ->prev = temp1;
        } else {
            if (head_count == 0){
                delete_tail(currList);
            } else if (tail_count == 0){
                delete_head(currList);
            } else {
                delete_nodes(currList);
            }
        }
        currList ->len--;
    } else {
        write_line("VALUE NOT FOUND");
    }
}

int main() {
    List new_list = create_list();
    insert_node(3, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);

    insert_node(1, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);

    insert_node(7, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);

    insert_node(2, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);    

    insert_node(9, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);    

    delete_head(&new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);    

    delete_tail(&new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);

    delete_node(&new_list, 7);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(1000);

    delete_node(&new_list, 2);
    write("The linked list is: ");
    display_list_new(&new_list);

    // delete_node(&new_list, 1);
    // write("The linked list is: ");
    // display_list_new(&new_list);
    return 0; 
}