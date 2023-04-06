#include <stdio.h>
#include <stdlib.h>


struct Point {
	int x;
	int y;
	int *p;
};	// close Point


void print_point(struct Point *p) {
	printf("x = %d; y = %d\n", p->x, p->y);
	printf("size of point = %ld\n", sizeof(p));
}	// close print_point


int main(int argc, char const *argv[]) {
	struct Point p;
	p.x = 0;
	p.y = 1;
	print_point(&p);
	printf("x = %d; y = %d\n", p.x, p.y);
	return 0;
}	// end  main 