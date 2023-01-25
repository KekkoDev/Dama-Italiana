/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : main.cpp
 *  Versione  : 1.0
 *  Data      : 04/01/2023
 *  Descr     :
 * ? Gioco della Dama Italiana
 *================================================================================================**/
#include <iostream>
#include "../lib/pedina.h"
#include "../lib/grafica.h"
#include "../lib/supporto.h"
#include "../lib/errori.h"
#include "../lib/giocatore.h"
#include "../lib/supporto_grafica.h"
using namespace std;

int main()
{
        Pedina pedina;
        Grafica grafica;
        Giocatore giocatore1, giocatore2;
        Errori errori;
        Color color;
        string nome;

        cl();
        grafica.banner();
        cout << "Inserisci Nome > ";
        fflush(stdin);
        getline(cin, nome);
        errori._errNome(nome);
        giocatore1.set_nome(nome);

        cout << "Inserisci Nome > ";
        fflush(stdin);
        getline(cin, nome);
        errori._errNome(nome);
        giocatore2.set_nome(nome);

        do
        {
                cl();
                grafica.banner();
                grafica.tabellone(giocatore1, giocatore2);
                grafica.stampa(pedina);
#ifdef _WIN32
                color.foreground(RED_INTENSE);
                cout << "[Turno] > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(RED_INTENSE, "[Turno] > ");
#endif
                cout << giocatore1.get_nome() << endl;
                inserimento(pedina, giocatore1, 'O');

                cl();
                grafica.banner();
                grafica.tabellone(giocatore1, giocatore2);
                grafica.stampa(pedina);
#ifdef _WIN32
                color.foreground(BLUE_INTESE);
                cout << "[Turno] > ";
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.foreground(BLUE_INTESE, "[Turno] > ");
#endif
                cout << giocatore2.get_nome() << endl;
                inserimento(pedina, giocatore2, 'X');
        } while (giocatore1.get_punti() < 12 && giocatore2.get_punti() < 12);

        if (giocatore1.get_punti() == 12)
                cout << "Vince " << giocatore1.get_nome() << endl;
        else
                cout << "Vince " << giocatore2.get_nome() << endl;

        cout << "Arrivederci :)!";
        cout << "Premere un tasto per continuare....";
        cin.get();

        return 0;
}
