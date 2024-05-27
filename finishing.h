#pragma once
#include <SFML/Graphics.hpp>
#include "Tree.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WorkButton.h"
#include <iostream>
#include <sstream>
using namespace std;
using namespace sf;
namespace global { // ���������� ���������� ����������
    char sought = ' '; // ������� ��� ����������
    char key = ' '; // ����� ��������
    int soughtDel = -1; // ������� ��� ��������
    char soughtForDel = ' '; // ������� ��� ��������
}
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black) { // ��������� ��������
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}
void drawNodeAdd(bool flag) { // ��������� ������ � ����� �����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Adding successfully");
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // ��������� ������
        exit(32);
    }
    sf::Color background�olor(600,600,600);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { // ������� �������� ����
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(background�olor);

        sf::Vector2f positions[] = { // ����������� ������� ��� ������ ����������
            sf::Vector2f(100.f, 250.f),
            sf::Vector2f(200.f, 150.f), 
            sf::Vector2f(280.f, 250.f),
            sf::Vector2f(350.f, 50.f), 
            sf::Vector2f(400.f, 250.f),
            sf::Vector2f(500.f, 150.f), 
            sf::Vector2f(600.f, 250.f)
        };
        char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
        for (int i = 0; i < 7; ++i) { // ��������� ����������� � ������
            sf::CircleShape circle(50.f);
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150,150,150));

            char data = masData[i];  // �������� �� ������ ������
            sf::Text text(data, font, 24);
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = { // ����������� ������� ��� ������ �����
            sf::Vector2f(150.f, 250.f), 
            sf::Vector2f(295.f, 220.f),
            sf::Vector2f(280.f, 160.f),
            sf::Vector2f(450.f, 117.f), 
            sf::Vector2f(597.f, 220.f),
            sf::Vector2f(507.f, 220.f),
        };
        sf::Vector2f positionsS2[] = { // ����������� ������� ��� ����� �����
            sf::Vector2f(205.f, 220.f), 
            sf::Vector2f(325.f, 250.f), 
            sf::Vector2f(350.f, 113.f), 
            sf::Vector2f(510.f, 170.f), 
            sf::Vector2f(652.f, 250.f),
            sf::Vector2f(450.f, 250.f), 
        };
        for (size_t i = 0; i < 6; ++i) { // ���������� ����� ����� ������������
            sf::Vertex line[] = {
                sf::Vertex(positionsS[i]),
                sf::Vertex(positionsS2[i])
            };
            window.draw(line, 2, sf::Lines);
        }
        if (flag == true && global::sought != ' ') { // ���������� ������ ����
            if (global::sought == 'l' || global::sought == 'u') {  // ���� ����� ��������� � ���� l ��� u
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(10.f, 350.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key;
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(10.f + 30, 350.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(55.f , 350.f)),
                    sf::Vertex(sf::Vector2f(102.f, 320.f))
                };

                window.draw(line, 2, sf::Lines);
            }
            else if (global::sought == 'c') { // ���� ����� ��������� � ���� c
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(350.f, 365.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key;
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(350.f + 30, 365.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(400.f , 363.f)),
                    sf::Vertex(sf::Vector2f(370.f, 325.f))
                };
                window.draw(line, 2, sf::Lines);
            }
            else if (global::sought == 'k' || global::sought == 'y') {  // ���� ����� ��������� � ���� k ��� y
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(350.f, 365.f));
                circle.setFillColor(sf::Color(600,600,600));

                char data = global::key;  // �������� �� ������ ������
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(350.f + 30, 365.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(400.f, 363.f)),
                    sf::Vertex(sf::Vector2f(420.f, 340.f))
                };

                window.draw(line, 2, sf::Lines);
            }
            else {  // ���� ����� ��������� � ���� !
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(680.f, 365.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key;  // �������� �� ������ ������
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(680.f + 30, 365.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(730.f, 365.f)),
                    sf::Vertex(sf::Vector2f(694.f, 323.f))
                };
                window.draw(line, 2, sf::Lines);
            }
        }
        window.display();
    }
}


