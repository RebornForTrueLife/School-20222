
# Maze problem 

***This is the strategy to solve the maze problem***


## Problem

Given a maze represented by a 2-dimension matrix and start location(i.e index of a cell in the matrix). The objective is to find the shortest path to get out the maze, start from the start-location.

A cell in matrix can be 2 types: blocked(represented by 1), non-blocked(represented by 0). From a location, we can only move to 4 directions: up-right-down-left and also can only move to non-blocked cell. 

Return the number of step needs to perform that shortest path. In case that is unable to find any exit path, return -1.


## Strategy

> Modelize the path space by tree-data-structure. To find the shortest exit path, using breadth-first-search method

*Note: from there, we can inply that if all leaves are locations where we can not move, we can conclude that we can not find any path to exit the maze* 

1. Modelize problem

- The maze: 2-dimension matrix, it is different from initial input matrix. The maze now is bound by set of cells, has value of -1 to easily determine whether we are out of maze.

- location: a structure of 2 integer value, represents the index of the cell. To move up, right, down, left: denote loc.up, ...

- queue: which is used to implement the search approach, to store all possible moves in breadth-first order.


## Code design

```
PathTree {
	root
	maze
}

Node {
	value: Location
	parent: Node
	children: list of Node
}

buildPathTree ( tree ):
	root = {startLocation, NULL, EMPTY}
	ENQUEUE root TO queue
	WHILE queue is not EMPTY:
		node = DEQUEUE queue
		IF isExit(node) is TRUE:
			RETURN node
		born(node)
		pruneNode(tree, node)
		ENQUEUE node.children TO queue
	RETURN NULL

isExit ( node ):
	RETURN node.value == -1

born( node ):
	path: list of Node
	parent = node.parent
	WHILE parent != NULL: 			// find path from root to this node
		path.add(parent)
		parent = parent.parent
	currentLocation = node.value
	moveSpace = [UP, RIGHT, DOWN, LEFT] of currentLocation
	possibleMove: list of Location
	FOR loc IN moveSpace:
		IF maze[loc] == 1:
			CONTINUE
		IF loc isAppear(path):
			CONTINUE
		possibleMove.add(loc)

pruneNode ( tree, node )
	
```