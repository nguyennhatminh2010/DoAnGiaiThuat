#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct book {
    char isbn[5];
    char title[30];
    char author[20];
    char publishingHouse[20];
    int  publishingYear;
    int state;
};
typedef struct book Book;

struct node {
    Book book;
    node *pNext;
};
typedef struct node Node;

struct list {
    Node *pHead;
    Node *pTail;
};
typedef struct list List;
//Khai bao ham chinh
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
List filterBook(List &list, char type[], char keyword[]);
void searchBook(List &list);
void print(Book &book);
List stateBooks(List &list, int state);
void options(List &list);
void writeFile(FILE* fout);
void readFile(FILE* fin);
//Khai bao ham phu
bool strcmp(char s1[], char s2[]);
int strlen(char s[]);
void strProcessing(char s[]);
												//Cho nay cua thang Minh
//Dinh nghia ham phu
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
void strProcessing(char s[])
{
	for(int i = 0; i < strlen(s); i++)
		if(s[i] == '_') s[i] = ' ';
}
//Dinh nghia ham chinh
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
            book.state = 1;
        else if(s == 'N' || s == 'n')
            book.state = 0;
    }
	return book;
}

Node *createNode(Book book){
    Node *temp = (Node*)malloc(sizeof(Node));
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

void insertAfter(List &l,Book book)
{
    char isbn[5];
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
void createListFromFile(List &l)
{
	FILE *file;
	Book book;
	l.pHead = NULL;
	l.pTail = NULL;
	char s;
	file = fopen("thuvien.txt","r");
	if(file == NULL){
		perror("Error");
		exit(1);
	}
	while(!feof(file)){
		fscanf(file,"%s %s %s %s %d %d",&book.isbn,&book.title,&book.author,&book.publishingHouse,&book.publishingYear,&book.state);
		strProcessing(book.title);
		strProcessing(book.author);
		strProcessing(book.publishingHouse);
		insertLast(l,book);
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
	char isbn[5];
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
	char isbn[5];
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
	char title[30];
    printf("\nPlease enter the book's title need to remove: ");
    fflush(stdin);
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
    fflush(stdin);
    gets(author);
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
                system("pause");
                break;

            case 5: //Delete a book after the orther by book's isbn
                printf("Delete a book after the orther by book's isbn\n");
                removeAfter(list);
                break;

            case 6: //Delete a book at the end of the list
                printf("Delete a book at the end of the list\n");
                removeLast(list);
                system("pause");
                break;

            default:
                break;
        }
        system("cls");
    }
}

													//cho nay cua thang bao
//searching feature============================================
void displaySearchingMenu() {
    printf("1. Search all books of the list by book's title\n");
    printf("2. Search all books of the list by author\n");
    printf("3. Search all books of the list by publisher's name\n");
    printf("0. Back\n");
}


List filterBook(List &list, char type[], char keyword[]) {
    List oList;
    createNullList(oList);
    Node* current = list.pHead;
    while (current != NULL)
    {
        if(strcmp(type, "title")) {
            if(strcmp(current->book.title, keyword)) {
            	printf("%s\n", keyword);
            	insertLast(oList, current->book);
            }
        } 

        if (strcmp(type, "author")) {
            if(strcmp(current->book.author, keyword)) {
                insertLast(oList, current->book);
            }
        }

        if (strcmp(type, "publisher")) {
            if(strcmp(current->book.publishingHouse, keyword)) {
                insertLast(oList, current->book);
            }
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
                {
                    List oList;
                    createNullList(oList);
                    char keyword[20];
                    char title[10] = "title";
                    printf("Enter the book's title: ");
                    fflush(stdin);
					gets(keyword); 
                    oList = filterBook(list, title, keyword);
                    display(oList);
                    break;
                }

			case 2:
	            {
	                List oList;
                    createNullList(oList);
	                char keyword[20];
	                char author[10] = "author";
                    printf("Enter the book's author: ");
                    fflush(stdin);
					gets(keyword); 
                    oList = filterBook(list, author, keyword);
                    display(oList);
                    break;
                }

            case 3:
                {
                    List oList;
                    createNullList(oList);
                    char keyword[20];
                    char publisher[10] = "publisher";
                    printf("Enter the book's publisher: ");
                    fflush(stdin);
					gets(keyword); 
                    oList = filterBook(list, publisher, keyword);
                    display(oList);
                    break;
                }

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
	printf("%10s", book.isbn);
	printf("%30s", book.title);
	printf("%20s", book.author);
	printf("%20s", book.publishingHouse);
	printf("%20d", book.publishingYear);
	if(book.state == 1) {
		printf("      Completed\n");
	} else {
		printf("     Incomplete\n");
	}
}

void display(List &list) {
	Node* current = list.pHead;
	char heading[200] = "      ISBN                         Title              Author    Publishing House     Publishing Year          State \n";
	printf("%s", heading);
	printf("========================================================================================================================\n");
	while(current != NULL) {
		print(current->book);
//		printf("------------------------------------------------------------------------------------------------------------------------\n");
		current = current->pNext;
	};
	printf("========================================================================================================================\n");
	printf("Press something to back!");
	getch();
	system("cls");
}

List stateBooks(List &list, int state) {
    List oList;
    Node* current = list.pHead;
    createNullList(oList);
    while (current != NULL) {
        if(current->book.state == state) {
            insertLast(oList, current->book);
        }
        current = current->pNext;
    }
    return oList;
}
void copyList(List &oList, List &list) {
    if(list.pHead == NULL) {
        return;
    } 
    Node* current = list.pHead;

    while (current != NULL)
    {
        insertLast(oList, current->book);
        current = current->pNext;
    }
    
}

void swap(Node *a, Node *b) 
{ 
    Book temp = a->book; 
    a->book = b->book; 
    b->book = temp; 
} 

List sortList(List &list, char keyword[]) {
    if (list.pHead == NULL) 
        return list;
    
	List oList;
    createNullList(oList);
    copyList(oList, list);
    Node* currentOutside = oList.pHead;
    Node* currentInside; 
    
    while (currentOutside->pNext != NULL)
    {
        currentInside = currentOutside->pNext;
        while (currentInside != NULL)
        {
            if(strcmp(keyword, "title")) {
                if(currentOutside->book.title[0] > currentInside->book.title[0] ) {
                    swap(currentOutside, currentInside);
                }
            }

            if(strcmp(keyword, "author")) {
                if(currentOutside->book.author[0] > currentInside->book.author[0] ) {
                    swap(currentOutside, currentInside);
                }
            }

            if(strcmp(keyword, "publisher")) {
                if(currentOutside->book.publishingHouse[0] > currentInside->book.publishingHouse[0] ) {
                    swap(currentOutside, currentInside);
                }
            }

            if(strcmp(keyword, "nearly")) {
                if(currentOutside->book.publishingYear < currentInside->book.publishingYear ) {
                    swap(currentOutside, currentInside);
                }
            }
            currentInside = currentInside->pNext;
        }
        currentOutside = currentOutside->pNext;
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
				display(list);//t?m th?i hi?n th? t?t c?, update sau
                break;

            case 2: //Display state of the book
                {
                    int subSelection;
                    printf("1. Completed\n");
                    printf("2. Incomplete\n");
                    scanf("%d", &subSelection);
                    switch (subSelection) {
                    
                        case 1: //sach da tra
                            {
                                List oList;
                                oList = stateBooks(list, 1);
                                display(oList);
                                break;
                            }
                        
                        case 2://sach chua tra
                            {
                                List oList;
                                oList = stateBooks(list, 0);
                                display(oList);
                                break;
                            }
                        
                        default:
                            break;
                    }
                    break;
                }

            case 3: //Display all books in order
                {
                    int subSelection;
                    printf("1. View by alpha Title\n");
                    printf("2. View by alpha Author\n");
                    printf("3. View by alpha Publisher\n");
                    printf("4. View by nearly Books\n");
					scanf("%d", &subSelection);
                    switch (subSelection) {
                    
                        case 1: 
                            {
                                List oList;
                                createNullList(oList);
                                oList = sortList(list, "title");
                                display(oList);
                                break;
                            }
                        
                        case 2:
                            {
                                List oList;
                                createNullList(oList);
                                oList = sortList(list, "author");
                                display(oList);
                                break;
                            }
                        
                        case 3:
                            {
                                List oList;
                                createNullList(oList);
                                oList = sortList(list, "publisher");
                                display(oList);
                                break;
                            }
                            
                        case 4:
                            {
                                List oList;
                                createNullList(oList);
                                oList = sortList(list, "nearly");
                                display(oList);
                                break;
                            }
                        
                        default:
                            break;
                    }
                    break;
                }
                
            default:
                break;
        }
    }
}

//==================================Cho nay hoi nhau truoc khi sua=======================================
//main ===========================================
void displaySubMenu() {
    printf("1. Add a new Book\n");
    printf("2. Delete book\n");
    printf("3. Search book\n");
    printf("4. Library\n");
    printf("0. Back\n");
}

void options(List &list) {
    int selection;
    int isRunning = 1;
    Book book;

    while (isRunning) {

        displaySubMenu();
        printf("\n-> ");
        scanf("%d", &selection);
        switch (selection) {

            case 0: //back
                isRunning = 0;
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
                searchBook(list);
                break;

            case 4: //display book
            	system("cls");
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

void writeFile(FILE* fout) {

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
            	{
            		system("cls");
	            	createNullList(list);
	                options(list);
	                break;
				}

            case 2://open file
            	{
            		system("cls");
                	createListFromFile(list);
					options(list);
                	break;
				}

            default:
                break;
        }
    }
    printf("\nThank for watching!");
    // getch();
    return 0;
}

