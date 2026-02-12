/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 04/24/2024
 * Project Name: hw7
 * Description of Program: This C++ program is a program that creates/runs an Asteroids video game.
 ************************************************************************************************/

/************************************************************************************************
 *                                    ~ Necessary Notes: ~
 * 1. In order to run the program, the debug button has to be used and not the regular run button.
 * 2. For the 20 pts extra credit, I have the following:
 *      - Tracking of the score
 *      - Tracking of lives
 *      - Added sounds for the bullet and explosions
 *      - Game Over Screen
 * 3. Necessary Instructions for the Game:
 *      - If you hit an asteroid, 15 points will be added onto the score.
 *      - If you hit a UFO, 25 points are added to the score and a life if you do not have all of your lives.
 *      - If an asteroid or the UFO comes in contact with you, then you lose a life.
 *              - For an asteroid, you will also lose an additional 10 points.
 *              - For the UFO, you will lose an additional 20 points.
 *      - You are given 5 lives and if you run out of lives, the game will be over.
 *              - To restart the game, simply press the "r" key if the game is over.
 *      - Use the arrows to move and space to shoot.
 *      - To close the game, simply press the close button on the window or press the "ESC" key.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Necessary Header Files */
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf; // using SFML namespace

// Constant variables
const int W = 1200; // Window width of 1200
const int H = 800; // Window height of 800

float DEGTORAD = 0.017453f; // DEGTORAD constant float

/*************************************************************
 * Description: The Animation class creates and manages animations
 *            using SFML.
 * Type: Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class Animation {
public: // public attributes
    float Frame, speed; // Frame and speed of animation variables
    Sprite sprite; // Sprite to be animated
    std::vector<IntRect> frames; // Vector of frames

    Animation(){} // Default constructor

    /*************************************************************
     * Description: The Animation class constructor takes in multiple
     *            parameters in order to assign certain variables to the
     *            correct values.
     * Type: Constructor
     * Inputs: texture, x, y, width, height, count, and speed variables
     * Outputs: N/A
     **************************************************************/
    Animation (Texture &t, int x, int y, int w, int h, int count, float Speed) {
        Frame = 0; // set Frame variable to 0
        speed = Speed; // set speed variable to Speed

        for (int i=0;i<count;i++) // for i < count...
            frames.push_back( IntRect(x+i*w, y, w, h)  ); // add the IntRect to the frames vector
        sprite.setTexture(t); // set the texture of the sprite
        sprite.setOrigin(w/2,h/2); // set the origin of the sprite
        sprite.setTextureRect(frames[0]); // set the texture rectangle of the sprite
    }

    /*************************************************************
     * Description: The update function updates the animation by adding
     *            speed to the Frame variable and then setting the
     *            texture rectangle of the sprite to the IntRect corresponding
     *            to the new Frame variable
     * Type: Function
     * Inputs: N/A
     * Outputs: N/A
     **************************************************************/
    void update() {
        Frame += speed; // add speed to the Frame variable
        int n = frames.size(); // get the size of the frames vector and assign it to n
        if (Frame >= n) { // if Frame >= n...
            Frame -= n; // subtract n from the Frame variable
        }
        if (n > 0) { // if n > 0...
            // set the texture rectangle of the sprite to the frames vector at the Frame variable
            sprite.setTextureRect(frames[int(Frame)]);
        }
    }


    /*************************************************************
     * Description: The bool function returns true if the animation
     *            is at the end of the frames vector.
     * Type: Function
     * Inputs: N/A
     * Outputs: boolean
     **************************************************************/
    bool isEnd() {
        return Frame + speed >= frames.size(); // return true if the Frame + speed >= frames.size()
    }
};

