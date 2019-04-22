#include <stdio.h>
#include <windows.h>

// Prof: Bruno Monteiro
// Objetivo: emitir sons.

int main()
{
    int T = 3000;

    // Aumento o volume para ouvir os beeps

    Sleep(1000); // Sleep pertence à <windows.h>
    Beep(261,T); //C
    Beep(293,T); //D
    Beep(329,T); //E
    Beep(349,T); //F
    Beep(392.5,T); //G
    Beep(220,T); //A
    Beep(247,T); //B

    return 0;
}

