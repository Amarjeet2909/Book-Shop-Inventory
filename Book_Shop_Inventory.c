#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//declaring nesting of structures
struct record{
    char author[30];
    char title[20];
    float price;
struct{
    char month[10];
    int year;
}
date;
char publisher [20];
int quantity;
};
//defining a function
int lookup (struct record table[],char s1[], char s2[], int m);
//defining a another function
void get (char string [] );
int main(){
    char title[30], author[20];
    int index, no_of_records;
    char response[5], quantity[10];
    struct record book[] = {
    {"singh","The Golden",256.00,"Jan",2004,"Gitanjali",5},
    {"das","Spirit of Education",635.00,"Mar",1992,"GrowPb",2},
    {"Chatanya","A Lion",411.00,"Aug",2019,"Hill",6},
    {"ojha","The Machine",566.3,"Sept",2018,"MountainPb",1}
    };
    no_of_records = sizeof(book)/ sizeof(struct record);
    //here no_of_records will give number of elements in book[]

    do
    {
        printf("Enter title and Author name as per the list::::::::\n");
        printf("\nTitle::    ");
        get(title);
        printf("Author::   ");
        get(author);
        index = lookup(book, title, author, no_of_records);
        if(index != -1)
        {
            printf("\n%s %s %.2f %s %d %s\n\n",book[index].author,book[index].title,book[index].price,book[index].date.month,book[index].date.year,book[index].publisher);
            printf("Enter number of copies::");
            get(quantity);
            if(atoi(quantity) < book[index].quantity)
                printf("Cost of %d copies is:: %.2f\n",atoi(quantity),book[index].price * atoi(quantity));
            else
                printf("Required copies is not in stock\n\n");
        }    
            else
            printf("\nBook is not in the List\n\n");

        printf("\nDo you Want any other Books ? (Yes / No)::");
        get(response);        
        }
        while(response[0] == 'Y' || response[0] == 'y');
        printf("\n\nThank You.  Good bye!!\n");
    }
    void get(char string [] )
    {
        char c;
        int i = 0;
        do
        {
            c= getchar();
            string[i++] = c;
        }
        while(c != '\n');
        string[i-1] = '\0';
    }

    int lookup(struct record table[], char s1[], char s2[], int m)
    {
        int i;
        for(i=0;i<m;i++)
             if(strcmp(s1,table[i].title) == 0  &&  strcmp(s2, table[i].author) == 0)
             return (i); //book found
        return (-1);     //book not found
    }
