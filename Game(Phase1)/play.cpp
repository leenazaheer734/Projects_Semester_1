#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

string setcolor(unsigned short color);
void welcomeScreen();
void load();
string mainmenu();
string optionmenu();
void keysMenu();
void instructionsMenu();
void gameLogo();
void printBorder(char border[][122]);
void storeMaze(char border[][122]);
void loadmaze(char border[][122]);
void gotoxy(int a, int b);
char getCharAtxy(short int x, short int y);

void printHawk(int &hawkX, int &hawkY, char hawk[][7]);
void eraseHawk(int &hawkX, int &hawkY);
void moveHawkRight(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire);
void moveHawkLeft(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire);
void moveHawkUp(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire);
void moveHawkDown(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire);

void printBullet(int x, int y);
void eraseBullet(int x, int y);
void generateBullet(int &hawkX, int &hawkY, int bulletX[], int bulletY[], int &bulletCount);
void moveBullet(int &bulletCount, int bulletX[], int bulletY[]);
void deleteBulletfromarray(int index, int &bulletCount, int bulletX[], int bulletY[]);
void checkdamage(char next, int &playerHealth, int &playerlives, char &enemy2fire, char &enemy3fire);
void checkPlayerHealth(int &hawkX, int &hawkY, int &playerHealth, int &playerlives, char &enemy2fire, char &enemy3fire);

void printChicken1(int &enemy1X, int &enemy1Y, char cruella[][7]);
void eraseChicken1(int &enemy1X, int &enemy1Y);
void moveEnemy1(string &enemy1direction, char &wing2, char &wing1, int &enemy1X, int &enemy1Y, char cruella[][7]);
void bulletcollisionwithEnemy1(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy1X, int &enemy1Y, int &enemy1health);
void Foodscore(char next, int &score);

void printChicken2(int &enemy2X, int &enemy2Y, char zelda[][7]);
void eraseChicken2(int &enemy2X, int &enemy2Y);
void moveChicken2down(int &enemy2X, int &enemy2Y, char zelda[][7]);
void moveChicken2up(int &enemy2X, int &enemy2Y, char zelda[][7]);
void moveChicken2right(int &enemy2X, int &enemy2Y, char zelda[][7]);
void moveChicken2left(int &enemy2X, int &enemy2Y, char zelda[][7]);
void bulletcollisionwithenemy2(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy2X, int &enemy2Y, int &enemy2health);
void randomfood();

void printenemyfire(int x, int y);
void generateenemy1fire(int &enemy1X, int &enemy1Y, int enemy1fireX[], int enemy1fireY[], int &fire1count);
void moveenemy1fire(int &fire1count, int enemy1fireX[], int enemy1fireY[]);
void deletefire1fromarray(int index, int &fire1count, int enemy1fireX[], int enemy1fireY[]);

void generateenemy2fire(int &enemy2X, int &enemy2Y, int &fire2count, int enemy2fireX[], int enemy2fireY[], char &enemy2fire);
void deletefire2fromarray(int index, int &fire2count, int enemy2fireX[], int enemy2fireY[]);
void printenemy2fire(int x, int y);
void moveenemy2fire(int &fire2count, int enemy2fireX[], int enemy2fireY[], char &enemy2fire);

void printChicken3(int &enemy3X, int &enemy3Y, char tiana[][7]);
void eraseChicken3(int &enemy3X, int &enemy3Y);
void generateenemy3fire(int &fire3count, int &enemy3X, int &enemy3Y, int enemy3fireX[], int enemy3fireY[], char &enemy3fire);
void printenemy3fire(int x, int y, char &enemy3fire);
void moveenemy3fire(int enemy3fireX[], int enemy3fireY[], int &fire3count, char &enemy3fire);
void deletefire3fromarray(int index, int enemy3fireX[], int enemy3fireY[], int &fire3count);

void bulletcollisionwithenemy3(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy3X, int &enemy3Y, int &enemy3health);
void moveenemy3up(int &enemy3X, int &enemy3Y, char tiana[][7]);
void moveenemy3down(int &enemy3X, int &enemy3Y, char tiana[][7]);
void moveenemy3right(int &enemy3X, int &enemy3Y, char tiana[][7]);
void moveenemy3left(int &enemy3X, int &enemy3Y, char tiana[][7]);
void moveEnemy3(int &hawkX, int &hawkY, int &enemy3X, int &enemy3Y, char tiana[][7]);
void checkplayercollisionwithenemy(int &hawkX, int &hawkY, int &playerHealth, char &enemy2fire, char &enemy3fire);
void playerenemycollision(char next, int &playerHealth, char &enemy2fire, char &enemy3fire);
void gameoverborder();
void makinggameover(int &score);
void storegameStats(int &tempscore,int &empplayerlive,int &empplayerhealthint , int &tempE1health, int &empE2health,int &empE3health,int &empplayerX,int &empplayerY,int &tempE3X,int &tempE3Y,int &tempE2X,int &tempE2Y,int &tempE1X,int &tempE1Y,int &temptimer);
void movep(int ppX[], int ppY[], int &pcount);
void printpp(int x, int y);
void erasepp(int x, int y);
void poweerup(int ppX[], int ppY[], int &pcount);
void deletePfromarray(int indx, int &pcount, int ppX[], int ppY[]);
string parsedata(string line, int feild);
void loadstats(int &score, int &playerlives, int &playerhealth,int &enemy1health,int &enemy2health,int &enemy3health,int &hawkX, int &hawkY, int enemy3X,int &enemy3Y,int &enemy2X,int &enemy2Y,int &enemy1X,int &enemy1Y,int &timer );
void wingame(int &score);

