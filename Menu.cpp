#include "Menu.h"

void Menu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos) { //��������� ��������� �������� ������� �������� ����
	text.setFont(font); // �����
	text.setFillColor(menuTextColor); // ���� 
	text.setString(str); // �����
	text.setCharacterSize(sizeFont); // ������ ������
	text.setPosition(xpos, ypos); // ���������� ���������� �������
	text.setOutlineThickness(0); // ������� ������� ������� ������
	text.setOutlineColor(borderColor); // ���� ������� ������� ������
}

void Menu::alignMenu(int posx) { // ������������ ������� ���� �� ������ �� ������� �� ������ 
	float nullx = 0;
	for (int i = 0; i < maxMenu; i++) {
		switch (posx)
		{
		case 0:
			nullx = 0; // ������������ �� ������� ���� �� ������������� ���������
			break;
		case 1:
			nullx = mainMenu[i].getLocalBounds().width;  // �� ������ ����
			break;
		case 2:
			nullx = nullx = mainMenu[i].getLocalBounds().width / 2;  // �� ������
			break;
		}
		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
	}

}

Menu::Menu(sf::RenderWindow& window, float menux, float menuy,
	int index, sf::String name[], int sizeFont, int step)
	:mywindow(window), menuX(menux), menuY(menuy), sizeFont(sizeFont), menuStep(step) {
	// �������� ������
	if (!font.loadFromFile("ArialRegular.ttf")) exit(32); // �������� ������
	maxMenu = index; // ���������� ��������� ���� 
	mainMenu = new sf::Text[maxMenu]; // ������������ ������ ������� ����
	for (int i = 0, ypos = menuY; i < maxMenu; i++, ypos += menuStep) // ������������ ��������� ����
		setInitText(mainMenu[i], name[i], menuX, ypos);
	mainMenuSelected = 0; // ������� ��������� ��������� ��������� ������ ����
	mainMenu[mainMenuSelected].setFillColor(choseTextColor); // ���� ��������� ������ ����
}

void Menu::MoveUp()
{
	mainMenuSelected--;
	if (mainMenuSelected >= 0) { // ������������� ���������� ������ ����
		mainMenu[mainMenuSelected].setFillColor(choseTextColor);
		mainMenu[mainMenuSelected + 1].setFillColor(menuTextColor);
	}
	else
	{
		mainMenu[0].setFillColor(menuTextColor);
		mainMenuSelected = maxMenu - 1;
		mainMenu[mainMenuSelected].setFillColor(choseTextColor);
	}
}

void Menu::MoveDown() {
	mainMenuSelected++;
	if (mainMenuSelected < maxMenu) { // ������������� ���������� ������ ����
		mainMenu[mainMenuSelected - 1].setFillColor(menuTextColor);
		mainMenu[mainMenuSelected].setFillColor(choseTextColor);
	}
	else
	{
		mainMenu[maxMenu - 1].setFillColor(menuTextColor);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(choseTextColor);
	}

}

void Menu::draw() {	
	for (int i = 0; i < maxMenu; i++) mywindow.draw(mainMenu[i]); // ������� ��� ��������� ������������ ��������� �������� ������� ���� 
}

void Menu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor) {
	menuTextColor = menColor; // ���� ������� ����
	choseTextColor = ChoColor; // ���� ��������� ������ ����
	borderColor = BordColor; // ���� ������� ������� ����

	for (int i = 0; i < maxMenu; i++) {
		mainMenu[i].setFillColor(menuTextColor);
		mainMenu[i].setOutlineColor(borderColor);
	}

	mainMenu[mainMenuSelected].setFillColor(choseTextColor);
}