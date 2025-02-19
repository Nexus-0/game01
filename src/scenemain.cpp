#include "scenemain.h"
#include "game.h"
#include "scenetitle.h"
#include "sceneend.h"

#include<SDL.h>
#include<SDL_image.h>
#include<random>


SceneMain::~SceneMain()
{

}

void SceneMain::init()
{
    //加载背景音乐
    bgm = Mix_LoadMUS("assets/music/03_Racing_Through_Asteroids_Loop.ogg");
    if(bgm == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
    }
    Mix_PlayMusic(bgm, -1);

    //读取ui Health；
    uiHealth = IMG_LoadTexture(game.getRenderer(), "assets/image/Health UI Black.png");
    //随机数
    std::random_device rd;
    gen = std::mt19937(rd()); 
    dis = std::uniform_real_distribution<float>(0.0f,1.0f);

    scoreFont = TTF_OpenFont("assets/font/VonwaonBitmap-12px.ttf", 24);


    //读取音效
    sounds["player_shoot"] = Mix_LoadWAV("assets/sound/laser_shoot4.wav");
    sounds["enemy_shoot"] = Mix_LoadWAV("assets/sound/xs_laser.wav");
    sounds["player_explosion"] = Mix_LoadWAV("assets/sound/explosion1.wav");
    sounds["enemy_explosion"] = Mix_LoadWAV("assets/sound/explosion3.wav");
    sounds["get_item"] = Mix_LoadWAV("assets/sound/eff5.wav");
    sounds["hit"] = Mix_LoadWAV("assets/sound/eff11.wav");
    


    //初始化玩家
    player1.texture = IMG_LoadTexture(game.getRenderer(), "assets/image/SpaceShip.png");
    SDL_QueryTexture(player1.texture, NULL, NULL, &player1.width, &player1.height);
    player1.width /= 4;
    player1.height /= 4;
    player1.position.x = game.getWindowWidth() / 2 - player1.width / 2;
    player1.position.y = game.getWindowHeight()- player1.height;

    //初始化子弹

    playerProjectileTemplate.texture = IMG_LoadTexture(game.getRenderer(), "assets/image/laser-1.png");
    SDL_QueryTexture(playerProjectileTemplate.texture, NULL, NULL, &playerProjectileTemplate.width, &playerProjectileTemplate.height);
    playerProjectileTemplate.width /= 4;
    playerProjectileTemplate.height /= 4;

    //初始化敌人
    enemyTemplate.texture = IMG_LoadTexture(game.getRenderer(), "assets/image/insect-2.png");
    SDL_QueryTexture(enemyTemplate.texture, NULL, NULL, &enemyTemplate.width, &enemyTemplate.height);
    enemyTemplate.width /= 4;
    enemyTemplate.height /= 4;

    //初始化敌人子弹
    enemyProjectileTemplate.texture = IMG_LoadTexture(game.getRenderer(), "assets/image/bullet-1.png");
    SDL_QueryTexture(enemyProjectileTemplate.texture, NULL, NULL, &enemyProjectileTemplate.width, &enemyProjectileTemplate.height);
    enemyProjectileTemplate.width /= 4;
    enemyProjectileTemplate.height /= 4; 
    
    //初始化爆炸
    explosionTemplate.texture = IMG_LoadTexture(game.getRenderer(), "assets/effect/explosion.png");
    SDL_QueryTexture(explosionTemplate.texture, NULL, NULL, &explosionTemplate.width, &explosionTemplate.height);
    explosionTemplate.totalFrame = explosionTemplate.width / explosionTemplate.height;
    explosionTemplate.width = explosionTemplate.height;   

    //初始化道具
    itemLifeTemplate.texture = IMG_LoadTexture(game.getRenderer(), "assets/image/bonus_life.png");
    SDL_QueryTexture(itemLifeTemplate.texture, NULL, NULL, &itemLifeTemplate.width, &itemLifeTemplate.height);
    itemLifeTemplate.width /= 4;
    itemLifeTemplate.height /= 4;

}

