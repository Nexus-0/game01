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
    bool isTyping = true;//是否正在输入
    std::string name = "";//输入的名字
    float blinkTimer = 1.0f;//闪烁时间

     void renderPhase1();//渲染游戏结束
     void renderPhase2();//渲染得分榜
    void removeLastUTF8Char(std::string& str);//移除最后一个UTF-8字符
    Mix_Music* bgm;
    std::string scoreText;
    std::string highScoreText;
    
};

#endif