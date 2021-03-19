#include "tree.h" //load header file
#include <iostream> //load iostream

//////////////////////////////////////////////////////////////////////////////

tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right)
{
    Tree* leaf = new Tree; //making new tree in heap for global access
    leaf->key_ = key; //rest of create_tree assigning input values to tree values
    leaf->value_ = value;
    leaf->left_ = left;
    leaf->right_ = right;
    return leaf; //return the pointer to new tree

}


//////////////////////////////////////////////////////////////////////////////
void destroy_tree(tree_ptr_t tree)
{
    if (tree->left_ != nullptr) destroy_tree(tree->left_); //if there is a left node, recurse to it, this will apply to all nodes until there isnt a left one.
    if (tree->right_ != nullptr) destroy_tree(tree->right_); //same as left
    delete tree;//once there isnt a left or right node, it deletes the tree, as it all of its children have already been destroyed
}


//////////////////////////////////////////////////////////////////////////////
bool find(tree_ptr_t tree, key_t key, std::string* path) {//recursive find function to find the key it is looking for
    if (tree->key_ == key)return true; //base case, if the key is correct, it returns up the call stack
    if (tree->left_ != nullptr) { //searching on left node for correct key
        if (find(tree->left_, key, path)) { //call itself on left branch
            path->insert(0, "L"); //returning up call stack it inserts left to indicate the direction
            return true; //return true to last call
        }
    }
    if (tree->right_ != nullptr) {//same for right
        if (find(tree->right_, key, path)) {
            path->insert(0, "R");
            return true;
        }
    }

    return false; //if the key wasnt found, return false.
}
std::string path_to(tree_ptr_t tree, key_t key) {
    std::string path; //defining string before find is called
    if (!find(tree, key, &path)) path = "-"; //calls find and checks if the correct key was found.
    return path; //return the string post find call
}


//////////////////////////////////////////////////////////////////////////////
tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
    int count = 0;//count to increment through string with
    while (path[count] != 0) {//checking for end of string
        if (path[count] != *"L" && path[count] != *"R") return nullptr;//if the current char isnt an R or L, return a null ptr
        if (tree == nullptr)return nullptr; //if the current tree is a null ptr, return a null ptr
        if (path[count] == *"L")tree = tree->left_;//if the char is L go left
        if (path[count] == *"R")tree = tree->right_; //same for right
        count++; //increment count
    }
    return tree; //return the pointer found
}




