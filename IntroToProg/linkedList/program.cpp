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

void set_prev(List *currList){
    struct Node *ptr;
    struct Node *ptr_next;
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
}

void delete_tail(List *currList){

}

void delete_node(List *currList){

}

void delete_list(List *currList){

}

int main() {
    List new_list = create_list();
    insert_node(3, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(2000);

    insert_node(1, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(2000);

    insert_node(7, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(2000);

    insert_node(2, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);
    delay(2000);    

    insert_node(9, &new_list);
    write("The linked list is: ");
    display_list_new(&new_list);

    return 0; 
}