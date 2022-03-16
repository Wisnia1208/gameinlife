
#include <iostream>
#include "gen.h"
//#include <conio.h>

int main()
{
    setlocale(LC_CTYPE, "Polish");

    srand(time(NULL));

    int w;
    int k;

    std::cout << "wprowadź ilość wierszy"<<std::endl;
    std::cin >> w;
    std::cout << std::endl;

    std::cout << "wprowadź ilość kolumn" << std::endl;
    std::cin >> k;
    std::cout << std::endl;

    gen teraz(w, k, 1);

    teraz.losowanie();

    teraz.c_show();

    gen nast(teraz);

    std::cin >> w;

    nast.losowanie();

    nast.c_show();

    std::cin >> w;
}