/*************************************************************
 * Description: The Entity class creates and manages entities
 *            in the game like the location, angle, and velocity
 *            of the entity.
 * Type: Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class Entity {
public: // public attributes
    float x,y,dx,dy,R,angle; // x, y, dx, dy, R, and angle float variables
    bool life; // life boolean variable
    std::string name; // name string variable
    Animation anim; // animation object

/*************************************************************
 * Description: The Entity class constructor sets the life
 *            variable equal 1.
 * Type: Constructor
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
    Entity() {
        life=1; // set the life variable equal to 1
    }

/*************************************************************
 * Description: The settings function sets the x, y, R, and
 *            angle variables equal to the inputted values.
 * Type: Function
 * Inputs: alias a object and x, y, R, and angle variables
 * Outputs: N/A
 **************************************************************/
    void settings(Animation &a,int X,int Y,float Angle=0,int radius=1) {
        anim = a; // set the animation object equal to the inputted animation object
        x=X; y=Y; // set the x and y variables equal to the inputted X and Y values
        angle = Angle; // set the angle variable equal to the inputted angle value
        R = radius; // set the R variable equal to the inputted radius value
    }

    virtual void update() {}; // a backup update function

/*************************************************************
 * Description: The draw function sets the defualt position and
 *            rotation and sets the defualt color and draws the
 *            entity.
 * Type: Function
 * Inputs: the app's window object
 * Outputs: N/A
 **************************************************************/
    void draw(RenderWindow &app) {
        anim.sprite.setPosition(x,y);
        anim.sprite.setRotation(angle+90);
        app.draw(anim.sprite);

        CircleShape circle(R);
        circle.setFillColor(Color(255,0,0,170));
        circle.setPosition(x,y);
        circle.setOrigin(R,R);
        //app.draw(circle);
    }

/*************************************************************
 * Description: The Entity class destructor deletes entity from
 *            the game.
 * Type: Destructor
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
    virtual ~Entity(){}; // Entity destructor
};

/*************************************************************
 * Description: The Entity-inherited asteroid class creates and
 *            updates the asteroid entity.
 * Type: Inherited Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class asteroid: public Entity {
public: // public attributes
    asteroid() {
        dx=rand()%8-4; // set the dx variable equal to a random number between -4 and 4
        dy=rand()%8-4; // set the dy variable equal to a random number between -4 and 4
        name="asteroid"; // set the name variable equal to "asteroid"
        astrCount++; // increment the asteroid count up 1
    }

/*************************************************************
 * Description: The update function adds dx and dy to the position
 *            x and y coordinates. It also checks to see if the
 *            position of the asteroid is out of the screen. If
 *            it is, it resets the position to the opposite side
 *            of the screen.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
    void update() {
        x+=dx; // add dx to the x coordinate
        y+=dy; // add dy to the y coordinate
        /* check to see if the ufo is out of the screen and if it
            is, delete the sprite */
        if (x>W) {
            x=0;
        }
        if (x<0) {
            x=W;
        }
        if (y>H) {
            y=0;
        }
        if (y<0) {
            y=H;
        }
    }

    ~asteroid() { // asteroid destructor
        --astrCount; // subtract astroid count
    }

    static int astrCount; // astroid count number
};
int asteroid::astrCount = 0; // astroid count number outside class


/*************************************************************
 * Description: The Entity-inherited bullet class creates and
 *            updates the bullet's name and position.
 * Type: Inherited Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class bullet: public Entity {
public: // public attributes

    /*************************************************************
     * Description: The bullet class constructor sets the name variable
     *            to "bullet".
     * Type: Constructor
     * Inputs: N/A
     * Outputs: N/A
     **************************************************************/
    bullet() {
        name="bullet"; // set the name to bullet
    }

