#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"
#include "Cell.h"
#include <cstdlib>
#include <iostream>

const int cellSize = 20;
const int rows = 50;
const int cols = 50;

int main() {
    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "Game of Life");
    srand(time(0));


    GameBoard* MainBoard = new GameBoard(cols,rows,make_unique<MooreNeighborhood>(), make_unique<DeadOutside>(), make_unique<StanrdardConway>());
    BufferBoard TempBoard(cols, rows);
    bool started = false;
    int delay=100;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x / cellSize;
                int y = event.mouseButton.y / cellSize;
                if (x >= 0 && x < cols && y >= 0 && y < rows)
                    MainBoard->ChangeCellStatus(y, x);
            }

            if (event.type == sf::Event::KeyPressed) {                      //spacebar - start simulation
                if (event.key.code == sf::Keyboard::Space) {
                        started = !started;
                    }
            

                if (event.key.code == sf::Keyboard::R) {                        //r - clearing the board
                    MainBoard->reset();
                }

                if (event.key.code == sf::Keyboard::G) {                        //g - generating random board
                    MainBoard->randomGen();
                }

                if (!started && event.key.code == sf::Keyboard::Right) {        //right arrow - one step in simulation
                    MainBoard->checkBoard(TempBoard);
                }

                if (event.key.code == sf::Keyboard::Up) {                       //up arrow - faster simulation
                    if (delay > 10) delay -= 10;
                }
                else if (event.key.code == sf::Keyboard::Down) {                //down arrow - slower simulation
                    if (delay < 1000) delay += 10;
                }
                
                if (event.key.code == sf::Keyboard::Num1) {
                    MainBoard->setNeighborhood(make_unique<MooreNeighborhood>());
                }

                if (event.key.code == sf::Keyboard::Q) {                      
                    MainBoard->setNeighborhood(make_unique<VonNeumannNeighborhood>());
                    
                }

                if (event.key.code == sf::Keyboard::Num2) {
                    MainBoard->setBoundary(make_unique<DeadOutside>());
                }

                if (event.key.code == sf::Keyboard::W) {
                    MainBoard->setBoundary(make_unique<Looped>());
                }

                if (event.key.code == sf::Keyboard::Num3) {
                    MainBoard->setLiveRules(make_unique<StanrdardConway>());
                }

                if (event.key.code == sf::Keyboard::E) {
                    MainBoard->setLiveRules(make_unique<LabyrinthRules>());

                }
                
            }
            
        }


        if (started) {
            MainBoard->checkBoard(TempBoard);
            sf::sleep(sf::milliseconds(delay));
        }
        window.clear(sf::Color::White);

        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(MainBoard->at(y,x).getStatus() ? sf::Color::Black : sf::Color::White);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color(200, 200, 200));
                window.draw(cell);
            }
        }

        window.display();
    }

    delete MainBoard;
    
    return 0;
}