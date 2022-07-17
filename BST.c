#include<stdio.h>
#include<stdlib.h>

//template of node using typedef
/* it is simlar to 
struct node
{
    int data;
    struct node *right,*left;
};
*/
typedef struct node
{
    int data;
    struct node *right,*left;
}node;


// create a BST(binary searh tree)
node *insertIntoBST(node *root,int val)
{
    if(root == NULL)
    {
        root = (node *) malloc(sizeof(node));
        root->data = val;
        return root;
    }
    // given val is greater than root->dat then go to right sub tree
    if(val > root->data)
    {
        //then go to insert in right sub tree 
        root->right = insertIntoBST(root->right,val);
    }
    // given val is lesser than root->dat then go to left sub tree
    else
    {
        //then go to insert in left sub tree

        root->left = insertIntoBST(root->left,val);
    }
    // finally returning root

    return root;
}

// taking input using preorder method

node *takingInput(node *root)
{
    int val;
    // enter -1 to end creation of BST
    printf("Enter data:");
    scanf("%d",&val);
    while(val != -1)
    {
        root = insertIntoBST(root,val);
        printf("Enter data:");
        scanf("%d",&val);
    }
    return root;
}
//inorder traversal and also increasing order
void inorder(node *root)
{
    if(root == NULL){
        return;
    }
    //travelling left sub tree 
    inorder(root->left);
    //printing data
    printf("%d\t",root->data);
    //traversal right sub tree
    inorder(root->right);

}
/*
left view of tree
for example 
15 10 7 13 24 20 30 36 is a balance tree
                 15
            10        24
          7   13   20    30
                             36
Is a BST
so right view of tree is : 15 10 7 36
*/
// this is function
void leftview(node *root,int level,int *heightLevel)
{
    if(root == NULL){
        return;
    }
    //if we are not visited level then print first element in that element
    if(*heightLevel < level){
        printf("%d\t",root->data);
        *heightLevel = level;
    }
    //by using recursion we can print left view of left sub tree
    leftview(root->left,level+1,heightLevel);
    //any elements are seen in right sub tree from left view
    leftview(root->right,level+1,heightLevel);
    //cout<<endl;
}
void printLeftView(node *root)
{
    //checking given root is NULL 
    if(root == NULL){
        return;
    }
    else{
        //then print left view
        //we can print left view by simply tracking height of tree using pointer
        int heightLevel = 0;
        leftview(root,1,&heightLevel);//1 represnts as root node is not NULL
    }
}


/*
right view of tree
for example 
15 10 7 13 24 20 30 36 is a balance tree
                 15
            10        24
          7   13   20    30
                             36
Is a BST
so right view of tree is : 15 24 30 36 
*/
// this is function 
void rightview(node *root,int level,int *heightLevel)
{
    if(root == NULL){
        return;
    }

    if(*heightLevel < level){
        printf("%d\t",root->data);
        *heightLevel = level;
    }
    
    rightview(root->right,level+1,heightLevel);
    rightview(root->left,level+1,heightLevel);
}

void printRightView(node *root)
{
    //checking given root is NULL 
    if(root == NULL){
        return;
    }
    else{
        //then print left view
        //we can print right view as left view by simply tracking height of tree using pointer
        int heightLevel = 0;
        rightview(root,1,&heightLevel);//1 represnts as root is null root node is there
    }
}


//main program
int main()
{
    node *root = NULL;
    int choice;
    do
    {
        printf("\n**********MAIN MENU********\n");
        printf("1.Insert a element or to create a BST\n");
        printf("2.Inorder traversal\n");
        printf("3.print left view\n");
        printf("4.print right view\n");
        printf("0.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:root = takingInput(root);
                          break;
            case 2:inorder(root);
                   break;
            case 3:printLeftView(root);
                   break;
            case 4:printRightView(root);
                   break;
        }
    }while(choice != 0);
    
    return 0;
}
