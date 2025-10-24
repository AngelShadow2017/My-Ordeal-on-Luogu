cmake_minimum_required(VERSION 3.20)
project(cp LANGUAGES CXX)

# 默认 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 编译选项（根据需要调整）
if(MSVC)
    # 与配置相关的优化/运行时检查：Debug 用 /RTC1，Release 用 /O2 并保留调试信息 /Zi
    add_compile_options(
        "$<$<CONFIG:Debug>:/RTC1>"
        "$<$<CONFIG:Release>:/O2>"
        "$<$<CONFIG:Release>:/Zi>"
    )

    # 与编译器无关于配置的常用选项单独加入
    add_compile_options(/EHsc /DNOMINMAX /DWIN32_LEAN_AND_MEAN /wd4819)
else()
    add_compile_options(-O2 -pipe -Wall -Wextra)
endif()


# 头文件搜索路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 公用实现文件（可在 lib/ 放置 .cpp 并加到这里）
set(COMMON_LIB_SOURCES "")

# 自动把 problems 目录下的每个 .cpp 变成一个可执行文件
file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/problems/*.cpp")
if (PROBLEM_SOURCES STREQUAL "")
    message(WARNING "No problem sources found in problems/*.cpp")
endif()

foreach(src IN LISTS PROBLEM_SOURCES)
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src} ${COMMON_LIB_SOURCES})

    # 示例：为特定题目追加编译定义或选项
    # if(name STREQUAL "some_problem")
    #     target_compile_definitions(${name} PRIVATE SOME_MACRO)
    # endif()
endforeach()

# 可选：设置项目目录作为默认启动工作目录
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "")
