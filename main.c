#include <ncurses.h>
#include "src/app.h"

int main() {
  struct App * app = create_app();

  while (1) {
    int input = getch();
    if (input == 'q') {
      destroy_app(app);
      return 0;
    }
    handle_app_input(app, input);
    draw_app(app);
  }

  return 1;
}


