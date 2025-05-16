project(map_test) # 定义一个名为 map_test 的项目

# 添加一个可执行文件 map_test，由 map_test.cpp 和 pnc_map.cpp 编译而成
# map_test.cpp 是主程序，包含 main() 函数
# ${PNC_Map_Dir}/pnc_map.cpp 是地图模块的实现文件，包含如 PncMap 类的定义
# 如果省略 pnc_map.cpp，map_test.cpp 中调用 PncMap 的实现会导致链接错误
add_executable(${PROJECT_NAME} map_test.cpp ${PNC_Map_Dir}/pnc_map.cpp)

# 指定头文件搜索路径，供 map_test.cpp 引用 pnc_map.h 等头文件使用
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PNC_Map_Dir}
)

# 设置链接目录（注：此处写法可能有误，通常是用 target_link_libraries 进行链接）
# 如果 pnc_map 是一个已构建的库，应使用 target_link_libraries 替代
target_link_directories(${PROJECT_NAME}
    PUBLIC
    pnc_map  # 注意：此项应为目录路径，而非目标名称
)

# 添加一个测试项，名为 map_info_test，执行 map_test 可执行文件
add_test(
    NAME map_info_test
    COMMAND ${PROJECT_NAME}
)

# ======================= 附加说明 ========================
# 如果只写：
# add_executable(${PROJECT_NAME} map_test.cpp)
# 则不会编译 pnc_map.cpp，若 map_test.cpp 中引用了其中的实现，会链接失败。
# 只有在 map_test.cpp 是完全独立的、不依赖其他模块时才可以这样写。
#
# 更规范的做法（适用于模块化项目）是将 pnc_map.cpp 构建成库：
# add_library(pnc_map STATIC ${PNC_Map_Dir}/pnc_map.cpp)
# target_link_libraries(${PROJECT_NAME} PRIVATE pnc_map)