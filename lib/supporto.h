#ifndef SUPPORTO_H
#define SUPPORTO_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : supporto.h
 *  Versione  : 2.0
 *  Data      : 18/12/2022
 *  Descr     :
 * ? Libreria di supporto al Main
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "giocatore.h"
#include "pedina.h"
#include "logica.h"
#include "grafica.h"
#include "error.h"
using namespace std;

void inserimento(Giocatore &g, string m[RC][RC], int &x, int &y, int &x1, int &y1, char pe); // inserimento principale funzionamento del programma
void move(string m[RC][RC], int x, int y, int x1, int y1, char pe, bool found);              // muove la pedina nella scacchiera in base alle coordinate
void move2(string m[RC][RC], int x, int y, int x1, int y1, char pe, bool found);

void inserimento(Giocatore &g, string m[RC][RC], int &x, int &y, int &x1, int &y1, char pe)
{
    Pedina p;    // pedina
    Color color; // colore
    Logica l;    // logica
    Error e;     // errori
    bool dG, mD, d, d2, valid_move;
#ifdef _WIN32
    color.foreground(BLUE_INTESE);
    cout << "[Seleziona Pedina] > ";
    color.reset();
    cin >> x >> y;
    e.cntrl_ins(x, y, "[Seleziona Pedina] > ");
    e.ps_bianche(m, x, y, "[Seleziona Pedina] > ");
    e.vuota(m, x, y, "[Seleziona Pedina] > ");
    color.foreground(BLUE_INTESE);
    cout << "[Dove la sposto?] > ";
    color.reset();
    cin >> x1 >> y1;
    e.cntrl_ins2(x1, y1, x, y, pe, "[Dove la sposto?] > ");
    e.cntrl_ins(x1, y1, "[Dove la sposto?] > ");
    e.ps_bianche(m, x1, y1, "[Dove la sposto?] > ");
    e.pieno(m, x1, y1, "[Dove la sposto?] > ");
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(BLUE_INTESE, "[Seleziona Pedina] > ");
    cin >> x >> y;
    e.cntrl_ins(x, y, "[Seleziona Pedina] > ");
    e.ps_bianche(m, x, y, "[Seleziona Pedina] > ");
    e.vuota(m, x, y, "[Seleziona Pedina] > ");
    cout << color.foreground(BLUE_INTESE, "[Dove la sposto?] > ");
    cin >> x1 >> y1;
    e.cntrl_ins2(x1, y1, x, y, pe, "[Dove la sposto?] > ");
    e.cntrl_ins(x1, y1, "[Dove la sposto?] > ");
    e.ps_bianche(m, x1, y1, "[Dove la sposto?] > ");
    e.pieno(m, x1, y1, "[Dove la sposto?] > ");
#endif
    p.set_ps(x, y, x1, y1);
    dG = l.diagonale(x, y, x1, y1);
    mD = l.mossaDoppia(m, x, y, x1, y1, pe);
    d2 = l.dama(m);

    if (d2 == 1) // se c'e' una dama allora:
    {
        d = l.diagonaleD(x, y, x1, y1);
        if (d || mD)
        {
            if (mD)
            {
                valid_move = p.rm_pedina(m, x, y, pe); // x1, y1
                move2(m, x, y, x1, y1, pe, valid_move);
                if (valid_move)
                    g.aggPunti();
            }
            else
            {
                move2(m, x, y, x1, y1, pe, valid_move);
            }
        }
        // else
        // {
        //     e.err_dama(d, x, y, x1, y1);

        //     move(m, x, y, x1, y1);
        //     p.rm_pedina(m, x1, y1, pe);
        //
        // }
    }
    else // altrimenti controlla le diagonali normalmente
    {
        if (dG || mD)
        {
            if (mD) // mossa doppia
            {
                valid_move = p.rm_pedina(m, x, y, pe);
                move(m, x, y, x1, y1, pe, valid_move);
                if (valid_move)
                    g.aggPunti();
            }
            else
                move(m, x, y, x1, y1, pe, true); //! se da problemi togli e fai overload
            d2 = l.dama(m);
        }

        else // caso di errore
        {
            if (!dG)
            {
                e.err_diagonale(dG, x, y, x1, y1);
                move(m, x, y, x1, y1, pe, true);
            }

            else if (!mD)
            {
                e.err_diagonale(mD, x, y, x1, y1);
                valid_move = p.rm_pedina(m, x, y, pe);
                move(m, x, y, x1, y1, pe, valid_move);
                if (valid_move)
                    g.aggPunti();
            }
        }
    }
}

void move(string m[RC][RC], int x, int y, int x1, int y1, char pe, bool found)
{
    Logica l;
    Error e;
    Color color;
    string f, f2;
    f = get_cella(m, x1, y1);
    f2 = get_cella(m, x1, y1);
    if (f.compare(" D ") != 0 || f2.compare(" S ") != 0)
    {
        if (found)
        {
            m[x1][y1] = m[x][y];
            m[x][y] = " _ ";
        }
        else
        {
#ifdef _WIN32
            color.foreground(RED_WHITE_INTENSE);
            cout << "[Mossa non valida Turno successivo!]\n";
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(RED, "[Mossa non valida Turno successivo!]\n");
#endif

            fflush(stdin);
            cin.get();
        }
    }
}

void move2(string m[RC][RC], int x, int y, int x1, int y1, char pe, bool found)
{
    Color color;
    if (found == 1)
    {
        m[x1][y1] = m[x][y];
        m[x][y] = " _ ";
    }
    else
    {
#ifdef _WIN32
        color.foreground(RED_WHITE_INTENSE);
        cout << "[Mossa non valida Turno successivo!]\n";
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << color.foreground(RED, "[Mossa non valida Turno successivo!]\n");
#endif
        fflush(stdin);
        cin.get();
    }
}

#endif /* SUPPORTO_H */