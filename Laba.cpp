#include "BANKA.h"


//Laba; Interfais i polimorfizm v C++ na primere bankovskih schetov



int main()
{
	Debet DE;
	IBankAccount da;
	Nakop HA;
	Kredit la;
	HA.Stavka;
	da.begunok;
	da.P;
	da.P1;
	da.P2;
	da.ballance1;
	da.ballance2;
	da.DOLG1;
	da.DOLG2;
	la.doverie1;
	la.doverie2;
	DE.kom;
	int a = 0;
	int q = 0;
	int g = 0;
	double t = 0;
	int INT = 0;
	while (1)
	{
		da.DOLG1 = da.DOLG1 * HA.Stavka;
		da.DOLG2 = da.DOLG2 * HA.Stavka;
		cout << "\n WELOCOME TO BANK ZAKRITIE! Viberete accaunt 1 ili 2 \n";
		cin >> da.begunok;
		switch (da.begunok)
		{
		case 1: {
			cout << "\n PAROL! \n";
			cin >> da.P;
			if (da.P == da.P1)
			{
				a = 0;
				while (a <= 3)
				{
					cout << "\n viberete funkciyu: \n1) Kredit \n2) balans  \n3) viiti \n";
					cin >> a;
					if (a == 1)
					{
						cout << "\n Stavka kredita: " << HA.Stavka << "\n Doverie do summi: " << la.doverie1 << "\nNa kakuyu summu hotite ego vzyat ? \n";
						cin >> t;

						if (t >= 0 && t <= la.doverie1)
						{
							da.ballance1 = da.ballance1 + t;
							da.DOLG1 = da.DOLG1 + t;
							la.doverie1 = la.doverie1 - t;
							cout << "\n Kredit vzyat \n";
							break;
						}
						else
						{
							cout << "\n znachenie ukazano ne verno \n";
							break;

						}
					}
					if (a == 2)
					{
						cout << "\n viberete funkciyu: \n1) info \n2) perevod \n3) pogasit dolg\n";
						cin >> q;
						if (q == 1)
						{
							cout << endl << "balans: " << da.ballance1 << endl;
							cout << "dolg: " << da.DOLG1 << endl;
						}
						if (q == 2)
						{
							cout << "\n summa perevoda S kommissiei v: " << DE.kom << "\n";
							cin >> t;

							if (t >= 0 && t <= da.ballance1)
							{
								da.ballance1 = da.ballance1 - t;
								INT = t / 100;
								INT = DE.kom * INT;
								t = t - INT;
								da.ballance2 = da.ballance2 + t;
								cout << "\n perevod uspeshen, perevedeno: " << t << "\n";
								break;
							}
							else
							{
								cout << "\n znachenie ukazano ne verno \n";
								break;

							}
						}
						if (q == 3)
						{
							g = 0;
							while (g == 0)
							{
								da.ballance1--;
								da.DOLG1--;
								if (da.ballance1 == 0 || da.DOLG1 >= 0)
								{
									cout << "\nBalansa ne hvatilo na pogasheniye dolga\n";
									g++;
								}
								if (da.DOLG1 == 0 || da.ballance1 >= 0)
								{
									cout << "\nDolg pogashen, shas ispravim\n";
									g++;
								}
							}
						}
					}
					if (a == 3)
					{
						a++;
					}

				}

			}
			else
			{
				while (1)
				{
					cout << "\n zloumishlennik pshol VON!";
				}
			}
		}
		case 2:
		{
			cout << "\n PAROL! \n";
			cin >> da.P;
			if (da.P == da.P2)
			{
				a = 0;
				while (a <= 3)
				{
					cout << "\n viberete funkciyu: \n1) Kredit \n2) balans  \n3) viiti \n";
					cin >> a;
					if (a == 1)
					{
						cout << "\n Stavka kredita: " << HA.Stavka << "\n Doverie do summi: " << la.doverie2 << "\nNa kakuyu summu hotite ego vzyat ? \n";
						cin >> t;

						if (t >= 0 && t <= la.doverie2)
						{
							da.ballance2 = da.ballance2 + t;
							da.DOLG2 = da.DOLG2 + t;
							la.doverie2 = la.doverie2 - t;
							cout << "\n Kredit vzyat \n";
							break;
						}
						else
						{
							cout << "\n znachenie ukazano ne verno \n";
							break;

						}
					}
					if (a == 2)
					{
						cout << "\n viberete funkciyu: \n1) info \n2) perevod \n3) pogasit dolg\n";
						cin >> q;
						if (q == 1)
						{
							cout << endl << "balans: " << da.ballance2 << endl;
							cout << "dolg: " << da.DOLG2 << endl;
						}
						if (q == 2)
						{
							cout << "\n summa perevoda S kommissiei v: " << DE.kom << "\n";
							cin >> t;

							if (t >= 0 && t <= da.ballance2)
							{
								da.ballance2 = da.ballance2 - t;
								INT = t / 100;
								INT = DE.kom * INT;
								t = t - INT;
								da.ballance1 = da.ballance1 + t;
								cout << "\n perevod uspeshen, perevedeno: " << t << "\n";
								break;
							}
							else
							{
								cout << "\n znachenie ukazano ne verno \n";
								break;

							}
						}
						if (q == 3)
						{
							g = 0;
							while (g == 0)
							{
								da.ballance2--;
								da.DOLG1--;
								if (da.ballance2 == 0 || da.DOLG2 >= 0)
								{
									cout << "\nBalansa ne hvatilo na pogasheniye dolga\n";
									g++;
								}
								if (da.DOLG2 == 0 || da.ballance2 >= 0)
								{
									cout << "\nDolg pogashen, shas ispravim\n";
									g++;
								}
							}
						}
					}
					if (a == 3)
					{
						a++;
					}

				}

			}
			else
			{
				while (1)
				{
					cout << "\n zloumishlennik pshol VON!";
				}
			}
		}
		default:
			break;
		}

	}
}

//OTVETI:
// 1) Chto takoe interface i dlya chego on sozdaetsa: dlya opsaniya povedeniya klassa bez ukazsniya konkretnoi realizacii
// 2) V chem raznica abstraktnogo klassa ot obichnogo: Abstraktnii klass otlichatsa tem ot obichnogo tem, to chto  on ne prednaznachen dlya sozdaniya obyektov napryamuyu. Ego cel sluzhit osnovoi dlya drugih klassov, kotorie realizuyut ego funkcional
// 3) Chto takoe polimorfizm i kak on proyavlyaetsa v etoi rabote: Eto svoistvo obektov izmenyat svoyu formu ili povedeniye v zsvisimosti ot konteksta, pozvolyaya im reagirovat na odni i te zhe soobsheniya po raznomu. V moem proekte vozmozhno gde-to est.