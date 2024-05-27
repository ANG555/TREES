#pragma once
#include <SFML/Graphics.hpp>

using namespace sf; 
class Menu {
	float menuX; // ���������� ���� �� x
	float menuY; // ���������� ���� �� y
	int menuStep; // ���������� ����� �������� ����
	int maxMenu; // ������������ ���������� ������� ����
	int sizeFont; // ������ ������
	int mainMenuSelected; // ����� �������� ������ ���� 
	sf::Font font; // ����� ���� 
	sf::Text* mainMenu; // ������������ ������ ��������� �������� �������� ������� ����
	sf::Color menuTextColor = sf::Color::White; // ���� ������� ����
	sf::Color choseTextColor = sf::Color::Yellow; // ���� ������ ������ ����
	sf::Color borderColor = sf::Color::Black; // ���� ������� ������ ������� ����
	sf::RenderWindow& mywindow; // ������ �� ����������� ����

	void setInitText(sf::Text& text, sf::String str, float xpos, float ypos); // ��������� ������ ������� ����
public:
	Menu(sf::RenderWindow& window, float menux, float menuy,
		int index, sf::String name[], int sizeFont = 60, int step = 80); // �����������

	~Menu() { // ����������
		delete[] mainMenu;
	}

	void draw(); // ������� ����
	void MoveUp(); // ����������� ������ ���� �����
	void MoveDown(); // ����������� ������ ���� ����
	void setColorTextMenu(sf::Color menColor, sf::Color ChoColor,
		sf::Color BordColor); // ���� ��������� �������� ����
	void alignMenu(int posx); // ������������ ��������� ����
	int getSelectedMenuNumber() { // ���������� ����� ���������� �������� ����
		return mainMenuSelected;
	}
};