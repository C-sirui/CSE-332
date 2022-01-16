#include<string>

#include "enum.h"
#include "piece.h"

using namespace std;

string piece_colortostring(piece_color color) {
	switch (color)
	{
	case piece_color::red:
		return "red";
	case piece_color::white:
		return "white";
	case piece_color::black:
		return "black";
	case piece_color::blank:
		return "blank";
	case piece_color::blue:
		return "blue";
	default:
		return "invalid";
	}
}

piece_color stringtopiece_color(string color) {
	string ans = tosmall(color);
	if (ans == piece_colortostring(piece_color::blue)) {
		return piece_color::blue;
	}
	if (ans == piece_colortostring(piece_color::red)) {
		return piece_color::red;
	}
	if (ans == piece_colortostring(piece_color::white)) {
		return piece_color::white;
	}
	if (ans == piece_colortostring(piece_color::black)) {
		return piece_color::black;
	}
	if (ans == " ") {
		return piece_color::blank;
	}
	return piece_color::invalid;
	

}

game_piece::game_piece(): color_(piece_color::blank), piece_name_(" "), display_(" ") {}

game_piece::game_piece(piece_color color, string name, string display): color_(color), piece_name_(name), display_(display) {}
