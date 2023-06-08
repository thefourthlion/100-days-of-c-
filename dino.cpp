#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "Dinosaur Game");

    const int groundHeight = 40;
    const int dinosaurWidth = 50;
    const int dinosaurHeight = 70;
    const int jumpSpeed = 10;
    const int gravity = 2;

    bool isJumping = false;
    int jumpSpeedCurrent = 0;
    int dinosaurBottom = window.getSize().y - groundHeight - dinosaurHeight;
    int score = 0;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return -1; // Error loading font
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    sf::RectangleShape ground(sf::Vector2f(window.getSize().x, groundHeight));
    ground.setPosition(0, window.getSize().y - groundHeight);
    ground.setFillColor(sf::Color(192, 192, 192));

    sf::RectangleShape dinosaur(sf::Vector2f(dinosaurWidth, dinosaurHeight));
    dinosaur.setPosition(window.getSize().x / 2 - dinosaurWidth / 2, dinosaurBottom);
    dinosaur.setFillColor(sf::Color::Green);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && !isJumping)
                {
                    isJumping = true;
                    jumpSpeedCurrent = -jumpSpeed;
                }
            }
        }

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        score++;
        dinosaurBottom += jumpSpeedCurrent;
        jumpSpeedCurrent += gravity;

        if (dinosaurBottom >= window.getSize().y - groundHeight - dinosaurHeight)
        {
            dinosaurBottom = window.getSize().y - groundHeight - dinosaurHeight;
            isJumping = false;
        }

        scoreText.setString("Score: " + std::to_string(score));

        window.clear(sf::Color::White);
        window.draw(ground);
        window.draw(dinosaur);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}

