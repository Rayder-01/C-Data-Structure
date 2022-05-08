#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
// A11023048 
struct D_array 
{
    char symbolXO[10];
    struct D_array *prev; // 左節點
    struct D_array *next; // 右節點
    /* data */
};struct D_array *ptr, *head, *tail, *current;

void init_f(void);
void read_f(void);
// void write_f(void);
void insert_f(void);
void sort_f(void);
void display_f(void);

int main() {
    init_f();
    read_f();
    // insert_f();
    display_f();
}
void init_f(void)
{
    ptr = (struct D_array *)malloc(sizeof(struct D_array));
    strcpy(ptr->symbolXO, "0");
    ptr->prev = ptr;
    ptr->next = ptr;
    head = ptr;
    tail = ptr;
}

void read_f(void)
{
    FILE *fptr;
    if ((fptr = fopen("input.txt","r")) == NULL ) /* 如果找不到就開啟*/
    {
        printf(" file not exist \n");
        getch();
        insert_f();
     
    }
    else
    {
        ptr = (struct D_array *) malloc(sizeof(struct D_array));
        while(fscanf(fptr, "%s", ptr->symbolXO) != EOF)
        {
            if(strcmp(ptr->symbolXO, "") !=0 )
            {
                sort_f();
                ptr = (struct D_array *) malloc(sizeof(struct D_array));
            }
            else  
                free(ptr);
            
        }  
        fclose(fptr);   
    }
}
void sort_f(void)
{
	current = head->next;
	while(current != head)
	{
		if(strcmp(ptr->symbolXO , current->symbolXO) < 0)
		{
			ptr->next = current;
			ptr->prev = current->prev;
			current->prev->next = ptr;
			current->prev = ptr;
			break;
		}
		current = current->next;
	}
	if(head->next == head || current == head)
	{
		ptr->next = head;
		ptr->prev = head->prev;
		head->prev->next = ptr;
		head->prev = ptr;
	    tail = ptr;	
	}
}
void insert_f(void)
{
   char s_temp[4];
   system("cls");
   ptr = (struct D_array *) malloc(sizeof(struct D_array));
   printf(" O and X :");
   gets(ptr->symbolXO);
   gets(s_temp);
//   ptr->symbolXO =atoi(s_temp)
}

void display_f(void)
{
    int count = 0;
    system("cls");
    if(head->next == head) printf(" NO data");
    else
    {
        printf(" 雙向陣列(輸出) :");
        current = head->next;
        while (current != head)
        {
            printf(" %-20s \n", current ->symbolXO);
            count++;
            current = current->next;
            if(count % 20 == 0)
            getch();
        }
        printf(" ----------------------------\n");
        printf(" Total %d record found \n", count);     
    }
}



// void write_f(void){
//    FILE *fptr;
//    fptr = fopen("input(範例).txt","w");
//    current = head -> next;
//    while (current != head)
//    {
//        printf(fptr, "%s \n", current->symbolXO);
//        current = current->next;
//    }
//    fclose(fptr);
       
// }
