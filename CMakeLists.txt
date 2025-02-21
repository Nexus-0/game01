cmake_minimum_required(VERSION 3.16)
project(game01 VERSION 0.1.0 LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 macOS 应用程序
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum macOS deployment version")

# 设置目标架构（添加此行以确保架构设置）
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Target architectures")

# 设置编译选项
if(MSVC)
    add_compile_options(/W4)
elseif(APPLE)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 设置编译输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

# 设置目标文件名
set(TARGET ${PROJECT_NAME})

# 查找并载入预设
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

# 设置 macOS 应用程序包
set(CMAKE_MACOSX_BUNDLE TRUE)
set(MACOSX_BUNDLE_ICON_FILE "AppIcon.icns")
set(MACOSX_BUNDLE_INFO_PLIST_FILE "${CMAKE_SOURCE_DIR}/Info.plist")

# 添加可执行文件
add_executable(
    ${TARGET} 
    MACOSX_BUNDLE
    "src/main.cpp"
    "src/Game.cpp"
    "src/scene.cpp"
    "src/scenetitle.cpp"
    "src/scenemain.cpp"
    "src/sceneend.cpp"
)

# 链接 SDL2 和相关库
target_link_libraries(${TARGET}  
    ${SDL2_LIBRARIES}
    SDL2_image::SDL2_image
    SDL2_mixer::SDL2_mixer
    SDL2_ttf::SDL2_ttf
)

# 将资源文件夹复制到 .app 包中的 Resources 目录
#install(DIRECTORY assets/ DESTINATION ${CMAKE_BINARY_DIR}/Game01.app/Contents/Resources/assets/)

install(DIRECTORY assets/ DESTINATION ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}.app/Contents/Resources/assets/)

# 将可执行文件复制到 .app 包中的 MacOS 目录
#nstall(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR}/Game01.app/Contents/MacOS)

# 设置输出目录
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Game01.app/Contents/MacOS)