/*************************************************************
 * Description: The update function updates the bullet by adding
 *            the dx and dy values to the x and y variables and updating
 *            the life and dx/dy variables.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
    void  update() {
        dx=cos(angle*DEGTORAD)*6; // set the dx variable equal to the cosine of the angle multiplied by 6
        dy=sin(angle*DEGTORAD)*6; // set the dy variable equal to the sine of the angle multiplied by 6
        // angle+=rand()%6-3;
        x+=dx; // add dx to the x variable
        y+=dy; // add dy to the y variable

        if (x>W || x<0 || y>H || y<0) { // if x>width or x<0 or y>height or y<0...
            life=0; // set the life variable equal to 0
        }
    }
};

/*************************************************************
 * Description: The Entity-inherited player class creates and
 *            updates the name variable to "player" and sets
 *            the logic behind every movement and animation of
 *            the player ship.
 * Type: Inherited Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class player: public Entity {
public: // public attributes
    bool thrust; // thrust variable

    player() { // player constructor
        name="player"; // set the name to player
    }

    void update() {
        if (thrust){ // if thrust is true...
            dx+=cos(angle*DEGTORAD)*0.2; // set the dx variable equal to the cosine of the angle multiplied by 0.2
            dy+=sin(angle*DEGTORAD)*0.2; } // set the dy variable equal to the sine of the angle multiplied by 0.2
        else { // else...
            dx*=0.99; // add 0.99 to the dx variable
            dy*=0.99; // add 0.99 to the dy variable
        }

        int maxSpeed=15; // set the maxSpeed variable equal to 15
        float speed = sqrt(dx*dx+dy*dy); // set the speed variable equal to the square root of (dx^2 + dy^2)
        if (speed>maxSpeed){ // if speed is greater than maxSpeed...
            dx *= maxSpeed/speed; // set the dx variable equal to the maxSpeed divided by speed
            dy *= maxSpeed/speed; // set the dy variable equal to the maxSpeed divided by speed
        }

        x+=dx; // add dx to the x variable
        y+=dy; // add dy to the y variable

        /* check to see if the asteroid is out of the screen and if it
          is, reset the position to the opposite side of the screen */
        if (x>W) {
            x=0;
        }
        if (x<0) {
            x=W;
        }
        if (y>H) {
            y=0;
        }
        if (y<0) {
            y=H;
        }
    }

};

class ufo: public Entity { // ufo class
public: // public attributes
    ufo() { // ufo constructor
        name="ufo"; // set name to ufo
        x = 0; // set x to 0
        y = rand()%H; // set y to random number
        dx = 3; // set the dx variable to 3
        dy = 0; // set the dy variable to 0
    }

    void update() { // update function
        x+=dx; // add dx to the x variable
        y+=dy; // add dy to the y variable

        /* check to see if the ufo is out of the screen and if it
          is, set the life of it to 0 */
        if ((x>W) || (x<0) || (y>H) || (y<0)) { // if ufo is out of the screen...
            life=0; // set the life of the ufo to 0/false
        }
    }

};

/*************************************************************
 * Description: The isCollide function checks to see if the
 *              two entities are colliding.
 * Type: Function
 * Inputs: address of an entity object and address of another entity object
 * Outputs: boolean of whether the two entities are colliding or not
 **************************************************************/
bool isCollide(Entity *a,Entity *b) {
    // return true if the distance between the two entities is less than the sum of their radii
    return (b->x - a->x)*(b->x - a->x)+
           (b->y - a->y)*(b->y - a->y)<
           (a->R + b->R)*(a->R + b->R);
}

/*************************************************************
 * Description: The main function sets up the game and starts the game loop.
 *            It also sets up the window and creates the sprites.
 * Type: Main Function
 * Inputs: N/A
 * Outputs: the game and all of the components of the game onto a new window
 **************************************************************/
