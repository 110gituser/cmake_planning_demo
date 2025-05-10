# 设置当前工程的名称为 "pnc_map"
project(pnc_map)

# 定义并构建一个共享库（SHARED），库名称为当前项目的名称（即 pnc_map）
# 并指定实现文件 pnc_map.cpp
add_library(${PROJECT_NAME}
    SHARED
    pnc_map.cpp
)