main()
{
    char border[37][122] = {{'&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '&'},
                            {'&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&', '&'}};
    int hawkX = 15, hawkY = 30;
    char head = 235;
    char tail = 206; // special characters for players
    char mid = 209;
    string choice = "0"; // main menu options choice
    char hawk[4][7] = {{' ', ' ', ' ', head, ' ', ' ', ' '},
                       {'-', '-', '{', 'H', '}', '-', '-'},
                       {' ', '/', '/', mid, '\\', '\\', ' '},
                       {' ', ' ', ' ', tail, ' ', ' ', ' '}};
    int playerHealth = 100; // player health variables
    int playerlives = 3;
    char lifeSymbol = 3;
    int score = 0;
    int bulletCount = 0;
    int bulletX[100];
    int bulletY[100];
    int enemy1X = 20;
    int enemy1Y = 5;
    char face = 157; // enemy1 speial characters
    char wing1 = 174;
    char wing2 = 175;
    char cruella[3][7] = {{wing1, wing1, ' ', face, ' ', wing2, wing2},
                          {' ', wing1, '\\', 'C', '/', wing2, ' '},
                          {' ', ' ', ' ', '?', ' ', ' ', ' '}};
    int timer = 0;
    string enemy1direction = "right";
    int enemy2X = 50,enemy2Y = 19;
    char ztail = 234;
    char zmid = 127;
    char zelda[4][7] = {{' ', ' ', ' ', face, ' ', ' ', ' '},
                        {wing1, wing1, ' ', zmid, ' ', wing2, wing2},
                        {' ', wing1, wing1, 'Z', wing2, wing2, ' '},
                        {' ', ' ', ' ', ztail, ' ', ' ', ' '}};
    char Tmid = 235;
    int enemy3X = 10, enemy3Y = 3;
    char tiana[4][7] = {{' ', ' ', ' ', face, ' ', ' ', ' '},
                        {' ', wing1, wing1, ztail, wing2, wing2, ' '},
                        {wing1, wing1, wing1, 'T', wing2, wing2, wing2},
                        {' ', ' ', ' ', Tmid, ' ', ' ', ' '}};
    int enemy1health = 100;
    int enemy1fireX[100],enemy1fireY[100],enemy2fireX[100],enemy2fireY[100],enemy3fireX[100],enemy3fireY[100];
    int fire1count = 0;
    int fire2count = 0;
    char enemy2fire = 153;
    int enemy2health = 100;
    int fire3count = 0;
    char enemy3fire = 232;
    int enemy3health = 100;
    int ppslower = 0;
    int enemy3slower = 0;
    int enemy2slower = 0;
    int fireslower = 0;
    int foodslower = 0;
    int random;
    int pcount = 0;
    int ppX[100];
    int ppY[100];
    int tempscore,tempplayerlive,tempplayerhealth,tempE1health,tempE2health,tempE3health;
    int tempplayerX,tempplayerY,tempE3X,tempE3Y,tempE2X,tempE2Y,tempE1X,tempE1Y,temptimer;
    system("cls");
    welcomeScreen();
    int count = 0;
    char resume;
    while (choice != "3")
    {
        bool gamerunning = true;
        gameLogo();
        choice = mainmenu();
        if (choice == "1")
        {
            system("cls");
            if (count > 0)
            {
                gotoxy(20, 17);
                cout << "Do you want to resume previous game?(y/n)";
                cin >> resume;
                system("cls");
                if (resume == 'y')
                {
                    loadmaze(border);
                    loadstats(score,playerlives,playerHealth,enemy1health,enemy2health,enemy3health,hawkX,hawkY,enemy3X,enemy3Y,enemy2X,enemy2Y,enemy1X,enemy1Y,timer);
                }
                else if(resume != 'n')
                {
                    cout << "press any key to go back";
                    getch();
                    break;
                }
                count = 0;
            }
            // printing game characters
            printBorder(border);
            printHawk(hawkX, hawkY, hawk);
            printChicken1(enemy1X, enemy1Y, cruella);
            printChicken2(enemy2X, enemy2Y, zelda);
            printChicken3(enemy3X, enemy3Y, tiana);
            while (gamerunning)
            {
                if (enemy2health > 0)
                {
                    random = rand() % 4; // making enemy 2 move randomly
                    if (random == 0)
                    {
                        moveChicken2down(enemy2X, enemy2Y, zelda);
                    }
                    if (random == 1)
                    {
                        moveChicken2up(enemy2X, enemy2Y, zelda);
                    }
                    if (random == 2)
                    {
                        moveChicken2right(enemy2X, enemy2Y, zelda);
                    }
                    if (random == 3)
                    {
                        moveChicken2left(enemy2X, enemy2Y, zelda);
                    }
                }
                else
                {
                    // erassing enemy2 when his health is finished
                    eraseChicken2(enemy2X, enemy2Y);
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveHawkRight(hawkX, hawkY, hawk, playerHealth, playerlives, score, enemy2fire, enemy3fire);
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveHawkLeft(hawkX, hawkY, hawk, playerHealth, playerlives, score, enemy2fire, enemy3fire);
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveHawkUp(hawkX, hawkY, hawk, playerHealth, playerlives, score, enemy2fire, enemy3fire);
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveHawkDown(hawkX, hawkY, hawk, playerHealth, playerlives, score, enemy2fire, enemy3fire);
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet(hawkX, hawkY, bulletX, bulletY, bulletCount);
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    makinggameover(score); // making game over and showing score
                    break;
                }
                if (GetKeyState('P') & 0x8000)
                {
                    tempscore= score;
                    tempplayerlive=playerlives;
                    tempplayerhealth =playerHealth;
                    tempE1health = enemy1health;
                    tempE2health = enemy2health;
                    tempE3health = enemy3health;
                    tempplayerX = hawkX;
                    tempplayerY = hawkY;
                    tempE3X = enemy3X ;
                    tempE3Y = enemy3Y;
                    tempE2X = enemy2X ;
                    tempE2Y = enemy2Y ;
                    tempE1X = enemy1X ;
                    tempE1Y = enemy1Y;
                    temptimer = timer;
                    storegameStats(tempscore,tempplayerlive,tempplayerhealth , tempE1health, tempE2health,tempE3health,tempplayerX,tempplayerY,tempE3X,tempE3Y,tempE2X,tempE2Y,tempE1X,tempE1Y,temptimer);
                    storeMaze(border);
                    count++;
                    break;
                }
                if (timer == 2)
                {
                    if (enemy1health > 0)
                    {
                        moveEnemy1(enemy1direction, wing2, wing1, enemy1X, enemy1Y, cruella); // moving enemy 1 slowly
                        timer = 0;
                    }
                    else
                    {
                        eraseChicken1(enemy1X, enemy1Y); // ersaing  enemy1 when his health is finished
                    }
                }
                if (enemy3slower == 6)
                {
                    if (enemy3health > 0)
                    {
                        moveEnemy3(hawkX, hawkY, enemy3X, enemy3Y, tiana);
                        enemy3slower = 0;
                    }
                    else
                    {
                        eraseChicken3(enemy3X, enemy3Y);
                    }
                }
                if (fireslower == 10)
                {
                    // generating enemy fire only if their health is greater than zero
                    if (enemy1health > 0)
                    {
                        generateenemy1fire(enemy1X, enemy1Y, enemy1fireX, enemy1fireY, fire1count);
                    }
                    if (enemy2health > 0)
                    {
                        generateenemy2fire(enemy2X, enemy2Y, fire2count, enemy2fireX, enemy2fireY, enemy2fire);
                    }
                    if (enemy3health > 0)
                    {
                        generateenemy3fire(fire3count, enemy3X, enemy3Y, enemy3fireX, enemy3fireY, enemy3fire);
                    }
                    fireslower = 0;
                }
                if(foodslower == 30)
                {
                    randomfood();
                }
                if (ppslower == 50)
                {
                    poweerup(ppX, ppY, pcount);
                    ppslower = 0;
                }
                if (enemy1health <= 0 && enemy2health <= 0 && enemy3health <= 0)
                {
                    wingame(score);
                    break;
                }
                checkPlayerHealth(hawkX, hawkY, playerHealth, playerlives, enemy2fire, enemy3fire); // decresing player's health level when he gets hit
                timer++;
                fireslower++;
                enemy3slower++;
                foodslower++;
                ppslower++;
                moveBullet(bulletCount, bulletX, bulletY);
                moveenemy1fire(fire1count, enemy1fireX, enemy1fireY); // moving enemy fires
                moveenemy2fire(fire2count, enemy2fireX, enemy2fireY, enemy2fire);
                moveenemy3fire(enemy3fireX, enemy3fireY, fire3count, enemy3fire);
                movep(ppX, ppY, pcount);
                bulletcollisionwithEnemy1(bulletCount, score, bulletX, bulletY, enemy1X, enemy1Y, enemy1health); // checking if bullets of player are touching enemies and increasing score
                bulletcollisionwithenemy2(bulletCount, score, bulletX, bulletY, enemy2X, enemy2Y, enemy2health);
                bulletcollisionwithenemy3(bulletCount, score, bulletX, bulletY, enemy3X, enemy3Y, enemy3health);
                checkplayercollisionwithenemy(hawkX, hawkY, playerHealth, enemy2fire, enemy3fire);
                if (playerHealth <= 0)
                {
                    playerlives--;
                    playerHealth = 100;
                    // regenrating player when he loses one life
                    eraseHawk(hawkX, hawkY);
                    hawkX = 15;
                    hawkY = 30;
                    printHawk(hawkX, hawkY, hawk);
                }
                setcolor(3);
                gotoxy(135, 17);
                cout << "Total score: " << score;
                gotoxy(135, 20);
                cout << "Player health: " << playerHealth << " ";
                if (enemy1health > 0)
                {
                    gotoxy(135, 23);
                    cout << "Enemy 1 (C) health: " << enemy1health << " ";
                }
                else
                {
                    gotoxy(135, 23);
                    cout << "Enemy 1 (C) health:  Finished! ";
                }
                if (enemy2health > 0)
                {
                    gotoxy(135, 25);
                    cout << "Enemy 2 (Z) health: " << enemy2health << " ";
                }
                else
                {
                    gotoxy(135, 25);
                    cout << "Enemy 2 (Z) health:  Finished!";
                }
                if (enemy3health > 0)
                {
                    gotoxy(135, 27);
                    cout << "Enemy 3 (T) health: " << enemy3health << " ";
                }
                else
                {
                    gotoxy(135, 27);
                    cout << "Enemy 3 (T) health: Finished!";
                }
                setcolor(12);
                gotoxy(135, 19);
                cout << "LIVES: " << playerlives << "  ";
                setcolor(07);
                if (playerlives == 0)
                {
                    // finishing game when all lives of player are finished
                    makinggameover(score);
                    gamerunning = false;
                }
                Sleep(100);
            }
            // resseting all values for next gameplay
            score = 0;
            playerlives = 3;
            playerHealth = 100;
            enemy1health = 100;
            enemy2health = 100;
            enemy3health = 100;
            hawkX = 15;
            hawkY = 30;
            enemy3X = 10;
            enemy3Y = 3;
            enemy2X = 50;
            enemy2Y = 19;
            enemy1X = 20;
            enemy1Y = 5;
            timer = 2;
        }
        if (choice == "2")
        {
            string further = "0";
            while (further != "3")
            {
                gameLogo();
                further = optionmenu();
                if (further == "1")
                {
                    gameLogo();
                    keysMenu();
                    Sleep(100);
                }
                if (further == "2")
                {
                    gameLogo();
                    instructionsMenu();
                    Sleep(100);
                }
            }
        }
        else if (choice != "1" && choice != "2" && choice != "3")
        {
            cout << "invalid choice! enter again";
            cin >> choice;
        }
    }
}
string mainmenu()
{
    string option;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "           <><><>---<>---<>---<>---<>---<>---<>---<>---<<           Menu            >>---<>---<>---<>---<>---<>---<>---<><><>" << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << endl;
    cout << "         1. Start  " << endl;
    cout << "         2. Option " << endl;
    cout << "         3. Exit   " << endl;
    cout << "         seelct an option...";
    cin >> option;
    return option;
}
string optionmenu()
{
    string option;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "        <><><>---<>---<>---<>---<>---<>---<>---<<           Menu>>options       >>---<>---<>---<>---<>---<>---<>---<><><>" << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << endl;
    cout << "       1. key" << endl;
    cout << "       2. Intructions" << endl;
    cout << "       3. Exit" << endl;
    cin >> option;
    return option;
}
void keysMenu()
{
    cout << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "        <><><>---<>---<>---<>---<>---<>---<<           Menu>>options>>keys       >>---<>---<>---<>---<>---<>---<>---<><><>" << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << endl;
    cout << "      1. UP       go up" << endl;
    cout << "      2. DOWN     go down" << endl;
    cout << "      3. RIGHT    go right" << endl;
    cout << "      4. LEFT     go left" << endl;
    cout << "      5. SPACE    fire " << endl;
    cout << "      6. ESCAPE   end game" << endl;
    cout << "      7. P        pause game" << endl;
    cout << "      press any key to go back.." << endl;
    getch();
    Sleep(100);
}
void instructionsMenu()
{
    cout << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "        <><><>---<>---<>---<>---<>---<>---<>---<<      Menu>>options>>instructions     >>---<>---<>---<>---<>---<>---<>---<><><>" << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "         SAVE THE WORLD!" << endl;
    cout << "               You  are  the  only  hope  of  humans. Only  you  can  the  save  the  Earth   from   this  invasion." << endl;
    cout << "               To  kill  all  the  chickens   you  have  first  save  yourself  from   their  eggs. You  can   move " << endl;
    cout << "               around  in  space,  by  pressing  arrows  keys   you   can  move  the  hawk  up/down/right/left. The " << endl;
    cout << "               chicken (cruella)is  moving  horizontally  and   hitting  you  with  eggs. The  chicken (zelda) is   " << endl;
    cout << "               ranomly  moving  and  firing  eggs  the  most  powerful  of  them  Tiana  is  the   master   of  them." << endl;
    cout << "               After  killing  her  the  first   wave   will be  over  and  next   wave  will   come  in  next  version" << endl;
    cout << "               of  the  game. Bext  of  luck  for  the  first wave! " << endl;
    cout << "            Press any key to continue....." << endl;
    getch();
}
void gameLogo()
{
    system("cls");
    setcolor(12);
    cout << endl;
    cout << "    $$$$$$\\  $$\\       $$\\           $$\\                                     $$$$$$\\                                    $$\\                      " << endl;
    cout << "   $$  __$$\\ $$ |      \\__|          $$ |                                    \\_$$  _|                                   $$ |                     " << endl;
    cout << "   $$ /  \\__|$$$$$$$\\  $$\\  $$$$$$$\\ $$ |  $$\\  $$$$$$\\  $$$$$$$\\              $$ |  $$$$$$$\\ $$\\    $$\\ $$$$$$\\   $$$$$$$ | $$$$$$\\   $$$$$$\\   $$$$$$$\\ " << endl;
    cout << "   $$ |      $$  __$$\\ $$ |$$  _____|$$ | $$  |$$  __$$\\ $$  __$$\\             $$ |  $$  __$$\\ $$\\  $$  |\\____$$\\ $$  __$$ |$$  __$$\\ $$  __$$\\ $$  _____| " << endl;
    cout << "   $$ |      $$ |  $$ |$$ |$$ /      $$$$$$  / $$$$$$$$ |$$ |  $$ |            $$ |  $$ |  $$ |\\$$\\$$  / $$$$$$$ |$$ /  $$ |$$$$$$$$ |$$ |  \\__|\\$$$$$$\\  " << endl;
    cout << "   $$ |  $$\\ $$ |  $$ |$$ |$$ |      $$  _$$<  $$   ____|$$ |  $$ |            $$ |  $$ |  $$ | \\$$$  / $$  __$$ |$$ |  $$ |$$   ____|$$ |       \\____$$\\ " << endl;
    cout << "   \\$$$$$$  |$$ |  $$ |$$ |\\$$$$$$$\\ $$ | \\$$\\ \\$$$$$$$\\ $$ |  $$ |          $$$$$$\\ $$ |  $$ |  \\$  /  \\$$$$$$$ |\\$$$$$$$ |\\$$$$$$$\\ $$ |      $$$$$$$  | " << endl;
    cout << "    \\______/ \\__|  \\__|\\__| \\_______|\\__|  \\__| \\_______|\\__|  \\__|          \\______|\\__|  \\__|   \\_/    \\_______| \\_______| \\_______|\\__|      \\_______/ " << endl;
    cout << endl;
    cout << endl;
    setcolor(07);
}
void welcomeScreen()
{
    gotoxy(43, 7);
    cout << "                              :*:                             " << endl;
    gotoxy(43, 8);
    cout << "                            -::.::-                           " << endl;
    gotoxy(43, 9);
    cout << "                            -.\\ /.-                           " << endl;
    gotoxy(43, 10);
    cout << "                          -=++0 0+++=-                        " << endl;
    gotoxy(43, 11);
    cout << "                            --+ %> +--                         " << endl;
    gotoxy(43, 12);
    cout << "     ...::.::...           -+=#%%#=+-            ...::.::...    " << endl;
    gotoxy(43, 13);
    cout << "           ..::..::..       =%%%%%%=      ..::..::..            " << endl;
    gotoxy(43, 14);
    cout << "               ...:::.::...@@@@@@@@@@...:::.::...               " << endl;
    gotoxy(43, 15);
    cout << "....:::::..               @@@@@@@@@@@@              ..:::::.... " << endl;
    gotoxy(43, 16);
    cout << "    ...:::.::..         %%%%%%%%%%%%%%%%       ::.:::..:..      " << endl;
    gotoxy(43, 17);
    cout << "          ..:..::.::..%%%%%%%%%%%%%%%%%%%% ::..::.:::..         " << endl;
    gotoxy(43, 18);
    cout << "                     $$%################%$$                     " << endl;
    gotoxy(43, 19);
    cout << "                     %%%%%%%%%%%@@@@@@@@@@@                     " << endl;
    gotoxy(43, 20);
    cout << "                     $%%%%%%%%%%%%%%%%%%%%$                     " << endl;
    gotoxy(43, 21);
    cout << "                   +==++@@@@@@@%%@@@@@@@++==+                   " << endl;
    gotoxy(43, 22);
    cout << "                       ...::::....:::::...                      " << endl;
    gotoxy(43, 23);
    cout << "                    ::::::::::::::::::::::::                   " << endl;
    gotoxy(43, 24);
    cout << "                  :==*******==:   :==*******==:                " << endl;
    gotoxy(43, 25);
    cout << "                  :******+***:    +***+-+****+-                " << endl;
    gotoxy(43, 26);
    cout << "                  :***+-+****:    =*+**+-+***+                 " << endl;
    gotoxy(43, 27);
    cout << "                                                               " << endl;
    gotoxy(43, 28);
    cout << "                                                               " << endl;
    gotoxy(43, 29);
    cout << "                                                               " << endl;
    gotoxy(45, 31);
    cout << "          LOADING ";
    gotoxy(63, 31);
    load();
}
void load()
{
    int value = 178;
    char character;
    character = value;
    for (int i = 0; i < 26; i++)
    {
        cout << character;
        Sleep(100);
    }
}
void printBorder(char border[][122])
{
    for (int idx = 0; idx < 37; idx++)
    {
        for (int indx = 0; indx < 122; indx++)
        {
            cout << border[idx][indx];
        }
        cout << endl;
    }
}
void gotoxy(int a, int b) // Custom gotoxy() function
{
    COORD coordinates; // Data type of co-ordinates
    coordinates.X = a; // Assign value to X- Co-ordinate
    coordinates.Y = b; // Assign value to Y Co-ordinate

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printHawk(int &hawkX, int &hawkY, char hawk[][7])
{
    setcolor(15);
    for(int row=0;row<4;row++)
    {
        gotoxy(hawkX, hawkY + row);
        for(int col=0; col <7;col++)
        {
            cout<< hawk[row][col];
        }
    }
    
    setcolor(07);
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
void Foodscore(char next, int &score)
{
    if (next == '+')
    {
        score = score + 2;
    }
}
void moveHawkRight(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire)
{

    char next = getCharAtxy(hawkX + 7, hawkY);
    if (next == ' ' || next == '+')
    {
        for (int i = 0; i < 6; i++)
        {
            char next = getCharAtxy(hawkX + 7, hawkY + i);
            Foodscore(next, score);
        }
        checkPlayerHealth(hawkX, hawkY, playerHealth, playerlives, enemy2fire, enemy3fire);
        eraseHawk(hawkX, hawkY);
        hawkX = hawkX + 1;
        printHawk(hawkX, hawkY, hawk);
    }
}
void moveHawkLeft(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire)
{
    char next = getCharAtxy(hawkX - 1, hawkY);
    if (next == ' ' || next == '+')
    {
        for (int i = 0; i < 6; i++)
        {
            char next = getCharAtxy(hawkX - 1, hawkY + i);
            Foodscore(next, score);
        }
        checkPlayerHealth(hawkX, hawkY, playerHealth, playerlives, enemy2fire, enemy3fire);
        eraseHawk(hawkX, hawkY);
        hawkX = hawkX - 1;
        printHawk(hawkX, hawkY, hawk);
    }
}
void moveHawkUp(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire)
{
    checkPlayerHealth(hawkX, hawkY, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next = getCharAtxy(hawkX, hawkY - 1);
    if (next == ' ' || next == '+')
    {
        char next1 = getCharAtxy(hawkX + 3, hawkY - 1);
        Foodscore(next1, score);
        eraseHawk(hawkX, hawkY);
        hawkY = hawkY - 1;
        printHawk(hawkX, hawkY, hawk);
    }
}
void moveHawkDown(int &hawkX, int &hawkY, char hawk[][7], int &playerHealth, int &playerlives, int &score, char &enemy2fire, char &enemy3fire)
{
    char next = getCharAtxy(hawkX, hawkY + 4);
    if (next == ' ' || next == '+')
    {
        char next1 = getCharAtxy(hawkX + 3, hawkY + 4);
        Foodscore(next1, score);
        checkPlayerHealth(hawkX, hawkY, playerHealth, playerlives, enemy2fire, enemy3fire);
        eraseHawk(hawkX, hawkY);
        hawkY = hawkY + 1;
        printHawk(hawkX, hawkY, hawk);
    }
}
void eraseHawk(int &hawkX, int &hawkY)
{
    for(int row=0;row<4;row++)
    {
        gotoxy(hawkX, hawkY + row);
        for(int col=0; col <7;col++)
        {
            cout<< " ";
        }
    }
}
void printChicken1(int &enemy1X, int &enemy1Y, char cruella[][7])
{
    setcolor(5);
    for(int row=0;row<3;row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< cruella[row][col];
        }
    }
    setcolor(07);
}
void generateBullet(int &hawkX, int &hawkY, int bulletX[], int bulletY[], int &bulletCount)
{
    bulletX[bulletCount] = hawkX + 3;
    bulletY[bulletCount] = hawkY - 1;
    char next = getCharAtxy(bulletX[bulletCount], bulletY[bulletCount]);
    if (next != '#')
    {
        gotoxy(bulletX[bulletCount], bulletY[bulletCount]);
        cout << ".";
        bulletCount++;
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void moveBullet(int &bulletCount, int bulletX[], int bulletY[])
{
    for (int i = 0; i < bulletCount; i++)
    {
        char next = getCharAtxy(bulletX[i], bulletY[i] - 1);
        if (next == ' ')
        {
            eraseBullet(bulletX[i], bulletY[i]);
            bulletY[i]--;
            printBullet(bulletX[i], bulletY[i]);
        }
        else
        {
            eraseBullet(bulletX[i], bulletY[i]);
            deleteBulletfromarray(i, bulletCount, bulletX, bulletY);
        }
    }
}
void deleteBulletfromarray(int index, int &bulletCount, int bulletX[], int bulletY[])
{
    for (int i = index; i < bulletCount; i++)
    {
        bulletX[i] = bulletX[i + 1];
        bulletY[i] = bulletY[i + 1];
    }
    bulletCount--;
}
void moveEnemy1(string &enemy1direction, char &wing2, char &wing1, int &enemy1X, int &enemy1Y, char cruella[][7])
{
    if (enemy1direction == "right")
    {
        char next = getCharAtxy(enemy1X + 7, enemy1Y);
        if (next == ' ' || next == '.' || next == '+')
        {
            eraseChicken1(enemy1X, enemy1Y);
            enemy1X = enemy1X + 1;
            printChicken1(enemy1X, enemy1Y, cruella);
        }
        if (next == '&')
        {
            enemy1direction = "left";
        }
    }
    if (enemy1direction == "left")
    {
        char next = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next == ' ' | next == '.' || next == '+')
        {
            eraseChicken1(enemy1X, enemy1Y);
            enemy1X = enemy1X - 1;
            printChicken1(enemy1X, enemy1Y, cruella);
        }
        if (next == '&' || next == wing2 || next == wing1)
        {
            enemy1direction = "right";
        }
    }
}
void eraseChicken1(int &enemy1X, int &enemy1Y)
{
     for(int row=0;row<3;row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< " ";
        }
    }
}
void bulletcollisionwithEnemy1(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy1X, int &enemy1Y, int &enemy1health)
{
    if (enemy1health > 0)
    {
        for (int i = 0; i < bulletCount; i++)
        {
            if (enemy1Y + 2 == bulletY[i] && (enemy1X == bulletX[i] || enemy1X + 1 == bulletX[i] || enemy1X + 2 == bulletX[i] || enemy1X + 3 == bulletX[i] || enemy1X + 4 == bulletX[i] || enemy1X + 5 == bulletX[i] || enemy1X + 6 == bulletX[i]))
            {
                score++;
                enemy1health--;
            }
            if (enemy1Y + 1 == bulletY[i] && (enemy1X == bulletX[i] || enemy1X + 6 == bulletX[i]))
            {
                score++;
                enemy1health--;
            }
        }
    }
}
void printChicken2(int &enemy2X, int &enemy2Y, char zelda[][7])
{
    setcolor(2);
    for(int row=0;row<4;row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< zelda[row][col];
        }
    }
    setcolor(07);
}
void eraseChicken2(int &enemy2X, int &enemy2Y)
{
     for(int row=0;row<4;row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< " ";
        }
    }
}
void moveChicken2right(int &enemy2X, int &enemy2Y, char zelda[][7])
{
    char next = getCharAtxy(enemy2X + 7, enemy2Y);
    if (next == ' ')
    {
        eraseChicken2(enemy2X, enemy2Y);
        enemy2X++;
        printChicken2(enemy2X, enemy2Y, zelda);
    }
}
void moveChicken2left(int &enemy2X, int &enemy2Y, char zelda[][7])
{
    char next = getCharAtxy(enemy2X - 1, enemy2Y);
    if (next == ' ')
    {
        eraseChicken2(enemy2X, enemy2Y);
        enemy2X--;
        printChicken2(enemy2X, enemy2Y, zelda);
    }
}
void moveChicken2up(int &enemy2X, int &enemy2Y, char zelda[][7])
{
    char next = getCharAtxy(enemy2X, enemy2Y - 1);
    if (next == ' ')
    {
        eraseChicken2(enemy2X, enemy2Y);
        enemy2Y--;
        printChicken2(enemy2X, enemy2Y, zelda);
    }
}
void moveChicken2down(int &enemy2X, int &enemy2Y, char zelda[][7])
{
    char next = getCharAtxy(enemy2X + 3, enemy2Y + 4);
    if (next == ' ')
    {
        eraseChicken2(enemy2X, enemy2Y);
        enemy2Y++;
        printChicken2(enemy2X, enemy2Y, zelda);
    }
}
void bulletcollisionwithenemy2(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy2X, int &enemy2Y, int &enemy2health)
{
    if (enemy2health > 0)
    {
        for (int i = 0; i < bulletCount; i++)
        {
            if (enemy2Y + 3 == bulletY[i] && (enemy2X == bulletX[i] || enemy2X + 1 == bulletX[i] || enemy2X + 2 == bulletX[i] || enemy2X + 3 == bulletX[i] || enemy2X + 4 == bulletX[i] || enemy2X + 5 == bulletX[i] || enemy2X + 6 == bulletX[i]))
            {
                score++;
                enemy2health--;
            }
            if ((enemy2Y + 2 == bulletY[i] || enemy2Y + 1 == bulletY[i]) && (enemy2X == bulletX[i] || enemy2X + 6 == bulletX[i]))
            {
                score++;
                enemy2health--;
            }
        }
    }
}
void generateenemy1fire(int &enemy1X, int &enemy1Y, int enemy1fireX[], int enemy1fireY[], int &fire1count)
{
    enemy1fireX[fire1count] = enemy1X + 3;
    enemy1fireY[fire1count] = enemy1Y + 3;
    char next = getCharAtxy(enemy1fireX[fire1count], enemy1fireY[fire1count]);
    if (next == ' ')
    {
        gotoxy(enemy1fireX[fire1count], enemy1fireY[fire1count]);
        cout << "O";
        fire1count++;
    }
}
void printenemyfire(int x, int y)
{
    gotoxy(x, y);
    cout << "O";
}
void deletefire1fromarray(int index, int &fire1count, int enemy1fireX[], int enemy1fireY[])
{
    for (int i = index; i < fire1count; i++)
    {
        enemy1fireX[i] = enemy1fireX[i + 1];
        enemy1fireY[i] = enemy1fireY[i + 1];
    }
    fire1count--;
}
void moveenemy1fire(int &fire1count, int enemy1fireX[], int enemy1fireY[])
{
    for (int i = 0; i < fire1count; i++)
    {
        char next = getCharAtxy(enemy1fireX[i], enemy1fireY[i] + 1);
        char nextr = getCharAtxy(enemy1fireX[i] + 1, enemy1fireY[i]);
        char nextl = getCharAtxy(enemy1fireX[i] - 1, enemy1fireY[i]);
        if (next == ' ' && nextr == ' ' && nextl == ' ')
        {
            eraseBullet(enemy1fireX[i], enemy1fireY[i]);
            enemy1fireY[i]++;
            printenemyfire(enemy1fireX[i], enemy1fireY[i]);
        }
        else
        {
            eraseBullet(enemy1fireX[i], enemy1fireY[i]);
            deletefire1fromarray(i, fire1count, enemy1fireX, enemy1fireY);
        }
    }
}
void printenemy2fire(int x, int y, char &enemy2fire)
{
    gotoxy(x, y);
    cout << enemy2fire;
}
void generateenemy2fire(int &enemy2X, int &enemy2Y, int &fire2count, int enemy2fireX[], int enemy2fireY[], char &enemy2fire)
{
    enemy2fireX[fire2count] = enemy2X + 3;
    enemy2fireY[fire2count] = enemy2Y + 4;
    char next = getCharAtxy(enemy2fireX[fire2count], enemy2fireY[fire2count]);
    if (next == ' ')
    {
        gotoxy(enemy2fireX[fire2count], enemy2fireY[fire2count]);
        cout << enemy2fire;
        fire2count++;
    }
}
void deletefire2fromarray(int index, int &fire2count, int enemy2fireX[], int enemy2fireY[])
{

    for (int i = index; i < fire2count; i++)
    {
        enemy2fireX[i] = enemy2fireX[i + 1];
        enemy2fireY[i] = enemy2fireY[i + 1];
    }
    fire2count--;
}
void moveenemy2fire(int &fire2count, int enemy2fireX[], int enemy2fireY[], char &enemy2fire)
{
    for (int i = 0; i < fire2count; i++)
    {
        char next = getCharAtxy(enemy2fireX[i], enemy2fireY[i] + 1);
        if (next == ' ')
        {
            eraseBullet(enemy2fireX[i], enemy2fireY[i]);
            enemy2fireY[i]++;
            printenemy2fire(enemy2fireX[i], enemy2fireY[i], enemy2fire);
        }
        else
        {
            eraseBullet(enemy2fireX[i], enemy2fireY[i]);
            deletefire2fromarray(i, fire2count, enemy2fireX, enemy2fireY);
        }
    }
}
void printChicken3(int &enemy3X, int &enemy3Y, char tiana[][7])
{
    setcolor(6);
    for(int row=0;row<4;row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< tiana[row][col];
        }
    }
    setcolor(07);
}
void eraseChicken3(int &enemy3X, int &enemy3Y)
{
    for(int row=0;row<4;row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for(int col=0; col <7;col++)
        {
            cout<< " ";
        }
    }
}
void checkPlayerHealth(int &hawkX, int &hawkY, int &playerHealth, int &playerlives, char &enemy2fire, char &enemy3fire)
{
    char next = getCharAtxy(hawkX, hawkY);
    checkdamage(next, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next1 = getCharAtxy(hawkX + 1, hawkY);
    checkdamage(next1, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next2 = getCharAtxy(hawkX + 2, hawkY);
    checkdamage(next2, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next3 = getCharAtxy(hawkX + 3, hawkY - 1);
    checkdamage(next3, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next4 = getCharAtxy(hawkX + 4, hawkY);
    checkdamage(next4, playerHealth, playerlives, enemy2fire, enemy3fire);
    char next5 = getCharAtxy(hawkX + 5, hawkY);
    checkdamage(next5, playerHealth, playerlives, enemy2fire, enemy3fire);
}
void checkdamage(char next, int &playerHealth, int &playerlives, char &enemy2fire, char &enemy3fire)
{
    if (next == 'O')
    {
        playerHealth--;
    }
    else if (next == enemy2fire)
    {
        playerHealth = playerHealth - 2;
    }
    else if (next == enemy3fire)
    {
        playerHealth = playerHealth - 4;
    }
    else if (next == 'P')
    {
        playerlives++;
    }
}
void gameoverborder()
{
    gotoxy(38, 16);
    cout << "*********************************";
    gotoxy(38, 17);
    cout << "*                               *";
    gotoxy(38, 18);
    cout << "*                               *";
    gotoxy(38, 19);
    cout << "*                               *";
    gotoxy(38, 20);
    cout << "*                               *";
    gotoxy(38, 21);
    cout << "*                               *";
    gotoxy(38, 22);
    cout << "*********************************";
}
void generateenemy3fire(int &fire3count, int &enemy3X, int &enemy3Y, int enemy3fireX[], int enemy3fireY[], char &enemy3fire)
{
    enemy3fireX[fire3count] = enemy3X + 3;
    enemy3fireY[fire3count] = enemy3Y + 4;
    char next = getCharAtxy(enemy3fireX[fire3count], enemy3fireY[fire3count]);
    if (next == ' ')
    {
        gotoxy(enemy3fireX[fire3count], enemy3fireY[fire3count]);
        cout << enemy3fire;
        fire3count++;
    }
}
void printenemy3fire(int x, int y, char &enemy3fire)
{
    gotoxy(x, y);
    cout << enemy3fire;
}
void deletefire3fromarray(int index, int enemy3fireX[], int enemy3fireY[], int &fire3count)
{
    // deleting fire of enemy 3 from its array
    for (int i = index; i < fire3count; i++)
    {
        enemy3fireX[i] = enemy3fireX[i + 1];
        enemy3fireY[i] = enemy3fireY[i + 1];
    }
    fire3count--;
}
void moveenemy3fire(int enemy3fireX[], int enemy3fireY[], int &fire3count, char &enemy3fire)
{
    // moving all fires of enemy 3
    for (int i = 0; i < fire3count; i++)
    {
        char next = getCharAtxy(enemy3fireX[i], enemy3fireY[i] + 1);
        if (next == ' ')
        {
            eraseBullet(enemy3fireX[i], enemy3fireY[i]);
            enemy3fireY[i]++;
            printenemy3fire(enemy3fireX[i], enemy3fireY[i], enemy3fire);
        }
        else if (next != ' ')
        {
            eraseBullet(enemy3fireX[i], enemy3fireY[i]);
            deletefire3fromarray(i, enemy3fireX, enemy3fireY, fire3count);
        }
    }
}
void bulletcollisionwithenemy3(int &bulletCount, int &score, int bulletX[], int bulletY[], int &enemy3X, int &enemy3Y, int &enemy3health)
{
    // increseing score and decreasing enemy health with player's bullet touches it
    if (enemy3health > 0)
    {
        for (int i = 0; i < bulletCount; i++)
        {
            if (enemy3Y + 3 == bulletY[i] && (enemy3X == bulletX[i] || enemy3X + 1 == bulletX[i] || enemy3X + 2 == bulletX[i] || enemy3X + 3 == bulletX[i] || enemy3X + 4 == bulletX[i] || enemy3X + 5 == bulletX[i] || enemy3X + 6 == bulletX[i]))
            {
                score++;
                enemy3health--;
            }
            if ((enemy3Y + 1 == bulletY[i] || enemy3Y + 2 == bulletY[i]) && (enemy3X == bulletX[i] || enemy3X + 5 == bulletX[i]))
            {
                score++;
                enemy3health--;
            }
        }
    }
}
void checkplayercollisionwithenemy(int &hawkX, int &hawkY, int &playerHealth, char &enemy2fire, char &enemy3fire)
{
    // checking all coordinates of player for presence of enemy
    char next = getCharAtxy(hawkX, hawkY);
    playerenemycollision(next, playerHealth, enemy2fire, enemy3fire);
    char next1 = getCharAtxy(hawkX + 1, hawkY);
    playerenemycollision(next1, playerHealth, enemy2fire, enemy3fire);
    char next2 = getCharAtxy(hawkX + 2, hawkY);
    playerenemycollision(next2, playerHealth, enemy2fire, enemy3fire);
    char next3 = getCharAtxy(hawkX + 3, hawkY - 1);
    playerenemycollision(next3, playerHealth, enemy2fire, enemy3fire);
    char next4 = getCharAtxy(hawkX + 4, hawkY);
    playerenemycollision(next4, playerHealth, enemy2fire, enemy3fire);
    char next5 = getCharAtxy(hawkX + 5, hawkY);
    playerenemycollision(next5, playerHealth, enemy2fire, enemy3fire);
    char next6 = getCharAtxy(hawkX + 6, hawkY);
    playerenemycollision(next6, playerHealth, enemy2fire, enemy3fire);
    char next7 = getCharAtxy(hawkX - 1, hawkY + 1);
    playerenemycollision(next7, playerHealth, enemy2fire, enemy3fire);
    char next8 = getCharAtxy(hawkX + 7, hawkY + 1);
    playerenemycollision(next8, playerHealth, enemy2fire, enemy3fire);
    char next9 = getCharAtxy(hawkX, hawkY + 2);
    playerenemycollision(next9, playerHealth, enemy2fire, enemy3fire);
    char next10 = getCharAtxy(hawkX + 6, hawkY + 2);
    playerenemycollision(next10, playerHealth, enemy2fire, enemy3fire);
    char next11 = getCharAtxy(hawkX, hawkY + 3);
    playerenemycollision(next11, playerHealth, enemy2fire, enemy3fire);
    char next12 = getCharAtxy(hawkX + 1, hawkY + 3);
    playerenemycollision(next12, playerHealth, enemy2fire, enemy3fire);
    char next13 = getCharAtxy(hawkX + 2, hawkY + 3);
    playerenemycollision(next13, playerHealth, enemy2fire, enemy3fire);
    char next14 = getCharAtxy(hawkX + 3, hawkY + 4);
    playerenemycollision(next14, playerHealth, enemy2fire, enemy3fire);
    char next15 = getCharAtxy(hawkX + 4, hawkY + 3);
    playerenemycollision(next15, playerHealth, enemy2fire, enemy3fire);
    char next16 = getCharAtxy(hawkX + 5, hawkY + 3);
    playerenemycollision(next16, playerHealth, enemy2fire, enemy3fire);
    char next17 = getCharAtxy(hawkX + 6, hawkY + 3);
    playerenemycollision(next17, playerHealth, enemy2fire, enemy3fire);
}
void playerenemycollision(char next, int &playerHealth, char &enemy2fire, char &enemy3fire)
{
    // deducting 1 life if player touches enemy
    if (next != '&' && next != ' ' && next != '+' && next != 'O' && next != enemy2fire && next != enemy3fire && next != 'P' && next != '.')
    {
        playerHealth = 0;
    }
}
void makinggameover(int &score)
{
    system("cls");
    gameoverborder();
    gotoxy(46, 18);
    cout << "GAME OVER!";
    gotoxy(46, 20);
    cout << "YOUR SCORE: " << score;
    Sleep(5000);
}
void wingame(int &score)
{
    system("cls");
    gameoverborder();
    gotoxy(46, 18);
    cout << "Congrats! ^YOU WON^";
    gotoxy(46, 20);
    cout << "YOUR SCORE: " << score;
    Sleep(5000);
}
void moveenemy3up(int &enemy3X, int &enemy3Y, char tiana[][7])
{
    eraseChicken3(enemy3X, enemy3Y);
    enemy3Y--;
    printChicken3(enemy3X, enemy3Y, tiana);
}
void moveenemy3down(int &enemy3X, int &enemy3Y, char tiana[][7])
{
    eraseChicken3(enemy3X, enemy3Y);
    enemy3Y++;
    printChicken3(enemy3X, enemy3Y, tiana);
}
void moveenemy3right(int &enemy3X, int &enemy3Y, char tiana[][7])
{
    eraseChicken3(enemy3X, enemy3Y);
    enemy3X++;
    printChicken3(enemy3X, enemy3Y, tiana);
}
void moveenemy3left(int &enemy3X, int &enemy3Y, char tiana[][7])
{
    eraseChicken3(enemy3X, enemy3Y);
    enemy3X--;
    printChicken3(enemy3X, enemy3Y, tiana);
}
void moveEnemy3(int &hawkX, int &hawkY, int &enemy3X, int &enemy3Y, char tiana[][7])
{
    if (enemy3X - hawkX > 0)
    {
        char next = getCharAtxy(enemy3X - 1, enemy3Y);
        char next1 = getCharAtxy(enemy3X - 1, enemy3Y + 1);
        char next2 = getCharAtxy(enemy3X - 1, enemy3Y + 2);
        char next3 = getCharAtxy(enemy3X - 1, enemy3Y + 3);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            moveenemy3left(enemy3X, enemy3Y, tiana);
        }
    }
    if (enemy3X - hawkX < 0)
    {
        char next = getCharAtxy(enemy3X + 6, enemy3Y);
        char next1 = getCharAtxy(enemy3X + 6, enemy3Y + 1);
        char next2 = getCharAtxy(enemy3X + 7, enemy3Y + 2);
        char next3 = getCharAtxy(enemy3X + 6, enemy3Y + 3);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            moveenemy3right(enemy3X, enemy3Y, tiana);
        }
    }
    if (enemy3Y - hawkY < 0)
    {
        char next = getCharAtxy(enemy3X, enemy3Y + 3);
        char next1 = getCharAtxy(enemy3X + 1, enemy3Y + 3);
        char next2 = getCharAtxy(enemy3X + 2, enemy3Y + 3);
        char next3 = getCharAtxy(enemy3X + 3, enemy3Y + 4);
        char next4 = getCharAtxy(enemy3X + 4, enemy3Y + 3);
        char next5 = getCharAtxy(enemy3X + 5, enemy3Y + 3);
        char next6 = getCharAtxy(enemy3X + 6, enemy3Y + 3);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ')
        {
            moveenemy3down(enemy3X, enemy3Y, tiana);
        }
    }
    if (enemy3Y - hawkY > 0)
    {
        char next = getCharAtxy(enemy3X, enemy3Y);
        char next1 = getCharAtxy(enemy3X + 1, enemy3Y);
        char next2 = getCharAtxy(enemy3X + 2, enemy3Y);
        char next3 = getCharAtxy(enemy3X + 3, enemy3Y - 1);
        char next4 = getCharAtxy(enemy3X + 4, enemy3Y);
        char next5 = getCharAtxy(enemy3X + 5, enemy3Y);
        char next6 = getCharAtxy(enemy3X + 6, enemy3Y);
        if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ')
        {
            moveenemy3up(enemy3X, enemy3Y, tiana);
        }
    }
}
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}
void storeMaze(char border[][122])
{
    fstream mazefile;
    mazefile.open("maze.txt", ios::out);
    for (int x = 0; x < 37; x++)
    {
        for (int y = 0; y < 122; y++)
        {
            mazefile << border[x][y];
        }
        mazefile << endl;
    }
    mazefile.close();
}
void loadmaze(char border[][122])
{
    fstream mazefile;
    string line;
    int row = 0;
    mazefile.open("maze.txt", ios::in);
    while (getline(mazefile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            border[row][i] = line[i];
        }
        row++;
    }
    mazefile.close();
}
void randomfood()
{
    int x = rand() % 120;
    int y = rand() % 35;

    char location = getCharAtxy(x, y);
    gotoxy(125, 2);
    if (location == ' ')
    {
        gotoxy(x, y);
        cout << "+";
    }
}
void poweerup(int ppX[], int ppY[], int &pcount)
{
    ppX[pcount] = rand() % 120;
    ppY[pcount] = 1;
    char next = getCharAtxy(ppX[pcount], ppY[pcount]);
    if (next == ' ')
    {
        gotoxy(ppX[pcount], ppY[pcount]);
        cout << "P";
        pcount++;
    }
}
void movep(int ppX[], int ppY[], int &pcount)
{
    for (int i = 0; i < pcount; i++)
    {
        char next = getCharAtxy(ppX[i], ppY[i] + 1);
        if (next == ' ')
        {
            erasepp(ppX[i], ppY[i]);
            ppY[i]++;
            printpp(ppX[i], ppY[i]);
        }
        else if (next != ' ')
        {
            erasepp(ppX[i], ppY[i]);
            deletePfromarray(i, pcount, ppX, ppY);
        }
    }
}
void erasepp(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printpp(int x, int y)
{
    gotoxy(x, y);
    setcolor(9);
    cout << "P";
    setcolor(07);
}
void deletePfromarray(int indx, int &pcount, int ppX[], int ppY[])
{
    for (int i = indx; i < pcount; i++)
    {
        ppX[i] = ppX[i + 1];
        ppY[i] = ppY[i + 1];
    }
    pcount--;
}
void storegameStats(int &tempscore,int &tempplayerlive,int &tempplayerhealth , int &tempE1health, int &tempE2health,int &tempE3health,int &tempplayerX,int &tempplayerY,int &tempE3X,int &tempE3Y,int &tempE2X,int &tempE2Y,int &tempE1X,int &tempE1Y,int &temptimer)
{
    fstream gamestats;
    gamestats.open("stats.txt",ios::out);
    gamestats<< tempscore <<","<<tempplayerlive<<","<<tempplayerhealth <<","<<tempE1health<<","<<tempE2health<<","<<tempE3health<<","<<tempplayerX<<","<<tempplayerY<<","<<tempE3X<<","<<tempE3Y<<","<<tempE2X<<","<<tempE2Y<<","<<tempE1X<<","<<tempE1Y<<","<<temptimer;
    gamestats.close();
}
string parsedata(string line, int feild)
{
    string item = "";
    int commacount = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        else if (feild == commacount)
        {
            item = item + line[i];
        }
    }
    return item;
}
void loadstats(int &score, int &playerlives, int &playerhealth,int &enemy1health,int &enemy2health,int &enemy3health,int &hawkX, int &hawkY, int enemy3X,int &enemy3Y,int &enemy2X,int &enemy2Y,int &enemy1X,int &enemy1Y,int &timer )
{
    string line;
    fstream myFile;
    myFile.open("stats.txt", ios::in);
    while (getline(myFile, line))
    {
        score = stoi(parsedata(line, 1));
        playerlives= stoi(parsedata(line, 2));
        playerhealth= stoi(parsedata(line, 3));
        enemy1health=stoi(parsedata(line, 4));
        enemy2health= stoi(parsedata(line, 5));
        enemy3health= stoi(parsedata(line, 6));
        hawkX= stoi(parsedata(line, 7));
        hawkY=stoi(parsedata(line, 8));
        enemy3X=stoi(parsedata(line, 9));
        enemy3Y=stoi(parsedata(line, 10));
        enemy2X=stoi(parsedata(line, 11));
        enemy2Y=stoi(parsedata(line, 12));
        enemy1X=stoi(parsedata(line, 13));
        enemy1Y=stoi(parsedata(line, 14));
        timer=stoi(parsedata(line, 15));
    
    }
    myFile.close();
}