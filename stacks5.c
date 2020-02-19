/********************************************************************************************
 * dynamic_stacks_menu
 * @author: Carlos Huerta García
 * @description: Displays a menu to execute stacks functions with int and char dynamic stacks
 * *****************************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
typedef char StackEntry;

typedef struct StackElement {
    StackEntry entry;
    struct StackElement* next;
} StackElement;

typedef struct StackInt {
    int entry;
    struct StackInt* next;
} StackInt;

typedef struct Stack {
    StackElement* top;
} Stack;

typedef struct intStack {
    StackInt* top;
} intStack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

intStack* createiStack() {
    intStack* stack = (intStack*)malloc(sizeof(intStack));
    stack->top = NULL;
    return stack;
}

StackElement* createElement(StackEntry item) {
    StackElement* element = (StackElement*)malloc(sizeof(StackElement));
    if (element == NULL) {
        puts("Error at creating element");
        exit(1);
    }
    element->entry = item;
    element->next = NULL;
    return element;
}

StackInt* createInt(int item) {
    StackInt* element = (StackInt*)malloc(sizeof(StackInt));
    if (element == NULL) {
        puts("Error at creating int");
        exit(1);
    }
    element->entry = item;
    element->next = NULL;
    return element;
}

bool isEmpty(Stack* stack) {
    return !stack->top;
}

bool isIEmpty(intStack* stack) {
    return !stack->top;
}

void push(StackEntry item, Stack* stack) {
    StackElement* element = createElement(item);
    element->next = stack->top;
    stack->top = element;
}

void pushInt(int item, intStack* stack) {
    StackInt* element = createInt(item);
    element->next = stack->top;
    stack->top = element;
}

StackEntry pop(Stack* stack) {
    StackEntry popped = ' ';
    if (isEmpty(stack)) {
        puts("Error: current stack is empty");
        return popped;
    }
    StackElement* temp = stack->top;
    stack->top = stack->top->next;
    popped = temp->entry;
    free(temp);
    return popped;
}

int popInt(intStack* stack) {
    int popped = INT_MIN;
    if (isIEmpty(stack)) {
        puts("Error: current int stack is empty");
        return popped;
    }
    StackInt* temp = stack->top;
    stack->top = stack->top->next;
    popped = temp->entry;
    free(temp);
    return popped;
}

StackEntry peek(Stack* stack) {
    StackEntry peeked = ' ';
    if (isEmpty(stack)) {
        puts("Error: current stack is empty");
        return peeked;
    }
    return stack->top->entry;
}

int peekInt(intStack* stack) {
    int peeked = INT_MIN;
    if (isIEmpty(stack)) {
        puts("Error: current int stack is empty");
        return peeked;
    }
    return stack->top->entry;
}

void print(Stack* stack) {
    if (isEmpty(stack)) {
        puts("[ ]");
        return;
    }
    StackElement* element = stack->top;
    while (element->next != NULL) {
        printf("[%c]->", element->entry);
        element = element->next;
    }
    printf("[%c]->", element->entry);
}

void printi(intStack* stack) {
    if (isIEmpty(stack)) {
        puts("[ ]");
        return;
    }
    StackInt* element = stack->top;
    while (element->next != NULL) {
        printf("[%d]->", element->entry);
        element = element->next;
    }
    printf("[%d]->", element->entry);
}

void clear(Stack* stack) {
    if(!isEmpty(stack)){
        StackElement* element;
        while ((element = stack->top) != NULL) {
            stack->top = stack->top->next;
            free(element);
        }
    } else {
        puts("Error: current char stack is empty");
        return;
    }
}

void cleari(intStack* stack) {
    if(!isIEmpty(stack)){
        StackInt* element;
        while ((element = stack->top) != NULL) {
            stack->top = stack->top->next;
            free(element);
        }
    } else {
        puts("Error: current int stack is empty");
        return;
    }
}

void main() {
    Stack* charStack;
    intStack* intStack;
    char c, go = 's';
    int i = 0, option = 0;
    while(go == 's'){
        puts("\n0 Salir");
        puts("1 Crear pila de caracteres");
		puts("2 Crear pila de enteros");
		puts("3 Mostrar pila de caracteres");
		puts("4 Mostrar pila de enteros");
		puts("5 Tomar la último caracter");
		puts("6 Tomar el último entero");
		puts("7 Quitar la último caracter");
		puts("8 Quitar el último entero");
		puts("9 Agregar una caracter");
		puts("10 Agregar un entero");
		puts("11 Vaciar la pila de caracteres");
		puts("12 Vaciar la pila de enteros");
		scanf("%d", &option);
		switch(option){
            case 0:
				clear(charStack);
                cleari(intStack);
				exit(0);
				break;
            case 1:
                charStack = createStack();
                break;
            case 2:
                intStack = createiStack();
                break;
			case 3:
				print(charStack);
				break;
			case 4:
				printi(intStack);
				break;
			case 5:
                printf("Peeked: %c\n", peek(charStack));
				break;
			case 6:
				printf("Peeked: %d\n", peekInt(intStack));
				break;
			case 7:
                printf("Popped: %c\n", pop(charStack));
				break;
			case 8:
				printf("Popped: %d\n", popInt(intStack));
				break;
			case 9:
                puts("Introduzca el caracter:");
                fflush(stdin);
                scanf("%c", &c);
                scanf("%c", &c);
				push(c, charStack);
				break;
			case 10:
				puts("Introduzca el entero");
				scanf("%d", &i);
				pushInt(i, intStack);
				break;
			case 11:
				clear(charStack);
				break;
			case 12:
				cleari(intStack);
				break;
			default:
				puts("Operación inválida");
				break;
        }
        puts("\n¿Desea realizar más operaciones? (s/n)");
        fflush(stdin);
        scanf("%c", &go);
        scanf("%c", &go);
    }
    clear(charStack);
    cleari(intStack);
    free(charStack);
    free(intStack);
}