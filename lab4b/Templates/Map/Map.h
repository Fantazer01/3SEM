//
// Created by oleg on 13.12.2021.
//

#include "Pair.h"

#ifndef TEMPLATES_MAP_H
#define TEMPLATES_MAP_H

class Key {
private:
    int a;
public:
    Key() = default;
    explicit Key(int _a): a(_a) {}

    int getA() const { return a; }
    void setA(int _a) { a = _a; }

    bool operator ==(const Key &temp) const { return a == temp.a; }
    bool operator !=(const Key &temp) const { return a != temp.a; }
    bool operator < (const Key &temp) const { return a < temp.a; }
    bool operator <= (const Key &temp) const { return a <= temp.a; }
    bool operator > (const Key &temp) const { return a > temp.a; }
    bool operator >= (const Key &temp) const { return a >= temp.a; }

};

class Info {
private:
    int a;
public:
    Info() = default;
    explicit Info(int _a): a(_a) {}

    int getA() const { return a; }
    void setA(int _a) { a = _a; }

    bool operator ==(const Info &temp) const { return a == temp.a; }
    bool operator !=(const Info &temp) const { return a != temp.a; }
    bool operator < (const Info &temp) const { return a < temp.a; }
    bool operator <= (const Info &temp) const { return a <= temp.a; }
    bool operator > (const Info &temp) const { return a > temp.a; }
    bool operator >= (const Info &temp) const { return a >= temp.a; }

};

struct Node {
public:
    Pair<Key, Info> *p_info;
    Node *parent;
    Node *left;
    Node *right;

    Node(): p_info(nullptr), parent(nullptr), left(nullptr), right(nullptr) {}
    Node(Node *_parent): p_info(nullptr), parent(_parent), left(nullptr), right(nullptr) {}
    Node(Node *_parent, Pair<Key, Info> info): parent(_parent), left(nullptr), right(nullptr)
    { p_info = new Pair<Key, Info>(info.first, info.second); }
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

class Binary_tree {
public:
    class iterator {
    private:
        Node *ptr;

    public:
        iterator(): ptr(nullptr) {}
        explicit iterator(Node *_ptr): ptr(_ptr) {}

        Pair<Key, Info>& operator *() { return *(ptr->p_info); }
        const Pair<Key, Info>& operator *() const { return *(ptr->p_info); }

        Pair<Key, Info>* operator ->() { return ptr->p_info; }
        const Pair<Key, Info>* operator ->() const { return ptr->p_info; }

        bool operator == (const iterator &it) const { return ptr == it.ptr; }
        bool operator != (const iterator &it) const { return ptr != it.ptr; }


        iterator& operator ++();
        iterator operator ++(int) { iterator it(*this); ++(*this); return it; }

        friend Binary_tree;
    };

private:
    Node *root;
    uint _size;

public:
    Binary_tree(): root(nullptr), _size(0) {}
    ~Binary_tree() { clear(); }

    bool empty() const { return root == nullptr; }
    uint size() const { return _size; }

    iterator find(const Key &key);
    bool insert(const Pair<Key, Info> &_pair_);
    bool erase(const Key &key);

    iterator begin();
    static iterator end() { return {}; }

    void clear() { if (root != nullptr) { root->Erase_children(); delete root; root = nullptr; } }

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~realize~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Node* FindLeftmost(Node *leftmost)
{
    while (leftmost->left != nullptr)
        leftmost = leftmost->left;

    return leftmost;
}

Node* ClimbUpUntilExitFromRightSubtree(Node *ptr_node)
{
    while (ptr_node->parent != nullptr && ptr_node->p_info->first > ptr_node->parent->p_info->first) {
        ptr_node = ptr_node->parent;
    }

    return ptr_node->parent;
}

bool LeftSubtree(Node *ptr_node) { return ptr_node->p_info->first < ptr_node->parent->p_info->first;}

bool RightSubtree(Node *ptr_node) { return ptr_node->p_info->first > ptr_node->parent->p_info->first;}

Binary_tree::iterator& Binary_tree::iterator::operator ++()
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

Binary_tree::iterator Binary_tree::find(const Key &key)
{
    Node *ptr_node = root;

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

void InsertToNOEmptySubTree(const Pair<Key, Info> &_pair_, Node *ptr_node)
{
    Node *next = ptr_node;

    while (next != nullptr)
    {
        ptr_node = next;
        if (ptr_node->p_info->first > _pair_.first)
            next = ptr_node->left;
        else
            next = ptr_node->right;
    }

    if (ptr_node->p_info->first > _pair_.first)
        ptr_node->left = new Node(ptr_node, _pair_);
    else
        ptr_node->right = new Node(ptr_node, _pair_);

}

bool Binary_tree::insert(const Pair<Key, Info> &_pair_)
{
    if (empty()) {
        ++_size;
        root = new Node(nullptr, _pair_);
        return true;
    }

    if (find(_pair_.first) != end())
        return false;

    InsertToNOEmptySubTree(_pair_, root);
    ++_size;
    return true;
}

uint CheckBranch(Node *ptr_node)
{
    uint counter = 0;

    if (ptr_node->left != nullptr)
        ++counter;
    if (ptr_node->right != nullptr)
        ++counter;

    return counter;
}

void SimpleCaseErase(Node *&root, Node *ptr_node)
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

void SimpleCaseErase(Node *ptr_node)
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
    //ptr_node->left = nullptr;
    //ptr_node->right = nullptr;
    //ptr_node->parent = nullptr;
    delete ptr_node;
}

Node* FindRightmost(Node *rightmost)
{
    while (rightmost->right != nullptr)
        rightmost = rightmost->right;

    return rightmost;
}

void DifficultCaseErase(Node *ptr_node)
{
    Node *scapegoat = FindRightmost(ptr_node->left);
    Swap(ptr_node->p_info, scapegoat->p_info);
    SimpleCaseErase(scapegoat);
}

bool Binary_tree::erase(const Key &key)
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

Binary_tree::iterator Binary_tree::begin()
{
    if (empty())
        return end();

    Node *ptr_node = root;

    while (ptr_node->left != nullptr)
        ptr_node = ptr_node->left;

    return iterator(ptr_node);
}

typedef Binary_tree Map;
/*class Map {
private:
    int info;

};*/

#endif //TEMPLATES_MAP_H
