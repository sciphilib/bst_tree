#include <iostream>
#include "BST.h"

int main()
{
    BST<int, int> tree;
    bool is_inserted;
    tree.insert(tree.get_root(), 10, 5, is_inserted);
}