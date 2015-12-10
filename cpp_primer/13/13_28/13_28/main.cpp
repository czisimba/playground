//
//  main.cpp
//  13_28
//
//  Created by nichola on 15/11/27.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

class TreeNode {
public:
    TreeNode():value(""),count(0),left(NULL),right(NULL) {
    }
    TreeNode(TreeNode &orig):value(orig.value),count(orig.count) {
        left = orig.left == NULL ? NULL : new TreeNode(*orig.left);
        right = orig.right == NULL ? NULL : new TreeNode(*orig.right);
    }
    TreeNode &operator=(TreeNode &orig){
        value = orig.value;
        count = orig.count;
        if (left != NULL)
            delete  left;
        if (right != NULL)
            delete  right;
        left = new TreeNode(*orig.left);
        right = new TreeNode(*orig.right);
        return *this;
    }
    ~TreeNode() {
        if (left != NULL)
            delete  left;
        if (right != NULL)
            delete right;
    }
    
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

int main(int argc, const char * argv[]) {
    TreeNode old;
    TreeNode root(old);
    
    return 0;
}