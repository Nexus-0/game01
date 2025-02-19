#ifndef GAME_H
#define GAME_H  

#include "scene.h"
#include "object.h"
#include<SDL.h> 
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<string>


class Game
{
public:
    static Game& getinstance(){
        static Game instance;
        return instance;
    };
  
    ~Game();
    void run();
    void init();
    void clean();
    void changeScene(Scene* scene);

    void handleEvent(SDL_Event* event);
    void update(float deltaTime);
    void render();
    //渲染函数文字
    void renderTextCentered(std::string text,float posY,  bool isTitle);
    //setters
    void setFinalScore(int score){finalScore = score;};

    //getters
    SDL_Window* getWindow(){return window;};
    SDL_Renderer* getRenderer(){return renderer;};
    int getWindowWidth(){return windowWidth;};
    int getWindowHeight(){return windowHeight;};
    int getFinalScore(){return finalScore;};
private:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    TTF_Font* titleFont;
    TTF_Font* textFont;

    bool isRunning = true;
    Scene* currentScene = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int windowWidth = 600;
    int windowHeight = 800;
    int frameRate = 60;
    Uint32 frameTime = 1000 / frameRate;
    float deltaTime = 0.0f;
    int finalScore = 0;
    
    Background nearSight;
    Background farSight;

    void backgroundUpdate(float deltaTime);
    void renderBackground();

};



#endif // GAME_H