#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

struct Book;
struct Node;
struct List;
struct Book{
    char isbn[10];
    char title[20];
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
Book createBook() {
    char s;
    Book book;
    printf("Enter the book's ISBN: ");
    scanf("%s", &book.isbn);
    fflush(stdin);
    printf("Enter the book's title: ");
    gets(book.title);
    fflush(stdin);
    printf("Enter the book's author: ");
    gets(book.author);
    fflush(stdin);
    printf("Enter the book's Publishing House: ");
    gets(book.publishingHouse);
    fflush(stdin);
    printf("Enter the book's Publishing Year: ");
    scanf("%d", &book.publishingYear);
    fflush(stdin);
    while(s != 'Y' && s != 'y' && s != 'N' && s != 'n'){
        printf("Has the book been borrowed?(Y/N): ");
        scanf("%c", &s);
        fflush(stdin);
        if(s == 'Y' || s == 'y') 
            book.state = true;
        else if(s == 'N' || s == 'n')
            book.state = false;
    }
	return book;
}

Node *createNode(Book book){
    Node *temp = (Node*)malloc(sizeof(struct Node));
    temp->book = book;
    temp->pNext = NULL;
    return temp;
}
void createNullList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void insertFist(List &l,Book book){
    Node *temp = createNode(book);
    if(l.pHead == NULL){
        l.pHead = l.pTail = temp;
    }
    else{
        temp->pNext = l.pHead;
        l.pHead = temp;
    }
}
void insertLast(List &l,Book book){
    Node *temp = createNode(book);
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = temp;
    }
    else{
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
}
int strlen(char s[])
{
	int i = 0, count = 0;
	while(s[i] != '\0')
	{
		i++;
		count++;
	}
	return count;
}
bool strcmp(char s1[], char s2[])
{
	if(strlen(s1) != strlen(s2)) return false;
	else{
		for(int i = 0; i < strlen(s1); i++)
		{
			if(s1[i] != s2[i]) return false;
		}
	}
	return true;
}
void insertAfter(List &l,Book book)
{
    char isbn[10];
    Node *temp = createNode(book);
    printf("\nYou need insert it after book's isbn: ");
    scanf("%s",&isbn);
    fflush(stdin);
    for(Node *k = l.pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(k->book.isbn,isbn))
        {
            temp->pNext = k->pNext;
            k->pNext = temp;
        }
    }
}
void removeFirst(List &l){
	if(l.pHead == NULL) return;
	Node *temp = l.pHead;
	l.pHead = l.pHead->pNext;
	free(temp);
}
void removeLast(List &l)
{
	if(l.pHead == NULL) return;
	if (l.pHead->pNext == NULL)
	{
		removeFirst(l);
		return;
	}
	Node *p = l.pHead;
	for (Node *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			free(l.pTail); 
			k->pNext = NULL; 
			l.pTail = k;
			return;
		}
	}
}
void removeAfter(List &l)
{
	char isbn[10];
    printf("\nYou need remove book after book's isbn: ");
    scanf("%s",&isbn);
    fflush(stdin);
    if(l.pHead == NULL) return;
    for(Node *k = l.pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(k->book.isbn,isbn))
        {
        	if(k->pNext == NULL) return;
            Node *temp = k->pNext;
            k->pNext = temp->pNext;
            free(temp);
        }
    }
}
void removeBookByIsbn(List &l)
{
	char isbn[10];
    printf("\nPlease enter the book's isbn need to remove: ");
    scanf("%s",&isbn);
    fflush(stdin);
    if(l.pHead == NULL) return;
    if(strcmp(l.pHead->book.isbn,isbn)) removeFirst(l);
    if(strcmp(l.pTail->book.isbn,isbn)) removeLast(l);
    else{
	    for(Node *k = l.pHead; k->pNext != NULL; k = k->pNext)
	    {
	        if(strcmp(k->pNext->book.isbn,isbn))
	        {
	            Node *temp = k->pNext;
	            k->pNext = temp->pNext;
	            free(temp);
	        }
	    }
	}
}
void removeBookByTitle(List &l)
{
	char title[20];
    printf("\nPlease enter the book's title need to remove: ");
    gets(title);
    fflush(stdin);
    if(l.pHead == NULL) return;
    if(strcmp(l.pHead->book.title,title)) removeFirst(l);
    if(strcmp(l.pTail->book.title,title)) removeLast(l);
    else{
	    for(Node *k = l.pHead; k->pNext != NULL; k = k->pNext)
	    {
	        if(strcmp(k->pNext->book.title,title))
	        {
	            Node *temp = k->pNext;
	            k->pNext = temp->pNext;
	            free(temp);
	        }
	    }
	}
}
void removeBookByAuthor(List &l)
{
	char author[20];
    printf("\nPlease enter the book's author need to remove: ");
    scanf("%s",&author);
    fflush(stdin);
    if(l.pHead == NULL) return;
    if(strcmp(l.pHead->book.author,author)) removeFirst(l);
    if(strcmp(l.pTail->book.author,author)) removeLast(l);
    else{
	    for(Node *k = l.pHead; k->pNext != NULL; k = k->pNext)
	    {
	        if(strcmp(k->pNext->book.author,author))
	        {
	            Node *temp = k->pNext;
	            k->pNext = temp->pNext;
	            free(temp);
	        }
	    }
	}
}
//adding feature ===============================================
void displayInsertMenu() {
	printf("Add a book\n");
    printf("1. Insert a new book at the top of the list\n");
    printf("2. Insert a new book at after the orther\n");
    printf("3. Insert a new book at the end of the list\n");
    printf("0. Back\n");
}

