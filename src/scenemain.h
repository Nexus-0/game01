#ifndef SCENEMAIN_H
#define SCENEMAIN_H
 
#include "scene.h"
#include "object.h"

#include <list>
#include <random>
#include <map>
#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
class Game;
class SceneMain : public Scene
{
public:
   
    ~SceneMain();
    void init() override;
    void update(float deltaTime) override;
    void render() override;
    void clean() override;
    void handleEvent(SDL_Event* event) override;

private:
    Player player1;
    Mix_Music * bgm;
    SDL_Texture* uiHealth;
    TTF_Font* scoreFont;
    int score = 0;

    bool isAlive = true;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;

    Enemy enemyTemplate;
    EnemyProjectile enemyProjectileTemplate;
    PlayerProjectile playerProjectileTemplate;
    Explosion explosionTemplate;
    Item itemLifeTemplate;
    
    std::list<Enemy*> enemies;
    std::list<EnemyProjectile*> enemyProjectile;
    std::list<PlayerProjectile*> playerProjectile;
    std::list<Explosion*> explosions;
    std::list<Item*> items;
    std::map<std::string,Mix_Chunk*> sounds;

    void renderItems();
    void renderUI();
    void renderExplosions();
    void renderPlayerProjectile();
    void renderEnemyProjectile();
    void renderEnemies();

    void updateEnemies(float deltaTime);
    void updateEnemyProjectile(float deltaTime);
    void updatePlayer(float deltaTime);
    void updateItems(float deltaTime);
    void updateExplosion();
    void updatePlayerProjectile(float deltaTime);
    void keybordControl(float deltaTime);
    void spawnEnemy();

    void playerGetItem(Item *item);
    void shootControl();
    void shootEnemy(Enemy *enemy);
    SDL_FPoint getDirection(Enemy *enemy);
    void enemyExplode(Enemy *enemy);
    void dropItem(Enemy *enemy);

};

#endif // SCENEMAIN_H