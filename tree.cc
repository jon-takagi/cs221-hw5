#include <iostream>
#include "tree.hh"
bool containsKey(tree_ptr_t tree, key_t &key);

tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right){
    // if(left == nullptr) {
    //     if(right == nullptr) {
    //         return new Tree({key, value, nullptr, nullptr});
    //     } else {
    //         return new Tree({key,value, nullptr, right});
    //     }
    // } else {
    //     if(right == nullptr) {
    //         return new Tree({key,value,left,nullptr});
    //     } else {
    //         return new Tree({key, value, left, right});
    //     }
    // }
    return new Tree({key, value, left, right});
}
void destroy_tree(tree_ptr_t tree){
    if(tree -> right_) {
        destroy_tree(tree -> right_);
    }
    if(tree -> left_) {
        destroy_tree(tree -> left_);
    }
    delete tree;
}
std::string path_to(tree_ptr_t tree, key_t key){
    if(containsKey(tree -> left_, key)) {
        return "L" + path_to(tree -> left_, key);
    }
    if (tree -> key_ == key) {
        return "";
    }
    if (containsKey(tree -> right_, key)) {
        return "R" + path_to(tree -> right_, key);
    }
    exit(1);
}
tree_ptr_t node_at(tree_ptr_t tree, std::string path){
    if(path[0] == 'L') {
        return node_at(tree -> left_, path.substr(1));
    }
    if(path[0] == 'R') {
        return node_at(tree -> right_, path.substr(1));
    }
    if(path == "") {
        return tree;
    }
    return nullptr;
}
bool containsKey(tree_ptr_t tree, key_t &key){
    if (tree == nullptr){
        return false;
    }
    return tree -> key_ == key || containsKey(tree -> left_, key) || containsKey(tree -> right_,key);
}
