/*����Ʈ����ȸ*/
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode {
	char key; 
	struct treeNode* left; //���� ����Ʈ��
	struct treeNode* right; //������ ����Ʈ��
}treeNode;

// ��� �˻�
treeNode* searchBST(treeNode* root, char x)
{
	if (root == NULL)
	{
		printf("������ ��尡 �����ϴ�.");
		return;
	}
	else
	{
		treeNode* p;
		p = root;
		while (p != NULL)
		{
			if (x < p->key)
				p = p->left;
			else if (x == p->key)
				return p;
			else
				p = p->right;
		}

		printf("\n ã�� Ű�� �����ϴ�!!!");
		return p;
	}
}

//p�� ����Ű�� ��忡 ��� x�� ����
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)
		p->left = insertNode(p->left, x);
	else if (x > p->key)
		p->right = insertNode(p->right, x);
	else
		printf("\n�̹� ���� Ű�� �ֽ��ϴ�.\n");

	return p;
}

//Ű���� ���� ��带 ã�� ����
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	//������ ����� ��ġ �˻�
	while (p != NULL && (p->key != key))
	{
		parent = p;
		if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	//������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\nã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	//������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL)&&(p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
	}
	// ������ ����� �ڽĳ�尡 1���� ���
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL)
			child = p->left;
		else
			child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
		else root = child;
	}
	// ������ ����� �ڽĳ�尡 2���� ���
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) //���� ����Ʈ������ �İ��� ã��
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)
			succ_parent->left = succ->left;
		else
			succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

//����Ʈ�� ����Լ�
void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("%5c", root->key);
		displayInorder(root->right);
	}
}

void sub28()
{
	treeNode* root = NULL;
	treeNode* foundeNode = NULL;
	char choice, key;

	// ����
	root = insertNode(root, 'B');
	//����
	insertNode(root, 'A');
	insertNode(root, 'C');
	insertNode(root, 'D');
	insertNode(root, 'H');
	insertNode(root, 'K');
	insertNode(root, 'E');
	insertNode(root, 'F');
	insertNode(root, 'G');
	insertNode(root, 'I');
	//insertNode(root, 'J'); //�ߺ��� ���� �Ұ�
	insertNode(root, 'J');

	// ���
	displayInorder(root);
	printf("\n----------------------------------------------------------\n");

	// �˻�
	foundeNode = searchBST(root, 'A');
	displayInorder(foundeNode);

	printf("\n----------------------------------------------------------\n");

	// ����
	deleteNode(root, 'E');
	displayInorder(root);

	return 0;
}