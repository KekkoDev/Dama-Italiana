#ifndef GIOCATORE_H
#define GIOCATORE_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : giocatore.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Libreria classe Giocatore
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Giocatore
{
protected:
    string nome;
    int punteggio;

public:
    Giocatore()
    {
        punteggio = 0;
    };
    void set_nome(string nome);
    string get_nome();
    int get_punti();
    void agg_punti();
};

void Giocatore::set_nome(string nome)
{
    this->nome = nome;
}

string Giocatore::get_nome()
{
    return nome;
}

int Giocatore::get_punti()
{
    return punteggio;
}

void Giocatore::agg_punti()
{
    punteggio++;
}

#endif /* GIOCATORE_H */
