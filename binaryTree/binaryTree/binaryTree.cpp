// binaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree treenode;
typedef treenode *btree;

struct tree_t {
	_TCHAR data;
	struct tree_t *left;
	struct tree_t *right;
};
typedef struct tree_t treenode_t;
typedef treenode_t *btree_t;

btree insertnode(btree root, int value)
{
	btree newnode;
	btree current;
	btree back;

	newnode = (btree)malloc(sizeof(treenode) );
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;

	if (NULL == root) {
		return newnode;
	}

	current = root;
	while (current != NULL) {
		back = current;
		if (current->data > value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (back->data > value) {
		back->left = newnode;
	}
	else {
		back->right = newnode;
	}

	return root;
}

btree createbtree(int *data, int len)
{
	btree root = NULL;
	int i;

	for (i = 0; i < len; i++) {
		root = insertnode(root, data[i]);
	}

	return root;
}

void inorder(btree ptr)
{
	if (ptr != NULL) {
		inorder(ptr->left);
		printf("[%2d]\n", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(btree ptr)
{
	if (ptr != NULL) {
		printf("[%2d]\n", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(btree ptr)
{
	if (ptr != NULL) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("[%2d]\n", ptr->data);
	}
}

btree_t insertnode_t(btree_t root, _TCHAR value)
{
	btree_t newnode;
	btree_t current;
	btree_t back;

	newnode = (btree_t)malloc(sizeof(treenode_t) );
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;

	if (NULL == root) {
		return newnode;
	}

	current = root;
	while (current != NULL) {
		back = current;
		if (current->data > value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (back->data > value) {
		back->left = newnode;
	}
	else {
		back->right = newnode;
	}

	return root;
}

btree_t createbtree_t(_TCHAR *data, int len)
{
	btree_t root = NULL;
	int i;

	for (i = 0; i < len; i++) {
		root = insertnode_t(root, data[i]);
	}

	return root;
}

void inorder_t(btree_t ptr)
{
	if (ptr != NULL) {
		inorder_t(ptr->left);
		_tprintf(_T("[%c]\n"), ptr->data);
		inorder_t(ptr->right);
	}
}

void preorder_t(btree_t ptr)
{
	if (ptr != NULL) {
		_tprintf(_T("[%c]\n"), ptr->data);
		preorder_t(ptr->left);
		preorder_t(ptr->right);
	}
}

void postorder_t(btree_t ptr)
{
	if (ptr != NULL) {
		postorder_t(ptr->left);
		postorder_t(ptr->right);
		_tprintf(_T("[%c]\n"), ptr->data);
	}
}

/**
 * 计算二叉树的节点个数
 */
int calcNodeCount(btree root)
{
	int nodeCount = 0;

	if (NULL == root) {
		return 0;
	}

	if (root->left != NULL) {
		nodeCount += calcNodeCount(root->left);
	}

	if (root->right != NULL) {
		nodeCount += calcNodeCount(root->right);
	}

	return nodeCount+1;
}

/**
 * 计算二叉树的高度
 */
int calcTreeHeight(btree root, int level, int *pHeight)
{
	int height = 0;

	if (level > *pHeight) {
		*pHeight = level;
	}

	if (NULL == root) {
		return 0;
	}

	if (root->left != NULL) {
		calcTreeHeight(root->left, level+1, pHeight);
	}

	if (root->right != NULL) {
		calcTreeHeight(root->right, level+1, pHeight);
	}

	return height;
}

void showTreeLeaf_inorder(btree ptr)
{
	if (ptr != NULL) {
		showTreeLeaf_inorder(ptr->left);
		if (NULL == ptr->left && NULL == ptr->right) {
			printf("[%2d]\n", ptr->data);
		}
		showTreeLeaf_inorder(ptr->right);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	 btree root = NULL;
	 int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
	 int nodeCount = 0;
	 int height = 0;
	
	 root = createbtree(data, 9);
	 // inorder(root);
	 // preorder(root);
	 // postorder(root);
	 // nodeCount = calcNodeCount(root);
	 // printf("node count is: %2d", nodeCount);
	 // calcTreeHeight(root, 0, &height);
	 // printf("node height is: %2d", height);
	 showTreeLeaf_inorder(root);


	// btree_t root = NULL;
	// _TCHAR data[7] = { _T('h'), _T('d'), _T('i'), _T('a'), _T('e'), _T('h'), _T('r') };
	// root = createbtree_t(data, 7);
	// inorder_t(root);
	// preorder_t(root);
	// postorder_t(root);

	return 0;
}
