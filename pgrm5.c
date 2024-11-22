#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int usn;
    char name[10];
    char prog[10];
    int sem;
    long int ph;
    struct node *link;
};typedef struct node * NODE;
NODE insfront(NODE first){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("\n Enter usn, name,program,sem,phone number\n");
    scanf(" %d %s %s %d %d",&newnode->usn,newnode->name,newnode->prog,&newnode->sem,&newnode->ph);
    newnode->link=first;
    first=newnode;
    return newnode;
}
NODE inslast(NODE first){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("\n Enter usn, name,program,sem,phone number\n");
    scanf(" %d %s %s %d %d",&newnode->usn,newnode->name,newnode->prog,&newnode->sem,&newnode->ph);
    newnode->link=NULL;
     NODE temp=first;
    while(temp->link!=NULL)
    temp=temp->link;
    temp->link=newnode;
    return first;
}
NODE delfront(NODE first){
    NODE temp;
    if(first==NULL){
    printf("\nthe list is Empty\n");
    return first;
    }else{
        temp=first;
        
        printf("\n the usn %d details are deleted\n",temp->usn);
        first=first->link;
        free(temp);
        return first;
        
    }
}
NODE dellast(NODE first){
    NODE prev,pres;
    if(first==NULL){
    printf("\nthe list is Empty\n");
    return first;
    }else{
        pres=first;
        while(pres->link!=NULL){
            prev=pres;
            pres=pres->link;
        }
        
        printf("\n the usn %d details are deleted\n",pres->usn);
        prev->link=NULL;
        free(pres);
        return first;
        
    }
}
void display(NODE first){
    NODE temp;
    if(first==NULL)
    printf("\nthe list is Empty\n");
    else{
        temp=first;
        printf("USN  Name Program Semester Ph.Number\n");
        while(temp!=NULL){
            printf("%d\t %s\t %s\t %d\t %d\n",temp->usn,temp->name,temp->prog,temp->sem,temp->ph);
            temp=temp->link;
        }
    }
    
}

void main(){
    int ch;
    NODE first = NULL;
    while(1){
        printf("\n1:insfront 2:inslast  3:delfront  4:dellast 5:display 0:Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:first=insfront(first);
                   break;
            case 2:first=inslast(first);
                   break;
            case 3:first=delfront(first);
                   break;
            case 4:first=dellast(first);
                   break;
            case 5:display(first);
                   break;
            default:exit(0);
        }
    }
}