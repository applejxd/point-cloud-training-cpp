#ifndef _KD_TREE_H
#define _KD_TREE_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

namespace util {
    using std::vector;

    /**
     * k-d 木のノード
     * @tparam T    対象のデータ型
     */
    template<class T>
    struct Node {
        Node() : location_ptr_(nullptr), left_child_ptr_(nullptr), right_child_ptr_(nullptr) {};

        Node(T location, Node<T> left_child, Node<T> right_child) : location_ptr_(&location),
                                                                    left_child_ptr_(&left_child),
                                                                    right_child_ptr_(&right_child) {};
        T *location_ptr_;
        Node<T> *left_child_ptr_;
        Node<T> *right_child_ptr_;
    };

    template<class T>
    std::ostream &operator<<(std::ostream &os, const Node<T> &node) {
        os << std::fixed << std::noshowpoint << "(";
        if (node.location_ptr_ == nullptr) {
            os << ",";
        } else {
            vector<T> location_vec(std::begin(node.location_ptr_), std::end(node.location_ptr_));
            for (const auto& coord : location_vec) {
                os << coord << ",";
            }
        }
        if (node.left_child_ptr_ == nullptr) {
            os << ",";
        } else {
            os << *(node.left_child_ptr_) << ",";
        }
        if (node.right_child_ptr_ == nullptr) {
            os << ")";
        } else {
            os << *(node.right_child_ptr_) << ")";
        }
        return os;
    }

    /**
     * 平衡 k-d 木
     * @tparam T    対象のデータ型
     */
    template<class T>
    class KDTree {
    public:
        explicit KDTree(int dim, const vector<T> &points) : dim_(dim) { tree_ = make_tree(points); };

        void PrintTree() { std::cout << tree_ << std::endl; }

    private:
        int dim_;
        Node<T> tree_;

        Node<T> make_tree(const vector<T> &points, int depth = 0);
    };

    template<class T>
    Node<T> KDTree<T>::make_tree(const vector<T> &points, int depth) {
        if (points.empty()) { return Node<T>(); }

        vector<T> sorted_points{points};
        {
            int axis = depth % dim_;
            std::sort(sorted_points.begin(), sorted_points.end(),
                      [axis](T a, T b) { return a[axis] < b[axis]; });
        }

        int median = std::floor(points.size() / 2.0);
        vector<T> left_points(sorted_points.begin(), sorted_points.begin() + median);
        vector<T> right_points(sorted_points.begin() + median + 1, sorted_points.end());

        return Node<T>(points[median], make_tree(left_points, depth + 1), make_tree(right_points, depth + 1));
    }
}

#endif // _KD_TREE_H
