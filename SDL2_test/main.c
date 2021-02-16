#include "SDL.h"

extern void InitVideo();
extern void Redraw();

extern char *text;
extern char *composition;
extern Sint32 cursor;
extern Sint32 selection_len;

int main(int argc, char *argv[])
{
    SDL_bool done = SDL_FALSE;

    InitVideo();
    /* ... */

    SDL_StartTextInput();
    while (!done) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    /* Quit */
                    done = SDL_TRUE;
                    break;
                case SDL_TEXTINPUT:
                    /* Add new text onto the end of our text */
                    strcat(text, event.text.text);
                    break;
                case SDL_TEXTEDITING:
                    /*
                    Update the composition text.
                    Update the cursor position.
                    Update the selection length (if any).
                    */
                    composition = event.edit.text;
                    cursor = event.edit.start;
                    selection_len = event.edit.length;
                    break;
            }
        }
        Redraw();
    }

    SDL_Quit();

    return 0;
}
