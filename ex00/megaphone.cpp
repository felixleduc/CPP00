#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << "DEATH SILENCE, LOOKS LIKE THOMAS BERUBE ISN'T THERE...";
  else
  {
    for (int i = 1; argv[i]; i++)
      for (int j = 0; j < (int)strlen(argv[i]); j++)
        std::cout << (char)toupper(argv[i][j]);
  }
  std::cout << std::endl;
  return 0;
}