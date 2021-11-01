#include "src/main.h"

#include <iostream>
#include <vector>
#include <glog/logging.h>

using std::vector;

int main(int, char *argv[]) {
    FLAGS_log_dir = "./logs";
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    vector<vector<double>> points{{7, 2}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {2, 3}};
    util::KDTree<vector<double>> tree(2, points);
    tree.PrintTree();
}
