/**
 * @file main.cpp
 * @brief Juego tipo Pong en consola utilizando C++ y la librería <conio.h> para entrada sin bloqueo.
 */

 #include <iostream>
 #include <thread>
 #include <chrono>
 #include <conio.h>
 #ifdef _WIN32
 #include <windows.h>
 #endif
 
 using namespace std;
 
 // ============================================================================
 // VARIABLES GLOBALES DEL JUEGO
 // ============================================================================
 
 /** Posición en X de la pelota */
 int ballPosX = 40;
 /** Posición en Y de la pelota */
 int ballPosY = 12;
 /** Velocidad de la pelota en X */
 int ballVelocityX = 1;
 /** Velocidad de la pelota en Y */
 int ballVelocityY = 1;
 /** Posición de la pala izquierda */
 int paddle1Pos = 12;
 /** Posición de la pala derecha */
 int paddle2Pos = 12;
 /** Ancho del tablero */
 const int WIDTH = 80;
 /** Alto del tablero */
 const int HEIGHT = 24;
 /** Puntaje del jugador 1 */
 int score1 = 0;
 /** Puntaje del jugador 2 */
 int score2 = 0;
 /** Variable para indicar si el juego ha terminado */
 bool gameOver = false;
 /** Bandera para reiniciar la pelota después de un punto */
 bool ballReset = false;
 
 // ============================================================================
 // FUNCIONES
 // ============================================================================
 
 /**
  * @brief Mueve el cursor de la consola a una posición específica.
  * @param x Coordenada horizontal.
  * @param y Coordenada vertical.
  */
 void gotoxy(int x, int y) {
 #ifdef _WIN32
     COORD coord;
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 #else
     cout << "\033[" << y << ";" << x << "H";
 #endif
 }
 
 /**
  * @brief Dibuja el borde del tablero de juego una sola vez al inicio.
  */
 void draw() {
     for (int y = 0; y < HEIGHT; y++) {
         for (int x = 0; x < WIDTH; x++) {
             if (x == 0 || x == WIDTH - 1) {
                 cout << "|";
             } else if (y == 0 || y == HEIGHT - 1) {
                 cout << "-";
             } else {
                 cout << " ";
             }
         }
         cout << endl;
     }
 }
 
 /**
  * @brief Dibuja y actualiza la posición de las palas en la pantalla.
  */
 void updatePaddles() {
     // Pala izquierda
     for (int i = 0; i < 5; i++) {
         gotoxy(2, paddle1Pos + i);
         cout << " ";
     }
     for (int i = 0; i < 5; i++) {
         gotoxy(2, paddle1Pos + i);
         cout << "|";
     }
 
     // Pala derecha
     for (int i = 0; i < 5; i++) {
         gotoxy(WIDTH - 3, paddle2Pos + i);
         cout << " ";
     }
     for (int i = 0; i < 5; i++) {
         gotoxy(WIDTH - 3, paddle2Pos + i);
         cout << "|";
     }
 }
 
 /**
  * @brief Mueve la pelota y la redibuja en su nueva posición.
  */
 void updateBall() {
     gotoxy(ballPosX, ballPosY);
     cout << " ";  // Borrar la posición anterior
 
     ballPosX += ballVelocityX;
     ballPosY += ballVelocityY;
 
     gotoxy(ballPosX, ballPosY);
     cout << "O";
 }
 
 /**
  * @brief Captura la entrada del usuario para controlar las palas y terminar el juego.
  */
 void input() {
     if (_kbhit()) {
         char ch = _getch();
 
         if (ch == 'w' && paddle1Pos > 1) paddle1Pos--;
         if (ch == 's' && paddle1Pos < HEIGHT - 6) paddle1Pos++;
         if (ch == 'i' && paddle2Pos > 1) paddle2Pos--;
         if (ch == 'k' && paddle2Pos < HEIGHT - 6) paddle2Pos++;
         if (ch == 'q') gameOver = true;
     }
 }
 
 /**
  * @brief Lógica del juego: colisiones, rebotes y control de puntaje.
  */
 void logic() {
     // Rebote superior e inferior
     if (ballPosY == 0 || ballPosY == HEIGHT - 1)
         ballVelocityY = -ballVelocityY;
 
     // Rebote con palas
     if (ballPosX == 3 && ballPosY >= paddle1Pos && ballPosY < paddle1Pos + 5)
         ballVelocityX = -ballVelocityX;
     if (ballPosX == WIDTH - 4 && ballPosY >= paddle2Pos && ballPosY < paddle2Pos + 5)
         ballVelocityX = -ballVelocityX;
 
     // Puntos para el jugador contrario si se pasa la pelota
     if (ballPosX == 0) {
         score2++;
         ballReset = true;
     }
     if (ballPosX == WIDTH - 1) {
         score1++;
         ballReset = true;
     }
 
     // Reiniciar la pelota
     if (ballReset) {
         ballPosX = WIDTH / 2;
         ballPosY = HEIGHT / 2;
         ballVelocityX = -ballVelocityX;
         ballReset = false;
     }
 }
 
 /**
  * @brief Actualiza el puntaje mostrado en la parte superior de la pantalla.
  */
 void updateScore() {
     gotoxy(WIDTH / 2 - 10, 0);
     cout << "Jugador 1: " << score1 << "  Jugador 2: " << score2;
 }
 
 /**
  * @brief Función principal. Inicializa y corre el bucle principal del juego.
  * @return int Código de salida del programa.
  */
 int main() {
     draw();
 
     while (!gameOver) {
         updateBall();
         updatePaddles();
         input();
         logic();
         updateScore();
 
         Sleep(50);  // Control de velocidad
     }
 
     cout << "¡Juego terminado!" << endl;
     return 0;
 }
 