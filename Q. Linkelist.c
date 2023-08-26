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

void deletebeg(){
    struct node *temp;
    temp = head;
    if(head == NULL)
        printf("\nList is epmpty");
    else{
        head=head->next;
        free(temp);
        display();
    }
}

void deleteend(){
    struct node *temp, *prev;
    temp = head;
    if(head == NULL)
        printf("\nList is empty");
    else{
        while(temp->next!= NULL){
            prev = temp;
            temp=temp->next;
        }
        prev->next = NULL;
        free(temp);
        display();
    }
}

void deletepos(){
    struct node *temp;
    temp = head;
    int count=0, pos, i=1;
    if(head == NULL)
        printf("\nList is empty");
    else{
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        printf("\nEnter the position to delete : ");
        scanf("%d",&pos);
        if(pos > count){
            printf("\nInvalid position");
        }
        else{
            struct node *prev;
            temp = head;
            while(i<pos){
                prev = temp;
                temp=temp->next;
                i++;
            }
            prev->next = temp->next;
            free(temp);
            display();
        }
    }
}

void reverse(){
    struct node *next, *cur, *prev;
    next = cur = head;
    prev = NULL;
    while(next!=NULL){
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    display();
}

void sort(){
    struct node *temp, *sort;
    temp = head;
    int x;
    while(temp!=NULL){
        sort = temp->next;
        while(sort!=NULL){
            if(temp->data > sort->data){
                x = temp->data;
                temp->data = sort->data;
                sort->data = x;
            }
            sort = sort->next;
        }
        temp = temp->next;
    }
    display();
}

void search(){
    struct node *temp;
    int key, count=1, flag=0;
    temp = head;
    if(head==NULL){
        printf("\nEmpty list");
    }
    else{
        printf("\nEnter key to search : "); scanf("%d",&key);
        while(temp!=NULL){
            if(temp->data == key){
                count++;
                printf("\n%d found at %d",key,count);
                flag = 1;
            }
            temp = temp->next;
        }
        if(!flag)
            printf("%d not found",key);
    }
}

int main(){
    int n, ch;
    printf("Enter no. of nodes to be created : ");
    scanf("%d",&n);
    create(n);
    do{
        printf("\n1. Insert at beg\n2. Insert at end\n3. Insert at pos\n4. Delete at beg\n5. Delete at end\n6. Delete at pos\n7. Reverse\n8. Sort\n9. Search\n10. Display\n0. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : insertbeg(); break;
            case 2 : insertend(); break;
            case 3 : insertpos(); break;
            case 4 : deletebeg(); break;
            case 5 : deleteend(); break;
            case 6 : deletepos(); break;
            case 7 : reverse(); break;
            case 8 : sort(); break;
            case 9 : search(); break;
            case 10 : display(); break;
            case 0 : exit(0); break;
            default : printf("Enter valid choice"); break;
        }
    }while(ch!=0);
    return 0;
}
