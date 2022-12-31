#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *leftAdr, *rightAdr;
}*root=NULL;

struct node *insert(struct node *root, int ele){
    if(root==NULL){
        root = (struct node *)malloc(sizeof(struct node));
        root->key = ele;
        root->leftAdr = root->rightAdr = NULL;
    }
    
    if(root->key > ele)
        root->leftAdr = insert(root->leftAdr, ele);
    else if(root->key < ele)
        root->rightAdr = insert(root->rightAdr, ele);

    return root;
}

void preorder(struct node *temp)
{
	if (temp!=NULL)
	{
		printf(" => %d ",temp->key);
		preorder(temp->leftAdr);
		preorder(temp->rightAdr);
	}
}

void inorder(struct node *temp)
{
	if (temp!=NULL)
	{
		inorder(temp->leftAdr);
		printf(" => %d ",temp->key);
		inorder(temp->rightAdr);
	}
}

void postorder(struct node *temp)
{
	if (temp!=NULL)
	{
		postorder(temp->leftAdr);
		postorder(temp->rightAdr);
		printf(" => %d ",temp->key);
	}
}

int searchEle(struct node *root, int searchKey){
	if(root == NULL)
		return 0;
	if(root->key == searchKey)
		return 1;
		
	if(root->key > searchKey)
		searchEle(root->leftAdr, searchKey);
	else
		searchEle(root->rightAdr, searchKey);
}

struct node* maxEle(struct node *root){
	if(root->rightAdr!=NULL)
		root = maxEle(root->rightAdr);

	return root;
}

struct node* minEle(struct node *root){
	if(root->leftAdr!=NULL)
		root = minEle(root->leftAdr);

	return root;
}

int height(struct node *root){
	if(root==NULL)
		return -1;
		
	int leftHeight = height(root->leftAdr);
	int rightHeight = height(root->rightAdr);

	if(leftHeight > rightHeight)
		return(leftHeight+1);
	else
		return(rightHeight+1);
}

int depthOfEle(struct node *root, int ele){
	if(root==NULL)
		return -1;
		
	if(root->key < ele)
		return 1 + depthOfEle(root->rightAdr, ele);
	else if(root->key > ele)
		return 1 + depthOfEle(root->leftAdr, ele);

	return 0;
}

int main(void) {
	
	 	    root = insert(root, 4);
        root = insert(root, 2);
        root = insert(root, 3);
        root = insert(root, 1);
        root = insert(root, 6);
        root = insert(root, 5);
        root = insert(root, 7);
        
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");    
	postorder(root);
	printf("\n");    
	
	printf((searchEle(root, 7) == 1)?"Element is present\n":"Element is not present\n");
	
	printf("MAX ELEMENT = %d\n",maxEle(root)->key);
	
	printf("MIN ELEMENT = %d\n",minEle(root)->key);
	
	printf("HEIGHT = %d\n",height(root));
	
	printf("DEPTH = %d\n",depthOfEle(root,2));
	
	return 0;
}
