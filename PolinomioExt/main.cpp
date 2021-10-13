/***************************************************************************
* Name:		Polinomio
* FileName:	main.c
*
* Author:	Jose M Barba Gonzalez
* Created:	24/02/16 - vie febrero 24 00:20:28 2016
* License:	GPL version 3
* Copyright (C) 2016 Jose M Barba Gonzalez
* <zerokullneo@wordpress.com>
****************************************************************************/
/*
* 
*
* Copyright (C) 2016 - Jose M Barba Gonzalez
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#include "Polinomio.hpp"
#include <sys/types.h>

int main()
{
	Polinomio::nat g = 3, h = 4, i = 0, j = 0;
	Polinomio P1(g);
	Polinomio P2(h);

	//for(it = P2.ver_polinomio().begin(); it != P2.ver_polinomio().end(); i++, ++it)
	for(const auto &itr : P2.ver_polinomio())
	{
		cout << i << "-. " << itr.second << "x^" << itr.first << "\n";
		i++;
	}

	P1 += P2;

	cout << "------------------" << endl;
	for(const auto &it : P1.ver_polinomio())
	{
		cout << j << "-. " << it.second << "x^" << it.first << "\n";
		j++;
	}

	cout << "FIN" << endl;
	return 0;
}
