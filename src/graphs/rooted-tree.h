#pragma once

#include "node.h"

template<typename T>
class RootedTree {
public:
    RootedTree() {
        _root = nullptr;
    }

    RootedTree(T rootKey) {
        _root = new Node<T>(rootKey);
    }

    RootedTree(Node<T> *root) {
        _root = root;
    }

    Node<T> *GetRoot() const {
        return _root;
    }

    void AddLeaf(Node<T> *parent, T key) {
        Node<T> *node = new Node<T>(key);
        parent->AddChild(node);
    }

private:
    Node<T> *_root;
};
