/**********************************************
 * 
 * Name: Jacob Frommeyer
 * Date: 4/20/2018
 * Mancala class functions
 *********************************************/

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cmath>
#include "mancala.h"
#include "colors.h"

using namespace std;
using namespace main_savitch_14;

void mancala::make_move(const std::string& move)
{
	int num_stones = 0, position = 0, ply1 = 0, ply2 = 0;

	for (int i = 0; i < 6; i++)
	{
		if (mancala_array[i] == 0)
		{
			ply1++;
		}
	}

	for (int i = 12; i > 6; i--)
	{
		if (mancala_array[i] == 0)
		{
			ply2--;
		}
	}

	if (ply1 == 6 || ply2 == 6)
	{
		if (ply1 == 6)
		{
			int total = 0;

			for (int i = 7; i <=13; i++)
			{
				total = total + mancala_array[i];
			}

			mancala_array[13] = total;

			for (int i = 12; i > 6; i--)
			{
				mancala_array[i] = 0;
			}
		}
		else if (ply2 == 6)
		{
			int total = 0;

			for (int i = 0; i <= 6; i ++)
			{
				total = total + mancala_array[i];
			}

			mancala_array[6] = total;

			for (int i = 0; i < 6; i++)
			{
				mancala_array[i] = 0;
			}
		}
	}

	if (next_mover() == HUMAN)
	{
		if (move == "A" || move == "a")
		{
			position = 0;
		}
		else if (move == "B" || move == "b")
		{
			position = 1;
		}
		else if (move == "C" || move == "c")
		{
			position = 2;
		}
		else if (move == "D" || move == "d")
		{
			position = 3;
		}
		else if (move == "E" || move == "e")
		{
			position = 4;
		}
		else if (move == "F" || move == "f")
		{
			position = 5;
		}

		num_stones = mancala_array[position];
		mancala_array[position] = 0;
		position++;

		while (num_stones != 0)
		{
			if(position == 13)
			{
				position = 0;
			}

			mancala_array[position] = mancala_array[position] + 1;

			num_stones--;
			position++;
		}
	}
	else if (next_mover() == COMPUTER)
	{
		if (move == "A" || move == "a")
		{
			position = 7;
		}
		else if (move == "B" || move == "b")
		{
			position = 8;
		}
		else if (move == "C" || move == "c")
		{
			position = 9;
		}
		else if (move == "D" || move == "d")
		{
			position = 10;
		}
		else if (move == "E" || move == "e")
		{
			position = 11;
		}
		else if (move == "F" || move == "f")
		{
			position = 12;
		}

		num_stones = mancala_array[position];
		mancala_array[position] = 0;
		position++;

		while (num_stones != 0)
		{
			if (position == 14 || position == 6)
			{
				if(position == 14)
				{
					position = 0;
				}
				else if(position == 6){position = 7;}
			}

			mancala_array[position] = mancala_array[position] + 1;

			num_stones--;
			position++;
		}
	}

	if (mancala_array[position - 1] == 1)
	{
		if (next_mover() == HUMAN)
		{
			if ((position - 1) == 0)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[0] + mancala_array[12]; mancala_array[0] = 0; mancala_array[12] = 0;
			}
			else if ((position - 1) == 1)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[1] + mancala_array[11]; mancala_array[1] = 0; mancala_array[11] = 0;
			}
			else if ((position - 1) == 2)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[2] + mancala_array[10]; mancala_array[2] = 0; mancala_array[10] = 0;
			}
			else if ((position - 1) == 3)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[3] + mancala_array[9]; mancala_array[3] = 0; mancala_array[9] = 0;
			}
			else if ((position - 1) == 4)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[4] + mancala_array[8]; mancala_array[4] = 0; mancala_array[8] = 0;
			}
			else if ((position - 1) == 5)
			{
				mancala_array[6] = mancala_array[6] + mancala_array[5] + mancala_array[7]; mancala_array[5] = 0; mancala_array[7] = 0;
			}
		}
		else if (next_mover() == COMPUTER)
		{
			if ((position - 1) == 7)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[7] + mancala_array[5]; mancala_array[7] = 0; mancala_array[5] = 0;
			}
			else if ((position - 1) == 8)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[8] + mancala_array[4]; mancala_array[8] = 0; mancala_array[4] = 0;
			}
			else if ((position - 1) == 9)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[9] + mancala_array[3]; mancala_array[9] = 0; mancala_array[3] = 0;
			}
			else if ((position - 1) == 10)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[10] + mancala_array[2]; mancala_array[10] = 0; mancala_array[2] = 0;
			}
			else if ((position - 1) == 11)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[11] + mancala_array[1]; mancala_array[11] = 0; mancala_array[1] = 0;
			}
			else if ((position - 1) == 12)
			{
				mancala_array[13] = mancala_array[13] + mancala_array[12] + mancala_array[0]; mancala_array[12] = 0; mancala_array[0] = 0;
			}
		}
	}

	game::make_move(move);
}

