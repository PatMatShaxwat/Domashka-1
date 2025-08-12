#pragma once
#define _CRT_NO_WARRINGS
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

//Laba; Interfais i polimorfizm v C++ na primere bankovskih schetov

class IBankAccount
{
public:
	int dengi = 5;
	int begunok = 0;
	int P;
	int P1 = 3333;
	int P2 = 7070;
	double ballance1 = 1000;
	double DOLG1 = 0;
	double ballance2 = 1000;
	double DOLG2 = 0;

};
class Nakop : public IBankAccount
{
public:
	double Stavka = 10;
};
class Debet : public IBankAccount
{
public:
	double kom = 25;
};
class Kredit : public IBankAccount
{
public:
	double doverie1 = 10000;
	double doverie2 = 10000;
};
