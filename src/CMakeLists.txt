# 定义一个名为 planning_main 的 CMake 项目
project(planning_main)

# 添加子目录 pnc_map，会递归调用该目录下的 CMakeLists.txt
add_subdirectory(pnc_map)

# 添加子目录 process，同样会处理该目录下的 CMakeLists.txt
add_subdirectory(process)

# 创建一个可执行文件，文件名为 ${PROJECT_NAME}（即 planning_main）
# 使用的源文件是 planning_main.cpp
add_executable(${PROJECT_NAME} planning_main.cpp)

# 指定可执行文件的头文件搜索路径
# PUBLIC 表示该设置对自身和依赖该目标的其他目标均可见
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Process_Dir}  # 这个变量应指向 process 模块的头文件目录
)

# 将 process 这个库链接到当前可执行文件上
# PUBLIC 表示该依赖关系也会传递给依赖本目标的其他目标（尽管通常 EXECUTABLE 不会被其他目标依赖）
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    process
)
