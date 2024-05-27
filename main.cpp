#include "Menu.h"
#include "Tree.h"
#include "WorkButton.h"
#include <vector>
#include "finishing.h"
using namespace sf;
using namespace std;

int main() {
    system("chcp 1251 > Null");
    RenderWindow window; // �������� ���� windows
    window.create(VideoMode(1280,720), L"����", sf::Style::Close); // ��������� ����
    float width = VideoMode::getDesktopMode().width; // ��������� �������� ������� ������
    float height = VideoMode::getDesktopMode().height; // ��������� �������� ������� ������

    // �������� ������
    Image icon;
    icon.loadFromFile("Image/icon1.png");
    window.setIcon(1200, 1084, icon.getPixelsPtr());

    window.setMouseCursorVisible(false);// ���������� ��������� �������

    Music music;// ��������������� ����������� ��������
    music.openFromFile("music.ogg");
    music.play();
    music.setLoop(true);
    music.setVolume(2.f);

    // �������� ����������� ����
    Texture textureFon;
    textureFon.loadFromFile("Image/fon.jpg");
    RectangleShape fon(Vector2f(1280, 720));
    fon.setTexture(&textureFon);

    RectangleShape fon2(Vector2f(1280, 720));
    fon2.setTexture(&textureFon);
    fon2.setPosition(Vector2f(1280, 0));

    Vector2f pos;// ���������� ��������
    Clock clock;    // ������
    float time;

    RectangleShape background(Vector2f(width, height)); // ������� ������������� ��� �����������
    Texture texture_window;
    if (!texture_window.loadFromFile("fon.jpg")) return 4; // �������� � ������������� �������� � ������������ 
    background.setTexture(&texture_window);

    Font font;
    if (!font.loadFromFile("ArialRegular.ttf")) return 5; // ��������� ������ ��� ��������
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 410, 50, L"�������� ������:", 70, Color(15, 15, 15), 0); // ��������� ��� ���������

    String nameMenu[]{ L"������������ ������ ������", L"�������������� ������ ������", L"������ ������", L"�������� ����",  L"������� ����", L"������� ������� ������", L"������������ ������ ��������� ������ � �������", L"�����"};
    Menu mymenu(window, 670, 170, 8, nameMenu, 45, 90); // ������ ����
    mymenu.setColorTextMenu(sf::Color(150, 150, 150), Color(1, 1, 1), Color::Black); // ��������� ����� ��������� ������� ����
    mymenu.alignMenu(2); // ������������ �� ������ ������� ���� 

    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) //��� �������� ����� �������
                window.close();
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); } // ������� ������� �� ���������� ������� �����
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); } // ������� ������� �� ���������� ������� ����
                if (event.key.code == Keyboard::Return) { // ������� ������� �� ���������� ������� Enter
                    switch (mymenu.getSelectedMenuNumber()) {
                    case 0: drawTreeVertically(); break;
                    case 1: drawTreeHorizontally(); break;
                    case 2: rounds(); break;
                    case 3: addNode(); break;
                    case 4: deleteNode(); break;
                    case 5: createSearchTree(); break;
                    case 6: printInConsol(); break;
                    case 7: window.close(); break;
                    }
                }
            }
        }
        // ���������� �������
        time = clock.getElapsedTime().asMicroseconds();
        time = time / 15000;
        clock.restart();

        // �������� ����
        fon.move(-0.2 * time, 0);
        pos = fon.getPosition();
        if (pos.x < -1280) fon.setPosition(1280, pos.y);

        fon2.move(-0.2 * time, 0);
        pos = fon2.getPosition();
        if (pos.x < -1280) fon2.setPosition(1280, pos.y);

        window.draw(fon);// ��������� ��������� ����
        window.draw(fon2);
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }
    return 0;
}
