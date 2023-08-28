#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top;

void push(int data){
    if(top==NULL){
        top = malloc(sizeof(struct node));
        top->data = data;
        top->next = NULL;
    }
    else{
        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

int pop(){
    if(top == NULL){
        printf("Stack underflow");
        return 0;
    }
    struct node *temp = top;
    top = top->next;
    int val = temp->data;
    free(temp);
    return val;
}

int peek(){
    if(top==NULL){
        printf("\nStack is empty");
        return 0;
    }
    return top->data;
}

void display(){
    struct node *temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    int ch, value;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n0.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the value : "); scanf("%d",&value);
                    push(value); break;
            case 2 : printf("\nPopped item = %d",pop()); break;
            case 3 : printf("\nTop item = %d",peek()); break;
            case 4 : display(); break;
            case 0 : exit(0); break;
        }
    }
}
