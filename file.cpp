// library files
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

// function declarations
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void erasehero();
void eraseEnemy();
void eraseEnemy2();
void eraseEnemy3();
void eraseEnemy4();
void eraseEnemy5();
void makeBulletInactive(int x);
int submenu();
void eraseBullet(int x, int y);
void moveBullet();
void maze();
void printScore(int score);
void printfScore(int score);
void addScore();
void reduceEnemy3Health();
void reduceEnemy2Health();
void reduceEnemy1Health();
void reduceEnemy4Health();
void reduceEnemy5Health();

using namespace std;

// Global Variables
int option1;

int option2;
char option3;
string enemy1Direction = "Up";
string enemy2Direction = "Down";
string enemy3Direction = "Down";
string enemy4Direction = "Up";
string enemy5Direction = "Up";
bool moveEnemyOne = true;
bool moveEnemyTwo = true;
bool moveEnemyThree = true;
bool moveEnemyFour = true;
bool moveEnemyFive = true;

bool gameRunning = true;

// lives and healing
int enemy1Healing = 0;
int enemy2Healing = 0;
int enemy3Healing = 0;
int enemy4Healing = 0;
int enemy5Healing = 0;

int livesCount = 3;
int livesX = 80;
int livesY = 10;

int enemy1Heal = 20;
int enemy2Heal = 40;
int enemy3Heal = 200;
int enemy4Heal = 70;
int enemy5Heal = 100;

// hero character
char hero1[3] = {' ', 30, ' '};
char righthand = 169;
char lefthand = 170;
char hero2[3] = {righthand, 1, lefthand};
char legs = 234;
char hero3[3] = {' ', legs, ' '};

// Wining line Characters
char linee = 176;
char wining[6] = {linee, linee, linee, linee, linee, linee};
// wining coordinates
int winingX = 67;
int winingY = 43;

// enemy1 characters
char head = 148;
char enemy1[1] = {head};
char pait = 30;
char enemy2[1] = {pait};
char legsenemy = 19;
char enemy3[1] = {legsenemy};

// enemy2 characters
char head2 = 148;
char enemy21[1] = {head2};
char pait2 = 30;
char enemy22[1] = {pait2};
char legsenemy2 = 19;
char enemy23[1] = {legsenemy2};

// enemy3 characters
char head3 = 148;
char enemy31[1] = {head3};
char pait3 = 30;
char enemy32[1] = {pait3};
char legsenemy3 = 19;
char enemy33[1] = {legsenemy3};

// enemy4 characters
char head4 = 148;
char enemy41[1] = {head4};
char pait4 = 30;
char enemy42[1] = {pait4};
char legsenemy4 = 19;
char enemy43[1] = {legsenemy4};

// enemy5 characters
char head5 = 148;
char enemy51[1] = {head5};
char pait5 = 30;
char enemy52[1] = {pait5};
char legsenemy5 = 19;
char enemy53[1] = {legsenemy5};

// hero coordinates
int heroX = 1;
int heroY = 1;

// enemy coordinates at upper right
int enemy1X = 65;
int enemy1Y = 11;

// enemy coordinates at second right
int enemy2X = 65;
int enemy2Y = 15;

// enemy coordinates at third right
int enemy3X = 48; // 50
int enemy3Y = 30;

// enemy coordinates at third middle
int enemy5X = 32; // 32
int enemy5Y = 37;

// enemy coordinates at second left
int enemy4X = 24; // 17
int enemy4Y = 15;

// hero's bullets
int choice;
int bulletCount = 0;
int bulletX[1000];
int bulletY[1000];
bool isBulletActive[1000];

// score variables
int score = 0;

/*PROGRAM
STATEMENTS*/

void generateColors(int k)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printhero()
{
    generateColors(3);
    gotoxy(heroX, heroY);
    for (int i = 0; i < 3; i++)
    {
        cout << hero1[i];
    }
    cout << endl;
    gotoxy(heroX, heroY + 1);
    for (int i = 0; i < 3; i++)
    {

        cout << hero2[i];
    }
    cout << endl;
    gotoxy(heroX, heroY + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << hero3[i];
    }

    generateColors(4);
}

