#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

class gen
{
public:
	int w;
	int k;
	std::vector <std::vector <bool> > tab;
	int iteracja;

	gen(int w,int k,int iteracja): w(w),k(k),iteracja(iteracja),tab(w,std::vector<bool>(k)) {} //z lista inicjalizacyjna

	gen(const gen& popr) 
	{
		w = popr.w;
		k = popr.k;
		iteracja = popr.iteracja +1;
		//tab = popr.tab;
		
		tab = popr.tab;
	} //kopiujacy

	~gen() {} //destruktor

	void losowanie()
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
			{
				tab[i][j] = (std::rand() % 2);
			}
		}
	}

	void c_show()
	{
		system("cls");

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (tab[i][j])
				{
					std::cout << 'x';
				}
				else
				{
					std::cout << 'o';
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl<<iteracja;
	}

	int spr_wylot(int sprawdzana,int maksymalna)
	{
		if (sprawdzana < 0)
		{
			return (maksymalna-1);
		}
		else if (sprawdzana > maksymalna-1)
		{
			return 0;
		}
		else
		{
			return sprawdzana;
		}
	}

	int dookola(int wd, int kd)
	{
		int ile=0;
		if (tab[spr_wylot(wd-1,w)][spr_wylot(kd-1, k)]) //lewo g�ra
		{
			ile++;
		}
		if (tab[spr_wylot(wd-1, w)][spr_wylot(kd, k)]) // g�ra
		{
			ile++;
		}
		if (tab[spr_wylot(wd-1, w)][spr_wylot(kd+1, k)]) //prawo g�ra
		{
			ile++;
		}
		if (tab[spr_wylot(wd, w)][spr_wylot(kd-1, k)]) //lewo
		{
			ile++;
		}
		if (tab[spr_wylot(wd, w)][spr_wylot(kd+1, k)]) //prawo
		{
			ile++;
		}
		if (tab[spr_wylot(wd+1, w)][spr_wylot(kd-1, k)]) //lewo d�
		{
			ile++;
		}
		if (tab[spr_wylot(wd+1, w)][spr_wylot(kd, k)]) //d�
		{
			ile++;
		}
		if (tab[spr_wylot(wd+1, w)][spr_wylot(kd+1, k)]) //prawo d�
		{
			ile++;
		}
		return ile;
	}

	std::vector <std::vector <bool> > tabn(std::vector <std::vector <bool> > tab)
	{
		int ilosc;
		std::vector <std::vector <bool> > robo=tab;

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < k; j++)
			{
				ilosc = dookola(i, j);
				if ((!tab[i][j]) and (ilosc == 3))
				{
					robo[i][j] = true;
				}
				else if ((tab[i][j]) and ((ilosc == 3) or (ilosc == 2)))
				{
					robo[i][j] = true;
				}
				else if (tab[i][j])
				{
					robo[i][j] = false;
				}
				else if (!tab[i][j])
				{
					robo[i][j] = false;
				}
			}
		}
		return robo;
	}

	void nowy() //przygotowywyje generacje nast�pn�
	{
		tab = tabn(tab);
	}

	void wymus(std::vector <std::vector <bool> > tabw)
	{
		tab = tabw;
	}
};

