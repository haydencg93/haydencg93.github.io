/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 03/06/2024
 * Project Name: hw5
 * Description of Program: This C++ program is a program that creates/runs a DoodleJump video game.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Necessary Header Files */
#include <SFML/Graphics.hpp>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
using namespace sf;

/*************************************************************
 * Description: The main() function initializes the game and runs
 *          the main game loop. This function creates, loads, and
 *          positions all the game objects. It also handles keyboard
 *          inputs and collisions.
 * Type: Main Method
 * Inputs: Keyboard Clicks
 * Outputs: The game itself, sprites/objects, movements of sprites/objects
 **************************************************************/
class point {
public:
    int getXVar(){
        return x;
    }
    int getYVar(){
        return y;
    }
    void setXVar(int x1){
        x = x1;
    }
    void setYVar(int y1){
        y = y1;
    }
private:
    int x;
    int y;
};

/*************************************************************
 * Description: The main() function initializes the game and runs
 *          the main game loop. This function creates, loads, and
 *          positions all the game objects. It also handles keyboard
 *          inputs and collisions.
 * Type: Main Method
 * Inputs: Keyboard Clicks
 * Outputs: The game itself, sprites/objects, movements of sprites/objects
 **************************************************************/
int main() {
    srand(time(0)); // Seeds random generator

    RenderWindow app(VideoMode(400, 533), "Doodle Game!"); // Creates window
    app.setFramerateLimit(60); // Sets the framerate's limit to 60

    int score = 0;

    bool instructionState = true;
    bool playGame = false;

    Texture t1, t2, t3, t4, t5, t6, t7, t8; // Declares textures
    SoundBuffer buffer1,/* buffer2,*/ buffer3;
    Font font;

//    t1.loadFromFile("images/background.png");
    if (!t1.loadFromFile("images/background.png")) { // Loads background
        return EXIT_FAILURE;
    }
//    t2.loadFromFile("images/platform.png");
    if (!t2.loadFromFile("images/platform.png")) { // Loads platform
        return EXIT_FAILURE;
    }
//    t3.loadFromFile("images/doodle.png");
    if (!t3.loadFromFile("images/doodle.png")) { // Loads the doodle
        return EXIT_FAILURE;
    }
    if (!t4.loadFromFile("images/doodle2.png")) { // Loads the doodle2
        return EXIT_FAILURE;
    }
    if (!t5.loadFromFile("images/doodle3.png")) { // Loads the doodle3
        return EXIT_FAILURE;
    }
    if (!t6.loadFromFile("images/doodle4.png")) { // Loads the doodle4
        return EXIT_FAILURE;
    }
    if (!t7.loadFromFile("images/doodle5.png")) { // Loads the doodle5
        return EXIT_FAILURE;
    }
    if (!t8.loadFromFile("images/doodle6.png")) { // Loads the doodle6
        return EXIT_FAILURE;
    }
    if (!buffer1.loadFromFile("sounds/backgroundMusic.flac")) { // Loads the sound for falling off bottom
        return EXIT_FAILURE;
        // sound was created by Sakura Girl and uploaded to https://www.chosic.com/download-audio/58136/
    }
//    if (!buffer2.loadFromFile("sounds/jumpSound.flac")) { // Loads the sound for falling off bottom
//        return EXIT_FAILURE;
        // sound was created by mikala_oidua and uploaded to https://freesound.org/people/mikala_oidua/sounds/365672/
//    }
    if (!buffer3.loadFromFile("sounds/gameOverSound1.flac")) { // Loads the sound for falling off bottom
        return EXIT_FAILURE;
        // sound was created by satchdev and uploaded to https://freesound.org/people/satchdev/sounds/325413/
    }
    if (!font.loadFromFile("fonts/gameFont.ttf")) { // Loads the sound for falling off bottom
        return EXIT_FAILURE;
        // sound was created by satchdev and uploaded to https://freesound.org/people/satchdev/sounds/325413/
    }

    Sound backgroundMusic;
    backgroundMusic.setBuffer(buffer1);

//    Sound jumpSound;
//    jumpSound.setBuffer(buffer2);

    Text instructionsTitle;
    instructionsTitle.setFont(font);
    instructionsTitle.setString("Instructions:");
    instructionsTitle.setCharacterSize(25);
    instructionsTitle.setFillColor(::Color::Black);
    instructionsTitle.setStyle(Text::Bold | Text::Underlined);
    instructionsTitle.setPosition(95, 10);
    //
    Text spaceBarInstr;
    spaceBarInstr.setFont(font);
    spaceBarInstr.setString("(Press the SPACE bar to start the game)");
    spaceBarInstr.setCharacterSize(12);
    spaceBarInstr.setFillColor(::Color::Black);
    spaceBarInstr.setPosition(65, 50);
    //
    Text arrowsInstr;
    arrowsInstr.setFont(font);
    arrowsInstr.setString("- Using the left and right arrow keys, the goal \nis to get the Doodle Character onto the "
                          "green \nplatforms.");
    arrowsInstr.setCharacterSize(13);
    arrowsInstr.setFillColor(::Color::Black);
    arrowsInstr.setPosition(10, 80);
    //
    Text scoringSkinInstr;
    scoringSkinInstr.setFont(font);
    scoringSkinInstr.setString("- The higher up in the game you go, the \nhigher the score. As the score goes up, the "
                               "\nskin of the Doodle will change to a different \none.");
    scoringSkinInstr.setCharacterSize(13);
    scoringSkinInstr.setFillColor(::Color::Black);
    scoringSkinInstr.setPosition(10, 120);
    //
    Text skinsInstr1;
    skinsInstr1.setFont(font);
    skinsInstr1.setString("- The skins include a normal one with a shirt, \none with a top hat, a ninja one, a "
                               "cow-themed \none, a UIowa-themed one, and a wizard one. \nThe required minimum score amounts"
                               " for each \nskin includes:");
    skinsInstr1.setCharacterSize(13);
    skinsInstr1.setFillColor(::Color::Black);
    skinsInstr1.setPosition(10, 170);
    //
    Text skinsInstr2;
    skinsInstr2.setFont(font);
    skinsInstr2.setString("- 0 = Normal \n- 50 = Top Hat \n- 100 = Ninja \n- 175 = Cow \n- 275 = UIowa \n- 400 = Wizard");
    skinsInstr2.setCharacterSize(13);
    skinsInstr2.setFillColor(::Color::Black);
    skinsInstr2.setPosition(30, 235);
    //
    Text restartInstr;
    restartInstr.setFont(font);
    restartInstr.setString("- If you fail to land on a platform, the game is \nover. In order to start a new game, simply"
                          " press the \nthe R key.");
    restartInstr.setCharacterSize(13);
    restartInstr.setFillColor(::Color::Black);
    restartInstr.setPosition(10, 315);

    //
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score:");
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(::Color::Black);
    scoreText.setStyle(Text::Bold | Text::Underlined);
    scoreText.setPosition(0, 5);
    Text actualScore;
    actualScore.setFont(font);
//    actualScore.setString("500");
    actualScore.setCharacterSize(15);
    actualScore.setFillColor(::Color::Black);
    actualScore.setPosition(0, 22);


    Sound gameOverSound;
    gameOverSound.setBuffer(buffer3);

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(35);
    gameOverText.setFillColor(::Color::Red);
    gameOverText.setStyle(Text::Bold | Text::Underlined);
    gameOverText.setPosition(100, 200);

    Sprite sBackground(t1), sPlat(t2), sPers(t4); // Assigns images to Sprites
    bool gameOver = false;
    point plat[20]; // create an array for the vertices of the platform

    for (int i=0;i<10;i++) { // while index is less than 10...
        plat[i].setXVar(rand()%400); // Generate random x position between 0-399
        plat[i].setYVar(rand()%533); // Generate random y position between 0-532
    }

    int x=100, y=100, h=200; // Creates variables x, y, h to track position and height
    float dx=0, dy=0; // Creates variables dx, dy to track velocity in x and y directions

    backgroundMusic.play();
    backgroundMusic.setLoop(true);

    while (app.isOpen()) { // While the app is open...

        Event e; // Create an event object e
        while (app.pollEvent(e)) { // While events are occurring...
            if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)){ // If the event is a window close...
                app.close(); // Closes the app/game
            }
        }

        if (instructionState == true) {
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                instructionState = false;
                playGame = true;
                score = 0;
            } else {
                //backgroundMusic.pause();
                app.draw(sBackground);
                app.draw(instructionsTitle);
                app.draw(spaceBarInstr);
                app.draw(arrowsInstr);
                app.draw(scoringSkinInstr);
                app.draw(skinsInstr1);
                app.draw(skinsInstr2);
                app.draw(restartInstr);
            }
        }

        if (playGame == true) {
            //backgroundMusic.play();
            // If the right arrow is pressed, move the doodle position +3 more in the x direction (right)
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                x += 3;
            }
            // If the left arrow is pressed, move the doodle position -3 less in the x direction (left)
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                x -= 3;
            }

            dy += 0.2; // Increment dy by 0.2 each frame to represent/show gravity
            y += dy; // Increment y by dy each frame to fall/move the doodle downwards
            if (y > 550 && gameOver == false) { // If y position is greater than 500...
//            dy = -10; // Reverse dy to bounce -10 in the y direction (upwards)
                backgroundMusic.stop(); // Stops background music
                gameOverSound.play(); // Play game-over sound
                gameOver = true;
            }

            if (y < h) { // If y is less than the height h...

                for (int i=0;i<10;i++) { // While the index is less than 10...
                    y = h; // Set y to h to prevent falling below the visual platform
                    plat[i].setYVar(plat[i].getYVar()-dy); // Move the platform up by the amount dy has changed in the y direction
                    // If platform goes off screen, reset its position
                    if (plat[i].getYVar() > 533) {
                        plat[i].setYVar(0);
                        plat[i].setXVar(rand() % 400);
                    }
                }
            }

            for (int i=0;i<10;i++) { // While the index is less than 10...
                // If doodle collides with platform, reverse dy to bounce -10 in the y direction (upwards)
                if ((x + 50 > plat[i].getXVar()) && (x + 20 < plat[i].getXVar() + 68) && (y + 70 > plat[i].getYVar()) && (y + 70 < (plat[i].getYVar() + 14)) && (dy > 0)) {
                    dy = -10;
                    score += y/100;
                    actualScore.setString(std::to_string(score));
                }
            }

            if (score < 50) {
                sPers.setTexture(t4);
            } else if (score >= 50 && score < 100) {
                sPers.setTexture(t5);
            } else if (score >= 100 && score < 175) {
                sPers.setTexture(t3);
            } else if (score >= 175 && score < 275) {
                sPers.setTexture(t6);
            } else if (score >= 275 && score < 400) {
                sPers.setTexture(t7);
            } else if (score >= 400){
                sPers.setTexture(t8);
            } else {
                sPers.setTexture(t4);
            }

            sPers.setPosition(x, y); // Set doodle position to (x, y)

            app.draw(sBackground); // Draw/display background sprite
            app.draw(sPers); // Draw/display doodle sprite
            for (int i=0;i<10;i++) { // While the index is less than 10...
                sPlat.setPosition(plat[i].getXVar(), plat[i].getYVar()); // Set platform position to array (x, y) values
                app.draw(sPlat); // Draw/display the platform sprite
            }

            app.draw(scoreText);
            app.draw(actualScore);
        }
        if (gameOver == true) {
            y = 600;
            app.draw(gameOverText);
            playGame = false;
            //app.display();
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                score = 0;
                for (int i=0;i<10;i++) { // while index is less than 10...
                    plat[i].setXVar(rand()%400); // Generate random x position between 0-399
                    plat[i].setYVar(rand()%533); // Generate random y position between 0-532
                }
                x = 100;
                y = 100;
                gameOver = false;
                //app.display();
                playGame = true;
                backgroundMusic.play();
            }
        }

        app.display(); // Displays the whole app/game
    }

    return 0; // Returns if the app is not open in order to stop running the program
}
