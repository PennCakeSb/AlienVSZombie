// ****************************************************************************************************************** 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year  : Trimester 1, 2022/23 (T2215) 
// Lab   : TT5L 
// Names : NUR AISYAH NABILA BINTI NAHAR | ASYRANI SYAZWAN BIN YUHANIS   | LUQMAN HAKIM BIN NOORAZMI 
// IDs   : 1211104230                    | 1211103222                    | 1211101583
// Emails: 1211104230@student.mmu.edu.my | 1211103222@student.mmu.edu.my | 1211101583@student.mmu.edu.my 
// Phones: 0107662837                    | 0162117400                    | 0132874100
// ******************************************************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <unistd.h>

using namespace std;

class gameBoard
{
private:
    vector< vector<char> > map_;
    int dimX_, dimY_;
public:
    gameBoard(int dimX = 5, int dimY = 7);
    void init(int dimX, int dimY);
    void display() const;

    int getDimX() const; 
    int getDimY() const;

    char getObject(int x, int y) const;
    void setObject(int x, int y, char ch);
    bool isEmpty(int x, int y);
    bool isInsideMap(int x, int y);
};

class Alien{
private:
    int x_, y_;
    int life;
    int attack_;
    char alien;
    char z_;
public:
    Alien(int life = 100, int attack = 0);
    void land(gameBoard &gameBoard);
    int getLife();
    int getAttack();
    int getX() const;
    int getY() const;    
    void up(gameBoard &gameBoard, Alien &alien);
    void down(gameBoard &gameBoard, Alien &alien);
    void left(gameBoard &gameBoard, Alien &alien);
    void right(gameBoard &gameBoard, Alien &alien);
    void health(int x);
    void attack(int x);
    void setMove();
    char getMove();
};

class Zombie: public gameBoard{

    private:
        int x_, y_, health_, attack_, range_;
        char heading_;

    public:
        Zombie(){};
            void setZombieAttributes(int n, gameBoard &gameBoard);

            void print(Zombie &zombie, gameBoard &gameBoard){
                cout << "------------------" << endl;
                cout << "Zombie  : " << zombie.getZHeading() << endl;
                cout << "Position: " << "(" << zombie.getZX() << "," << zombie.getZY() << ")" << endl;
                cout << "Health  : " << zombie.getZHealth() << endl;
                cout << "Attack  : " << zombie.getZAttack() << endl;
                cout << "Range   : " << zombie.getZRange() << endl;
                cout << "------------------" << endl;
            }