void mancala::restart()
{
	for (int i = 0; i < 14; i++)
	{
		if (i == 6 || i == 13)
		{
			mancala_array[i] = 0;
		}
		else
		{
			mancala_array[i] = 4;
		}
	}

	game::restart();
}

game * mancala::clone()const
{
	return new mancala(*this);
}

void mancala::compute_moves(std::queue <std::string>& moves)const
{
	if (mancala_array[7] != 0)
	{
		moves.push("A");
	}
	else if (mancala_array[8] != 0)
	{
		moves.push("B");
	}
	else if (mancala_array[9] != 0)
	{
		moves.push("C");
	}
	else if (mancala_array[10] != 0)
	{
		moves.push("D");
	}
	else if (mancala_array[11] != 0)
	{
		moves.push("E");
	}
	else if (mancala_array[12] != 0)
	{
		moves.push("F");
	}
	else
	{
		compute_moves(moves);
	}
}

void mancala::display_status()const
{
	cout << endl << "Player 1 = " << RED << "RIGHT MANCALA" << RESET << " = "  << mancala_array[6] << endl;

	cout << CYAN << "____________________________________________" << RESET << endl;
	cout << CYAN << "|                                          |" << RESET << endl;
	cout << CYAN << "|   1    F    E    D    C    B    A    2   |" << RESET << endl;
	cout << CYAN << "|  ___  ___  ___  ___  ___  ___  ___  ___  |" << RESET << endl;
	cout << CYAN << "| |   || " << RESET << mancala_array[12] << CYAN << " || " << RESET << mancala_array[11] << CYAN << " || " << RESET << mancala_array[10] << CYAN << " || " << RESET << mancala_array[9] << CYAN << " || " << RESET << mancala_array[8] << CYAN << " || " << RESET << mancala_array[7] << CYAN << " ||   | |" << RESET << endl;
	cout << CYAN << "| |   ||___||___||___||___||___||___||   | |" << RESET << endl;
	cout << CYAN << "| |   |                              |   | |" << RESET << endl;
	cout << CYAN << "| |   | " << GREEN << "  Ohio University Mancala   " << CYAN << " |   | |" << RESET << endl;
	cout << CYAN << "| |   | ___  ___  ___  ___  ___  ___ |   | |" << RESET << endl;
	cout << CYAN << "| |   || " << RESET << mancala_array[0] << CYAN << " || " << RESET << mancala_array[1] << CYAN << " || " << RESET << mancala_array[2] << CYAN << " || " << RESET << mancala_array[3] << CYAN << " || " << RESET << mancala_array[4] << CYAN << " || " << RESET << mancala_array[5] << CYAN << " ||   | |" << RESET << endl;
	cout << CYAN << "| |___||___||___||___||___||___||___||___| |" << RESET << endl;
	cout << CYAN << "|                                          |" << RESET << endl;
	cout << CYAN << "|   1   A    B    C    D    E    F    2    |" << RESET << endl;
	cout << CYAN << "|__________________________________________|" << RESET << endl;

	cout << endl << "Player 2 = " << GREEN << "LEFT MANCALA" << RESET << " = " << mancala_array[13] << endl << endl;

	if (next_mover() == HUMAN)
	{
		cout << endl << RED << "Player 1 - Enter the letter of your pit." << RESET << endl << endl;
	}
	else if (next_mover() == COMPUTER)
	{
		cout << endl << GREEN << "Player 2 - Enter the letter of your pit." << RESET << endl << endl;
	}

	//cout << "Type in the letter of the pit you would like to pull stones from" << endl << endl;
}

