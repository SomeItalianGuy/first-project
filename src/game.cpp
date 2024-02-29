#include "game.hpp"

// Private methods

/*
    Initailizes a fullscreen winow at 60 fps
*/
void Game::initWindow() {
    this->m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                            "My first game",
                                            sf::Style::Fullscreen);

    this->m_window->setFramerateLimit(60);
}

void Game::initPlayer() {
    this->m_player = Entity(40.F, sf::Color::Blue);
}

// Constructor / Destructor

/* 
    Initializes:
    - Window
*/
Game::Game() {
    this->initWindow();
    this->initPlayer();
}

/*
    Does nothing
*/
Game::~Game() {
    delete this->m_window;
}

// Public methods

/*
    Tells if the window is open
*/
bool Game::isRunning() {
    return this->m_window->isOpen();
}

/*
    The current accepted events are:
    - Close -> Closes the window
*/
void Game::pollEvents() {
    if(this->m_window->pollEvent(this->m_event)) {
        switch(this->m_event.type) {
            case sf::Event::KeyPressed:
            if(this->m_event.key.code == sf::Keyboard::Escape) {
            this->m_window->close();
            }
            break;
            default:
            break;
        }
    }
}

/*
    This function:
    - polls the events
    
    Then updates:
    - player status
*/
void Game::update() {
    this->pollEvents();
}

/*
    This function:
    - clears the frame
    - displays 
*/
void Game::render() {
    this->m_window->clear(sf::Color::Black);

    this->m_window->draw(this->m_player.getShape());

    this->m_window->display();
}