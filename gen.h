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
};

