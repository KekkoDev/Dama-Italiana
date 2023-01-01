#ifndef LOGICA_H
#define LOGICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : logica.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria Logica
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
#define RC 8 // numero righe-colonne della scacchiera

string get_cella(string m[RC][RC], int a, int b); // ritorna la cella

class Logica
{
public:
    bool diagonale(int x, int y, int x1, int y1);                             // calcolo diagonali
    bool mossaDoppia(string m[RC][RC], int x, int y, int x1, int y1, char p); // controllo possibilta di mossa doppia
    bool dama(string m[RC][RC]);                                              // controllo se c'e' una dama
    bool diagonaleD(int x, int y, int x1, int y1);                            // controllo diagonale Dama
    
};

bool Logica::diagonale(int x, int y, int x1, int y1)
{
    if (abs(x - x1) == 1 && abs(y - y1) == 1)
        return true;
    else
        return false;
}

bool Logica::mossaDoppia(string m[RC][RC], int x, int y, int x1, int y1, char p)
{
    bool found = false;
    if (p == 'O')
    { // se la prossima posizione a quella selezionata e' X,O allora la mossa e' valida e ritorna vero
        if (m[x + 1][y + 1].compare(" O ") == 0 || m[x + 1][y + 1].compare(" X ") == 0 || m[x + 1][y - 1].compare(" O ") == 0 || m[x + 1][y - 1].compare(" X ") == 0)
        {
            found = true;
        }
    }
    else
    {
        if (m[x - 1][y - 1].compare(" O ") == 0 || m[x - 1][y - 1].compare(" X ") == 0 || m[x - 1][y + 1].compare(" O ") == 0 || m[x - 1][y + 1].compare(" X ") == 0)
            found = true;
    }
    return found;
}

bool Logica::dama(string m[RC][RC])
{
    bool found = false;
    string t;
    for (int i = 0; i < RC; i++)
    {
        for (int j = 0; j < RC; j++)
        {
            t.clear();
            t = get_cella(m, i, j);
            if (i == 0 && t.compare(" X ") == 0)
            {
                m[i][j] = " S ";
                found = true;
            }
        }
    }

    for (int i = 0; i < RC; i++)
    {
        for (int j = 0; j < RC; j++)
        {
            t.clear();
            t = get_cella(m, i, j);
            if (i == 7 && t.compare(" O ") == 0)
            {
                m[i][j] = " D ";
                found = true;
            }
        }
    }
    return found;
}

bool Logica::diagonaleD(int x, int y, int x1, int y1)
{
    if (abs(x - x1) == 2 || abs(y - y1) == 2)
        return true;
    else
        return false;
}

string get_cella(string m[RC][RC], int a, int b)
{
    return m[a][b];
}

#endif /* LOGICA_H */
