#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include "tree.h"

typedef struct pair{       //This structure is used for holding the seekitem info
    Trnode *parent;
    Trnode *child;
}Pair;

static Trnode *MakeNode (const Item *pi);
static Pair SeekItem(Item *pi, Tree *ptree);
static void AddNode(Trnode *new_node, Trnode *root);
static bool ToLeft(const Item *p1, const Item *p2);
static bool ToLeft(const Item *p1, const Item *p2);
static void DeleteNode(Trnode **ptr);


void InitializeTree(Tree *ptree)
{
    ptree->root=NULL;
    ptree->size=0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    return ptree->size==0;
}

bool TreeIsFull(const Tree *ptree)
{
    return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    /*1.search the item, if the item is not in the tree
    2. Make a node to hold the item
    3. find the place in the tree to add the node */
    Trnode *new_node;
    if(TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full.\n");
        return false;
    }

    if(SeekItem(pi,ptree).child!=NULL) // find the same item
    {
        fprintf(stderr, "Can not add duplicated items.\n");
        return false;
    }
    //below code describes when not find the duplicate item
    new_node = MakeNode(pi);
    ptree->size++;
    if(ptree->root==NULL)
    ptree->root = new_node;
    else
    AddNode(new_node,ptree->root);
    return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi,ptree).child==NULL)?false:true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    if(TreeIsEmpty(ptree))
    {
        fprintf(stderr,"No item to delete.\n");
        return false;
    }
    if(!InTree(pi,ptree))
    {
        fprintf(stderr,"Did not find item in tree.\n");
        return false;
    }
    Pair look;
    look = SeekItem(pi,ptree);
    if(look.parent==NULL)
    DeleteNode(&ptree->root);
    else if (look.parent->left==look.child)
    DeleteNode(&look.parent->left);
    else
    DeleteNode(&look.parent->right);
    ptree->size--;
    return true;


}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    while(ptree!=NULL)
    InOrder(ptree->root,pfun);
}

static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if(root!=NULL)
    {
        InOrder(root->left,pfun);
        (*pfun)(root->item);
        InOrder(root->right,pfun);
    }
}

void DeleteAll(Tree *ptree)
{
    if(ptree!=NULL)
    DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size=0;
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if(root!=NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode *ret_val;
    ret_val = (Trnode *)malloc(sizeof(Trnode));
    if(ret_val==NULL)
    {
        fprintf(stderr,"Allocate memory failed\n");
        exit(1);
    }
    ret_val->left=ret_val->right=NULL;
    ret_val->item = *pi;
    return ret_val;
}

static void AddNode(Trnode *new_node, Trnode *root)
{
    if(ToLeft(&new_node->item,&root->item)) // if item is on the left of root
    {
        if(root->left = NULL)
        root->left = new_node;
        else
        AddNode(new_node,root->left);
    }
    else if (ToRight(&new_node, &root->item))
    {
        if(root->right==NULL)
        root->right = new_node;
        else
        AddNode(new_node,root->right);
    }
    else
    {
        fprintf(stderr,"Location error in AddNode()\n");
        exit(1);
    }
    
}

static bool ToLeft(const Item *p1, const Item *p2)
{
    int comp1;
    comp1 = strcmp(p1->petname,p2->petname);
    if(comp1 >0)
    return true;
    else if (comp1==0 && strcmp(p1->petkind,p2->petkind)>0)
    return true;
    else return false;
}

static bool ToLeft(const Item *p1, const Item *p2)
{
    int comp1;
    comp1 = strcmp(p1->petname,p2->petname);
    if(comp1 < 0)
    return true;
    else if (comp1==0 && strcmp(p1->petkind,p2->petkind)<0)
    return true;
    else return false;
}

static Pair SeekItem(Item *pi, Tree *ptree)
{
    Pair look;
    look.parent=NULL;
    look.child = ptree->root;
    if(look.child==NULL)
    return look;
    while(look.child!=NULL)
    {
        if(ToLeft(pi,&(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if(ToRight(pi,&(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else break;       
    }
    return look;
}

static void DeleteNode(Trnode **ptr)
{
    Trnode *temp;
    if((*ptr)->left==NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if((*ptr)->right==NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for(temp =(*ptr)->left;temp->right!=NULL;temp = temp->right)
        continue;
        temp->right = (*ptr)->right;
        temp = (*ptr);
        *ptr = (*ptr)->left;
        free(temp);
    }
    
}