            int getZX(){
                return x_;
            }
            int getZY(){
                return y_;
            }
            int getZHealth();
            int getZAttack();
            int getZRange();
            char getZHeading();
            bool checkZombie(int n, gameBoard &gameBoard){
                const char letters[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                bool exists = false;
                for (int i=0; i<n; i++){
                    if (gameBoard.getObject(x_, y_) == letters[i]){
                        exists = true;
                    }
                }
                return exists;
            }
            void reduceHealth(int n){
                health_ = health_ - n;
            }
            void checkRange(Zombie &zombie, gameBoard &gameBoard);
            void moveZombie(int n, Zombie &zombie, gameBoard &gameBoard); 
        
};

class Arrow{
    private:
    int x_, y_;
    char heading_;
    char arrow;

public:
    Arrow();
    int getX() const;
    int getY() const;
    char getHeading() const;
    void left(gameBoard &gameBoard);
    void right(gameBoard &gameBoard);
    void up(gameBoard &gameBoard);
    void down(gameBoard &gameBoard);
    void setPosition(gameBoard &gameBoard, int x, int y);    
};

Alien::Alien(int health, int attack){
    life = health;
    attack_ = attack;
    z_ = 'M';
}

Arrow::Arrow(){}

void Arrow::left(gameBoard &gameBoard){
    gameBoard.setObject(x_,y_, '<');
}

void Arrow::right(gameBoard &gameBoard){
    gameBoard.setObject(x_,y_, '>');
}

void Arrow::up(gameBoard &gameBoard){
    gameBoard.setObject(x_,y_, '^');
}

void Arrow::down(gameBoard &gameBoard){
    gameBoard.setObject(x_,y_, 'v');
}

int Alien::getLife(){
    return life;
}

int Alien::getAttack(){
    return attack_;
}

void Alien::health(int x){
    int life = 100;
}

void Alien::attack(int x){
    int attack_ = 0;
}

void Alien::setMove(){
    z_ = 'M';
}

char Alien::getMove(){
    return z_;
}

void Alien::up(gameBoard &gameBoard, Alien &alien){
    //Alien alien;
    gameBoard.setObject(x_,y_,' ');
    int y = gameBoard.getDimY();
        
    while ((y_+1 <= y) && (gameBoard.isEmpty(x_,y_+1) || (gameBoard.getObject(x_,y_+1)=='.') || (gameBoard.getObject(x_,y_+1)=='^') || (gameBoard.getObject(x_,y_+1)=='v') || (gameBoard.getObject(x_,y_+1)=='<') || (gameBoard.getObject(x_,y_+1)=='>')|| (gameBoard.getObject(x_,y_+1)=='h') || (gameBoard.getObject(x_,y_+1)=='p'))){
    //while ((y_+1 <= y) && (gameBoard.isEmpty(x_,y_+1) || (gameBoard.getObject(x_,y_+1)=='.') || (gameBoard.getObject(x_,y_+1)=='^') || (gameBoard.getObject(x_,y_+1)=='v') || (gameBoard.getObject(x_,y_+1)=='<') || (gameBoard.getObject(x_,y_+1)=='>'))){
        //if (y_!= y || (game\Board.getObject(x_,y_+1)=='.') || (gameBoard.getObject(x_,y_+1)=='^')){
        if (y_!= y && gameBoard.isEmpty(x_,y_+1)){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_+1)=='.'){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_+1)=='^'){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_+1)=='v'){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            alien.down(gameBoard, alien);
            break;
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_+1)=='>'){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            alien.right(gameBoard, alien);
            break;
        }
        else if (gameBoard.getObject(x_,y_+1)=='<'){
            y_=y_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            alien.left(gameBoard, alien);
        }
        else if (gameBoard.getObject(x_,y_+1)=='h'){
            y_=y_+1;
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            cout << "Alien has found a health pack!" << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
        }
        else if (gameBoard.getObject(x_,y_+1)=='p'){
            y_=y_+1;
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            cout << "Alien has found a pod!" << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
        }
        else{
            gameBoard.setObject(x_,y_,'A');
            z_='S';
        }

        if (y_+1 > y){
            gameBoard.setObject(x_,y_,'A');
            gameBoard.display();
            cout << "Alien has hit the border" << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
        }   
        else if (gameBoard.getObject(x_,y_+1)=='1'||gameBoard.getObject(x_,y_+1)=='2' || gameBoard.getObject(x_,y_+1)=='3'||gameBoard.getObject(x_,y_+1)=='4' || gameBoard.getObject(x_,y_+1)=='5'||gameBoard.getObject(x_,y_+1)=='6' || gameBoard.getObject(x_,y_+1)=='7'||gameBoard.getObject(x_,y_+1)=='8' || gameBoard.getObject(x_,y_+1)=='9'){
            gameBoard.setObject(x_,y_,'A');
            gameBoard.display();
            cout << "Alien attacks zombie" << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
        }
        else if (gameBoard.getObject(x_,y_+1)=='r'){
            y_=y_+1;
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_-1, '.');
            gameBoard.display();
            cout << "Alien has hit a rock." << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
        }
    }
}

