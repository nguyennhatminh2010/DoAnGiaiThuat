#include <stdio.h>
#include <conio.h>


//adding feature ===============================================
void displayInsertMenu() {
    printf("1. Insert a new book at the top of the list\n");
    printf("2. Insert a new book at after the orther\n");
    printf("3. Insert a new book at the end of the list\n");
    printf("0. Exit\n");
}

void insertBook() {
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

void deleteBook() {
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

void searchBook() {
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

void displayBooks() {
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
                printf("Display all books by category\n");
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

void options() {
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
                insertBook();
                break;

            case 2: //delete book
                printf("Delete book\n");
                deleteBook();
                break;

            case 3: //search book
                printf("Search book\n");
                searchBook();
                break;

            case 4: //display book
                printf("Display book\n");
                displayBooks();
                break;

            default:
                break;
        }
    }
}

int main() {
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
                options();
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
