#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* nxt;
};
typedef struct node node;
void printer(node**);
void insertbyval(node**,int);
void insertbyind(node**,int);
void delbyval(node**,int);
void delbyind(node**,int);
void replacerbyval(node**,int);
void replacerbyind(node**,int);
void recurprint(node**);
void dellast(node**);
void recurprint2(node*);
node** headshot(node**);
void reverse(node**);
void reverserec1(node**);
void reverserec2(node**,node*);
void recurprintIN(node**);
void recurprintIN2(node*);
int main(){
    node* i1=(node*)malloc(sizeof(node));
    node* i2=(node*)malloc(sizeof(node));
    node* i3=(node*)malloc(sizeof(node));
    node** head=&i1;
    i1->val=1;
    i2->val=2;
    i3->val=3;
    i1->nxt=i2;
    i2->nxt=i3;
    i3->nxt=NULL;
    printer(head);
    insertbyval(head,2);
    printer(head);
    insertbyind(head,2);
    printer(head);
    reverse(head);
    printer(head);
    reverserec1(head);
    printer(head);
    delbyval(head,5);
    printer(head);
    recurprintIN(head);
    delbyind(head,2);
    printer(head);
    replacerbyval(head,4);
    printer(head);
    replacerbyind(head,2);
    printer(head);
    recurprint(head);
    dellast(head);
    printer(head);
    head=headshot(head);
    printer(head);
    return 0;
}
//sabhi ko print kardo
void printer(node** head){
    node* temp=*head;
    printf("|");
    while(temp->nxt){
        printf("%d-",temp->val);
        temp=temp->nxt;
    }
    printf("%d|\n",temp->val);
}
//insert karo value se
void insertbyval(node** head,int n){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    while(temp->nxt){
        if (temp->val==n){
            break;
        }
        runner->nxt=temp;
        temp=temp->nxt;
    }
    node* new=(node*)malloc(sizeof(node));
    runner->nxt->nxt=new;
    new->val=4;
    new->nxt=temp;
}
//insert karo index se
void insertbyind(node** head,int n){
    node* temp=*head;
    while (temp->nxt){
        if (n==1){
            break;
        }
        n--;
        temp=temp->nxt;
    }
    node* new=(node*)malloc(sizeof(node));
    new->val=5;
    new->nxt=temp->nxt;
    temp->nxt=new;
}
//delete karo value se
void delbyval(node** head,int n){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    while(temp->nxt){
        if (temp->val==n){
            break;
        }
        runner=temp;
        temp=temp->nxt;
    }
    runner->nxt=temp->nxt;
    free(temp);
}
//delete karo index se
void delbyind(node** head,int n){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    while (temp->nxt){
        if (n==0){
            break;
        }
        n--;
        runner=temp;
        temp=temp->nxt;
    }
    runner->nxt=temp->nxt;
    free(temp);
}
//replace kardo value se
void replacerbyval(node** head,int n){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    node* new=(node*)malloc(sizeof(node));
    new->val=10;
    while(temp->nxt){
        if(temp->val==n){
            break;
        }
        runner=temp;
        temp=temp->nxt;
    }
    runner->nxt=new;
    new->nxt=temp->nxt;
    free(temp);
}
//replace kardo index se
void replacerbyind(node** head,int n){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    node* new=(node*)malloc(sizeof(node));
    new->val=15;
    while (temp->nxt){
        if (n==0){
            break;
        }
        n--;
        runner=temp;
        temp=temp->nxt;
    }
    runner->nxt=new;
    new->nxt=temp->nxt;
    free(temp);
}
//last ko delete kar do
void dellast(node** head){
    node* temp=*head;
    node* runner=(node*)malloc(sizeof(node));
    while (temp->nxt){
        runner=temp;
        temp=temp->nxt;
    }
    runner->nxt=NULL;
    free(temp);
}
//recursion se print karo
void recurprint(node** head){
    node* temp=*head;
    recurprint2(temp);
}
void recurprint2(node* temp){
    printf("%d-",temp->val);
    if (temp->nxt==NULL){
        printf("\n");
        return ;
    }
    recurprint2(temp->nxt);
}
//head ko delete karo
node** headshot(node** head){
    node* temp=*head;
    return &(temp->nxt);
}
//reverse the list through iteration
void reverse(node** head){
    node *curr=*head;
    node *prev=NULL,*next=NULL;
    while (curr!=NULL){
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
//reverse the list through recursion
void reverserec1(node** head){
    node *prev=NULL,*next=NULL;
    reverserec2(head,prev);
}
void reverserec2(node** head,node* prev){
    node *curr=*head,*next;
    if (!(curr->nxt)){
        curr->nxt=prev;
        return;
    }
    next=curr->nxt;
    curr->nxt=prev;
    prev=curr;
    *head=next;
    reverserec2(head,prev);
}
//recursion se ULTA print karo
void recurprintIN(node** head){
    node* temp=*head;
    recurprintIN2(temp);
    printf("\n");
}
void recurprintIN2(node* temp){
    if (temp->nxt==NULL){
        return ;
    }
    recurprintIN2(temp->nxt);
    printf("%d-",temp->val);
}