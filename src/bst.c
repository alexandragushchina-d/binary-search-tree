
#include <stdlib.h>

#include "bst.h"

void free_node(struct node *node)
{
    if ( node )
    {
        free(node);
    }
}

struct node *new_node(int val) {
    struct node *res = (struct node*) malloc(sizeof(struct node));
    if (res) {
        res->val = val;
        res->left = 0;
        res->right = 0;
    }
    return res;
}

struct node *insert_node(struct node *root, struct node *node) {
    if(!root) {
        return node;
    } 
    if(!node) {
        return root;
    }

    if(root->val >= node->val) {
        if(!root->left) {
            root->left = node;
        } else {
            insert_node(root->left, node);
        }
    } else {
        if(!root->right) {
            root->right = node;
        } else {
            insert_node(root->right, node);
        }
    }
    return root;
}

int find_min_val(struct node *root) {
    struct node *curr = root;
    while(curr->left) {
        curr = curr->left;
    }

    return curr->val;
}

struct node *remove_min_right_node(struct node *root, struct node *node) {
  while(node->left) {
      root = node;
      node = node->left;
  }
   if (root->left == node) {
    root->left = 0;
  } else {
    root->right = 0;
  }
  return node;
}

struct node *remove_node(struct node *root, int val) {
    struct node *res = root;
    if(!root) {
        return res;
    }
    if(root->val == val) {
        if(root->left && root->right) {
            //root->val = find_min_val(root->right);
            //root->right = remove_node(root->right, root->val);
            res = remove_min_right_node(root, root->right);
            res->right = root->right;
            res->left = root->left;
            free_node(root);
        } else {
            if(root->left) {
                res = root->left;
            } else if(root->right) {
                res = root->right;
            } else {
                res = 0;
            }
            free_node(root);
        }
    } else {
        if (root->val >= val) {
            root->left = remove_node(root->left, val);
        } else {
            root->right = remove_node(root->right, val);
        }
    } 

    return res;
}

void iterate_in_order(struct node *root, void (*f)(struct node *n)) {
    if(!root) {
        return;
    }
    iterate_in_order(root->left, f);
    (*f)(root);
    iterate_in_order(root->right, f);
}

void iterate_pre_order(struct node *node,void (*f)(struct node *n)){
    if(!node) {
        return;
    }
    (*f)(node);
    iterate_pre_order(node->left, f);
    iterate_pre_order(node->right, f);
}

void iterate_post_order(struct node *node,void (*f)(struct node *n)){
    if(!node) {
        return;
    }
    iterate_post_order(node->left, f);
    iterate_post_order(node->right, f);
    (*f)(node);
}
