#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "loop.h"

int keypressed;
int errorCount = 0;


int main(int argc, char const *argv[])
{
    loopThis();
    return 0;
}
