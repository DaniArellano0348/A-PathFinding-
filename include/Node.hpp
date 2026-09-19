#ifndef NODE_HPP
#define NODE_HPP

struct Node {

    int x;
    int y;

    float g;
    float h;
    float f;

    bool obstacle;

    Node* parent;
};

#endif