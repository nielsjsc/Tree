# Tree
 CS 221 Tree HW
Niels Christoffersen

create_tree:
for the create_tree function, 
i made sure to use "new" so the new tree was stored in the heap
as opposed to the local stack of create_tree.

destroy_tree:
for destroy_tree,
it was a simple three line recursive function
that went down the tree from the "root" and once it reached
the "leaf", it destroys the leaf and returns up the call stack
destroying each node.

path_to:
for path_to i used two functions,
find is a recursive function that 
searches every value of a tree until it finds
the correct key, then appends an L or R for whichever direction it went
then returns to path_to, which returns the string to the caller.

node_at:
the only non recursive function,
node_at was a simple while loop that 
incremented through the string until it reached 0,
which signals the end of the string. it moved the pointer left or right
depending on the current char of the string.
it then returns the final pointer.
if any errors occur in the string, it returns nullptr.

BUILDING:

with the g++ compiler, simply compile Test_tree.cpp, which includes 
tree.h and Tree.cpp. Then run it, it will take user input, 
generate a random tree, and print every node's key and path_to
to terminal for user observation. 