void SceneMain::update(float deltaTime)
{
    keybordControl(deltaTime);
    updatePlayerProjectile(deltaTime);
    updateEnemyProjectile(deltaTime);
    spawnEnemy();
    updateEnemies(deltaTime);
    updatePlayer(deltaTime);
    updateExplosion();
    updateItems(deltaTime);
    if(isAlive == false){
        changeSceneDelayed(deltaTime,3);
    };
}
void SceneMain::render()
{
    //渲染玩家子弹
    renderPlayerProjectile();
    //渲染敌人子弹
    renderEnemyProjectile();
    //渲染玩家
    if(isAlive){
        SDL_Rect player1Rect = {static_cast<int>(player1.position.x), 
            static_cast<int>(player1.position.y), 
            player1.width, 
            player1.height};
SDL_RenderCopy( game.getRenderer(), player1.texture,NULL ,&player1Rect);

    }
   
    //渲染敌人
    renderEnemies();
    //渲染道具
    renderItems();
    
    //渲染爆炸
    renderExplosions();

    //渲染UI
    renderUI();


}

void SceneMain::clean()
{
    //清理音频
    for (auto sound : sounds)
    {
        if (sound.second != nullptr)
        {
            Mix_FreeChunk(sound.second);
        }
    }
    sounds.clear();

    //清理ui
    if(uiHealth != nullptr){
        SDL_DestroyTexture(uiHealth);
    }
    //清理容器
    for (auto projectile : playerProjectile) 
    {
        if(projectile != nullptr){
            delete projectile;
        }
    }
    playerProjectile.clear();

    for (auto projectile : enemyProjectile)
    {
        if(projectile != nullptr){
            delete projectile;
        }
    }
    enemyProjectile.clear();

    
    //清理敌人
    for (auto enemy : enemies) 
    {
        if(enemy != nullptr){
            delete enemy;
        }
    }
    enemies.clear();
    //清理道具
    for (auto item : items) 
    {
        if(item != nullptr){
            delete item;
        }
    }
    items.clear();
    //清理爆炸
    for (auto explosion : explosions) 
    {
        if(explosion != nullptr){
            delete explosion;
        }
    }
    explosions.clear();

    //清理字体
    if(scoreFont != nullptr){
        TTF_CloseFont(scoreFont);
    }
   
    //清理模版
    if(player1.texture != nullptr){
        SDL_DestroyTexture(player1.texture);
    }
    if (playerProjectileTemplate.texture != nullptr)
    {
        SDL_DestroyTexture(playerProjectileTemplate.texture);
    }
    if (enemyTemplate.texture != nullptr)
    {
        SDL_DestroyTexture(enemyTemplate.texture);      
    }
    if (enemyProjectileTemplate.texture != nullptr)
    {   
        SDL_DestroyTexture(enemyProjectileTemplate.texture);
    }
    if (explosionTemplate.texture != nullptr)
    {
        SDL_DestroyTexture(explosionTemplate.texture);
    }
    if (itemLifeTemplate.texture != nullptr)
    {
        SDL_DestroyTexture(itemLifeTemplate.texture);
    }
    
    //清理背景音乐
    if(bgm != nullptr){
        Mix_HaltMusic();
        Mix_FreeMusic(bgm);

    }
    //清理随机数

    
}

void SceneMain::handleEvent(SDL_Event* event)
{
   if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.scancode == SDL_SCANCODE_ESCAPE){
            auto titleScene = new SceneTitle();
            game.changeScene(titleScene);
        }
    }
    if(player1.currentHealth <= 0){
        auto endScene = new SceneEnd();
        game.changeScene(endScene);
    }
}

void SceneMain::keybordControl(float deltaTime)
{
    if(!isAlive){
        return;
    }
   auto keyboardState = SDL_GetKeyboardState(NULL);
   //移动控制
   if (keyboardState[SDL_SCANCODE_UP])
   {
        player1.position.y -= deltaTime*player1.speed;
   }
   if (keyboardState[SDL_SCANCODE_DOWN])
   {
        player1.position.y += deltaTime*player1.speed;
   }
   if (keyboardState[SDL_SCANCODE_LEFT])
   {
        player1.position.x -= deltaTime*player1.speed;
   }
   if (keyboardState[SDL_SCANCODE_RIGHT])
   {
        player1.position.x += deltaTime*player1.speed;
   }
   //边界
   if(player1.position.x < 0){
        player1.position.x = 0;
   }
   if(player1.position.y < 0){
        player1.position.y = 0;
   }
   if(player1.position.x > game.getWindowWidth() - player1.width){
        player1.position.x = game.getWindowWidth() - player1.width;
   }
   if(player1.position.y > game.getWindowHeight() - player1.height){
        player1.position.y = game.getWindowHeight() - player1.height;
   }
   //射击控制
   if (keyboardState[SDL_SCANCODE_J])
   {
    auto currentTime = SDL_GetTicks();
    if(currentTime - player1.lastShootTime > player1.cooldown){
        shootControl();
        player1.lastShootTime = currentTime;
        
    }
      
   }
}

