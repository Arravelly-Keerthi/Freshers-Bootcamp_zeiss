// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct emp{
    int eid;
    float sal;
    char name[20];
    char email[20];
}emp;
int main() {
    // emp e1,e3;
    // // e1.eid=1234;
    // // e1.sal=99000.98;
    // // // e1.name="Keerthi"; this is not valid in c
    // // strcpy(e1.name,"Keerthi");//should be given like this
    // // strcpy(e1.email,"fgt");
    // emp e2={1235,98900.9876,"kavya","xyz"};
    // emp*ptr;
    // ptr=malloc(sizeof(emp));
    // // ptr=&e1
    // printf(" Enter e1 eid =\n");
    //  scanf("%d",&ptr->eid);
    // printf("e1 salary =\n");
    // scanf("%f",&ptr->sal);
    // printf("e1 name =\n");
    //   scanf("%s",ptr->name);
    //  printf("e1 email =\n");
    //  scanf("%s",ptr->email);
     
    //  printf("e1 eid =%d\n",ptr->eid);
    //   printf("e1 salary =%f\n",ptr->sal);
    // printf("e1 name =%s\n",ptr->name);
    //  printf("e1 email =%s\n",ptr->email);
    // //  ptr=&e2;
    // // printf("e2 eid =%d\n",ptr->eid);
    // // printf("e2 salary=%f\n",ptr->sal);
    // // printf("e2 name=%s\n",ptr->name);
    // //  printf("e2 email =%s\n",ptr->email);
    // //  scanf("%d\n",&e3.eid);
    // //  scanf("%f\n",&e3.sal);
    // //  scanf("%s\n",e3.name);
    // //  scanf("%s\n",e3.email);
    // //  printf("e2 eid =%d\n",e3.eid);
    // // printf("e2 salary=%f\n",e3.sal);
    // // printf("e2 name=%s\n",e3.name);
    // //  printf("e2 email =%s\n",e3.email);
    
     
     emp employees[5];//={{1,23.54,"keerthi","xcv"},
    //  {2,24.56,"kavya","dfg"},
    //  {3,98.79,"sindhu","wer"},
    //  {4,34.567,"pranay","poi"},
    //  {5.98.65,"sai","uyt"}};
//printf("Print size of employess = %ld\n",sizeof(employees));
     //scanf()
     int size;
     printf("Enter the number of employees: ");
     scanf("%d",&size);
     
     for(int i=0;i<size;i++)
     {
          printf(" Enter e1 eid =\n");
     scanf("%d",&employees[i].eid);
     scanf("%d",&(p+i)->eid);
    printf("e1 salary =\n");
    scanf("%f",&employees[i].sal);
    printf("e1 name =\n");
      scanf("%s",employees[i].name);
     printf("e1 email =\n");
     scanf("%s",employees[i].email);
     }
     emp *p;
     p=malloc(size*sizeof(employee));
     for(int i=0;i<size;i++)
     {
          printf(" Enter e1 eid =\n");
     scanf("%d",&(p+i)->eid);
    printf("e1 salary =\n");
    scanf("%f",&(p+i)->sal);
    printf("e1 name =\n");
      scanf("%s",&(p+i)->name);
     printf("e1 email =\n");
     scanf("%s",&(p+i)->email);
     }
     //  free(ptr);
    return 0;
}
