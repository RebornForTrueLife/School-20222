/********************************************
 * tower - move disks from one tower to other tower, satisfy
 * some constrants
 * Uage: 
	- run the object file
	- enter the number of disk at tower A
	- program will print out the steps to move all disks from
	tower A to B
 ********************************************/

#include <stdio.h>


// move 
void move(int tower1, int tower2, int tower3, int n) {
	if (n <= 1) {
		printf("Move from tower %d to tower %d \n", tower1,  tower2);
		return;
	}	// close if
	move(tower1, tower3, tower2, n - 1);
	move(tower1, tower2, tower3, 1);
	move(tower3, tower2, tower1, n - 1);
}	// close move


// MAIN
int main(int argc, char const *argv[]) {
	int n;	// number of disks
	scanf("%d", &n);
	// print out steps
	move(1, 2, 3, n);
	return 0;
}	// end  main 