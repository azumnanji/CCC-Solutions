#include <iostream>
#include <queue>
#include "lab3_binary_search_tree.hpp"

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	size = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {

}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	if (size == 0)
		return BinarySearchTree::TaskItem(-1, "N/A");
	else{
		TaskItem* curr = root;
		while (curr->right != NULL){
			curr = curr->right;
		}
		return (*curr);
	}
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	if (size == 0)
		return BinarySearchTree::TaskItem(-1, "N/A");
	else{
		TaskItem* curr = root;
		while (curr->left != NULL){
			curr = curr->left;
		}
		return (*curr);
	}
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
	return 0;
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
	queue<TaskItem*> q;
	
	if (root) 
		q.push(root); 
	while (!q.empty()) {
		TaskItem *cur = q.front();
		cout << cur->description << endl;
		if (cur->left) 
			q.push(cur->left); 
		if (cur->right) 
			q.push(cur->right);
		q.pop();
	}
	cout << endl;
}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	if (root == NULL)
		return false;
	TaskItem* curr = root;
	while (curr != NULL){
		if (*curr == val)
			return true;
		else if (val.priority > curr->priority)
			curr = curr->right;
		else if (val.priority < curr->priority)
			curr = curr->left;
	}
	return false;
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return NULL;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return NULL;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
	if (size == 0){
		root = new TaskItem(val);
		size++;
		return true;
	}
	else if (exists(val))
		 return false;
	else{
		size++;
		TaskItem* curr = root;
		while (curr != NULL){
			if (val.priority > curr->priority){
				if (curr->right == NULL){
					curr->right = new TaskItem(val);
					return true;
				}
				curr = curr->right;
			}
			else if (val.priority < curr->priority){
				if (curr->left == NULL){
					curr->left = new TaskItem(val);
					return true;
				}
				curr = curr->left;
			}
		}

	}
    return false;
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
	if (size == 0 || !exists(val))
		return false;
	else{
		TaskItem* curr = root;
		TaskItem* rightMin = NULL;
		TaskItem* leftMax = NULL;
		while(*curr != val){
			if (val.priority < curr->priority)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr->right == NULL && curr->left == NULL){
			delete curr;
			curr = NULL;
		}
		else if (curr->right != NULL && curr->left != NULL){
			leftMax = curr->left;
			while(leftMax->right!= NULL)
				leftMax = leftMax->right;
			TaskItem temp = *curr;
			*curr = *leftMax;
			*leftMax = temp;
			if (leftMax->right == NULL && leftMax->left == NULL)
				delete leftMax;
		}
		else if (curr->right != NULL || curr->left != NULL)
			TaskItem* swap = (curr->right == NULL) ? curr->left:curr->right;
			curr
		}
	}
    return false;
}
