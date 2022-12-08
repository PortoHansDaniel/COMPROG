#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node { //first node - head
    int value;
    struct Node *next;
};

void display(struct Node *linkedlist){
    struct Node *current = linkedlist -> next;
    while (current != NULL){
        printf("%d ", current -> value);
        current = current -> next;
    }
}

void insertEnd(struct Node *linkedlist, int new_val){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> value = new_val;
    
    struct Node *firstnode = linkedlist -> next;
    linkedlist -> next = new_node;
    new_node -> next = firstnode;
}
int exist(struct Node *linkedlist, int value){
    
    int flag = 0;

    struct Node *current = linkedlist -> next;
    while(current != NULL){
        if (current -> value == value){
            flag++;
        }
        current = current -> next;
        
    }
    return flag;
}
void replace(struct Node * linkedlist, int oldValue, int newValue){
    
    struct Node *current = linkedlist -> next;

    while(current != NULL){
        if (current -> value == oldValue){
            current -> value = newValue;

        }
        current = current -> next;
    }

}
int main(){
    int value = 0;
    int input;
    char cont, option;
    struct Node *linkedlist = malloc(sizeof(struct Node));
    do{
        printf("   1. Insert Number\n   2. Search Number\n   3. Display List\n   4. Replace\n");
        printf("\nChoose operation: ");
        scanf("%d", &input);

        if(input == 1){
            printf("\nInsert number: ");
            scanf("%d", &value);
            insertEnd(linkedlist, value);
            printf("\n %d INSERTED TO LIST\n", value);  
        }
        else if(input == 2){
            printf("Enter number to be searched: ");
            scanf("%d", &value);
            int count = exist(linkedlist, value);
            if(count > 0){
                printf("\nValue %d exist in the linked list %d time/s", value, count);
            }
            else{
                printf("\nNumber cannot be found");
            }
        }
        else if(input == 3){
            printf("\nList of Numbers: \n");
            display(linkedlist);
        }
        else if(input == 4){
            int oldValue, newValue;
            printf("\n Enter number to be Replaced: ");
            scanf("%d", &value);
            int count = exist(linkedlist, value);
            if(count > 0){
                printf("\nValue %d exist in the linked list", value);
                oldValue = value;
                printf("\n Enter number to replace: ");
                scanf("%d", &newValue);
                replace(linkedlist, oldValue, newValue);    
            }
            else{
                printf("\nNumber cannot be found");
            }
            
        }
        printf("\nContinue Linked List Structure? (Y/N): ");
        scanf(" %c", &cont);
        option = tolower(cont);
        
    }
    while(option == 'y');
    if(option == 'n'){
        printf("");
    }
}