
## find node
```
find-node ( node, name ):
	IF node == NULL: 			// terminate condition
		RETURN NULL
	IF node.name == name 		// found node!
	FOR sib IN node.sibling:    // search every sibling
		IF (sib.name == name):	// found node in sibling list
			RETURN sib
	find-node(node.leftMostChild) 	// search name for subtree of current Node
	FOR sib IN node.sibling:
		result = find-node( sib.leftMostChild, name)		// search for subtree of each node's sibling 
		IF result != NULL: 			// found
			RETURN result
	RETURN NULL 					// not found any match in given node
```

## Load tree from given file
```
load ( file )
	line0 = file.line[0] 									// read line 0
	root = line0.getString(0) 								// get first string of line 0
	FOR string in line0[1 .. ]:
		root.addChild( string )								// add children for root
	For line in file.line[1 .. ]: 							// read all lines left
		parent = find-node( root, line.getString(0) )				// read the parent of current line
		IF parent == NULL: 									// the node has not appeared in the tree
			RAISE WARNING: un-notice name: line.getString(0)
		FOR string in line[1 .. ]:
			parent.addChild( string )

```

## height of the given node of the tree
> number level of longest path from given node to its leaves
> find-height ( node )
	- find-height each child, return (height + 1): 1 step from child to the node
	- base-case is NULL, return height = 0
