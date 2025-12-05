
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
  void pauseGame();
  void reset();

 private:
  sf::RenderWindow& window;
 
  sf::Font font;
  sf::Text title_text;

  std::string game_state = "main";
  sf::Text play_option;
  sf::Text quit_option;
bool play_selected = true;

  bool is_paused = false;
  sf::Text pause_title;
  sf::Text continue_option;
  sf::Text pause_quit_option;
  bool continue_selected = true;



};

#endif // PLATFORMER_GAME_H
