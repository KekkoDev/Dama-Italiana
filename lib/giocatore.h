#ifndef GIOCATORE_H
#define GIOCATORE_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : giocatore.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria Giocatore
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Giocatore
{
protected:
    string nome; // nome giocatore
    int punti;   // punti giocatore

public:
    Giocatore()
    {
        punti = 0;
    };
    void set_nome(string n);
    string get_nome();
    int get_punti();
    string get_mangiati();
    void aggPunti();
};

void Giocatore::set_nome(string n)
{
    nome = n;
}

string Giocatore::get_nome()
{
    return nome;
}

int Giocatore::get_punti()
{
    return punti;
}

string Giocatore::get_mangiati()
{
    int dim = punti;
    string t;
    for (int i = 0; i < dim; i++)
    {
        t += " O ";
    }
    return t;
}

void Giocatore::aggPunti()
{
    punti++;
}
#endif /* GIOCATORE_H */