void SceneMain::shootControl()
{
    auto projectile = new PlayerProjectile(playerProjectileTemplate);
    projectile->position.x = player1.position.x + player1.width/2 - projectile->width/2;
    projectile->position.y = player1.position.y;
    playerProjectile.push_back(projectile); 
    Mix_PlayChannel(0, sounds["player_shoot"], 0);
  
}

void SceneMain::updatePlayer(float deltaTime)
{
    if(!isAlive){

        return;
    }
    if(player1.currentHealth <= 0){

        auto currentTime = SDL_GetTicks();
        isAlive = false;
        auto explosion = new Explosion(explosionTemplate);
        explosion->position.x = player1.position.x +player1.width/2 - explosion->width/2;
        explosion->position.y = player1.position.y +player1.height/2 - explosion->height/2;
        explosion->startTime = currentTime;
        explosions.push_back(explosion);
        Mix_PlayChannel(-1, sounds["player_explosion"], 0);
        game.setFinalScore(score);
    
        return;

    }
      
    for(auto enemy : enemies){
        SDL_Rect enemyRect = {  static_cast<int>(enemy->position.x),    
                                static_cast<int>(enemy->position.y),            
                                enemy->width, 
                                enemy->height};
        SDL_Rect playerRect = { static_cast<int>(player1.position.x),    
                                static_cast<int>(player1.position.y), 
                                player1.width, 
                                player1.height};
        if(SDL_HasIntersection(&playerRect, &enemyRect)){
            player1.currentHealth -= 1;
            enemy->currentHealth = 0;
            
        }
        (void) deltaTime;
    }
}

void SceneMain::updatePlayerProjectile(float deltaTime)
{
    for (auto it = playerProjectile.begin(); it != playerProjectile.end();)
    {
        int margin = 32;
        auto projectile = *it;
        projectile->position.y -= deltaTime*projectile->speed;
        if(projectile->position.y+margin < 0){
            delete projectile;
            it = playerProjectile.erase(it);
      
        }
        else
        {
            bool hit;
            for(auto enemy : enemies){
                SDL_Rect enemyRect = {  static_cast<int>(enemy->position.x),    
                                        static_cast<int>(enemy->position.y),            
                                        enemy->width, 
                                        enemy->height};
                SDL_Rect projectileRect = { static_cast<int>(projectile->position.x),    
                                            static_cast<int>(projectile->position.y), 
                                            projectile->width, 
                                            projectile->height};
                if(SDL_HasIntersection(&projectileRect, &enemyRect)){
                    enemy->currentHealth -= projectile->damage;
                    delete projectile;
                    it = playerProjectile.erase(it);
                    hit = true;
                    Mix_PlayChannel(-1, sounds["hit"], 0);
                    
                    break;
                }
            }
            if(!hit){
                ++it;
            }
        
        }
    }
}

void SceneMain::renderPlayerProjectile()
{
    for (auto projectile : playerProjectile)
    {
        SDL_Rect projectileRect = { static_cast<int>(projectile->position.x),    
                                    static_cast<int>(projectile->position.y), 
                                    projectile->width, 
                                    projectile->height};
        SDL_RenderCopy(game.getRenderer(), projectile->texture, NULL, &projectileRect);
    }
}

void SceneMain::spawnEnemy()
{
    if(dis(gen) > 1/60.0f){
        return;
    }
    Enemy *enemy = new Enemy(enemyTemplate);
    enemy->position.x = dis(gen)*(game.getWindowWidth() - enemy->width);
    enemy->position.y = -enemy->height ;
    this->enemies.push_back(enemy);
}

void SceneMain::changeSceneDelayed(float deltaTime, float delay)
{
    timer += deltaTime;
    if(timer > delay){ 
        auto sceneEnd = new SceneEnd();
        game.changeScene(sceneEnd);
        
    }
}

void SceneMain::updateEnemies(float deltaTime)
{
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        auto enemy = *it;
        enemy->position.y += deltaTime*enemy->speed;
        if (enemy->position.y > game.getWindowHeight())
        {
            delete enemy;
            it = enemies.erase(it);
        }
        else
        {
            auto currentTime = SDL_GetTicks();
            if(currentTime - enemy->lastShootTime > enemy->cooldown){
                shootEnemy(enemy);
                enemy->lastShootTime = currentTime;
            }
            if(enemy->currentHealth <= 0){
               enemyExplode(enemy); 
               Mix_PlayChannel(-1, sounds["enemy_explosion"], 0);
               it = enemies.erase(it);
            }else{
            ++it;}
        }
    }
}

