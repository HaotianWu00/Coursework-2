#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "interface.h"
#include "book_management.h"
#include "user.h"
#include "librarian.h"


int main(int argc, char** argv) {
	FILE* bookp;
	FILE* userp;
	if ((argc != 3) || !strcmp(argv[1], "book.txt") || !strcmp(argv[2], "user.txt")) {
		printf("Error\nExpected use: ./library book.txt user.txt\n");
	}
	else {
		bookp = fopen(argv[1], "rb");
		userp = fopen(argv[2], "rb");
		if (bookp == NULL) {
			printf("Error\nFile book.txt doesn't exist.");
		}
		else if (userp == NULL) {
			printf("Error\nFile user.txt doesn't exist.");
		}
		else {
			member = (userList*)malloc(sizeof(userList));
			library = (BookList*)malloc(sizeof(BookList));
			load_books(bookp);
			loadUser(userp);
			fclose(bookp);
			fclose(userp);
			bookp = NULL;
			userp = NULL;
			interface();
			bookp = fopen("book.txt", "wb+");
			store_books(bookp);
			fclose(bookp);
			bookp = NULL;
			userp = fopen("user.txt", "wb+");
			storeUser(userp);
			fclose(userp);
			userp = NULL;
		}
	}
	freeList(library);
	return 0;
}