void drawNodeDel(bool flag) { // ������� ���������� � ��������� ������ ����� �������� ����
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // ��������� ������
        exit(32);
    }
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Removal successful"); // �������� ����
    while (window.isOpen()) { 
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {  // ������� ��� �������� ����
                window.close();
            }
        }
        window.clear(background�olor);  // ��������� ����

        sf::Vector2f positions[] = { // ������� ��� ������ ����������
            sf::Vector2f(100.f, 400.f),
            sf::Vector2f(200.f, 300.f), 
            sf::Vector2f(280.f, 400.f),
            sf::Vector2f(350.f, 150.f),
            sf::Vector2f(400.f, 400.f),
            sf::Vector2f(500.f, 300.f),
            sf::Vector2f(600.f, 400.f) 
        };
        char masData[8] = { 'l', 'u', 'c', 'k', 'y', '!', '!', ' '};
        int amount;
        if (global::key != ' ') {
            amount = 8;
            masData[7] = global::key;
        }
        else amount = 7;
        for (int i = 0; i < amount; i++) { // ��������� ������
            if (i == global::soughtDel) { // ���� ������� ��� �������� ������
                if (i != 7) {
                    for (int j = i + 1; j < amount; j++) { // ������� ��������� ��������
                        sf::CircleShape circle(50.f); // �������� ����������
                        circle.setPosition(positions[j - 1]);
                        circle.setFillColor(sf::Color(150,150,150));

                        char data = masData[j];
                        sf::Text text(data, font, 24);  // �������� ������ � �� ����������
                        text.setPosition(positions[j - 1].x + 30, positions[j - 1].y + 30);
                        text.setFillColor(sf::Color::Black);

                        window.draw(circle);
                        window.draw(text);
                    }
                    break;
                }
                else break;
            }
            else {
                sf::CircleShape circle(50.f);  // �������� ����������
                circle.setPosition(positions[i]);
                circle.setFillColor(sf::Color(150,150,150));

                char data = masData[i];
                sf::Text text(data, font, 24);   // �������� ������ � �� ����������
                text.setPosition(positions[i].x + 30, positions[i].y + 30);
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
            }
        }

        sf::Vector2f positionsS[] = { // ������� ������ �����, ����������� ����������
            sf::Vector2f(150.f, 400.f),
            sf::Vector2f(290.f, 380.f), 
            sf::Vector2f(280.f, 310.f),
            sf::Vector2f(440.f, 235.f), 
            sf::Vector2f(450.f, 400.f),
            sf::Vector2f(590.f, 380.f), 

        };
        sf::Vector2f positionsS2[] = {  // ������� ����� �����, ����������� ����������
            sf::Vector2f(210.f, 380.f),
            sf::Vector2f(320.f, 400.f), 
            sf::Vector2f(360.f, 233.f), 
            sf::Vector2f(520.f, 310.f), 
            sf::Vector2f(510.f, 380.f),
            sf::Vector2f(655.f, 400.f), 
        };
        for (size_t i = 0; i < amount-2; ++i) { // ���������� ����� ����� ������������
                sf::Vertex line[] = {
                    sf::Vertex(positionsS[i]),
                    sf::Vertex(positionsS2[i])
                };
                window.draw(line, 2, sf::Lines);
        }
        window.display();  // ����������� �� ������ ��������
    }
}
void drawNodeAddHorizontal(bool flag) { // ���������� ���� � ��������� ������ �������������
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(800, 800), "Adding successfully");

    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) {
        exit(32);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(background�olor);

        sf::Vector2f positions[] = {
            sf::Vector2f(310.f, 550.f), 
            sf::Vector2f(190.f, 460.f),
            sf::Vector2f(310.f, 380.f),
            sf::Vector2f(70.f, 330.f),
            sf::Vector2f(310.f, 240.f), 
            sf::Vector2f(190.f, 190.f),
            sf::Vector2f(310.f, 100.f)
        };

        for (int i = 0; i < 7; ++i) {
            sf::CircleShape circle(50.f);
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150,150,150));

            char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
            char data = masData[i];  // �������� �� ������ ������
            sf::Text text(data, font, 24);
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = {
            sf::Vector2f(310.f, 590.f), 
            sf::Vector2f(200.f, 478.f), 
            sf::Vector2f(310.f, 430.f),
            sf::Vector2f(145.f, 335.f), 
            sf::Vector2f(280.f, 270.f), 
            sf::Vector2f(270.f, 200.f), 
        };
        sf::Vector2f positionsS2[] = {
            sf::Vector2f(270.f, 550.f), 
            sf::Vector2f(145.f, 420.f), 
            sf::Vector2f(279.f, 477.f),
            sf::Vector2f(200.f, 270.f),
            sf::Vector2f(310.f, 296.f),
            sf::Vector2f(310.f, 160.f), 
        };

        for (size_t i = 0; i < 6; ++i) {
            sf::Vertex line[] =
            {
                sf::Vertex(positionsS[i]),
                sf::Vertex(positionsS2[i])
            };

            window.draw(line, 2, sf::Lines);
        }
        if (flag == true && global::sought != ' ') {
            if (global::sought == 'l' || global::sought == 'u') {
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(440.f, 650.f));
                circle.setFillColor(sf::Color(150, 150, 150));

                char data = global::key;  
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(440.f + 30, 650.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(440.f , 690.f)),
                    sf::Vertex(sf::Vector2f(385.f, 640.f))
                };

                window.draw(line, 2, sf::Lines);
            }
            else if (global::sought == 'c') {
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(440.f, 310.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key; 
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(440.f + 30, 310.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(440.f , 363.f)),
                    sf::Vertex(sf::Vector2f(380.f, 390.f))
                };

                window.draw(line, 2, sf::Lines);
            }
            else if (global::sought == 'k' || global::sought == 'y') {
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(440.f, 310.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key; 
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(440.f + 30, 310.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(440.f, 368.f)),
                    sf::Vertex(sf::Vector2f(386.f, 328.f))
                };

                window.draw(line, 2, sf::Lines);
            }
            else {
                sf::CircleShape circle(50.f);
                circle.setPosition(sf::Vector2f(440.f, 190.f));
                circle.setFillColor(sf::Color(150,150,150));

                char data = global::key;
                sf::Text text(global::key, font, 24);
                text.setPosition(sf::Vector2f(440.f + 30, 190.f + 30));
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(440.f, 230.f)),
                    sf::Vertex(sf::Vector2f(390.f, 185.f))
                };

                window.draw(line, 2, sf::Lines);
            }
        }

        window.display();
    }
}
void drawNodeDelHorizontal(bool flag) { // ������� �������� � ��������� ������ �������������
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Removal succcessful");

    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) {
        exit(32);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(background�olor);
        
        sf::Vector2f positions[] = {
            sf::Vector2f(310.f, 550.f), 
            sf::Vector2f(190.f, 460.f), 
            sf::Vector2f(310.f, 380.f),
            sf::Vector2f(70.f, 330.f),
            sf::Vector2f(310.f, 240.f),
            sf::Vector2f(190.f, 190.f),
            sf::Vector2f(310.f, 100.f) 
        };

        char masData[8] = { 'l', 'u', 'c', 'k', 'y', '!', '!', ' ' };
        int amount;
        if (global::key != ' ') {
            amount = 8;
            masData[7] = global::key;
        }
        else amount = 7;
        for (int i = 0; i < amount; ++i) {
            if (i == global::soughtDel) {
                for (int j = i + 1; j < amount; j++) {
                    sf::CircleShape circle(50.f);
                    circle.setPosition(positions[j - 1]);
                    circle.setFillColor(sf::Color(150,150,150));

                    char data = masData[j]; 
                    sf::Text text(data, font, 24);
                    text.setPosition(positions[j - 1].x + 30, positions[j - 1].y + 30);
                    text.setFillColor(sf::Color::Black);

                    window.draw(circle);
                    window.draw(text);
                }
                break;
            }
            else {
                sf::CircleShape circle(50.f);
                circle.setPosition(positions[i]);
                circle.setFillColor(sf::Color(150,150,150));

                char data = masData[i]; 
                sf::Text text(data, font, 24);
                text.setPosition(positions[i].x + 30, positions[i].y + 30);
                text.setFillColor(sf::Color::Black);

                window.draw(circle);
                window.draw(text);
            }
        }

        sf::Vector2f positionsS[] = {
            sf::Vector2f(310.f, 590.f), 
            sf::Vector2f(200.f, 478.f),
            sf::Vector2f(310.f, 430.f), 
            sf::Vector2f(145.f, 335.f),
            sf::Vector2f(280.f, 270.f), 
            sf::Vector2f(270.f, 200.f), 
        };
        sf::Vector2f positionsS2[] = {
            sf::Vector2f(270.f, 550.f),
            sf::Vector2f(145.f, 420.f),
            sf::Vector2f(279.f, 477.f),
            sf::Vector2f(200.f, 270.f),
            sf::Vector2f(310.f, 296.f), 
            sf::Vector2f(310.f, 160.f),
        };
        for (size_t i = 0; i < amount-2; ++i) {
            sf::Vertex line[] =
            {
                sf::Vertex(positionsS[i]),
                sf::Vertex(positionsS2[i])
            };

            window.draw(line, 2, sf::Lines);
        }

        window.display();
    }
}
int GetHeight() { // ������� ��������� ������ ������
    char height = ' ';
    if (global::key != ' ' && global::soughtForDel != ' ') height = '3';
    else if (global::key != ' ')
        height = '4';
    else return '3';
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // �������� ������
        exit(32);
    }
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Height");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // ������� �������� ����
                window.close();
            }

        }
        window.clear(background�olor); // ��������� ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"������ ������:");
        text1.setFillColor(sf::Color::Black);
        text1.setCharacterSize(100);
        text1.setPosition(30, 100);
        window.draw(text1);
        text1.setString(height);
        text1.setPosition(360, 250);
        window.draw(text1);
        window.display();
    }
}

