#ifndef GRAFICA_H
#define GRAFICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : grafica.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria Grafica
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "giocatore.h"
#include "supporto_grafica.h"
using namespace std;
#define RC 8 // numero righe-colonne scacchiera

#ifdef _WIN32
const string cerchio = " ● ";
const string cerchio_vuoto = " ○ ";
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
const string cerchio = " \u25CF ";       // cerchio pieno
const string cerchio_vuoto = " \u25CB "; // cerchio vuoto
#endif

void banner();
void stampa_scacchiera(string m[RC][RC]); // stampa della scacchiera
string punti(int dim);
void stampa_punti(Giocatore g, Giocatore g2);

void banner()
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
    cout << " l_____jl__j__jl___j___jl__j__j|____j  l__j  l__j__jl_____j|____jl__j__jl__j__jl__j__j\n";
    color.foreground(WHITE);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(GREEN_LIGHT_SUPER, "  ___     ____  ___ ___   ____  ____  ______   ____  _      ____   ____  ____    ____ \n");
    cout << color.foreground(GREEN_LIGHT_SUPER, " |   \\   /    T|   T   T /    Tl    j|      T /    T| T    l    j /    T|    \\  /    T\n");
    cout << color.foreground(GREEN_LIGHT_SUPER, " |    \\ Y  o  || _   _ |Y  o  | |  T |      |Y  o  || |     |  T Y  o  ||  _  YY  o  |\n");
    cout << color.foreground(WHITE_INTENSE, " |  D  Y|     ||  \\_/  ||     | |  | l_j  l_j|     || l___  |  | |     ||  |  ||     |\n");
    cout << color.foreground(WHITE_INTENSE, " |     ||  _  ||   |   ||  _  | |  |   |  |  |  _  ||     T |  | |  _  ||  |  ||  _  |\n");
    cout << color.foreground(RED_INTENSE, " |     ||  |  ||   |   ||  |  | j  l   |  |  |  |  ||     | j  l |  |  ||  |  ||  |  |\n");
    cout << color.foreground(RED_INTENSE, " l_____jl__j__jl___j___jl__j__j|____j  l__j  l__j__jl_____j|____jl__j__jl__j__jl__j__j\n");
#endif

    cout << endl
         << endl;
}

void stampa_scacchiera(string m[RC][RC])
{
#ifdef _WIN32
    _UTF_16;
#endif
    Color color;
    for (int i = 0; i < RC; i++)
        cout << "  " << i; // stampa delle posizioni della matrice in orizzontale
    cout << endl;
    for (int i = 0; i < RC; i++)
    {
        cout << i << setw(3); // stampa delle posizioni della matrice in verticale
        for (int j = 0; j < RC; j++)
        {
            if (m[i][j].compare(" O ") == 0) // pedina1
            {
#ifdef _WIN32
                color.foreground(RED_INTENSE);
                cout << cerchio;
                color.foreground(WHITE);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.background(RED_INTENSE, ULTRA_BLACK, cerchio);
#endif
            }
            else
            {
                if (m[i][j].compare(" X ") == 0) // pedina2
                {
#ifdef _WIN32
                    color.foreground(BLUE_INTESE);
                    cout << cerchio;
                    color.foreground(WHITE);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(BLUE, ULTRA_BLACK, cerchio);
#endif
                }
                else if (m[i][j].compare(" S ") == 0)
                {
#ifdef _WIN32
                    color.foreground(BLUE_WHITE); // dama "X"
                    cout << cerchio_vuoto;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, BLUE_INTESE, cerchio_vuoto);
#endif
                }
                else if (m[i][j].compare(" D ") == 0) // dama "O"
                {
#ifdef _WIN32
                    color.foreground(RED_WHITE);
                    cout << cerchio_vuoto;
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, RED_INTENSE, cerchio_vuoto);
#endif
                }
                else if (m[i][j].compare(" / ") == 0) // posizioni bianche
                {
                    m[i][j] = "   ";
#ifdef _WIN32
                    color.foreground(WHITE_WHITE_INTENSE);
                    cout << m[i][j];
                    color.foreground(WHITE);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(WHITE_INTENSE, WHITE_INTENSE, m[i][j]);
#endif

                    m[i][j] = " / ";
                }
                else // posizioni nere
                {
                    m[i][j] = "   ";
#ifdef _WIN32
                    cout << m[i][j];
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.background(ULTRA_BLACK, ULTRA_BLACK, m[i][j]);
#endif

                    m[i][j] = " _ ";
                }
            }
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
string punti(int dim)
{
#ifdef _WIN32
    _UTF_16;
#endif
    string r;
    for (int i = 0; i < dim; i++)
    {
        r += cerchio;
    }
    return r;
}
void stampa_punti(Giocatore g, Giocatore g2)
{
    Color color;
    cout << "+--------------+\n";
#ifdef _WIN32

    cout << g.get_nome() << " > ";
    color.foreground(BLUE);
    cout << punti(g.get_punti()) << endl;
    color.reset();
    cout << g2.get_nome() << " > ";
    color.foreground(RED);
    cout << punti(g2.get_punti()) << endl;
    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << g.get_nome() << " > " << color.foreground(BLUE, punti(g.get_punti())) << endl;
    cout << g2.get_nome() << " > " << color.foreground(RED, punti(g2.get_punti())) << endl;
#endif

    cout << "+--------------+\n";
}

#endif /* GRAFICA_H */
