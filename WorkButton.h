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
    if (global::soughtForDel != ' ') { drawNodeDel(true); return; } // печать дерева если были удалены элементы
    if (global::key != ' ') { cout << global::soughtDel;  drawNodeAdd(true); return; } // печать дерева если были добавлены элементы
    sf::Color backgroundСolor(600, 600, 600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Vertical printing"); // создание окна
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // установка шрифта
        exit(32);
    }
    char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // событие для закрытия окна
                window.close();
            }
        }
        window.clear(backgroundСolor); // установка фона

        sf::Vector2f positions[] = { // позиции для каждой окружности
            sf::Vector2f(100.f, 250.f),
            sf::Vector2f(200.f, 150.f),
            sf::Vector2f(280.f, 250.f),
            sf::Vector2f(350.f, 50.f),
            sf::Vector2f(400.f, 250.f), 
            sf::Vector2f(500.f, 150.f), 
            sf::Vector2f(600.f, 250.f)  
        };

        for (int i = 0; i < 7; ++i) {
            sf::CircleShape circle(50.f); // создание окружности
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150,150,150));

            char data = masData[i];  
            sf::Text text(data, font, 24); // устновка данных и их параметров
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = { // позиции начала линий, соединяющих окружности
            sf::Vector2f(150.f, 250.f),
            sf::Vector2f(295.f, 220.f), 
            sf::Vector2f(280.f, 160.f),
            sf::Vector2f(450.f, 117.f),
            sf::Vector2f(597.f, 220.f),
            sf::Vector2f(507.f, 220.f),
        };
        sf::Vector2f positionsS2[] = { // позиции конца линий, соединяющих окружности
            sf::Vector2f(205.f, 220.f), 
            sf::Vector2f(325.f, 250.f), 
            sf::Vector2f(350.f, 113.f), 
            sf::Vector2f(510.f, 170.f),
            sf::Vector2f(652.f, 250.f),
            sf::Vector2f(450.f, 250.f),
        };

        for (size_t i = 0; i < 6; ++i) { // добавление линий между окружностями
            sf::Vertex line[] = {
                sf::Vertex(positionsS[i]), 
                sf::Vertex(positionsS2[i])
            };

            window.draw(line, 2, sf::Lines); 
        }
        
        window.display(); // отображение на экране рисунков
    }
}
void drawTreeHorizontally() {
    if (global::soughtForDel != ' ') { drawNodeDelHorizontal(true); return; } // печать дерева если были удалены элементы
    if (global::key != ' ') { cout << global::key;  drawNodeAddHorizontal(true); return; }  // печать дерева если были добавлены элементы
    sf::Color backgroundСolor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Horizontal printing"); // создание окна
    
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // загрузка шрифта
        exit(32);
    }
    char masData[7] = { 'l', 'u', 'c', 'k', 'y', '!', '!' };
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // событие для закрытия окна
                window.close();
            }
        }

        window.clear(backgroundСolor); // установка фона

        sf::Vector2f positions[] = { // определение позиций для каждой окружности
            sf::Vector2f(310.f, 550.f),
            sf::Vector2f(190.f, 460.f),
            sf::Vector2f(310.f, 380.f),
            sf::Vector2f(70.f, 330.f),
            sf::Vector2f(310.f, 240.f),
            sf::Vector2f(190.f, 190.f),
            sf::Vector2f(310.f, 100.f)
        };

        for (int i = 0; i < 7; ++i) { // рисовка окружности и текста
            sf::CircleShape circle(50.f); // создание окружности
            circle.setPosition(positions[i]);
            circle.setFillColor(sf::Color(150, 150, 150));

            char data = masData[i];
            sf::Text text(data, font, 24); // установление текста и его параметров
            text.setPosition(positions[i].x + 30, positions[i].y + 30);
            text.setFillColor(sf::Color::Black);

            window.draw(circle);
            window.draw(text);
        }

        sf::Vector2f positionsS[] = { // позиции начала линий для соединения окружностей
            sf::Vector2f(310.f, 590.f),
            sf::Vector2f(200.f, 478.f), 
            sf::Vector2f(310.f, 430.f),
            sf::Vector2f(145.f, 335.f),
            sf::Vector2f(280.f, 270.f),
            sf::Vector2f(270.f, 200.f),
        };
        sf::Vector2f positionsS2[] = { // позиции конца линий для соединения окружностей
            sf::Vector2f(270.f, 550.f),
            sf::Vector2f(145.f, 420.f),
            sf::Vector2f(279.f, 477.f),
            sf::Vector2f(200.f, 270.f),
            sf::Vector2f(310.f, 296.f),
            sf::Vector2f(310.f, 160.f),
        }; 

        for (size_t i = 0; i < 6; ++i) { // добавление линий между окружностями
            sf::Vertex line[] =
            {
                sf::Vertex(positionsS[i]),
                sf::Vertex(positionsS2[i])
            };

            window.draw(line, 2, sf::Lines);
        }
        
        window.display(); // отображение рисунков на экране
    }
}

bool FindElementInTree(char sought) { // функция для проверки наличия данных в дереве
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
        if (sought == global::key) return true; // проверка новых добавленных элементов
    return false;
}
bool FindElementInTreeForDel(char sought) { // функция для проверки наличия данных в дереве
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
    if (sought == global::key) return true; // проверка новых добавленных элементов
    return false;
}

