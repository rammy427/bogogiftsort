#include "Entity.h"
#include "Container.h"
#include "TextureManager.h"
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(sf::RenderWindow& rw);
    void run();
private:
    void processEvents();
    void updateEntities();
    void drawFrame();
    /** Game Functions **/
    void endGame();
    void reset();
    void doEntityContainment();
    void saveTopScore();
    void loadTopScore();
private:
    sf::RenderWindow& rw;
    sf::Clock clock;
    /** Game Variables **/
    std::vector<Entity> entities;
    Container cont1;
    Container cont2;
    bool gameIsOver = false;
    int score = 0;
    int topScore = 0;
    /****** Timers ******/
    static constexpr float maxTime = 2.0f;
    static constexpr float minTime = 0.25f;
    static constexpr float step = 0.0175f;
    float spawnTime = maxTime;
    float curTime = 0.0f;
    /**** Text Stuff ****/
    sf::Font font;
    sf::Text scoreText;
    sf::Text topScoreText;
    /**** Sprite Data ****/
    std::shared_ptr<sf::Texture> pBgTex;
    sf::Sprite bg;
};

#endif