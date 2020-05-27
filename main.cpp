#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x, y, eatX, eatY, score;
int tailX[150], tailY[150];
int ktail;
enum eStep {STOP = 0, LEFT, RIGHT, UP, DOWN} ;
eStep s;


void Configyration() {
    gameOver = false;
    s = STOP;
    x = width/2 - 1;
    y = height/2 - 1;
    srand(time (NULL));
    eatX = rand() % (width - 1);
    eatY = rand() % height;
    score = 0;
}


void Painting(){
 int i, j;
 system ("cls");
 for (i = 0; i < width + 1; i++)
    cout << "#";
   cout << endl;


 for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++){
        if (j==0 || j== width - 1)
          cout << "#";


          if (i == y && j == x)
            cout << "8";
          else if (i == eatY && j == eatX)
            cout << "@";
          else{
                bool pr = false;
                for(int n = 0; n< ktail; n++){
                  if( tailX[n] == j && tailY[n] == i){
                    pr = true;
                    cout << "o";
                  }
                }
             if (!pr)
            cout << " ";
          }
    }
    cout << endl;
 }

   for (i = 0; i < width + 1; i++)
    cout << "#";
   cout << endl;
   cout << "СЧЕТ ИГРЫ: " << score << endl;
cout << "ПРАВИЛА ИГРЫ:·Управление змейкой происходит через клавиши «WASD»(язык клавиатуры должен быть переключён на английский)"<< endl;
cout << "Когда змейка достигает значка @, её длина  увеличивается на одну клетку. "<< endl;
cout << "Когда змейка втыкается в саму себя, вы проигрываете."<< endl;
cout << "Достигнув края поля, змейка появляется с другой стороны поля."<< endl;
cout << "Суть игры увеличить змейку на столько, на сколько это возможно."<< endl;

}

void Input(){
  if (_kbhit()){
    switch (_getch())
    {
    case 'a' :
    s = LEFT;
    break;
     case 'd':
    s = RIGHT;
    break;
      case 's':
    s = DOWN;
    break;
     case 'w':
    s = UP;
    break;
    case 'z':
    gameOver = true;
    break;

    }
  }
}

void Embodiment() {
    int pX = tailX[0];
    int pY = tailY[0];
    int p2X, p2Y;
    tailX[0] = x; tailY[0] = y;
    for (int i = 1; i < ktail; i++){
    p2X = tailX[i];
    p2Y = tailY[i];
    tailX[i] = pX;
    tailY[i] = pY;
    pX = p2X;
    pY = p2Y;
    }
    switch(s){
    case LEFT:
        x--;
    break;
    case RIGHT:
        x++;
    break;
    case DOWN:
        y++;
    break;
    case UP:
        y--;
    break;

    }

   if (x >= width - 1)
    x = 0;
   else if (x < 0)
    x = width - 2;

   if (y >= height - 1)
    y = 0;
   else if (y < 0)
    y = height - 2;

for (int i = 0; i < ktail; i++){
    if (tailX[i] == x && tailY[i] == y)
        gameOver = true;
}

    if (x == eatX && y == eatY) {
        score++;
    eatX = rand() % (width - 1);
    eatY = rand() % height;
    ktail++;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    Configyration();
    while (!gameOver)
        {
         Painting();
         Input();
         Embodiment();
        }

    return 0;
}
