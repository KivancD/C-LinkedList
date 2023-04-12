#include <stdio.h>                
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

struct Node {             
int data;
struct Node *link;
};
    


void PrintList(struct Node *head){
    struct Node *temp;
    printf("\nList items: ");
    temp=head;
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}

struct Node *CreateNode(){
    int given_data;
    printf("Enter Data for new node: \n");
  
    
            while (scanf("%d", &given_data)==false){
                printf("Ops. No letters! Only integer: \n");
                given_data = getchar();
            }
            
        
        struct Node *newNode;
        newNode = (struct Node*) malloc(sizeof(struct Node));  
        newNode->data = given_data;
        newNode->link=NULL;
        return newNode;
}

struct Node *AddLast(struct Node *head){
    struct Node *lastNode; 
    struct Node *temp;
    temp = head;
    if (head==NULL){
        struct Node *newHead;
        newHead=CreateNode();
        newHead->link=head;
        return newHead;
    }
    else{
        while(temp->link){
            temp=temp->link;
        }
        lastNode=CreateNode();
        temp->link=lastNode;}
}

struct Node *AddFirst(struct Node *head){
    struct Node *newHead;
    newHead=CreateNode();
    newHead->link=head;
    return newHead;
}

struct Node *DeleteFirst(struct Node *head){
   struct Node *temp;
   if (head == NULL) {
       printf("List is already empty.");
   }
   else {
        temp = head->link;
        free(head);        
        return temp;
   }
}   

struct Node *DeleteAllElements(struct Node* head){
    struct Node* before_temp;
    before_temp = head;
    
    if (head == NULL)
        printf("List is already empty.\n");
   return NULL;
 
   if (head->link == NULL) {
      free(head);
      head = NULL;
        }
    else {
        struct Node *temp = head;
        while(temp->link!=NULL) {
            before_temp = temp;
            temp = temp->link;
            free(before_temp);
        }
        free(temp);
        temp = NULL;
        }
        return NULL;
    }

void DeleteLast(struct Node* head){
    struct Node* temp;
    struct Node* temp2;
    temp = head;

        while (temp->link!=NULL){
            temp2=temp;
            temp=temp->link;
         }
         temp2->link=NULL;
         free(temp);
} 

void AddAfter(struct Node* head, int num){
     struct Node *suan_node;
     struct Node *newNode;
     suan_node = head;
     
     while (suan_node->link !=NULL && suan_node->data != num) {
         suan_node=suan_node->link;
     }
     if (suan_node->link == NULL && suan_node->data != num){
         printf("You typed wrong node\n\n");
     }
     else if (suan_node->link == NULL && suan_node->data == num) {
         newNode = CreateNode();
         suan_node->link = newNode;
     }
     else {
         newNode = CreateNode();
         newNode->link = suan_node->link;
         suan_node->link = newNode;
     }
     return;
}

struct Node *AddBefore(struct Node *head, int given){
    struct Node *suan_node;
    struct Node *newNode;
    struct Node *temp;
   
    
    suan_node=head;
    temp=head;
    
    
        newNode=CreateNode();
        while (temp->link != NULL && temp->data != given) {
       temp=temp->link;}
       
        if (temp->link == NULL && temp->data != given) {
           printf("Node is not found.\n\n");}
        else {
            while(suan_node->link != NULL && suan_node->link->data != given) {
                suan_node=suan_node->link;
            } 
            newNode->link = suan_node->link;
            suan_node->link = newNode;
            suan_node=suan_node->link;
        }
    
    return newNode;
   }

void *DeleteBefore(struct Node *head, int position){
    struct Node *suan_node;
    struct Node *controller; 
    struct Node *temp;
    
    suan_node=head;
    controller=head;
    temp=head;
  
    if (head->data == position){
        printf("There is no node before head.\n\n");
    }
    else {
        while (controller->link != NULL && controller->data != position) 
            controller=controller->link;
       
        if (controller->link == NULL && controller->data != position) 
           printf("Node is not found.\n\n");
        
        
        else {
            while(suan_node->link != NULL && suan_node->link->data != position) 
            suan_node=suan_node->link;
            
            while(temp->link != NULL && temp->link->link->data != position){
             temp=temp->link;}
            
            temp->link = suan_node->link;
            free(suan_node);
            }
    }
    return temp;
}