void printenemy()
{
    generateColors(6);
    int i = 0;
    gotoxy(enemy1X, enemy1Y);

    cout << enemy1[i];

    gotoxy(enemy1X, enemy1Y + 1);

    cout << enemy2[i];

    gotoxy(enemy1X, enemy1Y + 2);

    cout << enemy3[i];
}
void printenemy2()
{
    generateColors(1);
    int i = 0;
    gotoxy(enemy2X, enemy2Y);

    cout << enemy21[i];

    gotoxy(enemy2X, enemy2Y + 1);

    cout << enemy22[i];

    gotoxy(enemy2X, enemy2Y + 2);

    cout << enemy23[i];
}

void printenemy3()
{
    generateColors(4);
    int i = 0;
    gotoxy(enemy3X, enemy3Y);

    cout << enemy31[i];

    gotoxy(enemy3X, enemy3Y + 1);

    cout << enemy32[i];

    gotoxy(enemy3X, enemy3Y + 2);

    cout << enemy33[i];
}

void printenemy4()
{
    generateColors(2);
    int i = 0;
    gotoxy(enemy4X, enemy4Y);

    cout << enemy41[i];

    gotoxy(enemy4X, enemy4Y + 1);

    cout << enemy42[i];

    gotoxy(enemy4X, enemy4Y + 2);

    cout << enemy43[i];
}

void printenemy5()
{
    generateColors(9);
    int i = 0;
    gotoxy(enemy5X, enemy5Y);

    cout << enemy51[i];

    gotoxy(enemy5X, enemy5Y + 1);

    cout << enemy52[i];

    gotoxy(enemy5X, enemy5Y + 2);

    cout << enemy53[i];
}

void printmaze()
{
    generateColors(7);
    cout << "**************************************************************************" << endl;
    cout << "*                               *                                        *" << endl;
    cout << "*                               *                                        *" << endl;
    cout << "*                               *                                        *" << endl;
    cout << "*                               *                      ********          *" << endl;
    cout << "*   *********************       *                             *          *" << endl;
    cout << "*   *                   *       *                             *          *" << endl;
    cout << "*   *                   *       * *******    *                *          *" << endl;
    cout << "*   *                   *       *            *                           *" << endl;
    cout << "*   *                   *       *            *                           *" << endl;
    cout << "*   ***************     *       *            *                           *" << endl;
    cout << "*                       *                    *                           *" << endl;
    cout << "*                       *                    *                           *" << endl;
    cout << "*                       *                    *                           *" << endl;
    cout << "*********************************************************************    *" << endl;
    cout << "*                             *                                          *" << endl;
    cout << "*                             *                                          *" << endl;
    cout << "*                             *                                          *" << endl;
    cout << "*        ********             *                                          *" << endl;
    cout << "*               *             *                      *                   *" << endl;
    cout << "*               *             *************          *                   *" << endl;
    cout << "*     ****************                               *                   *" << endl;
    cout << "*                    *                               *                   *" << endl;
    cout << "*                    *                               *                   *" << endl;
    cout << "*                    *                               *                   *" << endl;
    cout << "*                    *                               *     *******       *" << endl;
    cout << "*                    *                               *     *     *       *" << endl;
    cout << "*                    *                               *     *     *       *" << endl;
    cout << "*     ********************************************************************" << endl;
    cout << "*                    **                      **                          *" << endl;
    cout << "*                     **                    **                           *" << endl;
    cout << "*                      **                  **                            *" << endl;
    cout << "*                        **              **          **                  *" << endl;
    cout << "* **************           **          **          **        *************" << endl;
    cout << "*                            **      **              **       *          *" << endl;
    cout << "*                                                      **      *         *" << endl;
    cout << "*                                                    **                  *" << endl;
    cout << "*                                                  **                    *" << endl;
    cout << "*                                                    **                  *" << endl;
    cout << "*                                                      **                *" << endl;
    cout << "*******************************************************************      *" << endl;
    cout << "                                                                  *      *" << endl;
    cout << "                                                                  *      *" << endl;
    cout << "                                                                           " << endl;
}

