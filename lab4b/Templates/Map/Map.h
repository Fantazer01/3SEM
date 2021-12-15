//
// Created by oleg on 13.12.2021.
//

#include "Pair.h"

#ifndef TEMPLATES_MAP_H
#define TEMPLATES_MAP_H

template <typename T_Key, typename T_Info>
struct Node {
public:
    Pair<T_Key, T_Info> *p_info;
    Node *parent;
    Node *left;
    Node *right;

    Node(): p_info(nullptr), parent(nullptr), left(nullptr), right(nullptr) {}
    Node(Node *_parent): p_info(nullptr), parent(_parent), left(nullptr), right(nullptr) {}
    Node(Node *_parent, Pair<T_Key, T_Info> info): parent(_parent), left(nullptr), right(nullptr)
    { p_info = new Pair<T_Key, T_Info>(info.first, info.second); }
    Node(Node *_parent, Node *_left, Node *_right): p_info(nullptr), parent(_parent), left(_left), right(_right) {}
    ~Node() { delete p_info; }

    void Erase_children()
    {
        if (left != nullptr) {
            left->Erase_children();
            delete left;
            left = nullptr;
        }

        if (right != nullptr) {
            right->Erase_children();
            delete right;
            right = nullptr;
        }

    }

};

template <typename T_Key, typename T_Info>
class Binary_tree {
public:
    class iterator {
    private:
        Node<T_Key, T_Info> *ptr;

    public:
        iterator(): ptr(nullptr) {}
        explicit iterator(Node<T_Key, T_Info> *_ptr): ptr(_ptr) {}

        Pair<T_Key, T_Info>& operator *() { return *(ptr->p_info); }
        const Pair<T_Key, T_Info>& operator *() const { return *(ptr->p_info); }

        Pair<T_Key, T_Info>* operator ->() { return ptr->p_info; }
        const Pair<T_Key, T_Info>* operator ->() const { return ptr->p_info; }

        bool operator == (const iterator &it) const { return ptr == it.ptr; }
        bool operator != (const iterator &it) const { return ptr != it.ptr; }


        iterator& operator ++();
        iterator operator ++(int) { iterator it(*this); ++(*this); return it; }

        friend Binary_tree;
    };

private:
    Node<T_Key, T_Info> *root;
    uint _size;

public:
    Binary_tree(): root(nullptr), _size(0) {}
    ~Binary_tree() { clear(); }

    bool empty() const { return root == nullptr; }
    uint size() const { return _size; }

    iterator find(const T_Key &key);
    bool insert(const Pair<T_Key, T_Info> &_pair_);
    bool erase(const T_Key &key);

    iterator begin();
    static iterator end() { return {}; }

