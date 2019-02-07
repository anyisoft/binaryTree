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

/**
 * 线索二叉树
 */
struct t_tree {
	int data;             // 节点数据
	int lefthread;        // 是否左线索
	int righthread;       // 是否右线索
	struct t_tree *left;  // 左子树
	struct t_tree *right; // 右子树
};
typedef struct t_tree t_treenode;
typedef t_treenode *t_btree;

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

/**
 * 插入线索二叉树的节点
 */
t_btree t_insertnode(t_btree root, int value)
{
	t_btree newnode;
	t_btree current;
	t_btree parent;
	t_btree previous;
	int     pos;

	newnode = (t_btree)malloc(sizeof(treenode) );
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->lefthread = 1;
	newnode->righthread = 1;

	current = root->right;
	if (NULL == current) {
		root->right = newnode;
		newnode->left = root;
		newnode->right = root;

		return root;
	}

	parent = root;
	pos = 0;
	while (current != NULL) {
		if (current->data > value) {
			if (pos != -1) {
				pos = -1;
				previous = parent;
			}
			parent = current;
			if (current->lefthread == 0 ) {
				current = current->left;
			}
			else {
				current = NULL;
			}
		}
		else {
			if (pos != 1) {
				pos = 1;
				previous = parent;
			}
			parent = current;
			if (current->righthread == 0) {
				current = current->right;
			}
			else {
				current = NULL;
			}
		}
	}
	if (parent->data > value) {
		parent->lefthread = 0;
		parent->left = newnode;
		newnode->left = previous;
		newnode->right = parent;
	}
	else {
		parent->righthread = 0;
		parent->right =newnode;
		newnode->left = parent;
		newnode->right = previous;
	}

	return root;
}

/**
 * 创建线索二叉树
 */
t_btree createtbtree(int *data, int len)
{
	t_btree root = NULL;
	int i;

	// 创建线索二叉树头节点
	root = (t_btree)malloc(sizeof(t_treenode) );
	root->left = root;
	root->right = NULL;
	root->lefthread = 1;
	root->righthread = 0;

	for (i = 0; i < len; i++) {
		root = t_insertnode(root, data[i]);
	}

	return root;
}

/**
 * 线索二叉树中序遍历输出
 */
void printbtree(t_btree root)
{
	t_btree ptr;

	ptr = root;
	do {
		if (1 == ptr->righthread) {
			ptr = ptr->right;
		}
		else {
			ptr = ptr->right;
			while (ptr->lefthread != 1) {
				ptr = ptr->left;
			}
		}
		if (ptr != root) {
			printf("[%d]\n", ptr->data );
		}
	} while (ptr != root);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// btree root = NULL;
	int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
	// int nodeCount = 0;
	// int height = 0;
	
	// root = createbtree(data, 9);
	// inorder(root);
    // preorder(root);
	// postorder(root);
	// nodeCount = calcNodeCount(root);
	// printf("node count is: %2d", nodeCount);
	// calcTreeHeight(root, 0, &height);
	// printf("node height is: %2d", height);
	// showTreeLeaf_inorder(root);


	// btree_t root = NULL;
	// _TCHAR data[7] = { _T('h'), _T('d'), _T('i'), _T('a'), _T('e'), _T('h'), _T('r') };
	// root = createbtree_t(data, 7);
	// inorder_t(root);
	// preorder_t(root);
	// postorder_t(root);

	t_btree root = NULL;

	root = createtbtree(data, 9);
	printf("thread tree's content: \n");
	printbtree(root);

	return 0;
}
