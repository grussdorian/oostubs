/* Add your code here */ 
#include "machine/cgascr.h"
#include "device/cgastr.h"
int main()
{
/* Add your code here */ 
	// CGA_Screen display = CGA_Screen();

	// for (int i=0; i<300; i++){
	// 	display.print("Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS \n", 76, 0x0F);
	// }
	// for (int i=0;i<10;i++){
	// 	display.show(i, i, 'X', 0x0F);
	// }
	CGA_Stream stream;
/* Add your code here */ 
	for (int i = 0; i < 5; i++) {
					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << endl;
	}
	for (int i = 0; i < 5; i++) {
			stream << endl;
	}
/* Add your code here */ 
 for (int i = 0; i < 5; i++) {
					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << endl;
	}
	for (int i = 0; i < 5; i++) {
					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << endl;
	}
	for (int i = 0; i < 5; i++) {
			stream << endl;
	}
/* Add your code here */ 
 for (int i = 0; i < 5; i++) {
					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << endl;
	}
	// for (int i = 0; i< 30; i++)
	// {
	// 	for (int j = 0; j< 80; j++)
	// 	{
	// 		stream << "*";
	// 	}
	// 	stream << endl;
	// }
	return 0;
}
