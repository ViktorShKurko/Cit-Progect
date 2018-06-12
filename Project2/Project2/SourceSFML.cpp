
#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "time.h"
#include "iostream"
using namespace sf;
using namespace std;

int NUM( int muxa_x, int muxa_y) 
{
	int pul;
	if (muxa_x == 0 and muxa_y == 0) 
	{
		pul = rand() % 3;
		switch (pul) {

		case 0:
			return 0;
			break;
		case 1:
			return 2;
			break;
		case 4:
			return 6;
			break;
		}
	}
	else if (muxa_x == 0 and muxa_y == 4)
	{
		pul = rand() % 3;
		switch (pul)
		{
		case 0:

			return 0;
			break;
		case 1:

			return 3;
			break;
		case 2:

			return 7;
			break;
		default:
			break;
		}
	}
	else if (muxa_x == 4 and muxa_y == 0)
	{
		pul = rand() % 3;
		switch (pul)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 5;
			break;
		default:
			break;
		}

	}
	else if (muxa_x == 4 and muxa_y == 4)
	{
		pul = rand() % 3;
		switch (pul)
		{
		case 0:
			return 1;
			
			break;
		case 1:
			return 3;
			
			break;
		case 2:
			return 4;
			
			break;
		default:
			break;
		}
	}
	else if (muxa_x == 0) {
		pul = rand() % 5;
		switch (pul) {
		case 0:
			return 3;
			
			break;
		case 1:
			return  2;
			
			break;
		case 2:
			return 7;
			
			break;
		case 3:
			return 6;
			
			break;
		case 4:
			return 0;
			
			break;
		default:
			break;
		}
	}
	else if (muxa_x == 4) {
		pul = rand() % 5;
		switch (pul) {
		case 0:
			return 2;
			break;
		case 1:
			return 3;
			
			break;
		case 2:
			return 5;
			
			break;
		case 3:
			return 4;
			
			break;
		case 4:
			return 1;
			
			break;
		default:
			break;
		}

	}
	else if (muxa_y == 0) {
		pul = rand() % 5;
		switch (pul) {
		case 0:
			return 2;
			
			break;
		case 1:
			return 0;
			
			break;
		case 2:
			return 5;
			
			break;
		case 3:
			return 6;
			
			break;
		case 4:
			return 1;
			
			break;
		default:
			break;
		}

	}
	else if (muxa_y == 4) {
		pul = rand() % 5;
		switch (pul) {
		case 0:
			return 3;
			
			break;
		case 1:
			return 0;
			
			break;
		case 2:
			return 4;
			
			break;
		case 3:
			return 7;
			
			break;
		case 4:
			return 1;
			
			break;
		default:
			break;
		}

	}
	else {
		pul = rand() % 8;
		switch (pul) {
		case 0:
			return 2;
			
			break;
		case 1:
			return 3;
			
			break;
		case 2:
			return 7;
			
			break;
		case 3:
			return 6;
			
			break;
		case 4:
			return 0;
			
			break;
		case 5:
			return 1;
			
			break;
		case 6:
			return 5;
			
			break;
		case 7:
			return 4;
			
			break;
		default:
			break;
		}
	} 
}

