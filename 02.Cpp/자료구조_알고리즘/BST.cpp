#include <iostream>

using namespace std;

class BST {
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node(int d) :data(d), left(NULL), right(NULL) {};
	};

private:
	Node* root;
public:

	Node* BST_Insert(Node* root, int data) {
		if (root == nullptr)
			root = new Node(data);
		else {
			if (root->data > data) //들어온 데이터가 현재노드의 데이터보다 작으면 왼쪽
				root->left = BST_Insert(root->left, data);
			else if(root->data < data) // 크면 오른쪽
				root->right = BST_Insert(root->right, data);
		}
		return root;
	}

	Node* BST_Delete(Node* parent, Node* root, int data) {
		if (root == nullptr)
			return nullptr;
		else if (root->data < data)
			root->right = BST_Delete(root, root->right, data);
		else if (root->data > data)
			root->left = BST_Delete(root, root->left, data);
		else {
			Node* temp = nullptr;
			
			if (root->left || root->right) {

				if (root->left) {

					temp = BST_FindMax(root->left);
					root->data = temp->data;
					root->left = BST_Delete(root, root->left, root->data);

				}
				else {
					temp = BST_FindMin(root->right);
					root->data = temp->data;
					root->right = BST_Delete(root, root->right, root->data);
				}
			}
			else {
				if (parent->left == root)
					parent->left = nullptr;
				else if (parent->right == root)
					parent->right = nullptr;

				delete root;
				return nullptr;
			}
		}
	}

	int BST_Find(Node* root, int data) {
		if (root->left)
			BST_Find(root->left, data);
		if (root->data == data)
			return data;
		if (root->right)
			BST_Find(root->right, data);

		return -1;
	}

	Node* BST_FindMax(Node* root) {
		if (root->right) {
			return BST_FindMax(root->right);
		}
		else
			return root;
	}

	Node* BST_FindMin(Node* root) {
		if (root->left) {
			return BST_FindMin(root->left);
		}
		else
			return root;
	}
};