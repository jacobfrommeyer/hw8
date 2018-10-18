/**********************************************
 * 
 * Name: Jacob Frommeyer
 * Date: 4/20/2018
 * Mancala class header
 *********************************************/

#ifndef MANCALA_H
#define MANCALA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "game.h"

namespace main_savitch_14
{
	class mancala: public game
	{
	    public:
		void make_move(const std::string& move);
		void restart();

		game * clone()const;

		void compute_moves(std::queue <std::string>& moves)const;
		void display_status()const;

		int evaluate()const;

		bool is_game_over()const;
		bool is_legal(const std::string& move)const;

		game:: who winning()const;

	    private:
		int mancala_array[13];
	};
#endif
}