string modifyStringStraight(std::string& original) { // �������, ��������� �������� ����� ������� ������
    string line = "";
    if (global::sought == 'l' || global::sought == 'u')
        original.insert(4, 1, global::key);
    if (global::sought == 'c')
        original.insert(3, 1, global::key);
    if (global::sought == 'k' || global::sought == 'y')
        original.insert(6, 1, global::key);
    if (global::sought == '!')
        original.insert(7, 1, global::key);
    if (global::soughtForDel != ' ')
        original.erase(std::remove(original.begin(), original.end(), global::soughtForDel), original.end());

    return original;
}

string modifyStringSymmetrically(std::string& original) { // �������, ��������� �������� ����� ������������� ������
    string line = "";
    if (global::sought == 'l' || global::sought == 'u')
        original.insert(1, 1, global::key);
    if (global::sought == 'c')
        original.insert(3, 1, global::key);
    if (global::sought == 'k' || global::sought == 'y')
        original.insert(5, 1, global::key);
    if (global::sought == '!')
        original.insert(7, 1, global::key);

    if (global::soughtForDel != ' ')
        original.erase(std::remove(original.begin(), original.end(), global::soughtForDel), original.end());
    return original;
}
string modifyStringBack(std::string& original) { // �������, ��������� �������� ����� ��������� ������
    string line = "";
    if (global::sought == 'l' || global::sought == 'u')
        original.insert(0, 1, global::key);
    if (global::sought == 'c')
        original.insert(1, 1, global::key);
    if (global::sought == 'k' || global::sought == 'y')
        original.insert(3, 1, global::key);
    if (global::sought == '!')
        original.insert(4, 1, global::key);

    if (global::soughtForDel != ' ')
        original.erase(std::remove(original.begin(), original.end(), global::soughtForDel), original.end());

    return original;
}