void erasehero()
{
    gotoxy(heroX, heroY);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    gotoxy(heroX, heroY + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    gotoxy(heroX, heroY + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
}
void moveheroleft()
{

    char next = getCharAtxy(heroX - 1, heroY);

    if (next == ' ')
    {
        erasehero();
        heroX = heroX - 1;
        gotoxy(heroX, heroY);
        printhero();

        if (heroX - 1 == 'p' || heroY == 'p')
        {
            addScore();
        }
    }
}
void moveheroRight()
{

    char next = getCharAtxy(heroX + 3, heroY);
    if (next == ' ')
    {
        erasehero();
        heroX = heroX + 1;
        gotoxy(heroX, heroY);
        printhero();
        if (heroX + 1 == 'p' || heroY == 'p')
        {
            addScore();
        }
    }
}
void moveheroUp()
{
    char next = getCharAtxy(heroX, heroY - 1);
    if (next == ' ')
    {
        erasehero();
        heroY = heroY - 1;
        gotoxy(heroX, heroY);
        printhero();
        if (heroX == 'p' || heroY - 1 == 'p')

        {
            addScore();
        }
    }
}
void moveheroDown()
{

    char next = getCharAtxy(heroX, heroY + 3);
    if (next == ' ')
    {
        erasehero();
        heroY = heroY + 1;
        gotoxy(heroX, heroY);
        printhero();
        if (heroX == 'p' || heroY + 1 == 'p')
        {
            addScore();
        }
    }
}
char getCharAtxy(short int x, short int y)

{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void moveEnemy1()
{

    if (enemy1Direction == "Up")

    {

        char next = getCharAtxy(enemy1X, enemy1Y - 1);
        if (next == ' ')
        {
            gotoxy(enemy1X, enemy1Y);
            eraseEnemy();
            enemy1Y--;
            gotoxy(enemy1X, enemy1Y);
            printenemy();
        }
        if (next == '*')
        {
            enemy1Direction = "Down";
        }
    }

    if (enemy1Direction == "Down")
    {
        Sleep(100);
        char next = getCharAtxy(enemy1X, enemy1Y + 4);
        if (next == ' ')
        {
            gotoxy(enemy1X, enemy1Y);
            eraseEnemy();
            enemy1Y++;
            gotoxy(enemy1X, enemy1Y);
            printenemy();

            // Sleep(200);
        }
        if (next == '*')
        {
            enemy1Direction = "Up";
        }
    }
}

void moveEnemy2()
{

    if (enemy2Direction == "Up")
    {

        char next = getCharAtxy(enemy2X, enemy2Y - 1);
        if (next == ' ')
        {
            gotoxy(enemy2X, enemy2Y);
            eraseEnemy2();
            enemy2Y--;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
        if (next == '*')
        {
            enemy2Direction = "Down";
        }
    }
    if (enemy2Direction == "Down")
    {
        char next = getCharAtxy(enemy2X, enemy2Y + 4);
        if (next == ' ')
        {
            gotoxy(enemy2X, enemy2Y);
            eraseEnemy2();
            enemy2Y++;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
        if (next == '*')
        {
            enemy2Direction = "Up";
        }
    }
}

void moveEnemy3()
{

    if (enemy3Direction == "Up")
    {
        char next = getCharAtxy(enemy3X, enemy3Y - 1);
        if (next == ' ')
        {
            gotoxy(enemy3X, enemy3Y);
            eraseEnemy3();
            enemy3Y--;
            gotoxy(enemy3X, enemy3Y);
            printenemy3();
        }
        if (next == '*')
        {
            enemy3Direction = "Down";
        }
    }
    if (enemy3Direction == "Down")
    {
        char next = getCharAtxy(enemy3X, enemy3Y + 4);
        if (next == ' ')
        {
            gotoxy(enemy3X, enemy3Y);
            eraseEnemy3();
            enemy3Y++;
            gotoxy(enemy3X, enemy3Y);
            printenemy3();
        }
        if (next == '*')
        {
            enemy3Direction = "Up";
        }
    }
}

void moveEnemy4()
{

    if (enemy4Direction == "Up")
    {
        char next = getCharAtxy(enemy4X, enemy4Y - 1);
        if (next == ' ')
        {
            gotoxy(enemy4X, enemy4Y);
            eraseEnemy4();
            enemy4Y--;
            gotoxy(enemy4X, enemy4Y);
            printenemy4();
        }
        if (next == '*')
        {
            enemy4Direction = "Down";
        }
    }
    if (enemy4Direction == "Down")
    {
        char next = getCharAtxy(enemy4X, enemy4Y + 4);
        if (next == ' ')
        {
            gotoxy(enemy4X, enemy4Y);
            eraseEnemy4();
            enemy4Y++;
            gotoxy(enemy4X, enemy4Y);
            printenemy4();
        }
        if (next == '*')
        {
            enemy4Direction = "Up";
        }
    }
}

void moveEnemy5()
{

    if (enemy5Direction == "Up")
    {
        char next = getCharAtxy(enemy5X, enemy5Y - 1);
        if (next == ' ')
        {
            gotoxy(enemy5X, enemy5Y);
            eraseEnemy5();
            enemy5Y--;
            gotoxy(enemy5X, enemy5Y);
            printenemy5();
        }
        if (next == '*')
        {
            enemy5Direction = "Down";
        }
    }
    if (enemy5Direction == "Down")
    {
        char next = getCharAtxy(enemy5X, enemy5Y + 4);
        if (next == ' ')
        {
            gotoxy(enemy5X, enemy5Y);
            eraseEnemy5();
            enemy5Y++;
            gotoxy(enemy5X, enemy5Y);
            printenemy5();
        }
        if (next == '*')
        {
            enemy5Direction = "Up";
        }
    }
}

void eraseEnemy()
{
    gotoxy(enemy1X, enemy1Y);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 1);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 2);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
}

void eraseEnemy2()
{
    gotoxy(enemy2X, enemy2Y);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 1);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 2);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
}

void eraseEnemy3()
{
    gotoxy(enemy3X, enemy3Y);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy3X, enemy3Y + 1);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy3X, enemy3Y + 2);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
}

