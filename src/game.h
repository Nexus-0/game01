#ifndef GAME_H
#define GAME_H  

#include "scene.h"
#include "object.h"
#include<SDL.h> 
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<string>
#include<map>

class Game
{
public:
    static Game& getinstance(){
        static Game instance;
        return instance;
    };
  
    ~Game();
    void run();//游戏主循环
    void init();//初始化
    void clean();//清理
    void changeScene(Scene* scene);//切换场景

    void handleEvent(SDL_Event* event);//事件处理
    void update(float deltaTime);//更新
    void render();//渲染
    //渲染函数文字
    SDL_Point renderTextCentered(std::string text,float posY,  bool isTitle);//居中渲染
    void renderTextPos(std::string text, float posX, float posY, bool isLeft = true);//位置渲染
    //setters
    void setFinalScore(int score){finalScore = score;};
    void insertLeaderBoard(int score, std::string name);//插入排行榜
    

    //getters
    SDL_Window* getWindow(){return window;};//获取窗口
    SDL_Renderer* getRenderer(){return renderer;};//获取渲染器
    int getWindowWidth(){return windowWidth;};//获取窗口宽
    int getWindowHeight(){return windowHeight;};//获取窗口高
    int getFinalScore(){return finalScore;};//获取最终得分
    std::multimap<int ,std::string,std::greater<int> > getLeaderBoard(){return leaderBoard;};//获取排行榜
private:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    TTF_Font* titleFont;
    TTF_Font* textFont;

    bool isRunning = true;//游戏是否运行
    Scene* currentScene = nullptr;//当前场景
    SDL_Window* window = nullptr;//窗口
    SDL_Renderer* renderer = nullptr;//渲染器

    int windowWidth = 600;
    int windowHeight = 800;
    int frameRate = 60;//帧率
    Uint32 frameTime = 1000 / frameRate;//每帧时间
    float deltaTime = 0.0f;
    int finalScore = 0;//最终得分
    
    Background nearSight;//渲染近景
    Background farSight;//渲染远景

    std::multimap<int ,std::string,std::greater<int> > leaderBoard;//排行榜

    void backgroundUpdate(float deltaTime);//更新背景
    void renderBackground();//渲染背景
    void saveData();
    void loadData();

};



#endif // GAME_H