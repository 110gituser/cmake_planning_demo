# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.29.0)

# 定义项目名称和元信息
project(planning
    VERSION 0.0.1                             # 项目版本号
    DESCRIPTION "a demo of cmake planning"    # 项目描述
    HOMEPAGE_URL "https://github.com/110gituser/cmake_planning_demo"  # 项目主页
    LANGUAGES CXX                             # 指定使用 C++ 语言
)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 设置可执行文件输出目录为 bin 目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 设置变量，用于在子模块中引用相应目录路径
set(Process_Dir ${PROJECT_SOURCE_DIR}/src/process)
set(PNC_Map_Dir ${PROJECT_SOURCE_DIR}/src/pnc_map)
set(Show_Result_Dir ${PROJECT_SOURCE_DIR}/src/show_ressult)

#三方库
set(EIGEN3_INCLUDE_DIR "E:/algo/cpp/eigen/eigen-3.4.0")
list(APPEND CMAKE_MODULE_PATH "${EIGEN3_INCLUDE_DIR}/cmake")
message("CMAKE_MOUDLE_PATH = ${CMAKE_MOUDLE_PATH}")

find_package(Eigen3 REQUIRED)
if(TARGET Eigen3::Eigen)
    message(STATUS "found eigen")
endif()

# 添加 src 子目录，其中应包含一个 CMakeLists.txt 来处理各个模块（如 process 和 pnc_map）
add_subdirectory(src)