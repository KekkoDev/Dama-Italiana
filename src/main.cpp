/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : main.cpp
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Gioco della Dama Italiana
 *================================================================================================**/
#include <iostream>
#include "../lib/giocatore.h"
#include "../lib/error.h"
#include "../lib/supporto.h"
#include "../lib/grafica.h"
using namespace std;

int main()
{
    //? scacchiera di base le posizioni con ("/") sono le posizioni bianche, le posizioni con("_") sono le posizioni nere libere
    string scacchiera[RC][RC] = {" O ", " / ", " O ", " / ", " O ", " / ", " O ", " / ",
                                 " / ", " O ", " / ", " O ", " / ", " O ", " / ", " O ",
                                 " O ", " / ", " O ", " / ", " O ", " / ", " O ", " / ",
                                 " / ", " _ ", " / ", " _ ", " / ", " _ ", " / ", " _ ",
                                 " _ ", " / ", " _ ", " / ", " _ ", " / ", " _ ", " / ",
                                 " / ", " X ", " / ", " X ", " / ", " X ", " / ", " X ",
                                 " X ", " / ", " X ", " / ", " X ", " / ", " X ", " / ",
                                 " / ", " X ", " / ", " X ", " / ", " X ", " / ", " X "};

    Giocatore p1, p2;
    Error e;
    int x, y, x1, y1;
    string n;
    cl();
    banner();
    cout << "Inserisci Nome Giocatore1 > ";
    fflush(stdin);
    getline(cin, n);
    e.cntrl_nome(n);
    p1.set_nome(n);
    n.clear();
    cout << "Inserisci Nome Giocatore2 > ";
    fflush(stdin);
    getline(cin, n);
    e.cntrl_nome(n);
    p2.set_nome(n);

    do
    {
        cl();
        banner();
        stampa_punti(p1, p2);
        stampa_scacchiera(scacchiera);
        cout << "Turno > O " << endl;
        inserimento(p1, scacchiera, x, y, x1, y1, 'O');

        cl();
        banner();
        stampa_punti(p1, p2);
        stampa_scacchiera(scacchiera);
        cout << "Turno > X " << endl; // creare metodo bool per mangiare solo la dama
        inserimento(p2, scacchiera, x, y, x1, y1, 'X');
    } while (p1.get_punti() < 12 || p2.get_punti() < 12);
    if (p1.get_punti() == 12)
        cout << "Vince " << p1.get_nome() << endl;
    else
        cout << "Vince " << p2.get_nome() << endl;

    return 0;
}