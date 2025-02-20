#include "scenetitle.h"
#include "scenemain.h"
#include "game.h"
#include<string>

void SceneTitle::init()
{
    bgm= Mix_LoadMUS("../../assets/music/06_Battle_in_Space_Intro.ogg");
    if(bgm == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
    }
    Mix_PlayMusic(bgm, -1);
}

void SceneTitle::update(float deltaTime)
{
    timer += deltaTime;
    if(timer > 1.0f){
        timer -= 1.0f;
    }
}

void SceneTitle::render()
{
    //渲染标题文字
    std::string titleText = "SDL太空战机";
    game.renderTextCentered(titleText, 0.4f, true);
    //渲染提示文字
    if(timer < 0.5f){
        std::string tipText = "按J键开始游戏";
        game.renderTextCentered(tipText, 0.8f, false);
        return;
    }

}

void SceneTitle::clean()
{
    if(bgm != nullptr){
        Mix_HaltMusic();
        Mix_FreeMusic(bgm);
    }

}

void SceneTitle::handleEvent(SDL_Event *event)
{
    if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.scancode == SDL_SCANCODE_J){
            auto mainScene = new SceneMain();
            game.changeScene(mainScene);
        }
   
    }
}
  