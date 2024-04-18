/* Add your code here */ 
#include "machine/cgascr.h"

int main()
{
/* Add your code here */ 
	CGA_Screen display = CGA_Screen();

	for (int i=0; i<300; i++){
		display.print("Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS \n", 76, 0x0F);
	}
	// for (int i=0;i<10;i++){
	// 	display.show(i, i, 'X', 0x0F);
	// }
/* Add your code here */ 
 
/* Add your code here */ 
 
	return 0;
}
