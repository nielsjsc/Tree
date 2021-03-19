# Tree
 CS 221 Tree HW
Niels Christoffersen
tree.cpp:

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
destroy_tree has been tested by valgrind to ensure it leaks no 
memory

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


test_tree.cpp:
I designed the test_tree file to test all four functions of tree.cpp.
first it creates a test tree with key=0. it then takes a user input int out of 100 to determine
the probability of each node having a left/right child. It then runs the create_rand_tree function 
on the test tree that was created. the random tree function uses the user probability to recursively
create a random tree, then returns the root of the tree. It then calls print_tree, which tests both 
the path_to and node_at functions, and iterates through every key, printing the path to the current 
node, as well as the key, which is found through node at. After print_tree is finished, main calls 
delete_tree, deleting the entire random tree, and deallocating all of the memory taken by it. 

I made sure to include a global variable recursion_depth, which kept track of the height of the tree.
If the depth reached 16, it returns, stopping the creation of nodes beyond a height of 16. this means a full
tree, if probability is set to 100% or higher, will have 2^17 nodes, as the depth count starts at 0. Making a full tree and watching
it print in terminal is a fascinating way to see how it returns up the stack.


BUILDING:

with the g++ compiler, simply compile test_tree.cpp, which includes 
tree.h and tree.cpp. Then run the compiled file, it will take user input, 
generate a random tree, and print every node's key and path_to
to terminal for user observation. 
