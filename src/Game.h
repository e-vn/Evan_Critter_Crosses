
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
  

 sf::Vector2f drag_position;

 // text
 sf::Font font;
 sf::Text title_text;
 sf::Text pause_title;
 sf::Text continue_option;
 sf::Text pause_quit_option;
 sf::Text displayPoints;
 sf::Text displayLives;
 sf::Text win_text;
 sf::Text lose_text;
 bool continue_selected = true;

 // background
 sf::Texture background_texture;
 sf::Sprite background_sprite;

 // sprites
 sf::Sprite* character;
 sf::Sprite* passport;
 sf::Texture* animals = new sf::Texture[3];
 sf::Texture* passports = new sf::Texture[3];

 sf::Texture* button_textures = new sf::Texture[2];
 sf::Sprite* accept_button;
 sf::Sprite* reject_button;

 sf::Sprite* accepted_stamp;
 sf::Sprite* rejected_stamp;
 sf::Texture* stamp_textures = new sf::Texture[2];

 sf::Sprite* dragged = nullptr;
 sf::Sprite Stamp;          

 sf::Vector2f drag_offset;



 // passport
 bool passport_accepted = false;
 bool passport_rejected = false;
 bool should_accept;


 // lives

 int player_lifes = 3;
 int max_lifes = 3;


 // points

 int player_points = 0;
 int max_points = 3;

 bool lose = false;
 bool win = true;

};

#endif // PLATFORMER_GAME_H
