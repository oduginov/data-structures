#include "node-test.h"

void TestSetKey() {
    Node<int> node(5);
    node.SetKey(2);
    ASSERT(node.GetKey(), 2);
}

void TestNode() {
    TestSetKey();
    TestGetKey();
    TestAddChild();
}

void TestGetKey() {
    Node<int> node(5);
    ASSERT(node.GetKey(), 5);
}

void TestAddChild() {
    Node<int> node;
    node.AddChild(new Node<int>(1));
    node.AddChild(new Node<int>(2));
    std::vector<int> expected = {1, 2};
    ASSERT(node.GetChildrenKeys(), expected);
}