    void clear() { if (root != nullptr) { root->Erase_children(); delete root; root = nullptr; } }

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~realize~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T_Key, typename T_Info>
Node<T_Key, T_Info>* FindLeftmost(Node<T_Key, T_Info> *leftmost)
{
    while (leftmost->left != nullptr)
        leftmost = leftmost->left;

    return leftmost;
}

template <typename T_Key, typename T_Info>
Node<T_Key, T_Info>* ClimbUpUntilExitFromRightSubtree(Node<T_Key, T_Info> *ptr_node)
{
    while (ptr_node->parent != nullptr && ptr_node->p_info->first > ptr_node->parent->p_info->first) {
        ptr_node = ptr_node->parent;
    }

    return ptr_node->parent;
}

template <typename T_Key, typename T_Info>
bool LeftSubtree(Node<T_Key, T_Info> *ptr_node)
{ return ptr_node->p_info->first < ptr_node->parent->p_info->first;}

template <typename T_Key, typename T_Info>
bool RightSubtree(Node<T_Key, T_Info> *ptr_node)
{ return ptr_node->p_info->first > ptr_node->parent->p_info->first;}

template <typename T_Key, typename T_Info>
typename Binary_tree<T_Key, T_Info>::iterator& Binary_tree<T_Key, T_Info>::iterator::operator ++()
{
    if (*this == Binary_tree::end())
        throw std::invalid_argument("invalid value!");

    if (this->ptr->right == nullptr) {
        if (this->ptr->parent == nullptr || LeftSubtree(this->ptr))
            this->ptr = this->ptr->parent;
        else
            this->ptr = ClimbUpUntilExitFromRightSubtree(this->ptr);
    } else if (this->ptr->right != nullptr) {
        this->ptr = FindLeftmost(this->ptr->right);
    }
    return (*this);
}

template <typename T_Key, typename T_Info>
typename Binary_tree<T_Key, T_Info>::iterator Binary_tree<T_Key, T_Info>::find(const T_Key &key)
{
    Node<T_Key, T_Info> *ptr_node = root;

    while (ptr_node != nullptr)
    {
        if (ptr_node->p_info->first == key)
            return iterator(ptr_node);
        if (ptr_node->p_info->first > key)
            ptr_node = ptr_node->left;
        else
            ptr_node = ptr_node->right;
    }

    return end();
}

template <typename T_Key, typename T_Info>
void InsertToNOEmptySubTree(const Pair<T_Key, T_Info> &_pair_, Node<T_Key, T_Info> *ptr_node)
{
    Node<T_Key, T_Info> *next = ptr_node;

    while (next != nullptr)
    {
        ptr_node = next;
        if (ptr_node->p_info->first > _pair_.first)
            next = ptr_node->left;
        else
            next = ptr_node->right;
    }

    if (ptr_node->p_info->first > _pair_.first)
        ptr_node->left = new Node<T_Key, T_Info>(ptr_node, _pair_);
    else
        ptr_node->right = new Node<T_Key, T_Info>(ptr_node, _pair_);

}

template <typename T_Key, typename T_Info>
bool Binary_tree<T_Key, T_Info>::insert(const Pair<T_Key, T_Info> &_pair_)
{
    if (empty()) {
        ++_size;
        root = new Node<T_Key, T_Info>(nullptr, _pair_);
        return true;
    }

    if (find(_pair_.first) != end())
        return false;

    InsertToNOEmptySubTree(_pair_, root);
    ++_size;
    return true;
}

template <typename T_Key, typename T_Info>
uint CheckBranch(Node<T_Key, T_Info> *ptr_node)
{
    uint counter = 0;

    if (ptr_node->left != nullptr)
        ++counter;
    if (ptr_node->right != nullptr)
        ++counter;

    return counter;
}

template <typename T_Key, typename T_Info>
void SimpleCaseErase(Node<T_Key, T_Info> *&root, Node<T_Key, T_Info> *ptr_node)
{
    if (ptr_node->left == nullptr) {
        root = ptr_node->right;
        if (ptr_node->right != nullptr)
            ptr_node->right->parent = nullptr;
    } else {
        root = ptr_node->left;
        if (ptr_node->left != nullptr)
            ptr_node->left->parent = nullptr;
    }

    delete ptr_node;
}

template <typename T_Key, typename T_Info>
void SimpleCaseErase(Node<T_Key, T_Info> *ptr_node)
{
    if (ptr_node->left == nullptr) {
        if (ptr_node->parent->left == ptr_node)
            ptr_node->parent->left = ptr_node->right;
        else
            ptr_node->parent->right = ptr_node->right;

        if (ptr_node->right != nullptr)
            ptr_node->right->parent = ptr_node->parent;
    } else {
        if (ptr_node->parent->left == ptr_node)
            ptr_node->parent->left = ptr_node->left;
        else
            ptr_node->parent->right = ptr_node->left;

        if (ptr_node->left != nullptr)
            ptr_node->left->parent = ptr_node->parent;
    }

    delete ptr_node;
}

template <typename T_Key, typename T_Info>
Node<T_Key, T_Info>* FindRightmost(Node<T_Key, T_Info> *rightmost)
{
    while (rightmost->right != nullptr)
        rightmost = rightmost->right;

    return rightmost;
}

template <typename T_Key, typename T_Info>
void DifficultCaseErase(Node<T_Key, T_Info> *ptr_node)
{
    Node<T_Key, T_Info> *scapegoat = FindRightmost(ptr_node->left);
    Swap(ptr_node->p_info, scapegoat->p_info);
    SimpleCaseErase(scapegoat);
}

template <typename T_Key, typename T_Info>
bool Binary_tree<T_Key, T_Info>::erase(const T_Key &key)
{
    iterator it;
    if ((it = find(key)) == end())
        return false;

    if (CheckBranch(it.ptr) < 2)
        if (it.ptr->parent == nullptr)
            SimpleCaseErase(root, it.ptr);
        else
            SimpleCaseErase(it.ptr);
    else
        DifficultCaseErase(it.ptr);

    --(_size);
    return true;
}

template <typename T_Key, typename T_Info>
typename Binary_tree<T_Key, T_Info>::iterator Binary_tree<T_Key, T_Info>::begin()
{
    if (empty())
        return end();

    Node<T_Key, T_Info> *ptr_node = root;

    while (ptr_node->left != nullptr)
        ptr_node = ptr_node->left;

    return iterator(ptr_node);
}

template <typename T_Key, typename T_Info>
using Map = Binary_tree<T_Key, T_Info>;

#endif //TEMPLATES_MAP_H