void Alien::down(gameBoard &gameBoard, Alien &alien){
    gameBoard.setObject(x_,y_,' ');
    int y = gameBoard.getDimY();

    while ((y_-1 > 0) && (gameBoard.isEmpty(x_,y_-1) || (gameBoard.getObject(x_,y_-1)=='.')  || (gameBoard.getObject(x_,y_-1)=='^') || (gameBoard.getObject(x_,y_-1)=='v') || (gameBoard.getObject(x_,y_-1)=='<') || (gameBoard.getObject(x_,y_-1)=='>')|| (gameBoard.getObject(x_,y_-1)=='h') || (gameBoard.getObject(x_,y_-1)=='p'))){
        if (y_!= y && gameBoard.isEmpty(x_,y_-1)){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_-1)=='.'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_-1)=='v'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_-1)=='^'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            alien.up(gameBoard, alien);
            break;
            //z_='S';
        }
        else if (gameBoard.getObject(x_,y_-1)=='>'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            alien.right(gameBoard, alien);
            break;
        }
        else if (gameBoard.getObject(x_,y-1)=='<'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            alien.left(gameBoard, alien);
        }
        else if (gameBoard.getObject(x_,y_-1)=='h'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            cout << "Alien has found a health pack!" << endl;
            cout << endl;
        }
        else if (gameBoard.getObject(x_,y_-1)=='p'){
            y_=y_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_,y_+1, '.');
            gameBoard.display();
            cout << "Alien has found a pod!" << endl;
            cout << endl;
        }
        else{
            gameBoard.setObject(x_,y_,'A');
            z_='S';
        }   
    }

    if (y_-1 == 0){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.display();
        cout << "Alien has hit the border" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        //z_='S';
    }
    else if (gameBoard.getObject(x_,y_-1)=='1'||gameBoard.getObject(x_,y_-1)=='2' || gameBoard.getObject(x_,y_-1)=='3'||gameBoard.getObject(x_,y_-1)=='4' || gameBoard.getObject(x_,y_-1)=='5'||gameBoard.getObject(x_,y_-1)=='6' || gameBoard.getObject(x_,y_-1)=='7'||gameBoard.getObject(x_,y_-1)=='8' || gameBoard.getObject(x_,y_-1)=='9'){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.display();
        cout << "Alien attacks zombie" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        z_='S';
    }
    else if (gameBoard.getObject(x_,y_-1)=='r'){
            gameBoard.setObject(x_,y_,'A');
            gameBoard.display();
            cout << "Alien has hit a rock." << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
    }
} 

void Alien::left(gameBoard &gameBoard, Alien &alien){
    gameBoard.setObject(x_,y_, ' ');
    int x = gameBoard.getDimX();

    while ((x_-1 > 0) && (gameBoard.isEmpty(x_-1,y_) || (gameBoard.getObject(x_-1,y_)=='.') || (gameBoard.getObject(x_-1,y_)=='^') || (gameBoard.getObject(x_-1,y_)=='v') || (gameBoard.getObject(x_-1,y_)=='<') || (gameBoard.getObject(x_-1,y_)=='>') || (gameBoard.getObject(x_-1,y_)=='h') || (gameBoard.getObject(x_-1,y_)=='p'))){
        if (gameBoard.isEmpty(x_-1,y_)){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            //z_='S';
        }
        else if (gameBoard.getObject(x_-1,y_)=='.'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
        }
        else if (gameBoard.getObject(x_-1,y_)=='<'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
        }
        else if (gameBoard.getObject(x_-1,y_)=='^'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            alien.up(gameBoard, alien);
            break;
        }
        else if (gameBoard.getObject(x_-1,y_)=='v'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            alien.down(gameBoard, alien);
            break;
        }
        else if (gameBoard.getObject(x_-1,y_)=='>'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            alien.right(gameBoard, alien);
            break;
        }
        else if (gameBoard.getObject(x_-1,y_)=='h'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            cout << "Alien has found a health pack!" << endl;
            cout << endl;
            //system("read -n 1 -s -p \"Press any key to continue...\"");
        }
        else if (gameBoard.getObject(x_-1,y_)=='p'){
            x_=x_-1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.setObject(x_,y_,'A');
            gameBoard.setObject(x_+1,y_, '.');
            gameBoard.display();
            cout << "Alien has found a pod!" << endl;
            cout << endl;
            //system("read -n 1 -s -p \"Press any key to continue...\"");
        }
        else{
            gameBoard.setObject(x_,y_,'A');
            z_='S';
        }
    }

    if (x_-1==0){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.display();
        cout << "Alien has hit the border" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        z_='S';
    }
    else if (gameBoard.getObject(x_-1,y_)=='1'||gameBoard.getObject(x_-1,y_)=='2' || gameBoard.getObject(x_-1,y_)=='3'||gameBoard.getObject(x_-1,y_)=='4' || gameBoard.getObject(x_-1,y_)=='5'||gameBoard.getObject(x_-1,y_)=='6' || gameBoard.getObject(x_-1,y_)=='7'||gameBoard.getObject(x_-1,y_)=='8' || gameBoard.getObject(x_-1,y_)=='9'){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.setObject(x_+1,y_,'.');
        gameBoard.display();
        cout << "Alien attacks zombie" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        gameBoard.setObject(x_-1,y_,'A');
        gameBoard.setObject(x_,y_,'.');
        gameBoard.display();
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        z_='S';
    }
    else if (gameBoard.getObject(x_-1,y_)=='r'){
            gameBoard.setObject(x_,y_,'A');
            gameBoard.display();
            cout << "Alien has hit a rock." << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
    }
}

