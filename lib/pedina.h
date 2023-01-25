#ifndef PEDINA_H
#define PEDINA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : pedina.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ?
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "supporto_grafica.h"
using namespace std;
#define RC 8
#define FILE_PATH "../file/init.csv"

class Pedina
{
protected:
    string scacchiera[RC][RC];
    int x;
    int y;
    int x1;
    int y1;

public:
    Pedina(void);
    void stampa_pedina(void);
    void set_xy(int x, int y);
    void set_xy1(int x1, int y1);
    void get_xy(int &a, int &b);
    void get_xy1(int &a, int &b);
    void muovi_pedina();
    void modifica_cella(int a, int b, string ch);
    void rimuovi(char p);
    string get_scacchiera(int a, int b);
};

Pedina::Pedina(void)
{
    ifstream File(FILE_PATH);
    string t, t2;
    while (!File.eof())
    {
        for (int i = 0; i < RC; i++)
        {
            for (int j = 0; j < RC; j++)
            {
                t.clear();
                getline(File, t, ',');

                scacchiera[i][j] = t;
            }
            getline(File, t2, '\n');
        }
    }
    scacchiera[RC - 1][RC - 1] = " X ";
}

void Pedina::stampa_pedina(void)
{
    for (int i = 0; i < RC; i++)
    {
        for (int j = 0; j < RC; j++)
        {
            cout << scacchiera[i][j];
        }
        cout << endl;
    }
}

void Pedina::set_xy(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Pedina::set_xy1(int x1, int y1)
{
    this->x1 = x1;
    this->y1 = y1;
}

void Pedina::get_xy(int &a, int &b)
{
    a = x;
    b = y;
}

void Pedina::get_xy1(int &a, int &b)
{
    a = x;
    b = y;
}
void Pedina::muovi_pedina()
{
    scacchiera[x1][y1] = scacchiera[x][y];
    scacchiera[x][y] = " _ ";
}

void Pedina::modifica_cella(int a, int b, string ch)
{
    scacchiera[a][b] = ch;
}

void Pedina::rimuovi(char p)
{
    string c = scacchiera[x - 1][y - 1];
    string c1 = scacchiera[x - 1][y + 1];
    string c2 = scacchiera[x + 1][y + 1];
    string c3 = scacchiera[x + 1][y - 1];

    if (p == 'O' || p == 'D')
    {
        if (c2.compare(" X ") == 0) //|| c.compare(" O ") == 0)  || c2.compare(" _ ") == 0
        {
            scacchiera[x + 1][y + 1] = " _ ";
        }
        else if (c3.compare(" X ") == 0) //|| c1.compare(" O ") == 0
        {
            scacchiera[x + 1][y - 1] = " _ ";
        }
    }
    else
    {
        if (c.compare(" O ") == 0) // c2.compare(" X ") == 0
        {
            scacchiera[x - 1][y - 1] = " _ ";
        }
        else if (c1.compare(" O ") == 0) // c3.compare(" X ") == 0 ||
        {
            scacchiera[x - 1][y + 1] = " _ ";
        }
    }
}

string Pedina::get_scacchiera(int a, int b)
{
    return scacchiera[a][b];
}

#endif /* PEDINA_H */
