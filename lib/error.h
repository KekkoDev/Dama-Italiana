#ifndef ERROR_H
#define ERROR_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : error.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria Gestione Errori
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "logica.h"
#include "pedina.h"
#include "supporto_grafica.h"
using namespace std;

class Error
{
public:
    void err_diagonale(bool f, int &x, int &y, int &x1, int &y1); // errore diagonale
    void err_dama(bool f, int &x, int &y, int &x1, int &y1);
    void pieno(string m[RC][RC], int &x1, int &y1, string out);    // controllo se la posizione e' piena
    void ps_bianche(string m[RC][RC], int &x, int &y, string out); // controllo se la posizione e' bianca
    void cntrl_ins(int &x, int &y, string out);                    // controlla le coordinate inserite se sono valide
    void vuota(string m[RC][RC], int &x, int &y, string out);      // controlla se la posizione sia vuota
    void err_pedina(string m[RC][RC], int &x, int &y, char p, string out);
    void cntrl_ins2(int &x, int &y, int &x1, int &y1, char p, string out);
    void cntrl_nome(string &str);
};

void Error::err_diagonale(bool f, int &x, int &y, int &x1, int &y1)
{
    Color color;
    Logica l;
    bool found = f;
    char s;
    while (!found)
    {
        found = l.diagonale(x, y, x1, y1);
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Errore Diagonale NON Valida!!]\n";
            color.reset();
            color.foreground(YELLOW_INTENSE);
            cout << "Vuoi cambiare pedina? (s/[N]) > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Errore Diagonale NON Valida!!]") << endl;
            cout << color.foreground(YELLOW_INTENSE, "Vuoi cambiare pedina? (s/[N]) > ");
#endif
            cin >> s;
            if (s == 's' || s == 'S')
            {
#ifdef _WIN32
                color.foreground(BLUE_INTESE);
                cout << "[Seleziona Pedina] > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(BLUE_INTESE, "[Seleziona Pedina] > ");
#endif

                cin >> x >> y;
            }
#ifdef _WIN32
            color.foreground(BLUE_INTESE);
            cout << "[Dove la sposto?] > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(BLUE_INTESE, "[Dove la sposto?] > ");
#endif
            cin >> x1 >> y1;
        }
    }
}

void Error::err_dama(bool f, int &x, int &y, int &x1, int &y1)
{
    Color color;
    Logica l;
    bool found = f;
    char s;
    while (!found)
    {
        found = l.diagonaleD(x, y, x1, y1);
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Errore Diagonale dama NON Valida!!]\n";
            color.reset();
            color.foreground(YELLOW_INTENSE);
            cout << "Vuoi cambiare pedina? (s/[N]) > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Errore Diagonale dama NON Valida!!]") << endl;
            cout << color.foreground(YELLOW_INTENSE, "Vuoi cambiare pedina? (s/[N]) > ");
#endif
            cin >> s;
            if (s == 's' || s == 'S')
            {
#ifdef _WIN32
                color.foreground(BLUE_INTESE);
                cout << "[Seleziona Pedina] > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(BLUE_INTESE, "[Seleziona Pedina] > ");
#endif

                cin >> x >> y;
            }
#ifdef _WIN32
            color.foreground(BLUE_INTESE);
            cout << "[Dove la sposto?] > ";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(BLUE_INTESE, "[Dove la sposto?] > ");
#endif
            cin >> x1 >> y1;
        }
    }
}

void Error::pieno(string m[RC][RC], int &x1, int &y1, string out)
{
    Color color;
    bool found = false;
    do
    {
        if (m[x1][y1].compare(" _ ") == 0)
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Posizione inserita piena!]\n";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(RED_INTENSE, "[Posizione inserita piena!]") << "\n";
#endif

            cout << out;
            cin >> x1 >> y1;
        }
    } while (!found);
}

void Error::ps_bianche(string m[RC][RC], int &x, int &y, string out)
{
    Color color;

    while (m[x][y].compare(" / ") == 0)
    {

#ifdef _WIN32
        color.foreground(RED_WHITE_INTENSE);
        cout << "[Posizione inserita vuota!]\n";
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << color.foreground(RED_INTENSE, "[Posizione inserita vuota!]") << "\n";
#endif
        cout << out;
        cin >> x >> y;
    }
}

