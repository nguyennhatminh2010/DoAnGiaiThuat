#include<stdio.h>
#include<stdlib.h>
struct Book;
struct Node;
struct List;
struct Book{
    char id[10];
    char name[20];
    char author[20];
    char publishingHouse[20];
    int  publishingYear;
    bool state;
};
struct Node{
    Book book;
    Node *pNext;
};
struct List{
    Node *pHead;
    Node *pTail;
};
Book createBook()
{
    char s;
    Book book;
    printf("Type Book Id: ");
    scanf("%s",&book.id);
    fflush(stdin);
    printf("Type Book Name: ");
    scanf("%s",&book.name);
    fflush(stdin);
    printf("Type Book Author: ");
    scanf("%s",&book.author);
    fflush(stdin);
    printf("Type Publishing House: ");
    scanf("%s",&book.publishingHouse);
    fflush(stdin);
    printf("Type Publishing Year: ");
    scanf("%d",&book.publishingYear);
    fflush(stdin);
    printf("Has the book been borrowed?(Y/N): ");
    scanf("%c",&s);
    fflush(stdin);
    if(s == 'Y' || s == 'y') book.state = true;
    else book.state = false;
    return book;
}
Node *createNode(){
    Node *temp = (Node*)malloc(sizeof(struct Node));
    temp->book = createBook();
    temp->pNext = NULL;
    return temp;
}
void createNullList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void insertFist(List &l){
    Node *temp = createNode();
    if(l.pHead == NULL){
        l.pHead = l.pTail = temp;
    }
    else{
        temp->pNext = l.pHead;
        l.pHead = temp;
    }
}
    
    
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
int main()
{
    
    return 0;
}