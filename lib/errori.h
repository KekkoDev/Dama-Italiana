#ifndef ERRORI_H
#define ERRORI_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : errori.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Libreria per Errori di inserimento/runtime
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "pedina.h"
#include "logica.h"
#include "supporto_grafica.h"
using namespace std;

class Errori
{
public:
    void _erroreDiagonale(int &x, int &y, int &x1, int &y1);
    void _erroremossaDp(Pedina pedina, int &x, int &y, int &x1, int &y1, char p);
    void _errorOccupata(Pedina pedina, int &x, int &y, int &x1, int &y1, string out);
    void _errNome(string &nome);
    void _errCoord(int &x, int &y, string out);
    void _errVuota(int &x, int &y, string out);
    void _errVuota2(int &x, int &y, string out);
};

void Errori::_erroreDiagonale(int &x, int &y, int &x1, int &y1)
{
    Color color;
    bool found = false;
    char s;
    do
    {
        if (_cntrlDiagonale(x, y, x1, y1))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Diagonale Errata!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Diagonale Errata!]\n");
#endif
#ifdef _WIN32
            color.foreground(79);
            cout << "[Vuoi cambiare Pedina?] (s/[N]) > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(WHITE_INTENSE, RED, "[Vuoi cambiare Pedina?] (s/[N]) > ");
#endif
            cin >> s;
            if (s == 's' || s == 'S')
            {
                cout << "[Seleziona Pedina] > ";
                cin >> x >> y;
            }
            cout << "[Dova la posiziono?] > ";
            cin >> x1 >> y1;
        }
    } while (!found);
}

void Errori::_erroremossaDp(Pedina pedina, int &x, int &y, int &x1, int &y1, char p)
{
    Color color;
    bool found = false;
    char s;
    do
    {
        if (_cntrlmossaDp(pedina, x, y, p) == 1)
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Mossa non Valida!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Mossa non Valida!]\n");
#endif
#ifdef _WIN32
            color.foreground(79);
            cout << "[Vuoi cambiare Pedina?] (s/[N]) > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(WHITE_INTENSE, RED, "[Vuoi cambiare Pedina?] (s/[N]) > ");
#endif
            cin >> s;
            if (s == 's' || s == 'S')
            {
                cout << "[Seleziona Pedina] > ";
                cin >> x >> y;
            }
            cout << "[Dove la posiziono?] > ";
            cin >> x1 >> y1;
        }
    } while (!found);
}

void Errori::_errorOccupata(Pedina pedina, int &x, int &y, int &x1, int &y1, string out)
{
    Color color;
    bool found = false;
    char s;
    do
    {
        if (_cntrlOccupata(pedina, x1, y1))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Posizione Occupata!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Posizione Occupata!]\n");
#endif
#ifdef _WIN32
            color.foreground(79);
            cout << "[Vuoi cambiare Pedina?] (s/[N]) > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(WHITE_INTENSE, RED, "[Vuoi cambiare Pedina?] (s/[N]) > ");
#endif
            cin >> s;
            if (s == 's' || s == 'S')
            {
                cout << "[Seleziona Pedina] > ";
                cin >> x >> y;
            }
            cout << out;
            cin >> x1 >> y1;
        }
    } while (!found);
}

void Errori::_errNome(string &nome)
{
    Color color;
    bool found = false;
    do
    {
        if (!_cntrlNome(nome))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Nessun Nome inserito!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Nessun Nome inserito!]") << endl;
#endif
            cout << "[Inserisci Nome] > ";
            fflush(stdin);
            getline(cin, nome);
        }
    } while (!found);
}

void Errori::_errCoord(int &x, int &y, string out)
{
    Color color;
    bool found = false;
    do
    {
        if (_cntrlCoordinate(x, y))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Coordinate Inserite non Valide!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Coordinate Inserite non Valide!]") << endl;
#endif
            cout << out;
            cin >> x >> y;
        }
    } while (!found);
}

void Errori::_errVuota(int &x, int &y, string out)
{
    Color color;
    bool found = false;
    do
    {
        if (!_cntrlVuoto(x, y))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Cella Vuota!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Cella Vuota!]") << endl;
#endif
            cout << out;
            cin >> x >> y;
        }
    } while (!found);
}

void Errori::_errVuota2(int &x, int &y, string out)
{
    Color color;
    bool found = false;
    do
    {
        if (!_cntrlVuoto(x, y))
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Cella Vuota!]";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Cella Vuota!]") << endl;
#endif
            cout << out;
            cin >> x >> y;
        }
    } while (!found);
}

#endif /* ERRORI_H */
