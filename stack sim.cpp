/*
SIMULATION PROJECT ON STACK
DONE BY: T. SHANMUHA SAI
ROLL NO: AP24110011281
SECTION: S
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("\n [ERROR] Stack Overflow! Cannot add %d (Stack is full).\n", x);
    } else {
        stack[++top] = x;
        printf("\n [SUCCESS] Pushed %d into the stack.\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("\n [ERROR] Stack Underflow! Cannot pop (Stack is empty).\n");
    } else {
        printf("\n [SUCCESS] Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("\n [INFO] Stack is Empty! No top element.\n");
    } else {
        printf("\n [INFO] Top Element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\n [VISUALIZATION] Stack is Empty: [ ]\n");
    } else {
        printf("\n --- CURRENT STACK VISUALIZATION --- \n\n");
        
        for (int i = top; i >= 0; i--) {
            printf("\t|  %3d  |", stack[i]); 
            
            if (i == top) {
                printf(" <--- TOP"); 
            }
            printf("\n");
            printf("\t+-------+\n");
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n======================================");
        printf("\n      STACK SIMULATOR CONTROL         ");
        printf("\n======================================");
        printf("\n 1. PUSH (Insert Item)");
        printf("\n 2. POP  (Remove Item)");
        printf("\n 3. PEEK (View Top Item)");
        printf("\n 4. SHOW VISUALIZATION");
        printf("\n 5. EXIT");
        printf("\n======================================");
        printf("\n Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n [INVALID INPUT] Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
        case 1:
            printf(" Enter value to push: ");
            scanf("%d", &value);
            push(value);
            display(); 
            break;
        case 2:
            pop();
            display(); 
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n Simulation Terminated. Goodbye, Shanmuha Sai!\n");
            exit(0);
        default:
            printf("\n [WARNING] Invalid Choice! Please select 1-5.\n");
        }
    }
    return 0;
}
