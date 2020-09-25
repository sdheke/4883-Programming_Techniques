// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/16/2020

#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
    int value;
    node * left;
    node * right;

    node()
    {
        left = nullptr;
        right = nullptr;
    }
}node;

void post_order(node * tree);
void place_node(node * tree, node * new_node);

int main(void)
{
    node * Tree = nullptr;
    int key;
    while(cin >> key){

        if(Tree == nullptr){
            Tree = new node();
            Tree->value = key;
            continue;
        }

        node * new_node = new node();
        new_node->value = key;

        place_node(Tree, new_node);
    }

    post_order(Tree);
    return 0;
}

void post_order(node * tree)
{
    if(tree == nullptr)
        return;
    post_order(tree->left);
    post_order(tree->right);
    cout << tree->value << endl;
    return;
}

void place_node(node * tree, node * new_node)
{
    while(true)
        if(tree->value > new_node->value)
        {
            if(tree->left == nullptr)
            {
                tree->left = new_node;
                return;
            }
            else
                tree = tree->left;
        }
        else
        {
            if(tree->right == nullptr)
            {
                tree->right = new_node;
                return;
            }
            else
                tree = tree->right;
        }

    return;
}