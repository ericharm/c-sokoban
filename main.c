#include <ncurses.h>
#include "src/app.h"

int main() {
  struct App * app = App__new();

  while (1) {
    int input = getch();
    if (input == 'q') {
      App__destroy(app);
      return 0;
    }
    App__handle_input(app, input);
    App__draw(app);
  }

  return 1;
}


