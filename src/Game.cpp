
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
    //main menu title
    if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
    {
        std::cout << "font did not load \n";
    }
    title_text.setString("Critter  Crosses");
    title_text.setFont(font);
    title_text.setCharacterSize(90);
    title_text.setFillColor(sf::Color(255, 255, 255, 255));
    title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 2 - title_text.getGlobalBounds().height / 2 - 150);

    // play button
    play_option.setString("> Play <");
    play_option.setFont(font);
    play_option.setCharacterSize(50);
    play_option.setFillColor(sf::Color(255, 255, 255, 128));
    play_option.setPosition(
    window.getSize().x / 2 - play_option.getGlobalBounds().width / 2 - 200,
    window.getSize().y / 2 - play_option.getGlobalBounds().height / 2 + 200);

    // quit button
    quit_option.setString("Quit");
    quit_option.setFont(font);
    quit_option.setCharacterSize(50);
    quit_option.setFillColor(sf::Color(255, 255, 255, 128));
    quit_option.setPosition(
    window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2 + 200,
    window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2 + 200);


  return true;
}

void Game::update(float dt)
{
    if (game_state == "main")
    {
        // main menu state
    }


}

void Game::render()
{
    if (game_state == "main") 
    {
        window.draw(title_text);
        window.draw(play_option);
        window.draw(quit_option);
    }

}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
    if (game_state == "main")
    {
        if (
            (event.key.code == sf::Keyboard::Left) ||
            (event.key.code == sf::Keyboard::Right))
        {
            play_selected = !play_selected;
            if (play_selected)
            {
                play_option.setString("> Play <");
                quit_option.setString("Quit");
            }
            else
            {
                play_option.setString("Play");
                quit_option.setString("> Quit <");
            }
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (play_selected)
            {
                game_state = "in_game";
            }
           else
            {
                window.close();
            }
        }
    }
}
void Game::keyReleased(sf::Event event) {

}


