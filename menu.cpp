#include<stdio.h>
#include<stdlib.h>
//Chua xong cai chi het :v 
struct Book;
struct SingleLinkedList;
typedef struct SingleLinkedList *node;
struct Book{
    char id[10];
    char name[20];
    char author[20];
    char publishingHouse[20];
    int  publishingYear;
    bool state;
    void createNullList();
    node createListFromFile();
    Book insertFist();
    Book insertAfter();
    Book insertLast();
    Book removeByCode();
    Book removeByName();
    Book removeByAuthor();
    Book removeFirst();
    Book removeAfterCode();
    Book removeLast();
    Book searchByName();
    Book searchByAuthor();
    Book searchByPublishingHouse();
    Book viewALL();
    Book viewByState();
    Book viewByAlpha();
    Book viewByPublishYear();
    Book sort();
    void input();
};
struct SingleLinkedList{
    Book book;
    node *pHead;
    node *pTail;
    node *pNext;
};

int main()
{
    node temp;
    temp = (node)malloc(sizeof(struct SingleLinkedList));
    return 0;
}