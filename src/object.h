#ifndef OBJECT_H
#define OBJECT_H    

#include <SDL.h>

enum ItemType   
{
    Life,
    Shield,
    Time
};
struct Player
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    int width = 0;
    int height = 0;
    int speed = 300;
    Uint32 cooldown = 500;
    Uint32 lastShootTime = 0;
    int currentHealth = 3;
    int maxHealth = 3;

};
struct Enemy
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    int width = 0;
    int height = 0;
    int speed = 150;
    Uint32 cooldown = 2000;
    Uint32 lastShootTime = 0;
    int currentHealth = 2;
};

struct PlayerProjectile
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    int width = 0;
    int height = 0;
    int speed = 600;
    int damage = 1;
};
struct EnemyProjectile
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    SDL_FPoint direction = {0, 0};
    int width = 0;
    int height = 0;
    int speed = 400;    
    int damage = 1;
};
struct Explosion
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    int width = 0;
    int height = 0; 
    int currentFrame= 0;
    int framecount = 0; 
    int totalFrame = 0;
    Uint32 startTime = 0;
    Uint32 FPS = 10;
};
struct Item
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    SDL_FPoint direction = {0, 0};
    int width = 0;
    int height = 0;
    int speed = 200;
    int bounceCount = 3;
    ItemType type = ItemType::Life;
};

struct Background
{
    SDL_Texture *texture = nullptr;
    SDL_FPoint position = {0, 0};
    float offset = 1.0f;
    int width = 0;
    int height = 0;
    int speed = 30;
};




#endif