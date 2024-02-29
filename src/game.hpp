#ifndef GAME_HPP
#define GAME_HPP

#include "entity.hpp"


class Game{
    private:
    // Private variables

    sf::RenderWindow* m_window;
    sf::Event m_event;
    Entity m_player;

    // Private methods

    void initWindow();
    void initPlayer();

    public:
    // Constructor / Destructor

    Game();
    
    ~Game();

    // Public methods

    bool isRunning();
    void pollEvents();
    void update();
    void render();
};

#endif