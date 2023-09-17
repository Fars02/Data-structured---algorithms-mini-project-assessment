#include <stdio.h>
#include <stdlib.h>


typedef struct ToDo todo;

struct Days{
  char day[20];
  struct Days *ptrnext;
};

struct ToDo{
 char data[100];
 int number;
 int count;
 todo *link;
};

todo *start=NULL;

struct Days *headptr=0, *newptr, *currentptr;

int main()
{
    int choice;
    welcomeUser();
    while(1){
        //system("color 3F");
        system("cls");
        printf("\n1.See Your ToDo List");
        printf("\n2.See Your ToDo's Days");
        printf("\n3.Create Your ToDos");
        printf("\n4.Add days");
        printf("\n5.Delete Your ToDos");
        printf("\n6.Update Your ToDos");
        printf("\n7.Search");
        printf("\n8.Exit");
        printf("\n\nEnter your choice..");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          seeToDo();
        break;
      case 2:
          display();
        break;
      case 3:
          createToDo();
        break;
      case 4:
         push();
         break;
      case 5:
        delToDo();
        break;
      case 6:
        updateToDo();
        break;
      case 7:
        shah();
        break;
      case 8:
        exit(0);
        }
    }
}

void welcomeUser(){
   //system("color 4F");
   printf("\n\n\n\n\n");
   printf("\t------------------------------------------------------------------------------------------------------\n\n");
   printf("\t#################################### YOUR TODO LIST APP ##############################################\n\n");
   printf("\t------------------------------------------------------------------------------------------------------");
   printf("\n\n\n\t\t*******************************WELCOME*******************************\n\n\n\n\n\n\n\n\n\t");
   system("pause");
}

void seeToDo(){
   system("cls");
   todo *temp;
   temp=start;

        if(start==NULL){
           printf("\nEmpty TODO\n\n");
        }

       while(temp!=NULL){
          printf("\n\n%d)",temp->count);
          puts(temp->data);
          fflush(stdin);

          temp=temp->link;
       }
       printf("\n\n\n");
       system("pause");
   }

void createToDo(){
    char k;
    todo *t,*temp;
    //t->number = 1;
    //temp->number =1;

    int d;

    system("cls");
    while(1){
        printf("\nWant to add?y/n: ");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       else{
        if(start==NULL){
        t=(todo *)calloc(1,sizeof(todo));
        start=t;
        printf("\nADD it..\n");
        fflush(stdin);
        gets(t->data);
        printf("\nNumber: ");
        scanf("%d", &t->number);

        t->count=1;
        start->link=NULL;
        
       }
       else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD it..\n");
       fflush(stdin);
       gets(temp->data);
       printf("\nNumber: ");
        scanf("%d", &temp->number);

       temp->link=NULL;
       t->link=temp;
       t=t->link;
       
     }
     fixcount();
    }
   }
}

void delToDo(){
  system("cls");
  int d;
  todo *temp1,*temp;
  printf("\nEnter the no of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
}
system("pause");
}

void fixcount(){
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

void updateToDo(){
  system("cls");
  todo *temp,*t;
  char k;

  while(1){
        printf("\nWant to add?y/n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       printf("\nADD it..\n");
       temp=(todo *)calloc(1,sizeof(todo));
       fflush(stdin);
       gets(temp->data);

       temp->link=NULL;
       t=start;
      while(t->link!=NULL){
        t=t->link;
      }
      t->link=temp;
      fixcount();
}
printf("\n\n");
system("pause");
}

void push(){
  system("cls");
  newptr = (struct Days *)malloc(sizeof(struct Days));

          printf("\n\nEnter days to relate: ");
          scanf("%s", &newptr->day);

          newptr->ptrnext = headptr;
          headptr = newptr;
}


void display(){
  system("cls");
  int i=1;
          currentptr = headptr;

          if(headptr == 0){
              printf("\n\nStack is empty or underflow, nothing to be shown");
          }else
          {
              printf("\n\n   Days: \n");
              while(currentptr !=0)
              {
                  printf("\n\t%d).%s", i, currentptr->day);
                  currentptr = currentptr->ptrnext;
                  i++;
              }
          }
       printf("\n\n\n");
       system("pause");
}


void shah(){

  todo *temp;
  int search;
  
  system("cls");
   if(start == 0)
   {
    printf("\n\nThe list is empty\n\n");
   }else{
    printf("\nEnter search value: ");
    scanf("%d", &search);

    temp = start;

    while (temp->link != NULL)
    {
      if(temp->number == search)
      {
        printf("\nSearch is found: %d", search);
        printf("\nTo Do is : %s", temp->data);
        break;
      }
      else{
        temp = temp->link;
      }
    }

    if(temp->number == search){
      printf("\nSearch is found: %d", search);
      printf("\nTo Do is : %s", temp->data);
    }else{
      printf("\nSorry no match found");
    }

   }
   printf("\n\n\n");
   system("pause");
}