void SceneMain::renderEnemies()
{
    for (auto enemy : enemies)
    {
        SDL_Rect enemyRect = { static_cast<int>(enemy->position.x),    
                                    static_cast<int>(enemy->position.y), 
                                    enemy->width, 
                                    enemy->height};
        SDL_RenderCopy(game.getRenderer(), enemy->texture, NULL, &enemyRect);
    }
    
}

void SceneMain::updateEnemyProjectile(float deltaTime)
{
    
    auto margin=32;
  
    for (auto it = enemyProjectile.begin(); it != enemyProjectile.end();)
    {
        
        auto projectile = *it;
        projectile->position.x += projectile->speed * projectile->direction.x*deltaTime;
        projectile->position.y += projectile->speed * projectile->direction.y*deltaTime;

        if( projectile->position.y+margin > game.getWindowHeight() + margin || 
            projectile->position.y+margin < 0 || 
            projectile->position.x+margin < 0 || 
            projectile->position.x+margin > game.getWindowWidth() + margin){
            delete projectile;
            it = enemyProjectile.erase(it);
      
        }
        else
        {
            SDL_Rect projectileRect ={
                static_cast<int>(projectile->position.x),    
                static_cast<int>(projectile->position.y), 
                projectile->width, 
                projectile->height};
            SDL_Rect playerRect = {
                static_cast<int>(player1.position.x),    
                static_cast<int>(player1.position.y), 
                player1.width, 
                player1.height};
            if(SDL_HasIntersection(&projectileRect, &playerRect) && isAlive){
                player1.currentHealth -= projectile->damage;
                delete projectile;
                it = enemyProjectile.erase(it);
                Mix_PlayChannel(-1, sounds["hit"], 0);
            }else{
            ++it;
            }
        }
    }
    
}

void SceneMain::renderEnemyProjectile()
{
    for (auto projectile : enemyProjectile)     
    {
        SDL_Rect projectileRect = { static_cast<int>(projectile->position.x),    
                                    static_cast<int>(projectile->position.y), 
                                    projectile->width, 
                                    projectile->height};
        float angle = atan2(projectile->direction.y, projectile->direction.x) * 180 /  -90;
        SDL_RenderCopyEx(game.getRenderer(), projectile->texture, NULL, &projectileRect,angle,NULL,SDL_FLIP_NONE);         
    }
    
}

void SceneMain::shootEnemy(Enemy *enemy)
{
    auto projectile = new EnemyProjectile(enemyProjectileTemplate);
    projectile->position.x = enemy->position.x + enemy->width/2 - projectile->width/2;
    projectile->position.y = enemy->position.y;
    projectile->direction = getDirection(enemy);
    enemyProjectile.push_back(projectile);  
    Mix_PlayChannel(-1, sounds["enemy_shoot"], 0);
}

SDL_FPoint SceneMain::getDirection(Enemy *enemy)
{
    auto x = (player1.position.x + player1.width/2) - (enemy->position.x + enemy->width/2);
    auto y = (player1.position.y + player1.height/2) - (enemy->position.y + enemy->height/2);
    auto length = sqrt(x*x + y*y);
    x /= length;
    y /= length;
    return SDL_FPoint{x,y};
}

void SceneMain::enemyExplode(Enemy *enemy)
{
    auto currentTime = SDL_GetTicks();
    auto explosion = new Explosion(explosionTemplate);
    explosion->position.x = enemy->position.x +enemy->width/2 - explosion->width/2;
    explosion->position.y = enemy->position.y +enemy->height/2 - explosion->height/2;
    explosion->startTime = currentTime;
    explosions.push_back(explosion);
    if(dis(gen) >0.0f){
        dropItem(enemy);
    }
    score +=10;
    delete enemy;
}

void SceneMain::updateExplosion()
{
    auto currentTime = SDL_GetTicks();
    for (auto it = explosions.begin(); it != explosions.end();)
    {
        auto explosion = *it;
        explosion->currentFrame = (currentTime - explosion->startTime) * explosion-> FPS / 1000;
        if(explosion->currentFrame >= explosion->totalFrame){
            
        
            delete explosion;
            it = explosions.erase(it);
        }else{
            ++it;
        }
    }
}

