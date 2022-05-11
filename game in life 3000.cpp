
#include <iostream>
#include "gen.h"
#include <windows.h> //do sleepa
#include <time.h>

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

    

    /*
    std::vector <std::vector <bool> > tab;
    std::vector <bool> sex1 (6);
    std::vector <bool> sex2(6);
    sex1[1] = true;
    sex1[2] = true;
    sex1[3] = true;
    sex2[2] = true;
    sex2[3] = true;
    sex2[4] = true;
    std::vector <bool> puste(6);
    tab.push_back(puste);
    tab.push_back(puste);
    tab.push_back(sex1);
    tab.push_back(sex2);
    tab.push_back(puste);
    tab.push_back(puste);

    teraz.wymus(tab);
    */


    
    std::vector <std::vector <bool> > tab;
    std::vector <bool> sex1 (3);
    std::vector <bool> sex2 (3);
    std::vector <bool> sex3 (3);
    sex1[0] = true;
    sex1[1] = true;
    sex1[2] = true;
    sex2[0] = true;
    sex3[1] = true;
    tab.push_back(sex1);
    tab.push_back(sex2);
    tab.push_back(sex3);

    //teraz.wymus(tab);
    teraz.losowanie();


    teraz.c_show();

    teraz.nowy();

    std::cout << std::endl;
    std::cout << std::endl;

    int i=0;
    std::string s;

    std::cin >> s;

    while (s!="koniec")
    {
        teraz.c_show();
        teraz.nowy();
        gen nast(teraz);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cin >> s;
        teraz = nast;

        i++;

        
        
    }
    return 0;
}
