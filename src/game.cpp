#include "game.h"
#include "scenemain.h"
#include "scenetitle.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

Game::Game()
{
}

Game::~Game()
{
    clean();
}

void Game::run()
{
    while (isRunning) 
    {
        auto frameStart = SDL_GetTicks();
        SDL_Event event;
        handleEvent(&event);
        
        update(deltaTime);

        render();
        auto frameEnd = SDL_GetTicks();
        auto diff = frameEnd - frameStart;
        if (diff<frameTime)
        {
            SDL_Delay(frameTime - diff);    
            deltaTime= frameTime/1000.0f;
        }else
        {
            deltaTime = diff/1000.0f;
        }
        
    }
    
}

void Game::init()
{
    frameTime = 1000 / frameRate;
    //SDL初始化
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;
    } 
    //创建窗口
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight,SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        isRunning = false;
    }
    //创建渲染器
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        isRunning = false;
    }   
    //初始化SDL_image
   
    if (IMG_Init (IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;
    }
    //初始化SDL_mixer   
    if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) != (MIX_INIT_OGG | MIX_INIT_MP3))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", Mix_GetError());
        isRunning = false;
    }
    //打开音频设备
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", Mix_GetError());
        isRunning = false;
    }

    Mix_AllocateChannels(32);

    //设置音量
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
    Mix_Volume(-1, MIX_MAX_VOLUME / 8);

    //初始化SDL_ttf
    if (TTF_Init() == -1)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", TTF_GetError());
        isRunning = false;
    }
    //初始化背景卷轴
    nearSight.texture = IMG_LoadTexture(renderer, "../../assets/image/Stars-A.png");
    if(nearSight.texture == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;
    }
    SDL_QueryTexture(nearSight.texture, NULL, NULL, &nearSight.width, &nearSight.height);
    nearSight.height /=2;
    nearSight.width /=2;

    farSight.texture = IMG_LoadTexture(renderer, "../../assets/image/Stars-B.png");
    if(farSight.texture == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;  
    }
    SDL_QueryTexture(farSight.texture, NULL, NULL, &farSight.width, &farSight.height);
    farSight.height /=2;
    farSight.width /=2;
    farSight.speed = 20;
   

    //载入字体  
    titleFont = TTF_OpenFont("../../assets/font/VonwaonBitmap-16px.ttf", 64);
    textFont = TTF_OpenFont("../../assets/font/VonwaonBitmap-16px.ttf", 32);
    if(titleFont == nullptr || textFont == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = false;
    }


    currentScene = new SceneTitle();
    currentScene->init();
}

void Game::clean()
{ 
    if(currentScene != nullptr){
        currentScene->clean();   
        delete currentScene;
    }
    if(nearSight.texture != nullptr){
        SDL_DestroyTexture(nearSight.texture);
    }
    if(farSight.texture != nullptr){         
        SDL_DestroyTexture(farSight.texture);
    }
    if(titleFont != nullptr){
        TTF_CloseFont(titleFont);
    }
    if(textFont != nullptr){
        TTF_CloseFont(textFont);
    }
    TTF_Quit();
    IMG_Quit();

    Mix_CloseAudio();
    Mix_Quit();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::changeScene(Scene *scene)
{
    if(currentScene != nullptr){
        currentScene->clean();   
        delete currentScene;
    }

    currentScene = scene;
    currentScene->init();
}

void Game::handleEvent(SDL_Event *event)
{
    while (SDL_PollEvent(event))
    {
        if(event->type == SDL_QUIT){
            isRunning = false;
        }
        currentScene->handleEvent(event);
    }
    
}


void Game::update(float deltaTime)
{
    backgroundUpdate(deltaTime);
    currentScene->update(deltaTime);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    renderBackground();
    currentScene->render();
    SDL_RenderPresent(renderer);

}

SDL_Point Game::renderTextCentered(std::string text, float posY, bool isTitle)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *textSurface;
    if(isTitle){
        textSurface = TTF_RenderUTF8_Solid(titleFont, text.c_str(), color);
    }else{
        textSurface = TTF_RenderUTF8_Solid(textFont, text.c_str(), color);
    }
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int y = static_cast<int>((getWindowHeight() - textSurface->h)*posY);
    SDL_Rect textRect = {getWindowWidth() / 2 - textSurface->w / 2,
                        y,
                        textSurface->w,
                        textSurface->h};
   
    SDL_RenderCopy(getRenderer(), textTexture, NULL, &textRect); 
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    return{textRect.x+textRect.w,y};
}

void Game::renderTextPos(std::string text, float posX, float posY, bool isTitle)
{   
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *textSurface;
    if(isTitle){
        textSurface = TTF_RenderUTF8_Solid(titleFont, text.c_str(), color);
    }else{
        textSurface = TTF_RenderUTF8_Solid(textFont, text.c_str(), color);
    }
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {static_cast<int>(posX),
                        static_cast<int>(posY),
                        textSurface->w,
                        textSurface->h};    
    SDL_RenderCopy(getRenderer(), textTexture, NULL, &textRect); 
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);   
}

void Game::backgroundUpdate(float deltaTime)
{

    nearSight.offset += nearSight.speed * deltaTime;
    if(nearSight.offset >= 0){
        nearSight.offset -= nearSight.height;
    }

    farSight.offset += farSight.speed * deltaTime;
    if(farSight.offset >= 0){
        farSight.offset -= deltaTime;
    }
}

void Game::renderBackground()
{
    
    for (int posY = static_cast<int> (nearSight.offset); posY < getWindowHeight(); posY += nearSight.height) 
    {
        for(int posX = 0; posX < getWindowWidth(); posX += nearSight.width)
        {
            SDL_Rect nearSightRect = {posX, posY, nearSight.width, nearSight.height};
            SDL_RenderCopy(renderer, nearSight.texture, nullptr, &nearSightRect);
        }
        
    }
    
    for (int posY = static_cast<int> (farSight.offset); posY < getWindowHeight(); posY += farSight.height) 
    {
        for(int posX = 0; posX < getWindowWidth(); posX += farSight.width)
        {
            SDL_Rect farSightRect = {posX, posY, farSight.width, farSight.height};
            SDL_RenderCopy(renderer, farSight.texture, nullptr, &farSightRect);
        }
        
    }
        
}
