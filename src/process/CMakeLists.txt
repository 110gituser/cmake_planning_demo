project(process) # 定义一个名为 process 的 CMake 工程（project）模块

# 创建一个共享库（SHARED），库的名字是 ${PROJECT_NAME}（即 process）
# 并将 process.cpp 作为源文件编译进这个库
add_library(${PROJECT_NAME} SHARED process.cpp)

# 设置该库的头文件搜索路径（供使用该库的其他模块使用）
# PUBLIC 表示：当前库和链接该库的目标都可以使用这个包含目录
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PNC_Map_Dir}  # 外部传入的变量，表示头文件所在目录
)

# 设置该库依赖的其他库
# PUBLIC 表示：当前库链接了 pnc_map，链接该库的目标也将自动链接pnc_map
target_link_libraries(${PROJECT_NAME} PUBLIC pnc_map)
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)