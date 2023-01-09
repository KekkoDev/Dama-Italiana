#ifndef SUPPORTO_H
#define SUPPORTO_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : supporto.h
 *  Versione  : 3.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Libreria di supporto al main
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "pedina.h"
#include "giocatore.h"
#include "logica.h"
#include "errori.h"
using namespace std;

void inserimento(Pedina &pedina, Giocatore &giocatore, char p);

void inserimento(Pedina &pedina, Giocatore &giocatore, char p)
{
    int x, y, x1, y1;
    bool diagonale, mossaDoppia, damaD, diagonaleD;
    string p1;
    char p2;
    Errori errori;
    cout << "[Seleziona Pedina] > ";
    cin >> x >> y;
    errori._errVuota(x, y, "[Seleziona Pedina] > ");
    errori._errVuota2(x, y, "[Seleziona Pedina] > ");
    errori._errCoord(x, y, "[Seleziona Pedina] > ");
    cout << "[Dove la posiziono?] > ";
    cin >> x1 >> y1;
    errori._errVuota(x1, y1, "[Dove la posiziono?] > ");
    errori._errCoord(x1, y1, "[Dove la posiziono?] > ");
    errori._errorOccupata(pedina, x, y, x1, y1, "[Dove la posiziono?] > ");

    diagonale = _cntrlDiagonale(x, y, x1, y1);
    mossaDoppia = _cntrlmossaDp(pedina, x, y, p);
    damaD = _cntrlDama(pedina);

    if (diagonale || mossaDoppia)
    {
        pedina.set_xy(x, y);
        pedina.set_xy1(x1, y1);
        pedina.muovi_pedina();
        if (mossaDoppia)
        {
            pedina.rimuovi(p);
            giocatore.agg_punti();
        }
    }
    else if (damaD || mossaDoppia)
    {
        diagonaleD = _cntrlDiagonaleD(x, y, x1, y1);
        pedina.set_xy(x, y);
        p1 = pedina.get_scacchiera(x, y);
        p2 = p1[1];
        pedina.set_xy1(x1, y1);
        pedina.muovi_pedina();
        if (mossaDoppia)
        {
            pedina.rimuovi(p2);
            giocatore.agg_punti();
        }
        else if (!diagonaleD)
            errori._erroreDiagonale(x, y, x1, y1);
    }
    else
    {
        if (!diagonale)
        {
            errori._erroreDiagonale(x, y, x1, y1);
            pedina.set_xy(x, y);
            pedina.set_xy1(x1, y1);
            pedina.muovi_pedina();
        }
        else
        {
            errori._erroremossaDp(pedina, x, y, x1, y1, p);
            pedina.set_xy(x, y);
            pedina.set_xy1(x1, y1);
            pedina.muovi_pedina();
        }
    }
}

#endif /* SUPPORTO_H */
