#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;

void display(){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
} 

struct node *create(int n){
    struct node *newn, *temp;
    for(int i=0;i<n;i++){
        newn = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newn->data);
        if(head==NULL){
            head = temp = newn;
            temp->next = NULL;
        }
        else{
            temp->next = newn;
            newn->next = NULL;
            temp = newn;
        }
    }
}

void insertbeg(){
    struct node *newn;
    newn = (struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newn->data);
    if(head==NULL){
        head = newn;
        newn->next = NULL;
    }
    else{
        newn->next = head;
        head = newn;
    }
    display();
}

void insertend(){
    struct node *newn = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newn->data);
    if(head == NULL){
        head = newn;
        newn->next = NULL;
    }
    else{
        struct node *temp;
        temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newn;
        newn->next = NULL;
    }
    display();
}

void insertpos(){
    struct node *temp;
    int count, pos;
    temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    printf("Enter position to insert : "); scanf("%d",&pos);
    if(pos>count){
        printf("\nCannot insert");
    }
    else{
        struct node *newn = malloc(sizeof(struct node));
        printf("Enter data : "); scanf("%d",&newn->data);
        temp = head;
        int i=1;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    display();
}



int main(){
    int n, ch;
    printf("Enter no. of nodes to be created : ");
    scanf("%d",&n);
    create(n);
    do{
        printf("\n1. Insert at beg\n2. Insert at end\n3. Insert at pos\n4. Delete at beg\n5. Delete at end\n6. Delete at pos\n7. Reverse\n8. Sort\n9. Display\n0. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : insertbeg(); break;
            case 2 : insertend(); break;
            case 3 : insertpos(); break;
            case 9 : display(); break;
            case 0 : exit(0); break;
            default : printf("Enter valid choice"); break;
        }
    }while(ch!=0);
    return 0;
}
