#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //to avoid case-sensitive errors by user
#include <conio.h> //reads one character from user to proceed

struct Node { //first node - head
    int value;
    struct Node *next;
};

void display(struct Node *linkedlist){ //star points to head or the struct Node
    struct Node *current = linkedlist -> next;
    while (current != NULL){
        printf("%d ", current -> value); //thus creates a loop to print out values that are pointed to
        current = current -> next;
    }
}

void insertEnd(struct Node *linkedlist, int new_val){ //new_val is user input
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> value = new_val; //from previous node, new_val is added into the linkedlist
    
    struct Node *firstnode = linkedlist -> next;
    linkedlist -> next = new_node;
    new_node -> next = firstnode; //arrangement of previous node pushed for new_val
}
int exist(struct Node *linkedlist, int value){
    
    int flag = 0;

    struct Node *current = linkedlist -> next;
    while(current != NULL){
        if (current -> value == value){
            flag++; //tells how many times the value existed
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

void arrayStruc(){
    int len;
    printf("\n Array Length: ");
    scanf("%d", &len);

    int arr[len]; //array numbers begin at 0
    for(int i = 0; i < len; i++){
        printf("\n Element (%d): ", i + 1); //we increment another to count how many elements
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf(" Result:\n");

    for(int i = 0; i < len; i++){
        printf("\n\t Index (%d) --> %d", i, arr[i]); //the index of the inputted number are as given
    }
}

void linkedlistStruc(){
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
            insertEnd(linkedlist, value); //calls the insertEnd func
            printf("\n %d Inserted to list\n", value);  
        }
        else if(input == 2){
            printf("Enter number to be searched: ");
            scanf("%d", &value);
            int count = exist(linkedlist, value); //checks if value inputted exists
            if(count > 0){ //converts it to the variable "count" and if it is greater than zero...
                printf("\nValue %d exist in the linked list %d time/s", value, count); //increment from previous lines (flag) counts
            }
            else{
                printf("\nNumber cannot be found");
            }
        }
        else if(input == 3){
            printf("\nList of Numbers: \n");
            display(linkedlist); //calls display func
        }
        else if(input == 4){
            int oldValue, newValue;
            printf("\n Enter number to be Replaced: ");
            scanf("%d", &value);
            int count = exist(linkedlist, value);
            if(count > 0){ //same procedure to check if value exists
                printf("\nValue %d exist in the linked list", value);
                oldValue = value; //changes to value
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

void stacksStruc(){
    int n, a = 0, b, c;

    printf("\n Enter an integer: ");
    scanf("%d", &n);
    
    c = n;

    while (n != 0) {
        b = n % 10;
        a = a * 10 + b;
        n = n / 10; //same program from codechum when reversing a number

    } if (c == a) //confirms if stored value in c is equivalent to a
        printf("\n\t%d = Palindrome", c);
    else
        printf("\n\t%d = Not a Palindrome", c);
}

void queueStruc(){
    int num, x = 1, i;
        printf("\n Target number of customer: ");
        scanf("%d", &num);
    int iat[num], at[num], tsb[num], tsd[num], tse[num];
        
        for (i = 0; i < num; i++){
            printf("Customer %d interarrival time: ", x);
            scanf("%d", &iat[i]);
            printf("Customer %d service duration time: ", x);
            scanf("%d", &tsd[i]); 
            x++;    
        }
    
        printf("\nCN\tIAT\tAT\tTSB\tTSD\tTSE\n");
        if (num > 0){ //automatically true for values to be given and looped to print the queue
            at[0] = iat[0];
            tsb[0] = at[0];
            tse[0] = tsb[0] + tsd[0];
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", 1, iat[0], at[0], tsb[0], tsd[0], tse[0]);
        }

        for (i = 1; i < num; i++){
            at[i] = iat[i] + at[i - 1]; //for arival time
            if(at[i] > tse[i - 1]){ //if arrival time is greater than time service end
                tsb[i] = at[i];
            }else{
                tsb[i] = tse[i - 1];
            }tse[i] = tsd[i] + tsb[i];
    
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, iat[i], at[i], tsb[i], tsd[i], tse[i]); //prints customers numbers and queue
        }}

void searchStruc(){
    int i, low, high, middle, n, search, array[50];
    
    printf("\n Enter number of elements: ");
    scanf("%d", &n);

    printf("\n Enter %d integers: \n\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &array[i]); //loop for entering (n) amount of elements
        }
    printf("\nEnter value to find: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;
    middle = (low + high) / 2; //formula needed to find middle
    

    while (low <= high){ //conditions are expected for search to run
        if (array[middle] < search){
            low = middle + 1;
        }else if (array[middle] == search){
            printf("\n%d found at element %d.\n", search, middle);
            break; //this will loop till all numbers are scanned/eliminated and the variables are met
    }
    else
        high = middle - 1;

    middle = (low + high)/2; //if while loop = false, redo formula for middle

    }
    if (low > high)
        printf("\nNot found! %d isn't present in the list.\n", search);

}

void sortStruc(int array2[], int n){
    int i = 1, element, j; 

    for(i; i < n; i++){ //continuous loop similar to previous applications with incrementations
        element = array2[i]; 
        j = i - 1; 
        while (j >= 0 && array2[j] > element){
            array2[j + 1] = array2[j]; 
            j = j - 1; 
            } 
    array2[j + 1] = element; 
    } //sorts in an ascending order
}

void sortPrint(int array2[], int n){ 
    int i; 
    for (i = 0; i < n; i++) 
    printf(" %d ", array2[i]); //loops the numbers in an array list
} 
int main(){
    int value = 0;
    int input;
    char cont, option;
    int arrayList[] = {52, 31, 87, 12, 44, 29, 62, 75}; //change values here
    int n = sizeof(arrayList) / sizeof(arrayList[0]); 
    int choice;
    while(1){
        printf("\n1. Array\n2. Linked List\n3. Stacks (Palindrome)\n4. Queue\n5. Searching Algorithm\n6. Sorting Algorithm (Insertion)");
        printf("\n\n\tChoose Data Structure Application: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
        case 1:
            arrayStruc();
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        case 2:
            linkedlistStruc();
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        case 3:
            stacksStruc();
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        case 4:
            queueStruc();
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        case 5:
            searchStruc();
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        case 6:
            sortStruc(arrayList, n);
            sortPrint(arrayList, n); 
            printf("\n\n Continue to Data Structure Applications? (Y/N): ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
            else if (toupper(getch()) != 'Y'){
                exit(1);
            }
        default:
            printf(" Choose between the given data struct. applications || Press Y to go back: ");
            if (toupper(getch()) == 'Y'){
                continue;
            }
        }
    }
    return 0;
}