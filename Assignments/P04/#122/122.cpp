// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/18/2020

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


typedef struct node
{
    int value;
    node* left;
    node* right;
}node;

bool traverse_bt(node* tree, map <int, bool> tree_values);
void delete_bt(node* tree);

int main(void)
{
    string binary;
    while (cin >> binary)
    {
        node* tree = nullptr;
        bool not_complete = false;

        while (binary != "()") 
        {
            bool value_exists = false;
            int value = 0;
            string path;

            for (int i = 0; i < binary.size(); ++i)
                if (binary[i] >= '0' && binary[i] <= '9') 
                {
                    value_exists = true;
                    value = value * 10 + binary[i] - '0';
                }
                else if (binary[i] == 'L' || binary[i] == 'R')
                    path = path + binary[i];

            if (tree == nullptr) 
            {
                tree = new node;
                tree->value = -1;
                tree->left = nullptr;
                tree->right = nullptr;
            }

            node* tmp = tree;
            for (int i = 0; i < path.size(); ++i)
                if (path[i] == 'L') 
                {
                    if (tmp->left == nullptr)
                    {
                        node* left_current = new node;
                        left_current->value = -1;
                        left_current->left = nullptr;
                        left_current->right = nullptr;

                        tmp->left = left_current;
                        tmp = left_current;
                    }
                    else
                        tmp = tmp->left;
                }
                else 
                {
                    if (tmp->right == nullptr) 
                    {
                        node* right_current = new node;
                        right_current->value = -1;
                        right_current->left = nullptr;
                        right_current->right = nullptr;

                        tmp->right = right_current;
                        tmp = right_current;
                    }
                    else
                        tmp = tmp->right;
                }
            if (value_exists) 
            {
                if (tmp->value != -1)
                    not_complete = true;
                tmp->value = value;
            }

            cin >> binary;
        }

        vector <int> path;
        queue <node*> Queue;

        Queue.push(tree);

        while (!not_complete && !Queue.empty())
        {
            node* front = Queue.front();
            Queue.pop();
            if (front->value != -1)
                path.push_back(front->value);
            else
                not_complete = 1;

            if (front->left != nullptr)
                Queue.push(front->left);
            if (front->right != nullptr)
                Queue.push(front->right);
        }

        if (not_complete)
            cout << "not complete" << endl;
        else 
        {
            cout << path[0];
            for (int i = 1; i < path.size(); ++i)
                cout << ' ' << path[i];
            cout << endl;
        }

        delete_bt(tree);
        tree = nullptr;
    }
    return 0;
}

void delete_bt(node* tree)
{
    if (tree == nullptr)
        return;

    delete_bt(tree->left);
    delete_bt(tree->right);
    delete tree;

    return;
}