//review activities quiz 3

#include <iostream>
#include <stack>

using namespace std;

stack<int> remove_median_from_stack(stack<int> p){
	stack<int> q;
	if (p.empty())
		return p;

	int med1, med2;
	if (p.size() % 2 == 0){
		med1 = p.size() / 2;
		med2 = med1 - 1;
	}
	else
		med1 = med2 = p.size()/2;
	int last = p.size() - 1;
	int count = 0;
	while(last - count >= med1 || last - count >= med2){
		int temp = p.top();
		p.pop();
		if (last - count != med1 && last - count != med2){
			q.push(temp);
		}
		++count;
	}
	int i = q.size();

	for (int j = 0; j < i; j++){
		p.push(q.top());
		q.pop();
	}
	return p;
}

class SpecialQueue{
	stack<int> s1, s2;
	int size;
public:
	SpecialQueue():size(0){}

	void enqueue(int num){
		if (size == 0)
			s1.push(num);
		else{
			s2.push(num);
			while (!s1.empty()){
				int temp = s1.top();
				s1.pop();
				s2.push(temp);
			}
			stack<int> temp = s2;
			s2 = s1;
			s1 = temp;
		}
		++size;
	}

	void dequeue(){
		s1.pop();
		size--;
	}

	int top(){
		return s1.top();
	}
};

struct BinaryTreeNode{
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	int data;
};

void inorder_using_stack(BinaryTreeNode* T){
	stack<BinaryTreeNode*> s;
	BinaryTreeNode* curr = T;
	if (curr == NULL)
		return;
	else{
		while(!s.empty() || curr){
			if (curr){
				s.push(curr);
				curr = curr->left;
			}
			else if (!s.empty()){
				curr = s.top();
				s.pop();
				cout << curr->data << " ";
				curr = curr->right;
			}
		}

	}
}

void print_BFT(BinaryTreeNode* T){
	queue<BinaryTreeNode*> q;
	BinaryTreeNode* curr = T;
	if (T)
	    q.push(T);
	while (!q.empty()){
	    cout << q.front()->data << " ";
	    curr = q.front();
	    q.pop();
	    if (curr->left)
	        q.push(curr->left);
	    if (curr->right)
	        q.push(curr->right);
	}
}

BinaryTreeNode* create_minimal_height_BT(int A[], int first, int last) {    
    if (last < first) return NULL; // the range is empty, so terminate
    
    int middle = (first + last) / 2; // compute the middle point in the array
    BinaryTreeNode* newNode = new BinaryTreeNode(A[middle]);
    newNode->left = create_minimal_height_BT(A, first, middle - 1);
    newNode->right = create_minimal_height_BT(A, middle + 1, last);
    return newNode;
}

// PURPOSE: Creates a minimal-height binary tree from a given array
BinaryTreeNode* create_minimal_height_BT(int A[], int length) {
	return create_minimal_height_BT(A, 0, length - 1);
}

int main(){
	stack<int> a;
	for (int i = 0; i < 3; i ++)
		a.push(i);
	stack<int> q = remove_median_from_stack(a);
	int b = q.size();
	for (int i = 0; i < b; i ++){
		cout << q.top() << " ";
		q.pop();
	}
	BinaryTreeNode* T = create_minimal_height_BT(A, 8);


	 
}