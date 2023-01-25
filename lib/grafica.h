#ifndef GRAFICA_H
#define GRAFICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : grafica.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Libreria classe Grafica
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "pedina.h"
#include "giocatore.h"
#include "supporto_grafica.h"
using namespace std;

#ifdef _WIN32
const string cerchio = " ● ";
const string cerchio_vuoto = " ○ ";
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
const string cerchio = " \u25CF ";       // cerchio pieno
const string cerchio_vuoto = " \u25CB "; // cerchio vuoto
#endif

class Grafica
{
public:
    void banner();
    void stampa(Pedina pedina);
    void tabellone(Giocatore g, Giocatore g2);
    string generaPedine(int dim);
};

void Grafica::banner()
{
    Color color;
#ifdef _WIN32
    color.foreground(GREEN_INTESE);
    cout << "  ___     ____  ___ ___   ____  ____  ______   ____  _      ____   ____  ____    ____ \n";
    cout << " |   \\   /    T|   T   T /    Tl    j|      T /    T| T    l    j /    T|    \\  /    T\n";
    cout << " |    \\ Y  o  || _   _ |Y  o  | |  T |      |Y  o  || |     |  T Y  o  ||  _  YY  o  |\n";
    color.foreground(WHITE_INTENSE);
    cout << " |  D  Y|     ||  \\_/  ||     | |  | l_j  l_j|     || l___  |  | |     ||  |  ||     |\n";
    cout << " |     ||  _  ||   |   ||  _  | |  |   |  |  |  _  ||     T |  | |  _  ||  |  ||  _  |\n";
    color.foreground(RED_INTENSE);
    cout << " |     ||  |  ||   |   ||  |  | j  l   |  |  |  |  ||     | j  l |  |  ||  |  ||  |  |\n";
    cout << " l_____jl__j__jl___j___jl__j__j|____j  l__j  l__j__jl_____j|____jl__j__jl__j__jl__j__j\n\n";
    color.foreground(YELLOW_INTENSE);
    cout << "\t\t\t"
         << "By> Francesco Pio Nocerino\n";
    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(GREEN_LIGHT_SUPER, "  ___     ____  ___ ___   ____  ____  ______   ____  _      ____   ____  ____    ____ \n");
    cout << color.foreground(GREEN_LIGHT_SUPER, " |   \\   /    T|   T   T /    Tl    j|      T /    T| T    l    j /    T|    \\  /    T\n");
    cout << color.foreground(GREEN_LIGHT_SUPER, " |    \\ Y  o  || _   _ |Y  o  | |  T |      |Y  o  || |     |  T Y  o  ||  _  YY  o  |\n");
    cout << color.foreground(WHITE_INTENSE, " |  D  Y|     ||  \\_/  ||     | |  | l_j  l_j|     || l___  |  | |     ||  |  ||     |\n");
    cout << color.foreground(WHITE_INTENSE, " |     ||  _  ||   |   ||  _  | |  |   |  |  |  _  ||     T |  | |  _  ||  |  ||  _  |\n");
    cout << color.foreground(RED_INTENSE, " |     ||  |  ||   |   ||  |  | j  l   |  |  |  |  ||     | j  l |  |  ||  |  ||  |  |\n");
    cout << color.foreground(RED_INTENSE, " l_____jl__j__jl___j___jl__j__j|____j  l__j  l__j__jl_____j|____jl__j__jl__j__jl__j__j\n");
    cout << "\t\t\t" << color.foreground(YELLOW, "By> Francesco Pio Nocerino");
#endif

    cout << endl
         << endl;
}

void Grafica::stampa(Pedina pedina)
{

#ifdef _WIN32
    _UTF_16;
#endif
    Color color;
    string cella;
    for (int i = 0; i < RC; i++)
        cout << "  " << i; // stampa delle posizioni della matrice in orizzontale
    cout << endl;
    for (int i = 0; i < RC; i++)
    {
        cout << i << setw(3); // stampa delle posizioni della matrice in verticale
        for (int j = 0; j < RC; j++)
        {
            cella.clear();
            cella = pedina.get_scacchiera(i, j);
            if (cella.compare(" O ") == 0)
            {
#ifdef _WIN32
                color.foreground(RED_INTENSE);
                cout << cerchio;
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.background(RED_INTENSE, ULTRA_BLACK, cerchio);
#endif
            }
            else
            {
                if (cella.compare(" X ") == 0)
                {
#ifdef _WIN32
                    color.foreground(BLUE_INTESE);
                    cout << cerchio;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(BLUE, ULTRA_BLACK, cerchio);
#endif
                }
                else if (cella.compare(" S ") == 0)
                {
#ifdef _WIN32
                    color.foreground(BLUE_WHITE); // dama "X"
                    cout << cerchio_vuoto;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, BLUE_INTESE, cerchio_vuoto);
#endif
                }
                else if (cella.compare(" D ") == 0) // dama "O"
                {
#ifdef _WIN32
                    color.foreground(RED_WHITE);
                    cout << cerchio_vuoto;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, RED_INTENSE, cerchio_vuoto);
#endif
                }
                else if (cella.compare(" / ") == 0)
                {
                    cella = "   ";
#ifdef _WIN32
                    color.foreground(WHITE_WHITE_INTENSE);
                    cout << cella;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, WHITE_INTENSE, cella);
#endif
                }
                else
                {
                    cella = "   ";
#ifdef _WIN32
                    cout << cella;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(ULTRA_BLACK, ULTRA_BLACK, cella);
#endif
                }
            }
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

void Grafica::tabellone(Giocatore g, Giocatore g2)
{
    Color color;
    cout << "+-----------------------------+\n";
#ifdef _WIN32
    color.foreground(RED);
    cout << g.get_nome();
    color.reset();
    cout << " > ";
    color.foreground(BLUE);
    cout << generaPedine(g.get_punti()) << endl;
    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(RED_INTENSE, g.get_nome());
    cout << " > ";
    cout << color.foreground(BLUE_INTESE, generaPedine(g.get_punti())) << endl;
#endif

#ifdef _WIN32
    color.foreground(BLUE_INTESE);
    cout << g2.get_nome();
    color.reset();
    cout << " > ";
    color.foreground(RED_INTENSE);
    cout << generaPedine(g2.get_punti()) << endl;
    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(BLUE_INTESE, g2.get_nome());
    cout << " > ";
    cout << color.foreground(RED_INTENSE, generaPedine(g2.get_punti())) << endl;
#endif
    cout << "+-----------------------------+\n";
}

string Grafica::generaPedine(int dim)
{
    string r = " ";
    for (int i = 0; i < dim; i++)
        r += cerchio;
    return r;
}
#endif /* GRAFICA_H */
