#include <iostream>
#include "BST.h"

int main()
{
    BST<int, int> tree;
    //tree.insert(30);
    //tree.insert(20);
    //tree.insert(40);
    //tree.insert(15);
    //tree.insert(27);
    //tree.insert(50);
    //tree.insert(5);
    //tree.insert(18);
    //tree.insert(26);
    //tree.insert(28);
    //tree.insert(45);
    //tree.insert(35);
    //tree.insert(60);
    //tree.insert(23);
    //tree.insert(24);
    // tree.postorder_print();
    //std::cout << '\n';
    //std::cout << tree.remove(30) << '\n';
    //std::cout << tree.remove(23) << '\n';
    //tree.inorder_print();
    //std::cout << '\n';
    // --------------
    tree.insert(50);
    tree.insert(70);
    tree.insert(30);
    tree.insert(40);
    tree.insert(45);
    tree.insert(10);
    tree.insert(80);
    tree.insert(60);
    tree.insert(65);
    tree.insert(20);
    tree.insert(19);
    tree.insert(21);
    std::cout << '\n';
    tree.inorder_print();
    std::cout << '\n';
    tree.print();

    std::cout << '\n';
    std::cout << "------------tree 2-------------";
    std::cout << '\n';

    BST<int, int> tree2(tree);
    tree.inorder_print();
    std::cout << '\n';
    tree.print();
    std::cout << '\n';
    tree2.clear();

    std::cout << '\n';
    std::cout << "------------tree 2 after delete-------------";
    std::cout << '\n';

    tree2.insert(50);
    tree2.insert(70);
    tree2.insert(30);
    tree2.insert(40);
    tree2.insert(45);
    tree2.insert(10);
    tree2.insert(80);
    tree2.insert(60);
    tree2.insert(65);
    tree2.insert(20);
    tree2.insert(19);
    tree2.insert(21);
    std::cout << '\n';
    tree2.inorder_print();
    std::cout << '\n';
    tree2.print();

    // iterator
    //auto iter = tree.begin();
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';
    //++iter;
    //std::cout << *iter << ',' << tree.bal(iter.cur) << '\n';


    // reverse iterator
    //auto iter = tree.rbegin();
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';
    //++iter;
    //std::cout << *iter << '\n';

    //std::cout << '\n';
    //if (tree.get_data(66) != nullptr)
    //{
    //    std::cout << *tree.get_data(25) << ' ';
    //    *tree.get_data(25) = 7;
    //    *tree.get_data(25) = 117;
    //    *tree.get_data(25) = 72;
    //    std::cout << *tree.get_data(25) << ' ';
    //}
    //else
    //{
    //    std::cout << "there is no element.";
    //}

}