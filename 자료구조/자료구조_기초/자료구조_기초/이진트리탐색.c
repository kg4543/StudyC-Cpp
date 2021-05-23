/*이진트리순회*/
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode {
	char key; 
	struct treeNode* left; //왼쪽 서브트리
	struct treeNode* right; //오른쪽 서브트리
}treeNode;

// 노드 검색
treeNode* searchBST(treeNode* root, char x)
{
	if (root == NULL)
	{
		printf("생성된 노드가 없습니다.");
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

		printf("\n 찾는 키가 없습니다!!!");
		return p;
	}
}

//p가 가리키는 노드에 노드 x를 삽입
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
		printf("\n이미 같은 키가 있습니다.\n");

	return p;
}

//키값이 같은 노드를 찾아 삭제
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	//삭제할 노드의 위치 검색
	while (p != NULL && (p->key != key))
	{
		parent = p;
		if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	//삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	//삭제할 노드가 단말 노드인 경우
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
	// 삭제할 노드의 자식노드가 1개인 경우
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
	// 삭제할 노드의 자식노드가 2개인 경우
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) //왼쪽 서브트리에서 후계자 찾기
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

//이진트리 출력함수
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

	// 생성
	root = insertNode(root, 'B');
	//삽입
	insertNode(root, 'A');
	insertNode(root, 'C');
	insertNode(root, 'D');
	insertNode(root, 'H');
	insertNode(root, 'K');
	insertNode(root, 'E');
	insertNode(root, 'F');
	insertNode(root, 'G');
	insertNode(root, 'I');
	//insertNode(root, 'J'); //중복값 삽입 불가
	insertNode(root, 'J');

	// 출력
	displayInorder(root);
	printf("\n----------------------------------------------------------\n");

	// 검색
	foundeNode = searchBST(root, 'A');
	displayInorder(foundeNode);

	printf("\n----------------------------------------------------------\n");

	// 삭제
	deleteNode(root, 'E');
	displayInorder(root);

	return 0;
}