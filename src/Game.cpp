
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
    delete[] animals;
    delete[] passports;
    delete character;
    delete passport;
}

bool Game::init()
{
    // sprites
    character = new sf::Sprite();
    passport = new sf::Sprite();

    accept_button = new sf::Sprite();
    reject_button = new sf::Sprite();

    accepted = new sf::Texture();
    rejected = new sf::Texture();

    loadTextures();
 

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
        //in game
        dragSprite(dragged);
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
        window.draw(*passport);
        window.draw(*character);

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
                newAnimal();


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

void Game::MouseButtonPressed(sf::Event event)
{
   
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i click = sf::Mouse::getPosition(window);
        sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

        if (passport->getGlobalBounds().contains(clickf))
        {
            dragged = passport; 
        }
    }

    if (event.mouseButton.button == sf::Mouse::Right) 
    {





    }

}


void Game::MouseButtonReleased(sf::Event event)
{
   
    dragged = nullptr;

}


void Game::pauseGame()
{
    is_paused = true;
    game_state = "pause";
}

void Game::newAnimal()
{
    passport_accepted = false;
    passport_rejected = false;

    int animal_index = rand() % 3;
    int passport_index = rand() % 3;

    if (animal_index == passport_index)
    {
        should_accept = true;
    }
    else
    {
        should_accept = false;
    }

    character->setTexture(animals[animal_index], true);
    character->setScale(1.8, 1.8);
    character->setPosition(window.getSize().x / 12, window.getSize().y / 12);


    passport->setTexture(passports[passport_index], true);
    passport->setScale(0.6, 0.6);
    passport->setPosition(window.getSize().x / 2,  window.getSize().y / 3);

    accept_button->setTexture(accepted, true);
    accept_button->setScale(1.8, 1.8);
    accept_button->setPosition(window.getSize().x / 12, window.getSize().y / 12);

}

void Game::loadTextures() 
{
   
//penguin
if (!animals[0].loadFromFile("../Data/CritterCustoms/penguin.png"))
{
    std::cout << "penguin texture did not load \n";
}

if (!passports[0].loadFromFile("../Data/CritterCustoms/penguin passport.png"))
{
    std::cout << "penguin passport texture did not load \n";
}


//moose
if (!animals[1].loadFromFile("../Data/CritterCustoms/moose.png"))
{
    std::cout << "moose texture did not load \n";
}

if (!passports[1].loadFromFile("../Data/CritterCustoms/moose passport.png"))
{
    std::cout << "moose passport texture did not load \n";
}


//elephant
if (!animals[2].loadFromFile("../Data/CritterCustoms/elephant.png"))
{
    std::cout << "elephant texture did not load \n";
}

if (!passports[2].loadFromFile("../Data/CritterCustoms/elephant passport.png"))
{
    std::cout << "elephant passport texture did not load \n";
}

// accept button sprite
if (!accepted.loadFromFile("../Data/CritterCustoms/accept button.png"))
{
    std::cout << "accept button texture did not load \n";
}

// reject button sprite



}

void Game::dragSprite(sf::Sprite* sprite)
{
    if (sprite != nullptr)
    {
  
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

    sf::Vector2f drag_position = mouse_positionf;
    sprite->setPosition(drag_position.x, drag_position.y);

     }

}








