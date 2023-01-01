#ifndef PEDINA_H
#define PEDINA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : pedina.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria Pedina
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "logica.h"
using namespace std;
#define RC 8 // numero righe-colonne scacchiera

class Pedina
{
protected:
    int x;
    int y;
    int x1;
    int y1;

public:
    void set_ps(int a, int b, int a1, int b1);
    void get_xy(int &a, int &b);
    void get_xy1(int &a1, int &b1);
    bool rm_pedina(string m[RC][RC], int a, int b, char p);
};

void Pedina::set_ps(int a, int b, int a1, int b1)
{
    x = a;
    y = b;
    a1 = x1;
    b1 = y1;
}

void Pedina::get_xy(int &a, int &b)
{
    a = x;
    b = y;
}

void Pedina::get_xy1(int &a1, int &b1)
{
    a1 = x1;
    b1 = y1;
}

bool Pedina::rm_pedina(string m[RC][RC], int a, int b, char p)
{
    bool found = false;
    string c = get_cella(m, a - 1, b - 1);
    string c1 = get_cella(m, a - 1, b + 1);
    string c2 = get_cella(m, a + 1, b + 1);
    string c3 = get_cella(m, a + 1, b - 1);
    if (p == 'O')
    {
        if (c2.compare(" X ") == 0) //|| c.compare(" O ") == 0)  || c2.compare(" _ ") == 0
        {
            m[a + 1][b + 1] = " _ ";
            found = true;
        }
        else if (c3.compare(" X ") == 0) //|| c1.compare(" O ") == 0
        {
            m[a + 1][b - 1] = " _ ";
            found = true;
        }
    }
    else
    {
        if (c.compare(" O ") == 0) // c2.compare(" X ") == 0
        {
            m[a - 1][b - 1] = " _ ";
            found = true;
        }
        else if (c1.compare(" O ") == 0) // c3.compare(" X ") == 0 ||
        {
            m[a - 1][b + 1] = " _ ";
            found = true;
        }
    }
    return found;
}
#endif /* PEDINA_H */