void SceneMain::renderExplosions()
{
    for (auto explosion : explosions)
    {
         SDL_Rect src = {explosion->currentFrame * explosion->width, 0, explosion->width, explosion->height};
         SDL_Rect dst = {   static_cast<int>(explosion->position.x), 
                            static_cast<int>(explosion->position.y), 
                            explosion->width, 
                            explosion->height
                        };
        SDL_RenderCopy(game.getRenderer(), explosion->texture, &src, &dst);
    }
}

void SceneMain::dropItem(Enemy *enemy)
{
    auto item = new Item(itemLifeTemplate);
    item->position.x = enemy->position.x +enemy->width/2 - item->width/2;
    item->position.y = enemy->position.y +enemy->height/2 - item->height/2;
    float angle =dis(gen)*2*M_PI;
    item->direction.x = cos(angle);
    item->direction.y = sin(angle);
    items.push_back(item);
}

void SceneMain::updateItems(float deltaTime)
{
    for (auto it = items.begin(); it != items.end();)
    {
        auto item = *it;
        //更新位置
        item->position.x += item->direction.x*item->speed*deltaTime;
        item->position.y += item->direction.y*item->speed*deltaTime;
        //边界
        if (item->position.x < 0 && item->bounceCount > 0)
        {
            item->direction.x = -item->direction.x;
            item->bounceCount -= 1;
        }
        if (item->position.y < 0 && item->bounceCount > 0)
        {
            item->direction.y = -item->direction.y;
            item->bounceCount -= 1;
        }
        if (item->position.x +item->width > game.getWindowWidth() && item->bounceCount > 0)
        {
            item->direction.x = -item->direction.x;
            item->bounceCount -= 1; 
        }
        if (item->position.y +item->height > game.getWindowHeight() && item->bounceCount > 0)
        {
            item->direction.y = -item->direction.y;
            item->bounceCount -= 1;     
        }
        

        if(
        item->position.x +item->width<0 || 
        item->position.x >game.getWindowWidth() ||
        item->position.y + item->height<0 ||
        item->position.y >game.getWindowHeight()){
       
            delete item;
            it = items.erase(it);
        }
        else{
                SDL_Rect itemRect = {   static_cast<int>(item->position.x), 
                                static_cast<int>(item->position.y), 
                                item->width, 
                                item->height
                            };
                SDL_Rect playerRect = { static_cast<int>(player1.position.x),    
                                static_cast<int>(player1.position.y), 
                                player1.width, 
                                player1.height
                            };
                if(SDL_HasIntersection(&itemRect, &playerRect)){
                    if(isAlive)
                    { 
                    playerGetItem(item);
           
                    Mix_PlayChannel(-1, sounds["get_item"], 0);
                    delete item;
                    it = items.erase(it); 
                    }  }
                else{
                    ++it;
                }
            }
          
    }
}

void SceneMain::renderItems()
{
    for (auto item : items)
    {
        SDL_Rect itemRect = {   static_cast<int>(item->position.x), 
                                static_cast<int>(item->position.y), 
                                item->width, 
                                item->height
                            };
        SDL_RenderCopy(game.getRenderer(), item->texture, NULL, &itemRect); 
    }
    
}

void SceneMain::playerGetItem(Item *item)
{
    score += 5;
    if(item->type == ItemType::Life){
        player1.currentHealth ++;
        if(player1.currentHealth > player1.maxHealth){
            player1.currentHealth = player1.maxHealth;
        }   
    }
    if(item->type == ItemType::Shield){
        player1.speed += 50;
    }
    if(item->type == ItemType::Time){
        player1.cooldown -= 500;
    }
}

void SceneMain::renderUI()
{
    int x = 10;
    int y = 10;
    int size = 32;
    int offset = 40;
    SDL_SetTextureColorMod(uiHealth,100,100,100);
    for(int i = 0; i < player1.maxHealth; i++)
    {
        SDL_Rect healthRect = {x + i * offset, y, size, size};
        SDL_RenderCopy(game.getRenderer(), uiHealth, NULL, &healthRect);
       
    }
    SDL_SetTextureColorMod(uiHealth,255,255,255);
    for(int i = 0; i < player1.currentHealth; i++)
    {
        SDL_Rect healthRect = {x + i * offset, y, size, size};
        SDL_RenderCopy(game.getRenderer(), uiHealth, NULL, &healthRect);
     
    }
    auto text = "SCORE: " + std::to_string(score);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(scoreFont, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game.getRenderer(), textSurface);
    SDL_Rect textRect = {game.getWindowWidth() - 10-textSurface->w, 10, textSurface->w, textSurface->h};
    SDL_RenderCopy(game.getRenderer(), textTexture, NULL, &textRect);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}    
