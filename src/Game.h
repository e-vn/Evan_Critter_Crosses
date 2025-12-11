
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
 Game(sf::RenderWindow& window);
 ~Game();

 bool init();
 void update(float dt);
 void render();
 void mouseClicked(sf::Event event);
 void keyPressed(sf::Event event);
 void keyReleased(sf::Event event);
 void MouseButtonPressed(sf::Event event);
 void MouseButtonReleased(sf::Event event);
 void pauseGame();
 void newAnimal();
 void reset();
 void loadTextures();
 void dragSprite(sf::Sprite* sprite);


 private:

 sf::RenderWindow& window;
 
 // game states
 std::string game_state = "main";
 sf::Text play_option;
 sf::Text quit_option;
 bool play_selected = true;
 bool is_paused = false;

 // text
 sf::Font font;
 sf::Text title_text;
 sf::Text pause_title;
 sf::Text continue_option;
 sf::Text pause_quit_option;
 bool continue_selected = true;

 // sprites
 sf::Sprite* character;
 sf::Sprite* passport;
 sf::Texture* animals = new sf::Texture[3];
 sf::Texture* passports = new sf::Texture[3];

 sf::Texture* button_textures = new sf::Texture[2];
 sf::Sprite* accept_button;
 sf::Sprite* reject_button;

 sf::Sprite* dragged = nullptr;

 // passport
 bool passport_accepted;
 bool passport_rejected;
 bool should_accept;

};

#endif // PLATFORMER_GAME_H
