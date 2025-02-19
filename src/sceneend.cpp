#include "sceneend.h"
#include "scenetitle.h"
#include "game.h"

#include<string>


void SceneEnd::init()
{
    if(!SDL_IsTextInputActive())
    {
        SDL_StartTextInput();
        if(!SDL_IsTextInputActive())
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        }
    }
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
    if(isTyping){
        renderPhase1();
    }else{
        renderPhase2();
    }
    
}

void SceneEnd::clean()
{
    Mix_FreeMusic(bgm);
}

void SceneEnd::handleEvent(SDL_Event *event)
{
    if(isTyping){
        if(event->type == SDL_TEXTINPUT){

            name += event->text.text;
          
        }
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.scancode == SDL_SCANCODE_RETURN && event->text.text[0] != '\n'){
                SDL_StopTextInput();
                isTyping = false;
            }
        }
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.scancode == SDL_SCANCODE_BACKSPACE){
                removeLastUTF8Char(name);
            }
        }

    else{
   
            }
    }
}
void SceneEnd::renderPhase1()
{
    auto score = game.getFinalScore(); 
    std::string scoreText = "你的得分是： " + std::to_string(score);
    std::string GameOverText = "游戏结束";
    std::string tipText = "请输入你的名字，按回车键继续";
    game.renderTextCentered(scoreText, 0.4f, false);
    game.renderTextCentered(GameOverText, 0.2f, true);  
    game.renderTextCentered(tipText, 0.6f, false);

    if(name != ""){
        game.renderTextCentered(name, 0.8f, false);
       
       
    }
}

void SceneEnd::renderPhase2()
{
}

void SceneEnd::removeLastUTF8Char(std::string& str)
{
    auto lastChar = str.back();
    if((lastChar & 0b10000000) == 0b10000000){
        str.pop_back();
        while((str.back() & 0b11000000) != 0b11000000){
            str.pop_back();
        }
    }else{
        str.pop_back();
       
    }
}
