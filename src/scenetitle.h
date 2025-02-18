#ifndef SCENETITLE_H
#define SCENETITLE_H

#include "scene.h"
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
class SceneTitle : public Scene
{
public:

    void init() override;
    void update(float deltaTime) override;
    void render() override;
    void clean() override;
    void handleEvent(SDL_Event* event) override;
private:
    Mix_Music* bgm;
    float timer = 0.0f;

};

#endif // SCENETITLE_H