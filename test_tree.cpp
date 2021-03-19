#include "tree.h" 
#include "tree.cpp"
#include <iostream>
tree_ptr_t create_rand_tree(tree_ptr_t tree); //declare rand tree function
int print_tree(tree_ptr_t tree); //declare print tree function
int recursive_depth=0; //set global var for recursive depth limit
int key_count = 0; //set the key count globally
double node_child_prob; //set global user input val, this is so that the recursive function can use it, the same applies to the previous two vars.
int main() {
    srand(time(0)); //i'm using rand(), and to ensure randomness, i set the rand seed to the time.
    tree_ptr_t test_tree = create_tree(0, 100); //create a tree with key 0 for testing
    std::cout << "What would you like the probability of each node having a left/right child to be? (in % out of 100): "; 
    //ask user what they want to set the probability to for each node having left/right children
    std::cin>>node_child_prob;//take the user input
    node_child_prob /= 100;//divide by 100 for %
    test_tree = create_rand_tree(test_tree); //creates a random tree based on the user probability
    print_tree(test_tree); //calls print tree function that prints to terminal
    destroy_tree(test_tree); //destroy the original test tree, which includes all of its children
    std::cout << "destroyed tree's: key, value, left, right: " << test_tree->key_<<"<<"<< test_tree->value_<<"<<"<<test_tree->left_<<"<<"<<test_tree->right_;
    //prints out the values of test tree after it has been destroyed, the key and value are set to apparently weird large ints, but their memory has been deallocated
    return 0;
}

tree_ptr_t create_rand_tree(tree_ptr_t tree) {
    if (recursive_depth >= 16)return tree;//check for recursion depth to ensure the tree doesnt get too large, this ends the tree and returns to last call
    recursive_depth++;//increase the depth on every call
    double right_branch = (double) rand() / RAND_MAX; //set random double between 0 and 1 for right branch to decide whether or not it will have a right child
    double left_branch = (double) rand() / RAND_MAX;//same for left
    if (right_branch < node_child_prob && left_branch < node_child_prob) {//if both branch probabilities are less than the user input probability, create two children
        key_count++;//increase the key count so each node has a different key
        tree->left_ = create_tree(key_count, 0);//create a new tree on the left child
        key_count++;//increment the key count for right child
        tree->right_ = create_tree(key_count, 0);//create right child
        create_rand_tree(tree->left_); //call recursion on left child so it will decide if their children will have children
        create_rand_tree(tree->right_);//same for right
        
        recursive_depth--;//reduce the recursion depth because it is returning up the stack one layer
        return tree;//return to previous call
    }
    if (left_branch < node_child_prob) {//if only the left branch is decided to have a child
        key_count++;//same as other key increments
        tree->left_ = create_tree(key_count, 0);//same
        create_rand_tree(tree->left_);
        recursive_depth--;
        return tree;
    }
    if (right_branch < node_child_prob){//same for right
        key_count++;
        tree->right_ = create_tree(key_count, 0);
        create_rand_tree(tree->right_);
        recursive_depth--;
        return tree;
    }
    
    return tree;//if none should have children, return up the call stack one
}
int print_tree(tree_ptr_t tree) {//made for printing the tree for user to see
    for (int i = 0; i <= key_count; i++) {//the key count is global so it can be accessed everywhere, this loop reaches every node in the tree
        std::string path_str = path_to(tree, i);//call path to, both to test it and get the string path to print
        tree_ptr_t curr_node = node_at(tree, path_str);//use the string just returned from path_to and use node_at to get the key count, not really necessary but it tests node_at
        std::cout << "path to node= " + path_str + "  key =  " << curr_node->key_ << "\n";
        //print the path to node and the key, it prints in order of keys, which kind of graphs the randomness of the tree, so the user can see the contents of the tree.
    }
    return 0; 
}