void *DeleteAfter(struct Node *head, int y){
    struct Node *suan_node;
    struct Node *controller, *temp, *victim;
     suan_node = head;
     controller = head;
     temp = head;
     
     while (suan_node->link !=NULL && suan_node->data != y) {
         suan_node=suan_node->link;
     }
    
     if (suan_node->link == NULL && suan_node->data != y){
         printf("You typed wrong node\n\n");
     }
     else if (suan_node->link == NULL && suan_node->data == y) {
         printf("\nData you given is last node. There is no node after last node.\n\n");
     }
     else if (suan_node->link != NULL && suan_node->data == y) {
          victim = suan_node->link;
          controller = victim->link;
          free(victim);
          suan_node->link = controller;
     }
    
     else {
         printf("An unknown error happened.");
     }
    return NULL;
    }

void *CountElements(struct Node *head){
    struct Node *counter_node;
    counter_node = head;
    int sum=1; 
    if (head){
    while (counter_node->link != NULL) {
        counter_node=counter_node->link;
        sum++;
    }
    printf("\nTotal node count is: %d \n", sum);
    return NULL;}
    else {
        printf("Total node count is: 0\n");
    }
}



int main(void) {
    struct Node temp;
    struct Node *newNode;
    struct Node *given_pointer;
    struct Node *head;
    
    int position;
    int num;
    int choice;
    int x,y;
  
    head=CreateNode();
    
    
    
    do{

        
        printf("\n1:AddLast\n2:AddFirst\n3:DeleteFirst\n4:DeleteLast\n5:DeleteAllElements\n6:AddAfter\n7:AddBefore\n8:DeleteBefore\n9:DeleteAfter\n10:CountElements\n11:PrintList\n0:For Exit\n"); 
        printf("\nwhich function you want to use: ");
        
        
       if(scanf("%d", &choice) == false)
        {    
            printf("PLEASE ONLY ENTER INTEGER DATA. Enter 9 to continue: \n");
            
            do{
                choice = getchar();
            }
            while (!isdigit(choice));
            
        }

        system("clear");
        switch(choice){
            case 1: if (head){
                        AddLast(head); break;}
                    else{
                        head=AddLast(head);break;
                    }
            case 2: head=AddFirst(head); break;
            case 3: if (head){
                        head=DeleteFirst(head); break;}
                    else{
                        printf("\nList is already empty.\n");break;}
            case 4: if (!head) {
                        printf("\nList is already empty.\n");break;
                        }
                    else if (head->link==NULL){
                        head=DeleteFirst(head);break;
                    }
                    else {
                        DeleteLast(head); break;
                    }
            case 5: head=DeleteAllElements(head); break;
            case 6: if (head) {
                    printf("After which node you would like to add a node: ");
                    scanf("%d", &num);
                    AddAfter(head, num); break;}
                    else 
                    printf("List is empty. You should add first element.\n");break;
            case 7: if (head) {
                    printf("Before which node you would like to add a node: ");
                    scanf("%d", &x);
                        if(head->data == x) {
                           head=AddFirst(head);   
                        }
                        else {
                              AddBefore(head, x);}
                        break;}
                    else {
                    printf("List is empty. You should add first element.\n");break;
                    }
            case 8: if (head) {
                    printf("Before which node you would like to delete a node: ");
                    scanf("%d", &position);
                        if (head->link->data == position) {
                            head=DeleteFirst(head);break;
                            }
                        else {
                        DeleteBefore(head, position); break;}}
                    else {
                    printf("List is empty. You should add first element.\n");break;
                    }
            case 9: if (head) {
                    printf("After which node you would like to delete a node: ");
                    scanf("%d", &y);
                    DeleteAfter(head, y); break;}
                    else {
                    printf("List is empty. You should add first element.\n");break;
                    }
            case 10: CountElements(head); break;
            case 11: PrintList(head);
                     printf("\n"); break;
            case 0: printf("\nExit"); break;
            default: printf("\nWrong Choice!\n\n");
        }
        
        
        
        
        
    }while(choice !=0);
    
    
    
    system("pause=nul");
    
    
    return 0;
}


