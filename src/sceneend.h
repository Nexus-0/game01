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
    SceneEnd(Game& game);
    ~SceneEnd();
    void init() override;
    void update(float deltaTime) override;
    void render() override;
    void clean() override;
    void handleEvent(SDL_Event* event) override;
private:
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