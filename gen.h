#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

//dodaæ wiêcej polulacji

class gen
{
private:
	int w;
	int k;
	std::vector <std::vector <bool> > tab;
	int iteracja;


public:
	gen(int w, int k, int iteracja); //z lista inicjalizacyjna

	gen(const gen& popr);

	~gen();//destruktor

	void losowanie();//to do prawdopodobienstwo

	void c_show();

	int spr_wylot(int sprawdzana, int maksymalna);

	int dookola(int wd, int kd);

	std::vector <std::vector <bool> > tabn(std::vector <std::vector <bool> > tab);

	void nowy(); //przygotowywyje generacje nastêpn¹

	void wymus(std::vector <std::vector <bool> > tabw);

	/*
	to do

	std::vector <std::vector <int> > wiek;

	bool zapis();

	void symulacja();
	*/
};
