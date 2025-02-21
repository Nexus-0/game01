#include <iostream>
#include <filesystem>
#include <mach-o/dyld.h>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "game.h"

namespace fs = std::filesystem;

int main(int,char**)
{   
    //获取可执行文件路径
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) != 0) {
        std::cerr << "Buffer too small to store executable path!" << std::endl;
        return 1;
    }

    std::cout << "Executable path: " << path << std::endl;

    // 获取资源路径
    fs::path executablePath = path;
    fs::path resourcePath = executablePath.parent_path() / "Resources/assets/image/Stars-A.png";

    std::cout << "Resource path: " << resourcePath << std::endl;

    Game& game = Game::getinstance();
    game.init();
    game.run();
   
    return 0;
}
