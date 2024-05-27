#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Tree.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "finishing.h"
#include <string>
#include <sstream>
using namespace std;
using namespace sf;

void drawTreeVertically() {
    if (global::soughtForDel != ' ') { drawNodeDel(true); return; } // ������ ������ ���� ���� ������� ��������
    if (global::key != ' ') { cout << global::soughtDel;  drawNodeAdd(true); return; } // ������ ������ ���� ���� ��������� ��������
    sf::Color background�olor(600, 600, 600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vertical printing"); // �������� ����
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // ��������� ������
        exit(32);
    }
    char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // ������� ��� �������� ����
                window.close();
            }
        }
        window.clear(background�olor); // ��������� ����

        sf::Vector2f positions[] = { // ������� ��� ������ ����������
            sf::Vector2f(100.f, 250.f),
            sf::Vector2f(200.f, 150.f),
            sf::Vector2f(280.f, 250.f),
            sf::Vector2f(350.f, 50.f),
            sf::Vector2f(400.f, 250.f), 
            sf::Vector2f(500.f, 150.f), 
            sf::Vector2f(600.f, 250.f)  
        };

        for (int i = 0; i < 7; ++i) {
            sf::CircleShape circle(50.f); // �������� ����������
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150,150,150));

            char data = masData[i];  
            sf::Text text(data, font, 24); // �������� ������ � �� ����������
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = { // ������� ������ �����, ����������� ����������
            sf::Vector2f(150.f, 250.f),
            sf::Vector2f(295.f, 220.f), 
            sf::Vector2f(280.f, 160.f),
            sf::Vector2f(450.f, 117.f),
            sf::Vector2f(597.f, 220.f),
            sf::Vector2f(507.f, 220.f),
        };
        sf::Vector2f positionsS2[] = { // ������� ����� �����, ����������� ����������
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
        
        window.display(); // ����������� �� ������ ��������
    }
}
void drawTreeHorizontally() {
    if (global::soughtForDel != ' ') { drawNodeDelHorizontal(true); return; } // ������ ������ ���� ���� ������� ��������
    if (global::key != ' ') { cout << global::key;  drawNodeAddHorizontal(true); return; }  // ������ ������ ���� ���� ��������� ��������
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Horizontal printing"); // �������� ����
    
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // �������� ������
        exit(32);
    }
    char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // ������� ��� �������� ����
                window.close();
            }
        }

        window.clear(background�olor); // ��������� ����

        sf::Vector2f positions[] = { // ����������� ������� ��� ������ ����������
            sf::Vector2f(310.f, 550.f),
            sf::Vector2f(190.f, 460.f),
            sf::Vector2f(310.f, 380.f),
            sf::Vector2f(70.f, 330.f),
            sf::Vector2f(310.f, 240.f),
            sf::Vector2f(190.f, 190.f),
            sf::Vector2f(310.f, 100.f)
        };

        for (int i = 0; i < 7; ++i) { // ������� ���������� � ������
            sf::CircleShape circle(50.f); // �������� ����������
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150, 150, 150));

            char data = masData[i];
            sf::Text text(data, font, 24); // ������������ ������ � ��� ����������
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = { // ������� ������ ����� ��� ���������� �����������
            sf::Vector2f(310.f, 590.f),
            sf::Vector2f(200.f, 478.f), 
            sf::Vector2f(310.f, 430.f),
            sf::Vector2f(145.f, 335.f),
            sf::Vector2f(280.f, 270.f),
            sf::Vector2f(270.f, 200.f),
        };
        sf::Vector2f positionsS2[] = { // ������� ����� ����� ��� ���������� �����������
            sf::Vector2f(270.f, 550.f),
            sf::Vector2f(145.f, 420.f),
            sf::Vector2f(279.f, 477.f),
            sf::Vector2f(200.f, 270.f),
            sf::Vector2f(310.f, 296.f),
            sf::Vector2f(310.f, 160.f),
        }; 

        for (size_t i = 0; i < 6; ++i) { // ���������� ����� ����� ������������
            sf::Vertex line[] =
            {
                sf::Vertex(positionsS[i]),
                sf::Vertex(positionsS2[i])
            };

            window.draw(line, 2, sf::Lines);
        }
        
        window.display(); // ����������� �������� �� ������
    }
}

bool FindElementInTree(char sought) { // ������� ��� �������� ������� ������ � ������
    switch (sought) {
    case 'l': return true; break;
    case 'u': return true; break;
    case 'c': return true; break;
    case 'k': return true; break;
    case 'y': return true; break;
    case '!': return true; break;
    default:
        break;
    }
    if (global::soughtForDel != global::key)
        if (sought == global::key) return true; // �������� ����� ����������� ���������
    return false;
}
bool FindElementInTreeForDel(char sought) { // ������� ��� �������� ������� ������ � ������
    switch (sought) {
    case 'l': return true; break;
    case 'u': return true; break;
    case 'c': return true; break;
    case 'k': return true; break;
    case 'y': return true; break;
    case '!': return true; break;
    default:
        break;
    }
    if (sought == global::key) return true; // �������� ����� ����������� ���������
    return false;
}