int mancala::evaluate()const
{
	int evaluation = 0;

	evaluation = mancala_array[13] - mancala_array[6]; //Flip if you want to be mean

	return evaluation;
}

bool mancala::is_game_over()const
{
	int check = 0;
	int finish = 0;

	if(next_mover() == HUMAN)
	{
		for (int i = 0; i < 6; i++)
		{
			if (mancala_array[i] == 0)
			{
				check++;
			}
		}

		if(check == 6)
		{
			for (int i = 7; i < 14; i++)
			{
				finish = finish + mancala_array[i];
			}

			if (mancala_array[6] > finish)
			{
				cout << "First mancala wins!" << endl;
				return true;
			}
			else
			{
				cout << "Second mancala wins!" << endl;
				return true;
			}
		}
	}
	else if (next_mover() == COMPUTER)
	{
		for (int i = 7; i < 13; i++)
		{
			if (mancala_array[i] == 0)
			{
				check++;
			}
		}

		if (check == 6)
		{
			for (int i = 0; i < 7; i++)
			{
				finish = finish + mancala_array[i];
			}

			if (mancala_array[13] > finish)
			{
				cout << "First mancala wins!" << endl;
				return true;
			}
			else
			{
				cout << "Second mancala wins!" << endl;
				return true;
			}
		}
	}

	return false;
}

bool mancala::is_legal(const std::string& move)const
{
	int position = 0;

	if (move.length() != 1)
	{
		cout << "Not a valid move! Input JUST ONE pit letter!" << endl;
		return false;
	}

	if (move != "A" && move != "a" && move != "B" && move != "b" && move != "C" && move != "c" && move != "D" && move != "d" && move != "E" && move != "e" && move != "F" && move != "f")
	{
		cout << "Not a valid move! Input a DISPLAYED pit letter!" << endl;
		return false;
	}

	// if (next_mover() == HUMAN)
	// {
	// 	if (move == "A" || move == "a")
	// 	{
	// 		position = 0;
	// 	}
	// 	else if (move == "B" || move == "b")
	// 	{
	// 		position = 1;
	// 	}
	// 	else if (move == "C" || move == "c")
	// 	{
	// 		position = 2;
	// 	}
	// 	else if (move == "D" || move == "d")
	// 	{
	// 		position = 3;
	// 	}
	// 	else if (move == "E" || move == "e")
	// 	{
	// 		position = 4;
	// 	}
	// 	else if (move == "F" || move == "f")
	// 	{
	// 		position = 5;
	// 	}
	// }
	// else if (next_mover() == COMPUTER)
	// {
	// 	if (move == "A" || move == "a"){position = 7;}
	// 	else if (move == "B" || move == "b")
	// 	{
	// 		position = 8;
	// 	}
	// 	else if (move == "C" || move == "c")
	// 	{
	// 		position = 9;
	// 	}
	// 	else if (move == "D" || move == "d")
	// 	{
	// 		position = 10;
	// 	}
	// 	else if (move == "E" || move == "e")
	// 	{
	// 		position = 11;
	// 	}
	// 	else if (move == "F" || move == "f")
	// 	{
	// 		position = 12;
	// 	}
	// }

	if (mancala_array[position] == 0)
	{
		cout << "No stones in this pit! Try another!" << endl;
		return false;
	}

	return true;
}

game::who mancala::winning()const
{
	if (mancala_array[6] > mancala_array[13])
	{
		return HUMAN;
	}
	else if (mancala_array[13] > mancala_array[6])
	{
		return COMPUTER;
	}
	else
	{
		return NEUTRAL;
	}
}