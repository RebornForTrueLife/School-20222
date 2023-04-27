/********************************************
 * file - store and read in binary format
 * Uage: 
	- run the object files
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


// STRUCT DECLARE
typedef struct {
	int x;
	int y;
} Point;

// print point
void print_point(Point *p) {
	printf("(%d, %d)\n", p->x, p->y);
}	// close 



// store data in binary format
void store(char fileName[], Point *listPoint, int size) {
	// open file for writing binary
	FILE *file = fopen(fileName, "wb");
	if (file == NULL) {
		printf("Unable to open file: %s\n", fileName);
		return;
	}	// close if
	// write 
	int count = fwrite(listPoint, sizeof(Point), size, file);
	if (count == size)
		printf("Stored successfully\n");
	fclose(file);
}	// close listPoint


// load data from file
void load(char fileName[], Point *listPoint, int size) {
	FILE *file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("Unable to open file: %s\n", fileName);
		return;
	}	// close if
	// read data
	int count = fread(listPoint, sizeof(Point), size, file);
	if (ferror(file)) {
		printf("There is an error while reading file\n");
	}	// close if
	printf("Successfully read %d Points\n", count);
	fclose(file);
}	// close load



// MAIN
int main(int argc, char const *argv[]) {
	// Initialize data
	Point listPoint[10];
	for (int i = 0; i < 10; i ++ ) {
		listPoint[i].x = i;
		listPoint[i].y = -i;
	}	// close for
	// store data
	store("data.bin", listPoint, 10);
	// load data
	Point *otherList = (Point *) malloc (10 * sizeof(Point));
	load("data.bin", otherList, 10);
	// print data
	for (int i = 0; i < 10; i ++ ) 
		print_point(otherList + i);
	return 0;
}	// end  main 