void Alien::right(gameBoard &gameBoard, Alien &alien){
    gameBoard.setObject(x_,y_,' ');
    int x = gameBoard.getDimX();
    //while ((x_+1 <= x) && gameBoard.isEmpty(x_+1,y_) || (gameBoard.getObject(x_+1,y_)=='.')){
    while ((x_+1 <= x) && (gameBoard.isEmpty(x_+1,y_) || (gameBoard.getObject(x_+1,y_)=='.') || (gameBoard.getObject(x_+1,y_)=='^') || (gameBoard.getObject(x_+1,y_)=='v') || (gameBoard.getObject(x_+1,y_)=='<') || (gameBoard.getObject(x_+1,y_)=='>') || (gameBoard.getObject(x_+1,y_)=='h') || (gameBoard.getObject(x_+1,y_)=='p'))){
        if (gameBoard.isEmpty(x_+1,y_)){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            //z_='S';
        } 
        else if (gameBoard.getObject(x_+1,y_)=='.'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
        }
        else if (gameBoard.getObject(x_+1,y_)=='>'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
        }
        else if (gameBoard.getObject(x_+1,y_)=='^'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            alien.up(gameBoard,alien);
            break;
        }
        else if (gameBoard.getObject(x_+1,y_)=='v'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            alien.down(gameBoard,alien);
            break;
        }
        else if (gameBoard.getObject(x_+1,y_)=='<'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            alien.left(gameBoard,alien);
            break;
        }
        else if (gameBoard.getObject(x_+1,y_)=='h'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            cout << "Alien has found a health pack!" << endl;
            cout << endl;
        }
        else if (gameBoard.getObject(x_+1,y_)=='p'){
            x_=x_+1;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            gameBoard.setObject(x_, y_, 'A');
            gameBoard.setObject(x_-1, y_, '.');
            gameBoard.display();
            cout << "Alien has found a pod!" << endl;
            cout << endl;
        }
        else{
            gameBoard.setObject(x_,y_,'A');
            z_='S';
        }
    }

    if (x_+1 > x){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.display();
        cout << "Alien has hit the border" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        z_='S';
    }
    else if (gameBoard.getObject(x_+1,y_)=='1'||gameBoard.getObject(x_+1,y_)=='2' || gameBoard.getObject(x_+1,y_)=='3'||gameBoard.getObject(x_+1,y_)=='4' || gameBoard.getObject(x_+1,y_)=='5'||gameBoard.getObject(x_+1,y_)=='6' || gameBoard.getObject(x_+1,y_)=='7'||gameBoard.getObject(x_+1,y_)=='8' || gameBoard.getObject(x_+1,y_)=='9'){
        gameBoard.setObject(x_,y_,'A');
        gameBoard.display();
        cout << "Alien attacks zombie" << endl;
        cout << endl;
        system("read -n 1 -s -p \"Press any key to continue...\"");
        cout << endl;
        z_='S';
    }
    else if (gameBoard.getObject(x_+1,y_)=='r'){
            gameBoard.setObject(x_,y_,'A');
            gameBoard.display();
            cout << "Alien has hit a rock." << endl;
            cout << endl;
            system("read -n 1 -s -p \"Press any key to continue...\"");
            cout << endl;
            z_='S';
    }
}

void Alien::land(gameBoard &gameBoard)
{ 
    x_ = (gameBoard.getDimX() + 1)/2;
    y_ = (gameBoard.getDimY() + 1)/2;
    char A = 'A';

    gameBoard.setObject(x_, y_, A);
}

int Arrow::getX() const{
    return x_;
}
int Arrow::getY() const{
    return y_;
}
char Arrow::getHeading() const{
    return heading_;
}

int Alien::getX() const{
    return x_;
}
int Alien::getY() const{
    return y_;
}

gameBoard::gameBoard(int dimX, int dimY){
    init(dimX, dimY);
}

void Arrow::setPosition(gameBoard &gameBoard, int x, int y){
    x_ = x;
    y_ = y;
}

