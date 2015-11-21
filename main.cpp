#include <iostream>

#define RIADOK 5
#define STLPEC 5

using namespace std;

/*
 * Bunka struktura
 * todo
 */
struct bunka
{
    int hodnota;
};

/*
 * Dalsia faza jeden cyklus
 * todo
 */
int aktualizuj(bunka poleBuniek[RIADOK][STLPEC], bunka pomocnePoleBuniek[RIADOK][STLPEC])
{
    //Aplikujem pre danu bundku pravidlo a ulozim do pomocneho pola buniek
    for(int i = 0; i < RIADOK; i++)
    {
        for(int j = 0; j < STLPEC; j++)
        {
            //todo pomocnePoleBuniek[i][j] = nieco(poleBuniek[i][j]);
        }
    }
    //Ulozim nove bunky do pola buniek
    for(int i = 0; i < RIADOK; i++)
    {
        for(int j = 0; j < STLPEC; j++)
        {
            poleBuniek[i][j] = pomocnePoleBuniek[i][j];
        }
    }
}

int main()
{
    cout << "hello world" << endl;
    bunka poleBuniek[RIADOK][STLPEC];
    bunka pomocnePoleBuniek[RIADOK][STLPEC];
    aktualizuj(poleBuniek, pomocnePoleBuniek);

    return 0;
}