void Error::cntrl_ins(int &x, int &y, string out)
{
    Color color;
    bool found = false;
    do
    {
        if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
            found = true;
        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Posizione NON valida!]\n";
            color.foreground(BLUE_INTESE);
            cout << out;
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(RED_INTENSE, "[Posizione NON valida!]") << "\n";
            cout << color.foreground(BLUE_INTESE, out);
#endif

            cin >> x >> y;
        }

    } while (!found);
}

void Error::vuota(string m[RC][RC], int &x, int &y, string out)
{
    Color color;
    string cella = get_cella(m, x, y);
    while (cella.compare(" _ ") == 0)
    {

#ifdef _WIN32
        color.foreground(RED_WHITE_INTENSE);
        cout << "[Posizione inserita vuota!]\n";
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << color.foreground(RED_INTENSE, "[Posizione inserita vuota!]") << "\n";
#endif
        cout << out;
        cin >> x >> y;
        cella = get_cella(m, x, y);
    }
}

void Error::err_pedina(string m[RC][RC], int &x, int &y, char p, string out)
{
    Color color;
    Pedina ped;
    bool found = false, f2;
    while (!found)
    {

        if (!found)
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Posizione inserita Errata!]\n";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(RED_INTENSE, "[Posizione inserita Errata!]") << "\n";
#endif
            cout << out;
            cin >> x >> y;
            f2 = ped.rm_pedina(m, x, y, p);
            if (f2)
            {
                found = true;
            }
        }
    }
}

void Error::cntrl_ins2(int &x, int &y, int &x1, int &y1, char p, string out)
{
    Color color;
    bool found = false;
    char s;
    if (p == 'O')
    {

        do
        {
            if (x > 2)
                found = true;
            if (!found)
            {
#ifdef _WIN32
                color.foreground(RED_WHITE_INTENSE);
                cout << "[Posizione inserita Errata!]\n";
                color.foreground(YELLOW_INTENSE);
                cout << "Vuoi cambiare pedina? (s/[N]) > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(RED_INTENSE, "[Posizione inserita Errata!]") << "\n";
                cout << color.foreground(YELLOW_INTENSE, "Vuoi cambiare pedina? (s/[N]) > ");
#endif
                cin >> s;
                if (s == 'S' || s == 's')
                {
                    cout << "[Seleziona Pedina] > ";
                    cin >> x1 >> y1;
                }
                cout << out;
                cin >> x >> y;
            }
        } while (!found);
    }
    else
    {

        do
        {
            if (x < 5)
                found = true;
            if (!found)
            {
#ifdef _WIN32
                color.foreground(RED_WHITE_INTENSE);
                cout << "[Posizione inserita Errata!]\n";
                color.foreground(YELLOW_INTENSE);
                cout << "Vuoi cambiare pedina? (s/[N]) > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(RED_INTENSE, "[Posizione inserita Errata!]") << "\n";
                cout << color.foreground(YELLOW_INTENSE, "Vuoi cambiare pedina? (s/[N]) > ");
#endif
                cin >> s;
                if (s == 'S' || s == 's')
                {
                    cout << "[Seleziona Pedina] > ";
                    cin >> x1 >> y1;
                }
                cout << out;
                cin >> x >> y;
            }
        } while (!found);
    }
}

void Error::cntrl_nome(string &str)
{
    Color color;
    while (str.empty())
    {
#ifdef _WIN32
        color.foreground(RED_WHITE_INTENSE);
        cout << "[Nome non inserito!]";
        color.reset();
        cout << endl;
        color.foreground(YELLOW);
        cout << "Inserisci Nome > ";
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << color.foreground(RED_INTENSE, "[Non non inserito!]") << endl;
        cout << color.foreground(YELLOW_LIGHT, "Inserisci Nome > ");
#endif
        fflush(stdin);
        getline(cin, str);
    }
}
#endif /* ERROR_H */
