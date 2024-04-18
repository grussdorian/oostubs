#ifndef __screen_include__
#define __screen_include__

/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/io_port.h"

class CGA_Screen {
private:

	static const int WIDTH = 80;
	static const int HEIGHT = 25;
	static const int VIDEO_MEMORY = 0xB8000;
	int x;
	int y;
	char c;
	
public:
	unsigned char attrib;
	volatile char *video = (volatile char*)VIDEO_MEMORY;

	CGA_Screen(const CGA_Screen &copy) = delete; // prevent copying
	CGA_Screen() : x(0), y(0), c('A'), attrib(0x0F) {
		for (int row=0; row<WIDTH; row++){
			for (int col=0; col<HEIGHT; col++){
				show(row, col, ' ', 0x0F);
			}
		}
		this->x = 0;
		this->y = 0;
	}

	void show(int x, int y, char c, unsigned char attrib) {
			if (c == '\n')
			{
				this->x = 0;
				if (++this->y == HEIGHT)
				{
					this->y = 0;
					shift_screen_up();
				}
				return;
			}
			video[(y * WIDTH + x) * 2] = c;
			video[(y * WIDTH + x) * 2 + 1] = attrib;
	}

	void setpos(int x, int y) {
			this->x = x;
			this->y = y;
	}

	void getpos(int &x, int &y) {
			x = this->x;
			y = this->y;
	}

void print(char* text, int length, unsigned char attrib) {
    for (int i = 0; i < length; ++i) {
        if (text[i] == '\n') {
            x = 0;
            if (++y == HEIGHT) {
                y = 0;
                shift_screen_up();
            }
        } else {
            show(x, y, text[i], attrib);
            if (++x == WIDTH) {
                x = 0;
                if (++y == HEIGHT) {
                    y = 0;
                    shift_screen_up();
                }
            }
        }
    }
}

	public:
		void shift_screen_up(){
			// Copy every character in a temp variable, shift up by one index on the screen, and write the copied variable
			for (int row = 0; row < HEIGHT - 1; row++) {
				for (int col = 0; col < WIDTH; col++) {
					char tempChar = video[((row + 1) * WIDTH + col) * 2];
					unsigned char tempAttrib = video[((row + 1) * WIDTH + col) * 2 + 1];
					show(col, row, tempChar, tempAttrib);
				}
			}

			// Clear the last row
			for (int col = 0; col < WIDTH; col++) {
				show(col, HEIGHT - 1, ' ', 0x0F);
			}
	}
};

#endif
