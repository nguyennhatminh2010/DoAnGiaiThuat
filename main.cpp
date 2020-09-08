#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

struct Book;
struct Node;
struct List;

struct Book {
    char isbn[10];
    char title[20];
    char author[20];
    char publishingHouse[20];
    int  publishingYear;
    bool state;
};

struct Node {
    Book book;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

Book createBook() {
    char s;
    Book book;
    printf("Enter the book's ISBN': ");
    scanf("%s", &book.isbn);
    fflush(stdin);
    printf("Enter the book's title: ");
    scanf("%s", &book.title);
    fflush(stdin);
    printf("Enter the book's author: ");
    scanf("%s", &book.author);
    fflush(stdin);
    printf("Enter the book's Publishing House: ");
    scanf("%s", &book.publishingHouse);
    fflush(stdin);
    printf("Enter the book's Publishing Year: ");
    scanf("%d", &book.publishingYear);
    fflush(stdin);
    printf("Has the book been borrowed?(Y/N): ");
    scanf("%c", &s);
    fflush(stdin);
    
	if(s == 'Y' || s == 'y') 
		book.state = true;
    else 
		book.state = false;
    
	return book;
}

Node *createNode() {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->book = createBook();
    temp->pNext = NULL;
    return temp;
}

void createNullList(List &list)
{
	list.pHead = NULL;
	list.pTail = NULL;
}

void insertFist(List &list) {
    Node *temp = createNode();
    if(list.pHead == NULL) {
        list.pHead = list.pTail = temp;
    } else {
        temp->pNext = list.pHead;
        list.pHead = temp;
    }
}

//adding feature ===============================================
void displayInsertMenu() {
    printf("1. Insert a new book at the top of the list\n");
    printf("2. Insert a new book at after the orther\n");
    printf("3. Insert a new book at the end of the list\n");
    printf("0. Exit\n");
}

void insertBook(List &list) {
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
                //printf("Insert a new book at the top of the list\n");
                insertFist(list);
				break;

            case 2: //Insert a new book at after the orther
                printf("Insert a book at after the orther\n");
                break;

            case 3: //Insert a new book at the end of the list
                printf("Insert a new book at the end of the list\n");
                break;

            default:
                break;
        }
    }
}

//deleting feature==========================================
void displayDeletingMenu() {
    printf("1. Delete a book by id\n");
    printf("2. Delete a book by book's title\n");
    printf("3. Delete all books by author\n");
    printf("4. Delete a book at the top of the list\n");
    printf("5. Delete a book after the orther by id\n");
    printf("6. Delete a book at the end of the list\n");
    printf("0. Exit\n");
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
                break;

            case 2: //Delete a book by title
                printf("Delete a book by book's title\n");
                break;

            case 3: //Delete all book by author
                printf("Delete all book by author\n");
                break;

            case 4: //Delete a book at the top of the list
                printf("Delete all book by author\n");
                break;

            case 5: //Delete a book after the orther by id
                printf("Delete all book by author\n");
                break;

            case 6: //Delete a book at the end of the list
                printf("Delete all book by author\n");
                break;

            default:
                break;
        }
    }
}

//searching feature=========================================
void displaySearchingMenu() {
    printf("1. Search all books of the list by book's title\n");
    printf("2. Search all books of the list by author\n");
    printf("3. Search all books of the list by publisher's name\n");
    printf("0. Exit\n");
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
    printf("0. Exit\n");
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
void displayMenu() {
    printf("1. Create\n");
    printf("2. Open...\n");
    printf("0. Exit\n");
}

void displaySubMenu() {
    printf("1. Add a new Book\n");
    printf("2. Delete book\n");
    printf("3. Search book\n");
    printf("4. Library\n");
    printf("0. Exit\n");
}

void options(List &list) {
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
                printf("Add a book\n");
                insertBook(list);
                break;

            case 2: //delete book
                printf("Delete book\n");
                deleteBook(list);
                break;

            case 3: //search book
                printf("Search book\n");
                searchBook(list);
                break;

            case 4: //display book
                printf("Display book\n");
                displayBooks(list);
                break;

            default:
                break;
        }
    }
}

int main() {
	List list;
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
            	createNullList(list);
                options(list);
                break;

            case 2://open file
                //options();
                break;

            default:
                break;
        }
    }

    getch();
    return 0;
}
