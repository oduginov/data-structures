#pragma once

#include <vector>

template<typename T>
class Node {
public:
    Node() {}

    Node(T key) : _key(key) {

    }

    void SetKey(const T &key) {
        _key = key;
    }

    T GetKey() const {
        return _key;
    }

    void AddChild(Node<T> *child) {
        children.push_back(child);
    }

    std::vector<T> GetChildrenKeys() {
        std::vector<T> childrenKey;
        for (const auto child : children) {
            childrenKey.push_back(child->GetKey());
        }
        return childrenKey;
    }

private:
    T _key;
    std::vector<Node<T> *> children;
};