void eraseEnemy4()
{
    gotoxy(enemy4X, enemy4Y);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy4X, enemy4Y + 1);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy4X, enemy4Y + 2);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
}

void eraseEnemy5()
{
    gotoxy(enemy5X, enemy5Y);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy5X, enemy5Y + 1);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
    gotoxy(enemy5X, enemy5Y + 2);
    for (int i = 0; i < 1; i++)
    {
        cout << " ";
    }
}
void generateBullet()
{

    bulletX[bulletCount] = heroX + 3;
    bulletY[bulletCount] = heroY + 1;
    isBulletActive[bulletCount] = true;
    gotoxy(heroX + 3, heroY + 1);
    cout << ".";
    bulletCount++;
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    generateColors(6);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void makeBulletInactive(int x)
{
    isBulletActive[x] = false;
}
int headermenu()
{

    generateColors(9);
    system("Cls");
    cout << "__________________________________________________________________________________" << endl;
    cout << " __            _      _        _   _          __        _           _     _   _    " << endl;
    cout << "|  |   ___ ___| |_   |_|___   | |_| |_ ___   |  |   ___| |_ _ _ ___|_|___| |_| |_ " << endl;
    cout << "|  |__| . |_ -|  _|  | |   |  |  _|   | -_|  |  |__| .'| . | | |  _| |   |  _|   |" << endl;
    cout << "|_____|___|___|_|    |_|_|_|  |_| |_|_|___|  |_____|__,|___|_  |_| |_|_|_|_| |_|_|" << endl;
    cout << "                                                           |___|                   " << endl;
    cout << "_________________________________________________________________________________" << endl;

    generateColors(6);
    cout
        << " _____________________" << endl;
    cout << " 1. START           " << endl;
    cout << " 2. OPTION          " << endl;
    cout << " 3. Exit            " << endl;
    cout << " ENTER ANY OPTION:  " << endl;
    cin >> option1;

    system("Cls");
    return option1;
}

// void showenemy1Healingth()
// {
//     if (enemy1Healing <= 100 && enemy1Healing >= 0)
//     {
//         gotoxy(enemyHealthX, enemyHealthY);
//         cout << "Enemy Health: ";
//         char healthBox = 254;
//         gotoxy(enemyHealthX + 14, enemyHealthY);
//         cout << enemy1Healing;
//     }
// }
void showLives()
{
    char live = 3;
    gotoxy(livesX, livesY);
    cout << "Lives Remaining: ";
    gotoxy(livesX + 17, livesY);
    generateColors(4);
    for (int x = 0; x < livesCount; x++)
    {
        cout << live;
    }
    generateColors(2);
}
int submenu()
{
    int continuE, continue1;
    generateColors(9);
    cout << "    _____   _____  _______  _______  _____   _     _   _____  " << endl;
    cout << "   (_____) (_____)(__ _ __)(_______)(_____) (_)   (_) (_____) " << endl;
    cout << "  (_)   (_)(_)__(_)  (_)      (_)  (_)   (_)(__)_ (_)(_)___   " << endl;
    cout << "  (_)   (_)(_____)   (_)      (_)  (_)   (_)(_)(_)(_)  (___)_" << endl;
    cout << "  (_)___(_)(_)       (_)    __(_)__(_)___(_)(_)  (__)  ____(_)" << endl;
    cout << "   (_____) (_)       (_)   (_______)(_____) (_)   (_) (_____) " << endl;

    generateColors(6);

    cout << "__________________" << endl;
    cout << "1.KEYS" << endl;
    cout << "2.INSTRUCTIONS" << endl;
    cout << "3.EXIT" << endl;
    cout << "ENTER ANY OPTION: ";
    cin >> option2;
    if (option2 == 1)
    {
        generateColors(9);
        system("Cls");
        cout << "__________________________________________" << endl;
        cout << "       _    _   ______   _     _   _____  " << endl;
        cout << "      (_)  (_) (______) (_)   (_) (_____) " << endl;
        cout << "      (_)_(_)  (_)__     (_)_(_) (_)___   " << endl;
        cout << "      (____)   (____)      (_)     (___)_ " << endl;
        cout << "      (_) (_)  (_)____     (_)     ____(_)" << endl;
        cout << "      (_)  (_) (______)    (_)    (_____) " << endl;
        cout << "__________________________________________" << endl;
        generateColors(6);

        cout << "__________________________" << endl;
        cout << "1.UP        GO UP" << endl;
        cout << "2.DOWN      GO DOWN" << endl;
        cout << "3.RIGHT     GO RIGHT" << endl;
        cout << "4.LEFT      GO LEFT" << endl;
        cout << "5.SPACE     SHOOT BULLETS" << endl;
        cout << "6.ESC       END GAME" << endl
             << endl
             << endl;
        cout << "Press 1 to CONTINUE: ";
        cin >> continuE;
        if (continuE == 1)
        {
            return continuE;
        }
    }
    if (option2 == 2)
    {
        generateColors(9);
        system("Cls");
        cout << "____________________________________________________________________________________________" << endl;

        cout << " _______  _     _   _____  _______  _____   _     _    ___   _______  _______  _____   _     _       " << endl;
        cout << "(_______)(_)   (_) (_____)(__ _ __)(_____) (_)   (_) _(___)_(__ _ __)(_______)(_____) (_)   (_) ____ " << endl;
        cout << "   (_)   (__)_ (_)(_)___     (_)   (_)__(_)(_)   (_)(_)   (_)  (_)      (_)  (_)   (_)(__)_ (_)(____)" << endl;
        cout << "   (_)   (_)(_)(_)  (___)_   (_)   (_____) (_)   (_)(_)    _   (_)      (_)  (_)   (_)(_)(_)(_)(_)__ " << endl;
        cout << " __(_)__ (_)  (__)  ____(_)  (_)   ( ) ( ) (_)___(_)(_)___(_)  (_)    __(_)__(_)___(_)(_)  (__) _(__)" << endl;
        cout << "(_______)(_)   (_) (_____)   (_)   (_)  (_) (_____)   (___)    (_)   (_______)(_____) (_)   (_)(____)" << endl;

        cout << "_____________________________________________________________________________________________" << endl;

        generateColors(6);
        cout << "_____________________" << endl;
        cout << "MOVE THE CHARACTER BY ARROW KEYS" << endl;
        cout << "YOU CAN SHOOT THE BULLETS" << endl;
        cout << "GOAL IS TO COLLECT THE REWARD AND MOVE TO THE END OF MAZE" << endl
             << endl
             << endl;
        cout << "Press 1 to CONTINUE: ";
        cin >> continue1;
        if (continue1 == 1)
        {
            return continue1;
        }
    }
    return 0;
}
void addScore()
{
    score = score + 1;
    printfScore(score);
}

void printfScore(int scores)
{
    gotoxy(80, 8);
    generateColors(9);
    cout << "Score:" << score;
}

void printScore(int score)
{
    gotoxy(74, 8);
    cout << "Score:" << score;
}
void changeLives()
{
    if (livesCount >= 0)
    {
        int check = 0;
        char next = getCharAtxy(heroX, heroY);
        char next2 = getCharAtxy(heroX + 3, heroY + 1);
        char next3 = getCharAtxy(heroX + 3, heroY + 3);
        if (next != '.' && next != ' ' && next != '*')
        {
            livesCount--;
            check++;
            erasehero();
            gotoxy(1, 1);
            getCharAtxy(1, 1);

            printhero();
        }
        else if (next2 != '.' && next2 != ' ' && next2 != '*')
        {
            livesCount--;
            check++;
            erasehero();
            gotoxy(1, 1);
            getCharAtxy(1, 1);

            printhero();
        }
        else if (next3 != '.' && next3 != ' ' && next3 != '*')
        {
            livesCount--;
            check++;
            erasehero();
            gotoxy(1, 1);
            getCharAtxy(1, 1);

            printhero();
        }

        if (livesCount < 3)
        {
            gotoxy(livesX + 17, livesY);
            cout << "   ";
            showLives();
            erasehero();
            gotoxy(1, 1);
            getCharAtxy(1, 1);

            printhero();
        }

        if (livesCount == 0)
        {
            gameRunning = false;
            gotoxy(60, 10);
            system("Cls");
            cout << "                                                                   " << endl;
            cout << "                                                                   " << endl;
            cout << "                                                                   " << endl;
            cout << "                                                                   " << endl;
            cout << "              _____ _____ _____ _____    _____ _____ _____ _____ " << endl;
            cout << "             |   __|  _  |     |   __|  |     |  |  |   __| __  |" << endl;
            cout << "             |  |  |     | | | |   __|  |  |  |  |  |   __|    -|" << endl;
            cout << "             |_____|__|__|_|_|_|_____|  |_____|!___/|_____|__|__|" << endl;
        }
    }
}

void reduceEnemy1Health()
{
    enemy1Healing = enemy1Healing + 1;
    if (enemy1Healing == enemy1Heal)
    {
    }
}
void bulletCollisionWithEnemy1()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 2 || bulletY[x] == enemy1Y + 3))
            {
                addScore();
                reduceEnemy1Health();
            }
            if (enemy1X - 1 == bulletX[x] && enemy1Y + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}