void addNode() { // ������� ��������� ���� � ������
    cout << "������� �������, � �������� ����� �������� ����� ����: " << endl;
    cin >> global::sought;

    if (FindElementInTree(global::sought) == true) { // �������� ������� �������� ����
        cout << "������� ������ ��� ������ ����: " << endl;
        cin >> global::key;
        Font font;
        drawNodeAdd(true); // ���������� ���� � ��������� ������ ������
    }
    else {
        cout << "����� ������� �� ������" << endl;
        return;
    }
}
int findPosition(char sought) {  // ����� ������� �������� � ������
    switch (sought) {
    case 'l': return 0; break;
    case 'u': return 1; break;
    case 'c': return 2; break;
    case 'k': return 3; break;
    case 'y': return 4; break;
    case '!': return 5; break;
    default:
        break;
    }
    return - 1;
}
void deleteNode() { // ������� �������� �������� �� ������
    cout << "������� �������, ������� ������ �������: " << endl;
    cin >> global::soughtForDel;

    if (FindElementInTreeForDel(global::soughtForDel) == true) { // �������� ���������� �� � ������ ����� �������
        global::soughtDel = findPosition(global::soughtForDel);
        drawNodeDel(true); // �������� � ��������� ������ ��� ��������� ����
    }
    else {
        cout << "����� ������� �� ������" << endl;
        return;
    }
}

void rounds() { // ������ ������
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // ��������� ������
        exit(32);
    }
    sf::Color background�olor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree traversals");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { // ������� �������� ����
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
        }
        window.clear(background�olor); // ������������ ����
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"������ �����:");
        text1.setFillColor(sf::Color::Black);
        text1.setCharacterSize(50);
        text1.setPosition(30, 10);
        window.draw(text1);
        string message = "kulc!y!";
        message = modifyStringStraight(message); // ���������� ������� ������ � ������ ���� ��������/����������
        String mes(message);
        text1.setString(mes);
        text1.setPosition(30, 80);
        window.draw(text1);
        text1.setString(L"�������� �����: ");
        text1.setPosition(30, 150);
        window.draw(text1);
        message = "lcuy!!k";
        message = modifyStringBack(message); // ���������� ��������� ������ � ������ ���� ��������/����������
        mes = message;
        text1.setString(mes);
        text1.setPosition(30, 220);
        window.draw(text1);
        text1.setString(L"������������ �����: ");
        text1.setPosition(30, 290);
        window.draw(text1);
        message = "lucky!!";
        message = modifyStringSymmetrically(message); // ���������� ������������� ������ � ������ ���� ��������/����������
        mes = message;
        text1.setString(mes);
        text1.setPosition(30, 360);
        window.draw(text1);
        window.display();

    }
}


void findElementForKey() { // ������� ������ �������� �� �����
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // �������� ������
        exit(32);
    }
    sf::Color background�olor(600, 600, 600);
    char Key;
    cout << "������� �������, ������� ������ �����: " << endl;
    cin >> Key;
    bool flag = FindElementInTree(Key); // �������� ������� �������� � ������
    if (flag == false) {
        cout << "����� ������� �� ������!" << endl;
        return;
    }
    else {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "Item found"); // �������� ����
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) { // ������� �������� ����
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear(background�olor); 
            sf::CircleShape circle(100.f); // �������� ����������
            circle.setPosition(310, 200);
            circle.setFillColor(sf::Color(150, 150, 150));
            sf::Text text(Key, font, 60); // �������� ������ � ��� ����������
            text.setPosition(390, 260);
            text.setFillColor(sf::Color::Black);
            window.draw(circle); // ��������� ����������
            window.draw(text); // ��������� ������
            window.display(); // �����������
        }
    }
}

void createSearchTree(){ // ������� ��� �������� ���������� ���� � ��������� ������ ������
    system("chcp 1251 > Null");
    RenderWindow window; // �������� ���� 
    window.create(VideoMode(1280, 720), L"Search Tree", sf::Style::Close); // ��������� ����

    float width = VideoMode::getDesktopMode().width;  // ��������� ��������� ������� ������
    float height = VideoMode::getDesktopMode().height;  // ��������� ��������� ������� ������

    RectangleShape background(Vector2f(width, height)); // ������� ������������� ��� �����������
    Texture texture_window;
    if (!texture_window.loadFromFile("fon.jpg")) return ; // �������� � ������������� �������� � ������������ 
    background.setTexture(&texture_window);

    Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) exit(32); // ��������� ������
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 460, 50, L"�������� ������", 70, sf::Color(15,15,15), 0); // ��������� ��� ���������
    String nameMenu[]{ L"����� �� �����",L"�������� ������ ������", L"�����" };

    Menu mymenu(window, 670, 250, 3, nameMenu, 60, 120);  // ������ ����
    mymenu.setColorTextMenu(sf::Color(150,150,150), Color(600,600,600), Color::Black);  // ��������� ����� ��������� ������� ����
    mymenu.alignMenu(2);  // ������������ �� ������ ������� ���� 

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyReleased) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }  // ������� ������� �� ���������� ������� �����
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }  // ������� ������� �� ���������� ������� ����
                if (event.key.code == Keyboard::Return){  // ������� ������� �� ���������� ������� Enter
                    switch (mymenu.getSelectedMenuNumber()) {
                    case 0: findElementForKey(); break;
                    case 1: GetHeight();  break;
                    case 2: window.close();
                    }

                }
            }
        }
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }
}