int main()
{
	srand(time(NULL));
	int scale = 100;
	int num = -1;// номер который определяет варианты и направление движения
	int m = 1; // количество допустимых кликов на поле , при нажатии вне игрового поля , количество неуменьшается 
	int move = 5; // количкство ходов 
	int time = 3000; // длительность одного хода 
	int d = 0;

	double muxa_x = 2;// x-вая координата мухи 
	double muxa_y = 2;// y-вая координата мухи
	double m1x, m1y;//  координаты мышки  не целые 
 	double x, y;// сохраняе координаты мышки для сравнения 
	
	bool  r = false, h = true, k = false, j = false, g = false; // номер клавиш меню
    
	RenderWindow window(VideoMode(704, 500), "Myxa",Style::Close);
	RectangleShape rect(Vector2f(704, 500));

	Clock clock;
	Clock t;

	Image N; N.loadFromFile("321.png");// --- изображение Мухи
	Texture M; M.loadFromImage(N); 
	Sprite s;
	s.setTexture(M);

	Image Image1; Image1.loadFromFile("Анимация.png"); //--- Указатели 
	Texture Mimage; Mimage.loadFromImage(Image1);
	Sprite sprite;
	sprite.setTexture(Mimage);
	sprite.setTextureRect(IntRect(0, 2000, 500, 2500)); 

	Texture text;          // --- Карта/Игровое поле 
	text.loadFromFile("Карта 2.png");
	rect.setTexture(&text);

	Image WIN; WIN.loadFromFile("VIC.png"); // --- область попадания 
	Texture W; W.loadFromImage(WIN);
	Sprite win; win.setTexture(W);

	Image LOSE; LOSE.loadFromFile("LOSE.png"); // --- область проаха 
	Texture L; L.loadFromImage(LOSE);
	Sprite lose; lose.setTexture(L);

	Image menu1, menu2, menu3,menuWin,menuM1,menuLose,menuM2,set,set1,set2,set3,set4,set5,set6,ok;
	menu1.loadFromFile("Play.png");
	menu2.loadFromFile("Setting.png");
	menu3.loadFromFile("Exit.png");
	menuWin.loadFromFile("MWIN.png");
	menuLose.loadFromFile("MLOS.png");
	menuM1.loadFromFile("retry1.png");
	menuM2.loadFromFile("menu1.png");

    set.loadFromFile("setting1.png");
	set1.loadFromFile("1.png");
	set2.loadFromFile("2.png");
	set3.loadFromFile("3.png");
    set4.loadFromFile("5х.png");
	set5.loadFromFile("10х.png");
	set6.loadFromFile("15х.png");
	ok.loadFromFile("ок.png");

	Texture Menu1, Menu2, Menu3,MenuWin,MenuLos,MenuM1,MenuM2,Set, Set1, Set2, Set3, Set4, Set5, Set6,Ok;
	Menu1.loadFromImage(menu1);
	Menu2.loadFromImage(menu2);
	Menu3.loadFromImage(menu3);

	MenuWin.loadFromImage(menuWin);
	MenuLos.loadFromImage(menuLose);

	MenuM1.loadFromImage(menuM1);
	MenuM2.loadFromImage(menuM2);

	Set.loadFromImage(set);
	Set1.loadFromImage(set1);
	Set2.loadFromImage(set2);
	Set3.loadFromImage(set3);
	Set4.loadFromImage(set4);
	Set5.loadFromImage(set5);
	Set6.loadFromImage(set6);
	Ok.loadFromImage(ok);

	Sprite M1, M2, M3,Mw,Mls,Mn1,Mn2,SET, SET1, SET2, SET3, SET4, SET5, SET6,OK;
	M1.setTexture(Menu1);
	M1.setPosition(555, 135);
	M1.setColor(Color::Blue);

	SET.setTexture(Set);
	SET.setPosition(50, 120);

	OK.setTexture(Ok);
	OK.setPosition(300,323);

	////// SETTING --- TIME //////
	SET1.setTexture(Set1);
	SET1.setPosition(70, 240);

	SET2.setTexture(Set2);
	SET2.setPosition(140, 240);

	SET3.setTexture(Set3);
	SET3.setPosition(210, 240);
	  //////////////////////////

	  ////// SETTING --- MOVE ///////
	SET4.setTexture(Set4);
	SET4.setPosition(70, 323);

	SET5.setTexture(Set5);
	SET5.setPosition(140, 323);

	SET6.setTexture(Set6);
	SET6.setPosition(210, 323);
	  ///////////////////////////

	M1.setTexture(Menu1);    
	M1.setPosition(555, 135); // --- PLAY
	M1.setColor(Color::Blue);

	M2.setTexture(Menu2);
	M2.setPosition(555, 220); // --- SETTING
	M2.setColor(Color::Blue);

	M3.setTexture(Menu3);
	M3.setPosition(555, 420); // --- EXIT
	M3.setColor(Color::Blue);

	Mw.setTexture(MenuWin);    // --- WIN
	Mw.setPosition(101, 179);

	Mls.setTexture(MenuLos);  // --- LOSE
	Mls.setPosition(101, 179);

	Mn1.setTexture(MenuM1);   // --- RETRY
	Mn1.setPosition(204, 232);

	Mn2.setTexture(MenuM2);   // --- Menu
	Mn2.setPosition(204,266);


	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			m1x = Mouse::getPosition(window).x;
			m1y = Mouse::getPosition(window).y;

			////// Кнопки МЕНЮ  ---- PLAY ; SETTING ; EXIT ///////

			if (m1x == 555 && m1y == 135 || m1x > 555 && m1x < 655 && m1y>135 && m1y < 175) { M1.setColor(Color::Green);} // ------ Меню - Play
			else { M1.setColor(Color::Blue); }

			if (m1x == 555 && m1y == 220 || m1x > 555 && m1x < 655 && m1y < 260 && m1y >220) { M2.setColor(Color::Green);} // ------- Меню - Setting
			else { M2.setColor(Color::Blue); }

			if (m1x == 555 && m1y == 420 || m1x > 555 && m1x < 655 && m1y < 460 && m1y > 420) { M3.setColor(Color::Green);} // -------- Меню - Exit
			else { M3.setColor(Color::Blue); } 

			////// окна ----- WIN ; LOSE ---- RETY;MENU  /////////

			if (m1x ==204  && m1y == 232 || m1x > 204 && m1x < 296 && m1y <264  && m1y > 232 ) { Mn1.setColor(Color::Black); } // ------ Окно - RETRY
			else { Mn1.setColor(Color::Blue); }

			if (m1x == 204 && m1y == 266 || m1x > 204 && m1x < 296 && m1y < 307 && m1y > 266) { Mn2.setColor(Color::Black); } // ----- Окно - menu
			else { Mn2.setColor(Color::Blue); }

			//////  SETTING ------ TIME ---- 1;2;3///////

			if (m1x == 50 && m1y == 240 || m1x > 50 && m1x < 130 && m1y < 290 && m1y > 240) { SET1.setColor(Color::Green); } // --- 1
			else { SET1.setColor(Color::Blue); }

			if (m1x == 140 && m1y == 240 || m1x > 140 && m1x < 200 && m1y < 290 && m1y > 240) { SET2.setColor(Color::Green); } // --- 2
			else { SET2.setColor(Color::Blue); }

			if (m1x == 210 && m1y == 240 || m1x > 210 && m1x < 270 && m1y < 290 && m1y > 240) { SET3.setColor(Color::Green); } // --- 3
			else { SET3.setColor(Color::Blue); }

			//////  SETTING ------ MOVE ---- 5;10;15 ///////

			if (m1x == 50 && m1y == 323 || m1x > 50 && m1x < 130 && m1y < 373 && m1y > 323) { SET4.setColor(Color::Green); } // --- 5
			else { SET4.setColor(Color::Blue); }

			if (m1x == 140 && m1y == 323 || m1x > 140 && m1x < 200 && m1y < 373 && m1y > 323) { SET5.setColor(Color::Green); } // --- 10
			else { SET5.setColor(Color::Blue); }

			if (m1x == 210 && m1y == 323 || m1x > 210 && m1x < 270 && m1y < 373 && m1y > 323) { SET6.setColor(Color::Green); } // --- 15
			else { SET6.setColor(Color::Blue); }

			///////// SETTING ----- ОК ////////////

			if (m1x == 300 && m1y == 323 || m1x > 300 && m1x < 360 && m1y < 373 && m1y > 323) { OK.setColor(Color::Green); } // --- OK
			else { OK.setColor(Color::Blue); }
			
			if (m!=0 && d==move)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{   
					x = int(m1x);// координата x в точке куда указал пользователь 
					y = int(m1y); // координата y в точке куда указал пользователь 
					x = x / 100;
					y = y / 100;
					
					if (x < muxa_x + 1 && x > muxa_x&& y < muxa_y + 1 && y > muxa_y)
					{
						r = true; // попадание 
						h = true; // покажет муху
						cout << "WIN" << endl;
						cout << muxa_x << "  " << muxa_y;
						win.setPosition(Vector2f((muxa_x + 0.02)*scale, (muxa_y + 0.0115)*scale));// выводим зеленную текстурку при проммахе 
						//window.draw(win);
						m--; 
					}
					else
					{
						if (x < 5)// разделяем область меню от играовоййй 
						{
							r = false; // промах
							k = true;
							h = true;  // покажет муху
							lose.setPosition(Vector2f((int(x) + 0.03)*scale, (int(y) + 0.0115)*scale));// выводим красную текстурку при проммахе 
							cout << "LOSE" << endl;
							cout << "   " << x << " " << y;
							m--;// взамодействие с полем закончено 
						}
						else { m = 1; }
					}
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (m1x == 555 && m1y == 135 || m1x > 555 && m1x < 655 && m1y>135 && m1y < 175) { j = true; h = false; g = false; } // -------- PLAY

				if (r||k) 
				{
					
					if (m1x == 204 && m1y == 232 || m1x > 204 && m1x < 296 && m1y < 264 && m1y >232)  // --------- RETRY
					{
						d = 0; // количество ходов возобновляется 
						m = 1; // допустимое количество кликов в игровом поле возобновилось
						j = false; // таймер пере-ся 
						r = false; // исчезло окно WIN
						k = false; // исчезло окно LOSE
						muxa_x = 2; //   муха возвращается на середину 
						muxa_y = 2;
						j = true;  // мгновенный переход к игровому процессу
						g = false; // чтобы во время игры невыплывало окно с настройками
						h = false; // муха исчезает 
					}

					if (m1x == 204 && m1y == 266 || m1x > 204 && m1x < 296 && m1y < 307 && m1y > 266)
					{
						d = 0; // количество ходов возобновляется 
						m = 1; // допустимое количество кликов в игровом поле возобновилось
						j = false;  // таймер пере-ся 
						r = false;  // исчезло окно WIN
						k = false;  // исчезло окно LOSE
						h = false;  // муха исчезает 
						muxa_x = 2; //   муха возвращается на середину 
						muxa_y = 2; 
						h = true;
						g = false;
					}
				}
				if (m1x == 555 && m1y == 220 || m1x > 555 && m1x < 655 && m1y < 260 && m1y >220)  g = true; //  ----- Setting
				if (m1x == 300 && m1y == 323 || m1x > 300 && m1x < 360 && m1y < 373 && m1y > 323) g = false; // ----- OK
				if (g)
				{
					if (m1x == 50  && m1y == 240 || m1x > 50  && m1x < 130 && m1y < 290 && m1y > 240) time = 1000;
					if (m1x == 140 && m1y == 240 || m1x > 140 && m1x < 200 && m1y < 290 && m1y > 240) time = 2000;
					if (m1x == 210 && m1y == 240 || m1x > 210 && m1x < 270 && m1y < 290 && m1y > 240) time = 3000;
					if (m1x == 50  && m1y == 323 || m1x > 50  && m1x < 130 && m1y < 373 && m1y > 323) move = 5;
					if (m1x == 140 && m1y == 323 || m1x > 140 && m1x < 200 && m1y < 373 && m1y > 323) move = 10;
					if (m1x == 210 && m1y == 323 || m1x > 210 && m1x < 270 && m1y < 373 && m1y > 323) move = 15;
				}
				if (m1x == 555 && m1y == 420 || m1x > 555 && m1x < 655 && m1y < 460 && m1y > 420) window.close(); // ------- exite
				/////////////////////////////
			}
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) window.close();
		}
		if (j)
		{
		  if (clock.getElapsedTime().asMilliseconds() > time)
		  {
			clock.restart();

			if (d!=move)
			{
				      num = NUM( muxa_x, muxa_y);

				      if (num == 0) { muxa_x++; sprite.setTextureRect(IntRect(0, 0, 500, 500)); } // --- вправо
				 else if (num == 1) { muxa_x--; sprite.setTextureRect(IntRect(500, 0, 1000, 500)); } // ---- влево
				 else if (num == 2) { muxa_y++; sprite.setTextureRect(IntRect(0, 500, 500, 1000)); } //---- вниз
				 else if (num == 3) { muxa_y--; sprite.setTextureRect(IntRect(500, 500, 1000, 1000)); } // ------ вверх
				 else if (num == 4) { muxa_y--; muxa_x--; sprite.setTextureRect(IntRect(0, 1500, 500, 2000)); } // ------ вверх влево
				 else if (num == 5) { muxa_y++; muxa_x--; sprite.setTextureRect(IntRect(500, 1500, 1000, 2000)); } //--------  вниз влево
				 else if (num == 6) { muxa_y++; muxa_x++; sprite.setTextureRect(IntRect(500, 1000, 1000, 1500)); } //------ вниз впрао
				 else if (num == 7) { muxa_y--; muxa_x++; sprite.setTextureRect(IntRect(0, 1000, 500, 1500)); } // ----- вверх вправо
				 d++;
				t.restart();
			} 
			else { sprite.setTextureRect(IntRect(0, 2000, 500, 2500)); }
			if (event.type == Event::Closed)  window.close(); 
		  }
		}

		s.setPosition(Vector2f(muxa_x*scale, muxa_y*scale));
		window.clear();
		window.draw(rect);
		window.draw(M1);
		window.draw(M2);
		window.draw(M3);

		if(t.getElapsedTime().asMilliseconds()<(time/2))window.draw(sprite);  // ---- ЗАДЕРЖКА И ПОЯВЛЕНИЕ УКАЗАТЕЛЯ 
		if (r) window.draw(win); 
		else if (k)window.draw(lose); 
		if (h)window.draw(s);// ------ MYXA
		if (k) // ОКНО ------- LOSE
		{
			window.draw(Mls);
			window.draw(Mn1);
			window.draw(Mn2);
		}
		if (r) //  ОКНО ------ WIN
		{
			window.draw(Mw); 
			window.draw(Mn1); 
			window.draw(Mn2);
		}
		if (g && j==false)  // ----- SETTING --- MOVE ; TIME ; OK
		{
			window.draw(SET);
			window.draw(SET1);
			window.draw(SET2);
			window.draw(SET3);
			window.draw(SET4);
			window.draw(SET5);
			window.draw(SET6);
			window.draw(OK);
		}
		window.display();
	}
	return 0;
}