void bulletCollisionWithEnemy2()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 2 || bulletY[x] == enemy2Y + 3))
            {
                addScore();
                reduceEnemy2Health();
            }
            if (enemy2X - 1 == bulletX[x] && enemy2Y + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}
void bulletCollisionWithEnemy3()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy3X && (bulletY[x] == enemy3Y || bulletY[x] == enemy3Y + 2 || bulletY[x] == enemy3Y + 3))
            {
                addScore();
                reduceEnemy3Health();
            }
            if (enemy3X - 1 == bulletX[x] && enemy3Y + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}
void bulletCollisionWithEnemy4()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy4X && (bulletY[x] == enemy4Y || bulletY[x] == enemy4Y + 2 || bulletY[x] == enemy4Y + 3))
            {
                addScore();
                reduceEnemy4Health();
            }
            if (enemy4X - 1 == bulletX[x] && enemy4Y + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}
void bulletCollisionWithEnemy5()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy5X && (bulletY[x] == enemy5Y || bulletY[x] == enemy5Y + 2 || bulletY[x] == enemy5Y + 3))
            {
                addScore();
                reduceEnemy5Health();
            }
            if (enemy5X - 1 == bulletX[x] && enemy5Y + 1 == bulletY[x])
            {
                addScore();
            }
        }
    }
}
void reduceEnemy2Health()
{
    enemy2Heal++;
}

