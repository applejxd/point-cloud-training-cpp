cmake_minimum_required(VERSION 3.10)
project(KDTree)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC
        # 最適化
        -mtune=native -march=native -mfpmath=both -O2
        # 各種警告
        -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wno-char-subscripts
        # 数値関連エラー：オーバーフロー・未定義動作を検出
        -ftrapv -fno-sanitize-recover
        )
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_11)

find_package(glog 0.6.0 REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
        glog::glog)

add_subdirectory(test)