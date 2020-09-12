#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// struct Book;
// struct Node;
// struct List;

struct book {
    char isbn[10];
    char title[20];
    char author[20];
    char publishingHouse[20];
    int  publishingYear;
    int state;//chỗ này sửa thành kiểu int vì trong c k có kiểu boolen
};
typedef struct book Book;

struct node {
    Book book;
    Node *pNext;
};
typedef struct node Node;

struct list {
    Node *pHead;
    Node *pTail;
};
typedef struct list List;

void display(List &list);
void displayInsertMenu();
void displayDeletingMenu();
void displaySearchingMenu();
void displayBooks(List &list);
void displayMenu();
void displaySubMenu();
void displayBooksMenu();
Book createBook();
Node *createNode();
void createNullList(List &list);
void insertFist(List &list);
void insertBook(List &list);
void deleteBook(List &list);
List filterTitleBook(List list, char title[]);
void searchBook(List &list);
void print(Book &book);
List completedBooks(List &list);
List inCompleteBooks(List &list);
void options(List &list);

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
		book.state = 1;
    else 
		book.state = 0;
    
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


//==================================Chỗ này của thằng Minh=======================================
//adding feature ===============================================
void displayInsertMenu() {
    printf("1. Insert a new book at the top of the list\n");
    printf("2. Insert a new book at after the orther\n");
    printf("3. Insert a new book at the end of the list\n");
    printf("0. Exit\n");
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

void insertBook(List &list) {
    int selection;
    int isRunning = 1;

    while (isRunning) {

        displayInsertMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
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
    int isRunning = 1;

    while (isRunning) {

        displayDeletingMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
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


//==================================Chỗ này của thằng Bảo=======================================
//searching feature============================================
void displaySearchingMenu() {
    printf("1. Search all books of the list by book's title\n");
    printf("2. Search all books of the list by author\n");
    printf("3. Search all books of the list by publisher's name\n");
    printf("0. Exit\n");
}


List filterTitleBook(List list, char title[]) {
    List oList;
    Node* current = list.pHead;
    while (current != NULL)
    {
        if(strcmp(current->book.title, title) == 0) {
            //insertLast(oList, current);
        }
        current = current->pNext;
    }
    return oList;
}

void searchBook(List &list) {
    int selection;
    int isRunning = 1;

    while (isRunning) {

        displaySearchingMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
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
	printf("Publishing Year: %d\n", book.publishingYear);
	printf("State: %b\n", book.state);
}

void display(List &list) {
	Node* current = list.pHead;
	while(current != NULL) {
		print(current->book);
		current = current->pNext;
	};
}

List completedBooks(List &list) {
    List oList;
    Node* current = list.pHead;
    createNullList(oList);
    while (current != NULL) {
        if(current->book.state) {
            // insertLast(oList, current->book);
        }
        current = current->pNext;
    }
    return oList;
}

List inCompleteBooks(List &list) {
    List oList;
    Node* current = list.pHead;
    createNullList(oList);
    while (current != NULL) {
        if(!current->book.state) {
            // insertLast(oList, current->book);
        }
        current = current->pNext;   
    }
    return oList;
}

void displayBooks(List &list) {
    int selection;
    int isRunning = 1;

    while (isRunning) {

        displayBooksMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
                break;
            
            case 1: //Display all books by category
				display(list);//tạm thời hiển thị tất cả, update sau
                break;

            case 2: //Display state of the book
                int subSelection;
                printf("1. Completed\n");
                printf("2. Incomplete\n");
                scanf("%d", &subSelection);
                switch (subSelection) {
                
                case 1: //sach da tra
                    List oList;
                    oList = completedBooks(list);
                    display(oList);
                    break;
                
                case 2://sach chua tra
                    List oList;
                    oList = inCompleteBooks(list);
                    display(oList);
                    break;
                
                default:
                    break;
                }
                break;

            case 3: //Delete all books in order
                printf("Display all books in order\n");
                break;

            default:
                break;
        }
    }
}


//==================================Chỗ này hỏi nhau trước khi sửa=======================================
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
    int isRunning = 1;

    while (isRunning) {

        displaySubMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
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
    int isRunning = 1;
    
    while (isRunning) {
        
        displayMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0:
                isRunning = 0;
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
