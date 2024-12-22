#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct book
{
    char title[100];
    char author[100];
    char addressOfPub[100];
    int yearOfPub;
    int bookId;
} BOOK;

void displayOptions(char bookOptions[][100], int size);
void clearInputBuffer(int input);
int bookIdGenerator(BOOK book[], int bookCount);
int findBookId(BOOK book[], int *bookCount);
void addBook(BOOK book[], int *bookCount);
void updateBookInformation(BOOK book[], int *bookCount);
void deleteBook(BOOK book[], int *bookCount);
void displayBookList(BOOK book[], int bookCount);

int main()
{
    BOOK book[1000];
    char bookOptions[5][100] = {
        "Add a book.",
        "Update book information.",
        "Remove book.",
        "Display book lists.",
        "Quit program."};
    int bookOptionSize = 5, bookCount = 0;
    int choice, input;
    char ch;

    while (1)
    {
        displayOptions(bookOptions, bookOptionSize);
        printf("Enter choice: ");
        if ((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n')
        {
            printf("\n");
            switch (choice)
            {
            case 1:
                addBook(book, &bookCount);
                break;
            case 2:
                updateBookInformation(book, &bookCount);
                break;
            case 3:
                deleteBook(book, &bookCount);
                break;
            case 4:
                displayBookList(book, bookCount);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Not an option.\n");
            }
        }
        else
        {
            printf("INVALID OPTION!\n");
            clearInputBuffer(choice);
            printf("\n");
        }
    }

    return 0;
}

void displayOptions(char bookOptions[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d] - %s\n", i + 1, bookOptions[i]);
    }

    return;
}

void clearInputBuffer(int input)
{
    while ((input = getchar()) != '\n')
        ;

    return;
}

int bookIdGenerator(BOOK book[], int bookCount)
{
    int id;
    bool isUnique;

    // static retains value between function calls
    static bool isSeeded = false;
    if (!isSeeded)
    {
        // srand prevents repetitive number sequence
        srand(time(NULL)); // time(NULL) ensures seed is different every time program runs

        // srand wont be called again avoiding re-seeding
        isSeeded = true;
    }

    do
    {
        id = 10000 + rand() % 90000;
        isUnique = true;
        for (int i = 0; i < bookCount; i++)
        {
            if (book[i].bookId == id)
            {
                isUnique = false;
                break;
            }
        }
    } while (!isUnique); // to really make it unique

    return id;
}

int findBookId(BOOK book[], int *bookCount)
{
    int id;
    char ch;

    while (1)
    {
        printf("Enter ID: ");
        if ((scanf("%d%c", &id, &ch)) == 2 && ch == '\n') { // valid
            break;
        } else {
            printf("INVALID INPUT!\n");
            clearInputBuffer(id);
            printf("\n");
        }
    }

    for (int i = 0; i < *bookCount; i++)
    {
        if (book[i].bookId == id)
        {
            return i;
        }
    }

    return -1;
}

void addBook(BOOK book[], int *bookCount)
{
    char ch;

    printf("================================================================\n");
    printf("\t\t\t   ADD A BOOK\n");
    printf("----------------------------------------------------------------\n");
    printf("\n");

    printf("Enter book name: ");
    fgets(book[*bookCount].title, sizeof(book[*bookCount].title), stdin);

    printf("Enter author: ");
    fgets(book[*bookCount].author, sizeof(book[*bookCount].author), stdin);

    printf("Enter address of publisher: ");
    fgets(book[*bookCount].addressOfPub, sizeof(book[*bookCount].addressOfPub), stdin);

    while (1)
    {
        printf("Enter year of publication: ");
        if ((scanf("%d%c", &book[*bookCount].yearOfPub, &ch)) == 2 && ch == '\n')
        {
            break;
        }
        else
        {
            printf("Enter a valid integer for the year.\n");
            clearInputBuffer(book[*bookCount].yearOfPub);
            printf("\n");
        }
    }

    book[*bookCount].bookId = bookIdGenerator(book, *bookCount);
    printf("Book ID: %d\n", book[*bookCount].bookId);

    (*bookCount)++;

    printf("\nBook added to database!\n");
    printf("================================================================\n");
    printf("\n");

    return;
}

void updateBookInformation(BOOK book[], int *bookCount)
{
    char newTitle[100], newAuthor[100], newAddress[100];
    int newYearOfPub, choice, menuSize = 5, id;
    char ch;
    char updateMenu[5][100] = {
        "Update book title.",
        "Update book author.",
        "Update book address of publication.",
        "Update year of publication.",
        "Quit."};

    printf("================================================================\n");
    printf("\t\t     UPDATE BOOK INFORMATION\n");
    printf("----------------------------------------------------------------\n");
    printf("\n");

    if (*bookCount == 0) {
        printf("No books to update.\nBook Count: %d\n", *bookCount);
        return;
    }
    
    while(1) {
        id = findBookId(book, bookCount);

        if(id == -1) {
            printf("Book not found.\n");
        } else {
            break;
        }
    }

    printf("\n----------------------------------------------------------------\n");

    while(1) {
        printf("Editing information for %sID: %d\n", book[id].title, book[id].bookId);
        displayOptions(updateMenu, menuSize);
        printf("Enter choice: ");
        while(1) {
            if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                break;
            } else {
                printf("INPUT ERROR: Must be an integer.\n");
                printf("\n");
                clearInputBuffer(choice);
            }
        }

        switch(choice) {
            case 1: //book title
                printf("Updating book title...\n");
                printf("\n");
                printf("Enter new title: ");
                fgets(newTitle, sizeof(newTitle), stdin);
                strcpy(book[id].title, newTitle);
                printf("Successfully updated book title.\n");
                break;
            case 2: //author
                printf("Updating book author...\n");
                printf("\n");
                printf("Enter new author: ");
                fgets(newAuthor, sizeof(newAuthor), stdin);
                strcpy(book[id].author, newAuthor);
                printf("Successfully updated book author.\n");
                break;
            case 3: //address
                printf("Updating address of publisher...\n");
                printf("\n");
                printf("Enter new address: ");
                fgets(newAddress, sizeof(newAddress), stdin);
                strcpy(book[id].addressOfPub, newAddress);
                printf("Successfully updated address of publisher.\n");
                break;
            case 4: //year
                printf("Updating year of publication...\n");
                printf("\n");
                while(1) {
                    printf("Enter updated year: ");
                    if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                        break;
                    } else {
                        printf("INPUT ERROR: Must be an integer.\n");
                        printf("\n");
                        clearInputBuffer(choice);
                    }
                }
                book[id].yearOfPub = newYearOfPub;
                printf("Successfully updated year of publication.\n");
                break;
            case 5:
                printf("Exiting operation...\n");
                return;
            default:
                printf("INPUT ERROR: Invalid option.\n");
        }

        break;
    }

    printf("\n================================================================\n");
    printf("\n");
    return;
}

