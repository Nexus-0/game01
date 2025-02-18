#include "sceneend.h"
#include "scenetitle.h"
#include "game.h"


void SceneEnd::init()
{
        bgm = Mix_LoadMUS("assets/music/06_Battle_in_Space_Intro.ogg");
        if(bgm == nullptr){
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        }
        Mix_PlayMusic(bgm, -1); 
}

void SceneEnd::update(float deltaTime)
{
} 

void SceneEnd::render()
{
    std::string titleText = "GAMEOVER";
    game.renderTextCentered(titleText, 0.4f, true);
}

void SceneEnd::clean()
{
    Mix_FreeMusic(bgm);
}

void SceneEnd::handleEvent(SDL_Event *event)
{
    if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.scancode != SDL_SCANCODE_UNKNOWN && event->key.keysym.scancode != SDL_SCANCODE_ESCAPE){
            auto titleScene = new SceneTitle();
            game.changeScene(titleScene);
        }
    }
}