int main() {
    srand(time(0)); // initialize random seed

    int ufoCounter; // counter for ufo

    String gameState = "playGame"; // game state defualt is set to playGame

    int score = 0; // set defualt score to 0
    int lives = 5; // set defualt lives to 5

    RenderWindow app(VideoMode(W, H), "Asteroids!"); // create the window and name it
    app.setFramerateLimit(60); // set the framerate limit to 60 frames per second

    Texture t1, t2, t3, t4, t5, t6, t7, t8; // create the texture objects
    SoundBuffer buffer1, buffer2, buffer3; // create the SoundBuffer buffer1

    Font font; // create the font object

    t1.loadFromFile("images/spaceship.png"); // assign t1 object to the spaceship image
    t2.loadFromFile("images/background.jpg"); // assign t2 object to the background image
    t3.loadFromFile("images/explosions/type_C.png"); // assign t3 object to second explosion image
    t4.loadFromFile("images/rock.png"); // assign t4 object to the rock image
    t5.loadFromFile("images/fire_blue.png"); // assign t5 object to the blue fire image
    t6.loadFromFile("images/rock_small.png"); // assign t6 object to the small rock image
    t7.loadFromFile("images/explosions/type_B.png"); // assign t7 object to first explosion image
    t8.loadFromFile("images/ufo.png"); // assign t8 object to the ufo image
    // image was uploaded by smalllikeart to https://www.flaticon.com/free-icon/ufo_3823776?term=ufo&page=9&position=10&origin=search&related_id=3823776
    buffer1.loadFromFile("sounds/ufoSound.flac"); // assign buffer1 object to the ufo sound
    // sound was created by Victor_Natas and uploaded to https://freesound.org/people/Victor_Natas/sounds/653280/?
    font.loadFromFile("fonts/font.ttf"); // assign font object to the font
    // font was created by Typodermic Fonts and uploaded to https://www.1001freefonts.com/karmafuture.font
    buffer2.loadFromFile("sounds/bulletSound.flac"); // assign buffer2 object to the bullet sound
    // sound was created by cabled_mess and uploaded to https://freesound.org/people/cabled_mess/sounds/335034/
    buffer3.loadFromFile("sounds/explosionSound.flac"); // assign buffer3 object to the explosion sound
    // sound was created by SamsterBirdies and uploaded to https://freesound.org/people/SamsterBirdies/sounds/591998/

    t1.setSmooth(true); // set smoothness of spaceship object to true
    t2.setSmooth(true); // set smoothness of background object to true

    Sprite background(t2); // set the background as the background object

    // set the explosion animation to the explosion object with correct frames
    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);

    // set the rock animation to the rock object with correct frames
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);

    // set the small rock animation to the small rock object with correct frames
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);

    // set the bullet animation to the bullet object with correct frames
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);

    // set the second explosion animation to the second explosion object with correct frames
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);

    // set the player animation to the player object with correct frames
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);

    // set the ship's explosion animation to the ship explosion object with correct frames
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);

    // set the ufo animation to the ufo object
    Animation sUfo(t8, 0, 0, 77, 53, 1, 0);

    /* Assigning sounds to correct objects */
    Sound ufoSound; // ufo
    ufoSound.setBuffer(buffer1);
    Sound bulletSound; // bullet
    bulletSound.setBuffer(buffer2);
    Sound explosionSound; // explosion
    explosionSound.setBuffer(buffer3);

    /* Score text */
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score:");
    scoreText.setCharacterSize(25);
    scoreText.setFillColor(::Color::White);
    scoreText.setStyle(Text::Bold | Text::Underlined);
    scoreText.setPosition(0, 10);

    Text actualScore;
    actualScore.setFont(font);
    actualScore.setString("0");
    actualScore.setCharacterSize(18);
    actualScore.setFillColor(::Color::White);
    actualScore.setPosition(0, 40);

    /* Lives text */
    Text livesText;
    livesText.setFont(font);
    livesText.setString("Lives:");
    livesText.setCharacterSize(25);
    livesText.setFillColor(::Color::White);
    livesText.setStyle(Text::Bold | Text::Underlined);
    livesText.setPosition(100, 10);

    Text actualLives;
    actualLives.setFont(font);
    actualLives.setString("5");
    actualLives.setCharacterSize(18);
    actualLives.setFillColor(::Color::White);
    actualLives.setPosition(100, 40);

    /* Game over text */
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(55);
    gameOverText.setFillColor(::Color::Red);
    gameOverText.setStyle(Text::Bold | Text::Underlined);
    gameOverText.setPosition(450, 350);

    std::list<Entity *> entities; // create the list of entities

    for (int i = 0; i < 15; i++) { // for index of less than 15...
        asteroid *a = new asteroid(); // create an asteroid address object that also allocates memory for the asteroid
        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25); // set the settings of the asteroid
        entities.push_back(a); // add the asteroid to the list of entities
    }
    player *p = new player(); // create a player address object that also allocates memory for the player
    p->settings(sPlayer, 200, 200, 0, 20); // set the settings of the player
    entities.push_back(p); // add the player to the list of entities

    /////main loop/////
    while (app.isOpen()) { // while the window is open...

        Event event; // create an event object
        while (app.pollEvent(event)) { // while there are events to process...
            // if the window is closed or the escape key is pressed...
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
                app.close(); // close the window and end the program
            }
            if (event.type == Event::KeyPressed) { // if a key is pressed...
                if (event.key.code == Keyboard::Space) { // if the space key is pressed...
                    bullet *b = new bullet(); // create a bullet address object that also allocates memory for the bullet
                    b->settings(sBullet, p->x, p->y, p->angle, 10); // set the settings of the bullet
                    entities.push_back(b); // add the bullet to the list of entities
                    bulletSound.play();
                }
            }
        }
        if (gameState == "playGame" ) {
            if (Keyboard::isKeyPressed(Keyboard::Right)) { // if the right arrow key is pressed...
                p->angle += 3; // add 3 to the angle variable
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)) { // if the left arrow key is pressed...
                p->angle -= 3; // subtract 3 from the angle variable
            }

            if (Keyboard::isKeyPressed(Keyboard::Up)) { // if the up arrow key is pressed...
                p->thrust = true; // set the thrust variable to true
            } else { // else...
                p->thrust = false; // set the thrust variable to false
            }

            for (auto a: entities) { // when does it end???
                for (auto b: entities) { // for each entity in the list of entities...
                    if (a->name == "asteroid" &&
                        b->name == "bullet") { // if the two entities are asteroids and bullets...
                        if (isCollide(a, b)) { // if the two entities are colliding...
                            a->life = false; // set the life variable of the asteroid to false
                            b->life = false; // set the life variable of the bullet to false

                            Entity *e = new Entity(); // create an entity address object that also allocates memory for the entity
                            e->settings(sExplosion, a->x, a->y); // set the settings of the entity
                            e->name = "explosion"; // set the name of the entity to "explosion"
                            entities.push_back(e); // add the entity to the list of entities

                            explosionSound.play(); // play explosion sound

                            score += 15; // add 15 to score
                            actualScore.setString(std::to_string(score)); // set actualScore string to score

                            for (int i = 0; i < 2; i++) { // for index of less than 2...
                                if (a->R == 15) continue; // if the radius of the asteroid is 15, continue
                                Entity *e = new asteroid(); // create an entity address object that also allocates memory for the asteroid
                                e->settings(sRock_small, a->x, a->y, rand() % 360,
                                            15); // set the settings of the asteroid
                                entities.push_back(e); // add the asteroid to the list of entities
                            }

                        }
                    }
                    if (a->name == "player" &&
                        b->name == "asteroid") { // if the two entities are player and asteroid...
                        if (isCollide(a, b)) { // if the two entities are colliding...
                            b->life = false; // set the life variable of the asteroid to false

                            Entity *e = new Entity(); // create an entity address object that also allocates memory for the entity
                            e->settings(sExplosion_ship, a->x, a->y); // set the settings of the entity
                            e->name = "explosion"; // set the name of the entity to "explosion"
                            entities.push_back(e); // add the entity to the list of entities

                            explosionSound.play(); // play explosion sound

                            score -= 10; // minus 15 from the score
                            actualScore.setString(std::to_string(score)); // set the score string to score int

                            lives -= 1; // minus 1 life
                            actualLives.setString(std::to_string(lives)); // set lives string to lives int

                            p->settings(sPlayer, W / 2, H / 2, 0, 20); // set the settings of the player
                            p->dx = 0; // set the speed of the player to 0
                            p->dy = 0; // set the speed of the player to 0
                        }
                    }

                    if (a->name == "ufo" && b->name == "player") { // if the two entities are player and asteroid...
                        if (isCollide(a, b)) { // if the two entities are colliding...
                            a->life = false; // set the life variable of the asteroid to false

                            Entity *e = new Entity(); // create an entity address object that also allocates memory for the entity
                            e->settings(sExplosion_ship, a->x, a->y); // set the settings of the entity
                            e->name = "explosion"; // set the name of the entity to "explosion"
                            entities.push_back(e); // add the entity to the list of entities

                            explosionSound.play(); // play explosion sound

                            score -= 20; // minus 20 points from score
                            actualScore.setString(std::to_string(score)); // set score string to score int

                            lives -= 1; // minus 1 life
                            actualLives.setString(std::to_string(lives)); // set lives string to lives int

                            p->settings(sPlayer, W / 2, H / 2, 0, 20); // set the settings of the player
                            p->dx = 0; // set the speed of the player to 0
                            p->dy = 0; // set the speed of the player to 0
                        }
                    }

                    if (a->name == "ufo" && b->name == "bullet") { // if the two entities are player and asteroid...
                        if (isCollide(a, b)) { // if the two entities are colliding...
                            a->life = false; // set the life variable of the ufo to false
                            b->life = false; // set the life variable of the asteroid to false

                            Entity *e = new Entity(); // create an entity address object that also allocates memory for the entity
                            e->settings(sExplosion_ship, a->x, a->y); // set the settings of the entity
                            e->name = "explosion"; // set the name of the entity to "explosion"
                            entities.push_back(e); // add the entity to the list of entities

                            explosionSound.play(); // play explosion sound

                            score += 25; // add 25 to the score
                            actualScore.setString(std::to_string(score)); // set score string to score int

                            if (lives < 5) { // if lives are less than 3...
                                lives += 1; // add 1 to lives
                                actualLives.setString(std::to_string(lives)); // set lives string to lives int
                            }
                        }
                    }
                }
            }

            if (p->thrust) { // if the thrust variable is true...
                p->anim = sPlayer_go; // set the animation to the player animation
            } else { // else...
                p->anim = sPlayer; // set the animation to the player animation
            }


            for (auto e: entities) { // for each entity in the list of entities...
                if (e->name == "explosion") { // if the entity is an explosion...
                    if (e->anim.isEnd()) { // if the explosion animation has ended...
                        e->life = 0; // set the life variable of the explosion to false
                    }
                }
            }

            if (asteroid::astrCount == 0) {
                for (int i = 0; i < 15; i++) { // for index of less than 15...
                    asteroid *a = new asteroid(); // create an asteroid address object that also allocates memory for the asteroid
                    a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25); // set the settings of the asteroid
                    entities.push_back(a); // add the asteroid to the list of entities
                }
            }

            ufoCounter++; // add 1 to ufoCounter
            if (ufoCounter == 800) { // if ufoCounter is 800...
                ufoSound.play(); // play ufo sound
                ufoSound.setLoop(true); // loop the sound

                ufo *u = new ufo(); // create a ufo object that also allocates memory for the ufo
                u->settings(sUfo, 0, rand() % H, -90, 25); // set the settings of the ufo
                entities.push_back(u); // add the ufo to the list of entities

                ufoCounter = 0; // set ufoCounter to 0
            }

            for (auto i = entities.begin(); i != entities.end();) { // for each entity in the list of entities...
                Entity *e = *i; // create an entity address object that also allocates memory for the entity

                e->update(); // update the entity
                e->anim.update(); // update the animation of the entity

                if (e->life == false) { // if the life variable of the entity is false...
                    if (e->name == "ufo") { // if ufo...
                        ufoSound.stop(); // stop ufo sound
                    }
                    i = entities.erase(i); // erase index entity
                    delete e; // remove the entity from the list of entities and delete the entity
                } else { // else...
                    i++; // increment the iterator
                }
            }
            if (lives <= 0) { // if lives are below or equal to 0...
                gameState = "gameOver"; //set gameState to gameOver
            }
        }

        //////draw//////
        app.draw(background); // draw the background

        for (auto i: entities) { // for each entity in the list of entities...
            i->draw(app); // draw the entity
        }

        app.draw(scoreText); // shows the score text
        app.draw(actualScore); // shows the score number
        app.draw(livesText); // shows the lives text
        app.draw(actualLives); // shows the life number

        if (gameState == "gameOver") { // if gameOver is true and playGame false...
            app.draw(gameOverText);
            ufoSound.stop(); // stop ufo sound
            if (Keyboard::isKeyPressed(Keyboard::R)) { // if the R key is pressed...
                score = 0; // set the score to 0
                lives = 5; // set the lives to 3
                gameState = "playGame"; // set gameState to gameOver
                actualScore.setString("0"); // set the actual score to 0
                actualLives.setString("5"); // set the actual life number to 5
            }
        }

        app.display(); // display the window
    }
    return 0; // quit the program
}