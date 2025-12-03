
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

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;

  sf::Font font;
  sf::Text title_text;

  std::string game_state = "main";
  sf::Text play_option;
  sf::Text quit_option;

  bool play_selected = true;

};

#endif // PLATFORMER_GAME_H
