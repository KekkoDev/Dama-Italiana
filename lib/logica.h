#ifndef LOGICA_H
#define LOGICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : logica.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Libreria per la Logica dell gioco
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "pedina.h"
using namespace std;

bool _cntrlDiagonale(int x, int y, int x1, int y1);
bool _cntrlmossaDp(Pedina pedina, int x, int y, char p);
bool _cntrlDama(Pedina pedina);
bool _cntrlDiagonaleD(int x, int y, int x1, int y1);
bool _cntrlOccupata(Pedina pedina, int x1, int y1);
bool _cntrlNome(string str);
bool _cntrlCoordinate(int x, int y);
bool _cntrlVuoto(int x, int y);
bool _cntrlVuoto2(int x, int y);

bool _cntrlDiagonale(int x, int y, int x1, int y1)
{
    if (abs(x - x1) == 1 && abs(y - y1) == 1)
        return true;
    else
        return false;
}

bool _cntrlmossaDp(Pedina pedina, int x, int y, char p)
{
    bool found = false;
    if (p == 'O')
    {
        if (pedina.get_scacchiera(x + 1, y + 1).compare(" X ") == 0 || pedina.get_scacchiera(x + 1, y - 1).compare(" X ") == 0)
            found = true;
    }
    else
    {
        if (pedina.get_scacchiera(x - 1, y - 1).compare(" O ") == 0 || pedina.get_scacchiera(x - 1, y + 1).compare(" O ") == 0)
            found = true;
    }
    return found;
}

bool _cntrlDama(Pedina pedina)
{
    bool found = false;
    string t;
    for (int i = 0; i < RC; i++)
    {
        for (int j = 0; j < RC; j++)
        {
            t.clear();
            t = pedina.get_scacchiera(i, j);
            if (i == 0 && t.compare(" X ") == 0)
            {
                pedina.modifica_cella(i, j, " S ");
                found = true;
            }
        }
    }

    for (int i = 0; i < RC; i++)
    {
        for (int j = 0; j < RC; j++)
        {
            t.clear();
            t = pedina.get_scacchiera(i, j);
            if (i == 7 && t.compare(" O ") == 0)
            {
                pedina.modifica_cella(i, j, " D ");
                found = true;
            }
        }
    }
    return found;
}

bool _cntrlDiagonaleD(int x, int y, int x1, int y1)
{
    if (abs(x - x1) == 2 || abs(y - y1) == 2)
        return true;
    else
        return false;
}

bool _cntrlOccupata(Pedina pedina, int x1, int y1)
{
    if (pedina.get_scacchiera(x1, y1).compare(" _ ") == 0)
        return true;
    else
        return false;
}

bool _cntrlNome(string str)
{
    if (str.empty())
        return true;
    else
        return false;
}

bool _cntrlCoordinate(int x, int y)
{
    if (x >= 0 && x <= 8 && y >= 0 && y <= 8)
        return true;
    else
        return false;
}

bool _cntrlVuoto(int x, int y)
{
    Pedina pedina;
    if (pedina.get_scacchiera(x, y).compare(" / ") == 0)
        return true;
    else
        return false;
}

bool _cntrlVuoto2(int x, int y)
{
    Pedina pedina;
    if (pedina.get_scacchiera(x, y).compare(" _ ") == 0)
        return true;
    else
        return false;
}
#endif /* LOGICA_H */
