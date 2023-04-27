#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL){
// call the function recursively for the left sub tree
    traverseInOrder(root -> left);
// print the root
    cout << root -> key << " ";
// call the function recursively for the right sub tree
    traverseInOrder(root -> right);
  }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // if the root is null that means tree is empty
  if (node == NULL){
    // So create a new node to storing that key and return it
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
// se the key as the key of the new node.
    newNode -> key = key;
// set right to the null because there is no elements in the right
    newNode -> right = NULL;
// set left to the null because there is no elements in the left
    newNode -> left = NULL;
    return newNode;

  // if key is less than or equal root go to the left sub tree
  } else if (key <= node -> key){
      // call the function recursive by passing the left child of the root
      node -> left = insertNode(node -> left, key);
  // if key is less than root go to the left sub tree
  } else {
      // call the function recursive by passing the right child of the root 
      node -> right = insertNode(node -> right, key);
  }
  // return the updated tree(root)
  return node;
}

//Function to find minimum in the tree. 
node* FindMin(node* root)
{
  // since min key is in the final left sub tree trvael untill the root . left is not null
	while(root->left != NULL) {
      root = root->left;
  } 
	return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

// code segment find the node that we want to delete.
if(root == NULL) {
  return root; 
// If key is less than the root.key it means the node we want delete is in the left sub tree.
}else if( key < root->key) {
  // So recursively call the function to left sub tree.
   root->left = deleteNode(root->left,key);
}
// If key is greater than the root.key it means the node we want delete is in the right sub tree.
else if ( key > root->key) {
  // So recursively call the function to right sub tree.
  root->right = deleteNode(root->right,key);
}

// if the key is equal to the root
else {
		// Case 1:  when node has No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: when the node has One child 
    // if there is no children in the left sub tree. update the current root to the right sub tree
		else if(root->left == NULL) {
      // create a temporary node to hold the root
			struct node *temp = root;
      // assign the right of the root to the root
			root = root->right;
      // delete the temp node
			delete temp;
		}
    // if there is no children in the right sub tree. update the current root to the left sub tree
		else if(root->right == NULL) {
      // create a temporary node to hold the root
			struct node *temp = root;
      // assign the left of the root to the root
			root = root->left;
			delete temp;
		}
		// case 3: when node has 2 children
		else { 
      // find the minimum of the right sub tree and put it to a temp node
			struct node *temp = FindMin(root->right);
      // update the root.key to the temp.key since it is the new key of the updated tree.
			root-> key = temp-> key;
      // delete the minimum of the right sub tree and get the updated right subtree
			root->right = deleteNode(root->right,temp->key);
		}
	}
	return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
