#ifndef AABBTREE_H
#define AABBTREE_H

#include "AABB.hpp"
#include <SFML/Graphics.hpp>

struct AABBNode;

class AABBTree;

class AABBTree {

public:
    AABBTree();

    ~AABBTree() {};

    void insertNode();

    void removeNode();

    void updateNode();


private:
    AABBNode *root;

};

struct AABBNode {

    AABB box;

    //leftptr
    //rightptr
    //parentptr


};


#endif // AABBTREE_H
