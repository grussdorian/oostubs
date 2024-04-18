/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"

/* Add your code here */ 
O_Stream& endl(O_Stream& os) {
	os.put('\n');
	os.flush();
	return os;
}
// BIN: selects the binary number system
/* Add your code here */ 
O_Stream& bin(O_Stream& os) {
	os.setBase(BIN);
	return os;
}
	// OCT: selects the octal number system
	/* Add your code here */ 
O_Stream& oct(O_Stream& os) {
    os.setBase(OCT);
    return os;
}

	// DEC: selects the decimal number system
	/* Add your code here */ 
O_Stream& dec(O_Stream& os) {
    os.setBase(DEC);
    return os;
}

	// HEX: selects the hexadecimal number system
	/* Add your code here */ 

O_Stream& hex(O_Stream& os) {
    os.setBase(HEX);
    return os;
}