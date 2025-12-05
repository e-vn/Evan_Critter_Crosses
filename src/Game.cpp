
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

   //pause menu
   
  //pause title
    pause_title.setString("Pause");
    pause_title.setFont(font);
    pause_title.setCharacterSize(100);
    pause_title.setFillColor(sf::Color(255, 255, 255, 255));
    pause_title.setPosition(
    window.getSize().x / 2 - pause_title.getGlobalBounds().width / 2,
    window.getSize().y / 2 - pause_title.getGlobalBounds().height / 2 - 150);
    // play button
    continue_option.setString("> Continue <");
    continue_option.setFont(font);
    continue_option.setCharacterSize(50);
    continue_option.setFillColor(sf::Color(255, 255, 255, 128));
    continue_option.setPosition(
    window.getSize().x / 2 - continue_option.getGlobalBounds().width / 2 - 200,
    window.getSize().y / 2 - continue_option.getGlobalBounds().height / 2 + 200);

    // quit button
    pause_quit_option.setString("Quit");
    pause_quit_option.setFont(font);
    pause_quit_option.setCharacterSize(50);
    pause_quit_option.setFillColor(sf::Color(255, 255, 255, 128));
    pause_quit_option.setPosition(
    window.getSize().x / 2 - pause_quit_option.getGlobalBounds().width / 2 + 200,
    window.getSize().y / 2 - pause_quit_option.getGlobalBounds().height / 2 + 200);

  return true;
}

void Game::update(float dt)
{
    if (game_state == "main")
    {
        // main menu state
    }
    else if (game_state == "pause")
    {
        //pause state
    }
    else if (game_state == "in_game") 
    {
        //in game state
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
    else if (game_state == "pause")
    {
        window.draw(pause_title);
        window.draw(continue_option);
        window.draw(pause_quit_option);
    }
    else if (game_state == "in_game") 
    {
        window.draw(title_text);
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
    else if (game_state == "in_game")
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            pauseGame();
        }
    }
    else if (game_state == "pause")
    {
        if (
            (event.key.code == sf::Keyboard::Left) ||
            (event.key.code == sf::Keyboard::Right))
        {
            continue_selected = !continue_selected;
            if (continue_selected)
            {
                continue_option.setString("> Continue <");
                pause_quit_option.setString("Quit");
            }
            else
            {
                continue_option.setString("Continue");
                pause_quit_option.setString("> Quit <");
            }
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (continue_selected)
            {
                game_state = "in_game";
                is_paused = false;
            }
            else
            {
                game_state = "main";
                //reset();
            }
        }
    }
}


void Game::keyReleased(sf::Event event) {

}

void Game::pauseGame()
{
    is_paused = true;
    game_state = "pause";
}


