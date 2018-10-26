#include <iostream>
#include "tree.cc"
#include <assert.h>

int main() {
    Tree* t = create_tree(126,0);
    t -> left_ = create_tree(-5,0);
    t -> left_ -> left_ = create_tree(12,0);
    t -> left_ -> right_ = create_tree(6,0);
    t -> left_ -> right_ -> left_ = create_tree(9,0);
    t -> right_ = create_tree(12,0);
    t -> right_ -> left_ = create_tree(3,0);

    assert(path_to(t, 9) == "LRL");
    assert(path_to(t, 3) == "RL");
    assert(path_to(t, 126) == "");

    assert(node_at(t,"LR") -> key_ == 6);
    assert(node_at(t,"LLL") == nullptr);

    destroy_tree(t);

    Tree* t2 = create_tree(126,0);
    path_to(t2,5);
    assert(false);
}
