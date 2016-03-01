#include "naglowki.h"
#include "postacie.h"
#include "sterowanie.h"
#include "naboje.h"

using namespace std;

int main()
{
	float screenHeight = 600;
	float screenWidth = 800;
	float playerHeight = 50;
	float playerWidth = 50;
	float playerSpeed = 10;
	float kat=0;
	float PI = 3.14;

//==================    OBIEKTY          =========================================
	bohater A(400, 300);
	bohater B(200,200);
	myszka myszka;
	prosta prosta;





	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Podleze Slayer 2: Zemsta Atamanczuka");
	sf::CircleShape shape(200);
	sf::Clock clock;
	sf::Time time;


	sf::Vector2f graczVector(A.getX(), A.getY());
	sf::Texture teksturaA;
	sf::Sprite spriteA;

	sf::Texture teksturaB;
	

	sf::Sprite mapa;
	sf::Texture teksturaMapy;


//=================================    USTAWIENIA   ==================================================================


	if (!teksturaMapy.loadFromFile("mapa1.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!teksturaA.loadFromFile("postac1.png"))
	{
		std::cout << "Error" << std::endl;
	}
	spriteA.setTexture(teksturaA);
	mapa.setTexture(teksturaMapy);
	spriteA.setPosition(graczVector);
	spriteA.setOrigin(25, 25);

	



	int index = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			//============================   KLAWIATURA      ========================================================
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A && graczVector.x > 0)
				{
					
					graczVector.x = graczVector.x - playerSpeed;
					spriteA.setPosition(graczVector);
				}
				else if (event.key.code == sf::Keyboard::D && graczVector.x < screenWidth - playerWidth)
				{
					
					graczVector.x = graczVector.x + playerSpeed;
					spriteA.setPosition(graczVector);
				}
				if (event.key.code == sf::Keyboard::S && graczVector.y < screenHeight - playerHeight)
				{
					
					graczVector.y = graczVector.y + playerSpeed;
					spriteA.setPosition(graczVector);
				}
				else if (event.key.code == sf::Keyboard::W && graczVector.y > 0)
				{
					
					graczVector.y = graczVector.y - playerSpeed;
					spriteA.setPosition(graczVector);
				}
			}
			//===========================    MYSZKA   =============================================================

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				//cout << event.mouseMove.x << "   " << event.mouseMove.y << endl;
				break;
			case sf::Event::MouseButtonPressed:
				
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					myszka.ustaw(event.mouseButton.x, event.mouseButton.y);
				}
				break;
				
			}


			//=========================================================================================
			
			


		}

	//=========================================================================================
		kat = atan2(event.mouseMove.y - graczVector.y, event.mouseMove.x - graczVector.x);
		
		spriteA.setRotation(kat*180/PI);
		
		
		window.clear();
		time = clock.restart();


		window.draw(mapa);
		window.draw(spriteA);
		window.display();
	}
//======================
	return 0;
}