void insertBook(List &list,Book book) {
    int selection;
    bool isRunning = true;

    while (isRunning) {

        displayInsertMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = false;
                break;
            
            case 1: //Insert a new book at the top of the list
                printf("Insert a new book at the top of the list\n");
                book = createBook();
                insertFist(list,book);
				break;

            case 2: //Insert a new book at after the orther
                printf("Insert a book at after the orther\n");
                book = createBook();
                insertAfter(list,book);
                break;

            case 3: //Insert a new book at the end of the list
                printf("Insert a new book at the end of the list\n");
                book = createBook();
                insertLast(list,book);
                break;

            default:
                break;
        }
        system("cls");
    }
}

//deleting feature==========================================
void displayDeletingMenu() {
	printf("Delete a book\n");
    printf("1. Delete a book by id\n");
    printf("2. Delete a book by book's title\n");
    printf("3. Delete all books by author\n");
    printf("4. Delete a book at the top of the list\n");
    printf("5. Delete a book after the orther by id\n");
    printf("6. Delete a book at the end of the list\n");
    printf("0. Back\n");
}

void deleteBook(List &list) {
    int selection;
    bool isRunning = true;

    while (isRunning) {

        displayDeletingMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = false;
                break;
            
            case 1: //Delete a book by id
                printf("Delete a book by id\n");
                removeBookByIsbn(list);
                break;

            case 2: //Delete a book by title
                printf("Delete a book by book's title\n");
                removeBookByTitle(list);
                break;

            case 3: //Delete all book by author
                printf("Delete all book by author\n");
                removeBookByAuthor(list);
                break;

            case 4: //Delete a book at the top of the list
                printf("Delete a book at the top of the list\n");
                removeFirst(list);
                break;

            case 5: //Delete a book after the orther by book's isbn
                printf("Delete a book after the orther by book's isbn\n");
                removeAfter(list);
                break;

            case 6: //Delete a book at the end of the list
                printf("Delete a book at the end of the list\n");
                removeLast(list);
                break;

            default:
                break;
        }
        system("cls");
    }
}

//searching feature=========================================
void displaySearchingMenu() {
    printf("1. Search all books of the list by book's title\n");
    printf("2. Search all books of the list by author\n");
    printf("3. Search all books of the list by publisher's name\n");
    printf("0. Back\n");
}

void searchBook(List &list) {
    int selection;
    bool isRunning = true;

    while (isRunning) {

        displaySearchingMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = false;
                break;
            
            case 1: //Search all books of the list by book's title
                printf("Search all books of the list by book's title\n");
                break;

            case 2: //Search all books of the list by author
                printf("Search all books of the list by author\n");
                break;

            case 3: //Search all books of the list by publisher's name
                printf("Search all books of the list by publisher's name\n");
                break;

            default:
                break;
        }
    }
}

//display feature===========================================
void displayBooksMenu() {
    printf("1. Display all books by category\n");
    printf("2. Display state of the book\n");
    printf("3. Display all books in order\n");
    printf("0. Back\n");
}

void print(Book &book) {
	printf("ISBN: %s\n", book.isbn);
	printf("Title: %s\n", book.title);
	printf("Author: %s\n", book.author);
	printf("Publishing House: %s\n", book.publishingHouse);
	printf("Publishing Year: %s\n", book.publishingYear);
	printf("State: %s\n", book.state);
}

void display(List &list) {
	Node* current = list.pHead;
	while(current != NULL) {
		print(current->book);
		current = current->pNext;
	};
}

void displayBooks(List &list) {
    int selection;
    bool isRunning = true;

    while (isRunning) {

        displayBooksMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = false;
                break;
            
            case 1: //Display all books by category
				display(list);
                break;

            case 2: //Display state of the book
                printf("Delete a book by book's title\n");
                break;

            case 3: //Delete all book by author
                printf("Display all books in order\n");
                break;

            default:
                break;
        }
    }
}

//main ===========================================

void displaySubMenu() {
    printf("1. Add a new Book\n");
    printf("2. Delete book\n");
    printf("3. Search book\n");
    printf("4. Library\n");
    printf("0. Back\n");
}

void options(List &list,Book book) {
    int selection;
    bool isRunning = true;

    while (isRunning) {

        displaySubMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = false;
                break;
            
            case 1: //add a book
            	system("cls");
                insertBook(list,book);
                break;

            case 2: //delete book
            	system("cls");
                deleteBook(list);
                break;

            case 3: //search book
            	system("cls");
                printf("Search book\n");
                searchBook(list);
                break;

            case 4: //display book
            	system("cls");
                printf("Display book\n");
                displayBooks(list);
                break;

            default:
                break;
        }
        system("cls");
    }
}
void displayMenu() {
    printf("1. Create\n");
    printf("2. Open...\n");
    printf("0. Exit\n");
}
int main() {
	List list;
	Book book;
    int selection;
    bool isRunning = true;
    while (isRunning) {
        displayMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0:
                isRunning = false;
                break;
            
            case 1://create
            	system("cls");
            	createNullList(list);
                options(list,book);
                break;

            case 2://open file
                //options();
                system("cls");
                break;

            default:
                break;
        }
		system("cls");
    }
    printf("\nThank for watching!");
    return 0;
}
