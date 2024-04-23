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
	stream << 5;
	stream << endl;
	stream << 0x3fda1;
	stream << endl;
	stream << "hello world" << "wow";
	stream.flush();
	stream << endl;
	stream << 10;
	stream << endl;
	stream << "this is a test";
	stream << 10;
	stream << endl;
	stream << "this is a test";
	stream.flush();
	stream << "\0";

/* Add your code here */ 
// 	for (int i = 0; i < 5; i++) {
// 					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << i << endl;
// 	}
// 	for (int i = 0; i < 5; i++) {
// 			stream << endl;
// 	}
// /* Add your code here */ 
//  	for (int i = 0; i < 5; i++) {
// 					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << i << endl;
// 	}

// 	for (int i = 0; i < 5; i++) {
// 			stream << endl;
// 	}

// 	for (int i = 0; i < 5; i++) {
// 					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << i << endl;
// 	}
// 	for (int i = 0; i < 5; i++) {
// 			stream << endl;
// 	}
// /* Add your code here */ 
//  for (int i = 0; i < 5; i++) {
// 					stream << "Hello Welcome to OOstuBS Hello Welcome to OOstuBS Hello Welcome to OOstuBS " << i << endl;
// 	}
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
