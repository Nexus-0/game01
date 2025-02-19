#ifndef    SCENEEND_H
#define     SCENEEND_H

#include "scene.h"
#include "object.h"
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
class Game;
class SceneEnd : public Scene
{
public:
    
    void init() override;
    void update(float deltaTime) override;
    void render() override;
    void clean() override;
    void handleEvent(SDL_Event* event) override;
private:
    bool isTyping = true;
    std::string name = "";
    float blinkTimer = 1.0f;

     void renderPhase1();
     void renderPhase2();
    void removeLastUTF8Char(std::string& str);
    Mix_Music* bgm;
    std::string scoreText;
    std::string highScoreText;
    SDL_Texture* bgTexture = nullptr;
    SDL_Texture* scoreTexture = nullptr;
    SDL_Texture* highScoreTexture = nullptr;
    SDL_Texture* endTexture = nullptr;
    Mix_Chunk* endSound = nullptr;  
};

#endif