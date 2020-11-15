#include <SFML/Graphics.hpp>
#include <iostream>
#include "input_handler.hpp"

using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;
using sf::Color;
using sf::Event;
using sf::Keyboard;

using std::string;
using std::cout;
using std::endl;

#define WIDTH 1200
#define HEIGHT 800

int main() {
    // create window
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Window",
            sf::Style::Titlebar);
    win.setPosition(Vector2i(100, 100));
    win.setVerticalSyncEnabled(true);

    // input handler
    InputHandler ih = InputHandler();

    // initialization
    sf::CircleShape shape(100.0f);
    shape.setFillColor(Color::Green);

    while (win.isOpen()) {
        // event handling
        Event ev;
        while (win.pollEvent(ev)) {
            switch(ev.type) {
                case Event::Closed:
                    win.close();
                    break;
                case Event::TextEntered:
                    // if in valid unicode range
                    //if (32 < ev.text.unicode && ev.text.unicode < 127)
                        //cout << static_cast<char>(ev.text.unicode) << endl;
                    break;
                case Event::KeyPressed:
                    if (ev.key.code == Keyboard::W)
                        ih.w = true;
                    else if (ev.key.code == Keyboard::A)
                        ih.a = true;
                    else if (ev.key.code == Keyboard::S)
                        ih.s = true;
                    else if (ev.key.code == Keyboard::D)
                        ih.d = true;
                    break;
                case Event::KeyReleased:
                    if (ev.key.code == Keyboard::W)
                        ih.w = false;
                    else if (ev.key.code == Keyboard::A)
                        ih.a = false;
                    else if (ev.key.code == Keyboard::S)
                        ih.s = false;
                    else if (ev.key.code == Keyboard::D)
                        ih.d = false;
                    break;
                default:
                    break;

            }
        }
        // rendering
        win.clear();
        if (ih.w) {
            cout << "w" << endl;
        }
        win.draw(shape);
        win.display();
    }
    return 0;
}