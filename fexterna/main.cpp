/***************************************************************************
* Name:		fexterna
* FileName:	main.c
*
* Author:	Jose M Barba Gonzalez
* Created:	01/03/16 - mar marzo 01 18:29:18 2016
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

#include <iostream>

using namespace std;

struct B
{
	virtual void f(){cout << "f() de B." << endl;}
};

struct D: B
{
	void f(){cout << "f() de D." << endl;}
};

void f(B& b)
{
	cout << "f() externa." << endl;
	b.f();
}

int main()
{
	B b;
	D d;
	f(b);
	f(d);
	return 0;
}