void reduceEnemy3Health()
{
    enemy3Heal++;
}

void reduceEnemy4Health()
{
    enemy4Heal++;
}

void reduceEnemy5Health()
{
    enemy5Heal++;
}

void checkenemy1Health()
{
    if (enemy1Healing == 100)
    {
        eraseEnemy();
        moveEnemyOne = false;
    }
}
void printWiningMark()
{
    gotoxy(winingX, winingY);
    for (int i = 0; i < 6; i++)
    {
        cout << wining[i];
    }
}
main()
{
    option1 = headermenu();
    if (option1 == 2)
    {
        submenu();
    }

    if (option1 == 1)
    {
        system("Cls");
        printmaze();
        printWiningMark();
        printhero();
        printenemy();
        printenemy2();
        printenemy3();
        printenemy4();
        printenemy5();

        showLives();
        int scores = 0;
        printfScore(scores);
        while (gameRunning)
        {

            Sleep(100);
            moveEnemy1();
            moveEnemy2();
            moveEnemy3();
            moveEnemy4();
            moveEnemy5();
            changeLives();
            if (GetAsyncKeyState(VK_LEFT))
            {
                moveheroleft();
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                moveheroRight();
            }
            if (GetAsyncKeyState(VK_UP))
            {
                moveheroUp();
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                moveheroDown();
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                generateBullet();
            }
            moveBullet();
            bulletCollisionWithEnemy1();
            bulletCollisionWithEnemy2();
            bulletCollisionWithEnemy3();
            bulletCollisionWithEnemy4();
            bulletCollisionWithEnemy5();

            if (enemy1Healing <= 100)
            {
                checkenemy1Health();
            }
        }
    }
}