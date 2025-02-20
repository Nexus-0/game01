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

# 设置 macOS 应用程序包
set(CMAKE_MACOSX_BUNDLE TRUE)
set(MACOSX_BUNDLE_ICON_FILE "AppIcon.icns")
set(MACOSX_BUNDLE_INFO_PLIST_FILE "${CMAKE_SOURCE_DIR}/Info.plist")

#添加可执行文件
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


target_link_libraries(${TARGET}  
                        ${SDL2_LIBRARIES}
                        SDL2_image::SDL2_image
                        SDL2_mixer::SDL2_mixer
                        SDL2_ttf::SDL2_ttf
                        )
# 将资源文件夹复制到 .app 包中
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}.app/Contents/Resources)