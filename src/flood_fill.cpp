#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

#define HEIGHT 9
#define WIDTH 9

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

bool operator==(const Color &lhs, const Color &rhs) {
	return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}

std::ostream& operator<<(std::ostream &strm, const Color &color) {
	return strm << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")";
}

const Color black = Color{0, 0, 0};
const Color white = Color{255, 255, 255};
const Color red   = Color{255, 0, 0};
const Color green = Color{0, 255, 0};
const Color blue  = Color{0, 0, 255};

Color board[HEIGHT][WIDTH] = {
{black, black, black, black, black, black, black, black, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, white, white, white, white, white, white, white, black},
{black, black, black, black, black, black, black, black, black}
};

void flood_fill(unsigned int x, unsigned int y, Color new_color) {
	Color old_color = board[y][x];
	board[y][x] = new_color;
	if (y > 0)
		if (board[y-1][x] == old_color)
			flood_fill(x, y-1, new_color);
	if (y < HEIGHT-1)
		if (board[y+1][x] == old_color)
			flood_fill(x, y+1, new_color);
	if (x > 0)
		if (board[y][x-1] == old_color)
			flood_fill(x-1, y, new_color);
	if (x < WIDTH-1)
		if (board[y][x+1] == old_color)
			flood_fill(x+1, y, new_color);
}

void print_board() {
	for (unsigned int y = 0; y < HEIGHT; y++) {
		for (unsigned int x = 0; x < WIDTH; x++) {
			std::cout << board[y][x];
		}
		std::cout << std::endl;
	}
}

int main() {
	print_board();

	flood_fill(4, 4, red);

	print_board();
}