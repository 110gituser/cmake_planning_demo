project(planning_main) # 定义一个名为 planning_main 的 CMake 项目

add_subdirectory(pnc_map) # 添加子目录 pnc_map，会递归调用该目录下的 CMakeLists.txt
add_subdirectory(process) # 添加子目录 process，同样会处理该目录下的 CMakeLists.txt
add_subdirectory(show_result) # 添加子目录 show_result，同样会处理该目录下的 CMakeLists.txt

# 创建一个可执行文件，名为 ${PROJECT_NAME}（planning_main）使用的源文件是 planning_main.cpp
add_executable(${PROJECT_NAME} planning_main.cpp)

# 指定可执行文件的头文件搜索路径
# 使用 include_directories 配置全局包含路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/process  # process 目录的头文件路径
    ${CMAKE_CURRENT_SOURCE_DIR}/show_result  # show_result 目录的头文件路径
)

target_link_libraries(${PROJECT_NAME} PUBLIC process) # 将process这个库链接到当前可执行文件上

# 将 show_result 这个库链接到当前可执行文件上
target_link_libraries(${PROJECT_NAME} PUBLIC show_result)