void addNode() { // функция дабвления узла в дерево
    cout << "Введите элемент, к которому нужно добавить новый узел: " << endl;
    cin >> global::sought;

    if (FindElementInTree(global::sought) == true) { // проверка наличия искомого узла
        cout << "Введите данные для нового узла: " << endl;
        cin >> global::key;
        Font font;
        drawNodeAdd(true); // добавление узла и отрисовка нового дерева
    }
    else {
        cout << "Такой элемент не найден" << endl;
        return;
    }
}
int findPosition(char sought) {  // найти позицию элемента в дереве
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
void deleteNode() { // функция удаления элемента из дерева
    cout << "Введите элемент, который хотите удалить: " << endl;
    cin >> global::soughtForDel;

    if (FindElementInTreeForDel(global::soughtForDel) == true) { // проверка существует ли в дереве такой элемент
        global::soughtDel = findPosition(global::soughtForDel);
        drawNodeDel(true); // удаление и отрисовка дерева без заданного узла
    }
    else {
        cout << "Такой элемент не найден" << endl;
        return;
    }
}

void rounds() { // обходы дерева
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // установка шрифта
        exit(32);
    }
    sf::Color backgroundСolor(600,600,600);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree traversals");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { // событие закрытия окна
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
        }
        window.clear(backgroundСolor); // установление фона
        sf::Text text1;
        text1.setFont(font);
        text1.setString(L"Прямой обход:");
        text1.setFillColor(sf::Color::Black);
        text1.setCharacterSize(50);
        text1.setPosition(30, 10);
        window.draw(text1);
        string message = "kulc!y!";
        message = modifyStringStraight(message); // вычисление прямого обхода с учетом всех удалений/добавлений
        String mes(message);
        text1.setString(mes);
        text1.setPosition(30, 80);
        window.draw(text1);
        text1.setString(L"Обратный обход: ");
        text1.setPosition(30, 150);
        window.draw(text1);
        message = "lcuy!!k";
        message = modifyStringBack(message); // вычисление обратного обхода с учетом всех удалений/добавлений
        mes = message;
        text1.setString(mes);
        text1.setPosition(30, 220);
        window.draw(text1);
        text1.setString(L"Симметричный обход: ");
        text1.setPosition(30, 290);
        window.draw(text1);
        message = "lucky!!";
        message = modifyStringSymmetrically(message); // вычисление симметричного обхода с учетом всех удалений/добавлений
        mes = message;
        text1.setString(mes);
        text1.setPosition(30, 360);
        window.draw(text1);
        window.display();

    }
}


void findElementForKey() { // функция поиска элемента по ключу
    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) { // загрузка шрифта
        exit(32);
    }
    sf::Color backgroundСolor(600, 600, 600);
    char Key;
    cout << "Введите элемент, который хотите найти: " << endl;
    cin >> Key;
    bool flag = FindElementInTree(Key); // проверка наличия элемента в дереве
    if (flag == false) {
        cout << "Такой элемент не найден!" << endl;
        return;
    }
    else {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "Item found"); // создание окна
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) { // событие закрытия окна
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear(backgroundСolor); 
            sf::CircleShape circle(100.f); // создание окружности
            circle.setPosition(310, 200);
            circle.setFillColor(sf::Color(150, 150, 150));
            sf::Text text(Key, font, 60); // создание текста и его параметров
            text.setPosition(390, 260);
            text.setFillColor(sf::Color::Black);
            window.draw(circle); // отрисовка окружности
            window.draw(text); // отрисовка текста
            window.display(); // отображение
        }
    }
}

void createSearchTree(){ // функция для создания отедльного меню с функциями дерева поиска
    system("chcp 1251 > Null");
    RenderWindow window; // создание окна 
    window.create(VideoMode(1280, 720), L"Search Tree", sf::Style::Close); // параметры окна

    float width = VideoMode::getDesktopMode().width;  // получение текущиего размера экрана
    float height = VideoMode::getDesktopMode().height;  // получение текущиего размера экрана

    RectangleShape background(Vector2f(width, height)); // создаем прямоугольник для изображения
    Texture texture_window;
    if (!texture_window.loadFromFile("fon.jpg")) return ; // загрузка в прямоугольник текстуру с изображением 
    background.setTexture(&texture_window);

    Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) exit(32); // установка шрифта
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 460, 50, L"Бинарное дерево", 70, sf::Color(15,15,15), 0); // параметры для заголовка
    String nameMenu[]{ L"Поиск по ключу",L"Получить высоту дерева", L"Назад" };

    Menu mymenu(window, 670, 250, 3, nameMenu, 60, 120);  // объект меню
    mymenu.setColorTextMenu(sf::Color(150,150,150), Color(600,600,600), Color::Black);  // установка цвета элементов пунктов меню
    mymenu.alignMenu(2);  // выравнивание по центру пунктов меню 

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyReleased) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }  // событие нажатия на клавиатуре стрелки вверх
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }  // событие нажатия на клавиатуре стрелки вниз
                if (event.key.code == Keyboard::Return){  // событие нажатия на клавиатуре клавиши Enter
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
