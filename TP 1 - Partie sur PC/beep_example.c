#include <stdio.h>   // pôur printf
#include <windows.h> // pour Beep
#include <conio.h>   // pour getch

int main(void)
{
    
    // Function that beeps a sound of
    // frequency 440 Hertz for 0.8 sec
    Beep(440, 800);
    
    printf("\nAppuyez sur une touche..." );
    getch();

    return 0;
}
