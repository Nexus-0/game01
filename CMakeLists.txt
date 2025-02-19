cmake_minimum_required(VERSION 3.10.0)
project(game01 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
 add_compile_options(/W4)
elseif(APPLE)
 add_compile_options(-Wall -Wextra -Wpedantic) 
endif()

 #设置编译输出目录

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/bin)

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})
#查找并载入预设
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
#添加头文件

#添加可执行文件
add_executable(
            ${TARGET} 
            "src/main.cpp"
            "src/Game.cpp"
            "src/scene.cpp"
            "src/scenetitle.cpp"
            "src/scenemain.cpp"
            "src/sceneend.cpp"
            )


target_link_libraries(${TARGET}  
                        ${SDL2_LIBRARIES}
                        SDL2_image::SDL2_image
                        SDL2_mixer::SDL2_mixer
                        SDL2_ttf::SDL2_ttf
                        )