int gameBoard::getDimX() const{
    return dimX_;
}

int gameBoard::getDimY() const{
    return dimY_;
}

char gameBoard::getObject(int x, int y) const
{
    return map_[dimY_-y][x-1];
}

void gameBoard::setObject(int x, int y, char ch)
{
    map_[dimY_-y][x-1] = ch;
}

bool gameBoard::isEmpty(int x, int y){
    return map_[dimY_-y][x-1] == ' ';
}

bool gameBoard::isInsideMap(int x, int y)
{
    return x >= 1 && x <= dimX_ && y >= 1 && y <= dimY_;
}

void gameBoard::init(int dimX, int dimY){
    dimX_ = dimX;
    dimY_ = dimY;
    //char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '>', '<', 'h', 'h', 'p', 'p','r','r','r', ' ', ' ', ' ', ' ', ' '};
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '>', '<', 'h', 'r', 'p'};
    //char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int noOfObjects = sizeof(objects);

    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            if (j == (dimX_-1)/2 && i == (dimY_-1)/2){
                map_[i][j] = 'A';
            }
            else{
                map_[i][j] = objects[objNo];
            }
        }
    }
}

void gameBoard::display() const{
    system("clear");
    cout << " --__--__--__--__--__--__--__--__--__--__--" << endl;
    cout << "            = Alien vs Zombies =           " << endl;
    cout << " --__--__--__--__--__--__--__--__--__--__--" << endl;
    cout << endl;

    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

int Zombie::getZHealth(){
    return health_;
}

int Zombie::getZAttack(){
    return attack_;
}

int Zombie::getZRange(){
    return range_;
}

char Zombie::getZHeading(){
    return heading_;
}

void Zombie::setZombieAttributes(int n, gameBoard &gameBoard){
    {
            // set Positions
            const char letters[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

            x_ = rand() % gameBoard.getDimX()+1;
            y_ = rand() % gameBoard.getDimY()+1;
            
            heading_ = letters[n];
            // set Health, Attack and Attack Range

            health_ = rand() % 300 + 50;
            attack_ = rand() % 70 + 10;


            if (gameBoard.getDimX() > gameBoard.getDimY()){
                range_ = rand() % x_ + 1;
            }
            else{
                range_ = rand() % y_+ 1;
            }

            bool exists = false;
            for (int i=0; i<n; i++){
                if (gameBoard.getObject(x_, y_) == letters[i]){
                    exists = true;
                }
            }
            if ((x_ == (gameBoard.getDimX()+1)/2 && y_ == (gameBoard.getDimY()+1)/2) || exists){

                bool same = false;
                while (not same){
                    srand(time(NULL));
                    x_ = rand() % gameBoard.getDimX()+1;
                    y_ = rand() % gameBoard.getDimY()+1;
                    for (int i=0; i<n; i++){
                        if (gameBoard.getObject(x_, y_) == letters[i]){
                            exists = true;
                        }
                        else{
                            exists = false;
                        }
                    }
                    if ((x_ == (gameBoard.getDimX()+1)/2 && y_ == (gameBoard.getDimY()+1)/2) || exists){
                    }
                    else{
                        same=true;
                    }
                    
                }
                gameBoard.setObject(x_, y_, heading_);    
            }

            else{
                gameBoard.setObject(x_, y_, heading_);
            }
        }
}

void Zombie::moveZombie(int n, Zombie &zombie, gameBoard &gameBoard){

    cout << "Zombie " << n+1 << "'s Turn" << endl;
    cout << "------------------" << endl;
    int randMove;
    bool valid = false;
    while (not valid){
        randMove = rand() % 4+1;
        int y = gameBoard.getDimY();
        int x = gameBoard.getDimX();
        const char letters[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        // cout << "randMove before: " << randMove << endl;
        // cout << "x              : " << zombie.getZX() << endl;
        // cout << "y              : " << zombie.getZY() << endl;
        // cout << "dimX           : " << x << endl;
        // cout << "dimY           : " << y << endl;

        bool exists = false;

        // cant go up if y==dimY
        // cant go down if y==1
        // cant go left if x==1
        // cant go right if x==dimX

        if (randMove==1 && zombie.getZY()!=y){    
            if (
               gameBoard.getObject(x_,y_+1)=='1'
            || gameBoard.getObject(x_,y_+1)=='2' 
            || gameBoard.getObject(x_,y_+1)=='3'
            || gameBoard.getObject(x_,y_+1)=='4' 
            || gameBoard.getObject(x_,y_+1)=='5'
            || gameBoard.getObject(x_,y_+1)=='6' 
            || gameBoard.getObject(x_,y_+1)=='7'
            || gameBoard.getObject(x_,y_+1)=='8' 
            || gameBoard.getObject(x_,y_+1)=='9'
            || gameBoard.getObject(x_,y_+1)=='A'){
                // cout << "Zombie cannot move UP" << endl;
            } // problem arise when && changed to || (same for all 4 cases)
            else{
                valid=true;
                gameBoard.setObject(x_, y_, ' ');
                y_++;
                gameBoard.setObject(x_, y_, heading_);
                cout << "Moves Up" << endl;
            }
        }
        
        if (randMove==2 && zombie.getZY()!=1){
            if (
               gameBoard.getObject(x_,y_-1)=='1'
            || gameBoard.getObject(x_,y_-1)=='2' 
            || gameBoard.getObject(x_,y_-1)=='3'
            || gameBoard.getObject(x_,y_-1)=='4' 
            || gameBoard.getObject(x_,y_-1)=='5'
            || gameBoard.getObject(x_,y_-1)=='6' 
            || gameBoard.getObject(x_,y_-1)=='7'
            || gameBoard.getObject(x_,y_-1)=='8' 
            || gameBoard.getObject(x_,y_-1)=='9'
            || gameBoard.getObject(x_,y_-1)=='A'){
                // cout << "Zombie CANNOT move DOWN" << endl;
            } 
            else{
                valid=true;
                gameBoard.setObject(x_, y_, ' ');
                y_--;
                gameBoard.setObject(x_, y_, heading_);
                cout << "Moves Down" << endl;
            }
        }
        
        if (randMove==3 && zombie.getZX()!=1){
            if (
               gameBoard.getObject(x_-1,y_)=='1'
            || gameBoard.getObject(x_-1,y_)=='2' 
            || gameBoard.getObject(x_-1,y_)=='3'
            || gameBoard.getObject(x_-1,y_)=='4' 
            || gameBoard.getObject(x_-1,y_)=='5'
            || gameBoard.getObject(x_-1,y_)=='6' 
            || gameBoard.getObject(x_-1,y_)=='7'
            || gameBoard.getObject(x_-1,y_)=='8' 
            || gameBoard.getObject(x_-1,y_)=='9'
            || gameBoard.getObject(x_-1,y_)=='A'){
                // cout << "Zombie CANNOT move LEFT" << endl;
            } 
            else{
                valid=true;
                gameBoard.setObject(x_, y_, ' ');
                x_--;
                gameBoard.setObject(x_, y_, heading_);
                cout << "Moves Left" << endl;
            }
        }  
        
        if (randMove==4 && zombie.getZX()!=x){
            if (
               gameBoard.getObject(x_+1,y_)=='1'
            || gameBoard.getObject(x_+1,y_)=='2' 
            || gameBoard.getObject(x_+1,y_)=='3'
            || gameBoard.getObject(x_+1,y_)=='4' 
            || gameBoard.getObject(x_+1,y_)=='5'
            || gameBoard.getObject(x_+1,y_)=='6' 
            || gameBoard.getObject(x_+1,y_)=='7'
            || gameBoard.getObject(x_+1,y_)=='8' 
            || gameBoard.getObject(x_+1,y_)=='9'
            || gameBoard.getObject(x_+1,y_)=='A'){
                // cout << "Zombie CANNOT move RIGHT" << endl;
            } 
            else{
                valid=true;
                gameBoard.setObject(x_, y_, ' ');
                x_++;
                gameBoard.setObject(x_, y_, heading_);
                cout << "Moves Right" << endl;
            }
        } 
    }
    // cout << "randMove after: " << randMove << endl;  
}

void test()
{
    gameBoard gameBoard;
    Alien alien;
    Arrow arrow;

    int col = 7, row =5;
    string command;
    int x,y;
    string direction;
    int numOfZombies = 2;

    char s;
    s = 'M'; //M = Alien's turn/move

    cout << "----------Welcome Player----------" << endl;
    cout << "Number of Rows = " << row << endl;
    cout << "Number of Columns = " << col << endl;
    cout << "Number of Zombies = " << numOfZombies << endl;
    cout << "----------------------------------" << endl;

    char ed;
    cout << "Do you want to edit the Game Board (y/n)? ";
    cin >> ed;
    if (ed == 'y')
    {
        cout << "Please enter an ODD number of Rows = ";
        cin >> row;
        cout << "Please enter an ODD number of Columns = ";
        cin >> col;
        cout << "Please enter a number of Zombies = ";
        cin >> numOfZombies;
        cout << "-----------Game Board------------" << endl;
        cout << "Number of Rows = " << row << endl;
        cout << "Number of Columns = " << col << endl;
        cout << "Number of Zombies = " << numOfZombies << endl;
        cout << "---------------------------------" << endl;
        cout << "Let's Play!" << endl;
    }
    else if (ed == 'n')
    {
        cout << endl;
        cout << "Let's Play!" << endl;
        row = 5;
        col = 7;
    }
    else
    {
        cout << "Please enter the correct input" << endl;
    }
    gameBoard.init(col,row);
    alien.land(gameBoard);
    // gameBoard.display();
    Zombie zombies[numOfZombies];
    for(int i=0; i<numOfZombies; i++){
        zombies[i].setZombieAttributes(i, gameBoard);
    }
    //gameBoard.display();
    while (alien.getMove()!='S'){
        system("read -n 1 -s -p \"Press any key to continue...\"");
        gameBoard.display();
        cout << "--> Alien's    Life: " << alien.getLife() << ", Attack:  " << alien.getAttack() << endl;
        for(int i=0; i<numOfZombies; i++){
            cout << "    Zombie " << i+1 << "'s Life: " << zombies[i].getZHealth() << ", Attack: " << zombies[i].getZAttack() << endl;
        }
        cout << endl;
        cout << "Enter command: ";
        cin >> command;
        toupper(command[0]);
        cout << endl;

        if (command == "Up" || command == "up"){
            alien.up(gameBoard,alien);
        }
        else if (command == "Down" || command == "down"){
            alien.down(gameBoard,alien);
        }
        else if (command == "Left" || command == "left"){
            alien.left(gameBoard,alien);
        }
        else if (command == "Right" || command == "right"){
            alien.right(gameBoard,alien);
        }
        else if (command == "Arrow" || command == "arrow"){
            cout << "Enter row, column and direction = ";
            cin >> y >> x >> direction;
            arrow.setPosition(gameBoard, x, y);
            if (direction == "left"){
                arrow.left(gameBoard);
            }
            else if (direction == "right"){
                arrow.right(gameBoard);
            }
            else if (direction == "up"){
                arrow.up(gameBoard);
            }
            else if (direction == "down"){
                arrow.down(gameBoard);
            }
            gameBoard.display();
            system("read -n 1 -s -p \"Press any key to continue...\"");    
        }
        else if (command == "Quit" || command == "quit"){
            cout << "Goodbye" << endl;
            break;
        }
        else if (command == "Zombie || zombie"){
            Zombie zombies[numOfZombies];
                for(int i=0; i<numOfZombies; i++){
                    zombies[i].print(zombies[i], gameBoard);
                }           
        }
        else if (command == "Help" || "help"){
            cout <<"********************************" << endl;
            cout << "Valid Commands: " << endl;
            cout <<"********************************" << endl;
            cout << "Up = Move upwards" << endl;
            cout << "Down = Move downwards" << endl;
            cout << "Left = Move left" << endl;
            cout << "Right = Move right" << endl;
            cout << "Quit = Quit" << endl;
            cout << "Zombie = Show zombie attributes" << endl;
            cout <<"********************************" << endl;
            cout << endl;
        }

        if (alien.getMove()=='S'){
        gameBoard.display();
        cout << "    Alien's turn has ended." << endl;
        gameBoard.display();
        for(int i=0; i<numOfZombies; i++){
            zombies[i].moveZombie(i, zombies[i], gameBoard);
            zombies[i].print(zombies[i], gameBoard);
            system("read -n 1 -s -p \"Press any key to continue...\"");
            gameBoard.display();
            }
        }
        cout << "Zombie's turn has ended." << endl;
    }  
}

int main(){
    srand(5);
    //srand(time(NULL));
    test();
}