void deleteBook(BOOK book[], int *bookCount) {
    int foundBook;
    char resp;

    printf("================================================================\n");
    printf("\t\t\t  DELETE A BOOK\n");
    printf("----------------------------------------------------------------\n");
    printf("\n");

    while(1) {
        foundBook = findBookId(book, bookCount);

        if(foundBook == -1) {
            printf("Book not found.\n");
        }

        printf("Book found.\n");
        printf("Delete \"%s\"?", book[foundBook].title);
        printf("[Y] - Yes\t[N] - No\t:\t");
        scanf("%c", &resp);

        if(resp == 'Y' || resp == 'y') {
            for(int i = foundBook; i < *bookCount; i++) {
                book[i] = book[i + 1];
            }

            (*bookCount)--;
            break;
        } else if (resp == 'N' || resp == 'n') {
            printf("Operation cancelled.\n");
            break;
        } else {
            printf("INPUT ERROR: Invalid operation.\n");
        }

    }

    printf("\n================================================================\n");
    printf("\n");
    return;
}

void displayBookList(BOOK book[], int bookCount)
{
    printf("================================================================\n");
    printf("\t\t\t    BOOK LIST\n");
    printf("----------------------------------------------------------------\n");

    if(bookCount == 0) {
        printf("No books to display.\n");
        printf("Book count: %d\n", bookCount);
        printf("\n================================================================\n");
        printf("\n");
        return;
    }

    for(int i = 0; i < bookCount; i++) {
        printf("[%d]\t%s\t%s\t%s\t%d\n\t%d\n", i+1, book[i].title, book[i].author, book[i].addressOfPub, book[i].yearOfPub, book[i].bookId);
    }

    printf("\n================================================================\n");
    printf("\n");
    return;
}