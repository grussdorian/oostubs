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

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"
#include <cstdint>

enum NumberBase {
    BIN,
    OCT,
    DEC,
    HEX
};

class O_Stream : public Stringbuffer
/* Add your code here */ 
{
	private:
    NumberBase base;
	public:
		O_Stream(const O_Stream &copy) = delete; // prevent copying
    O_Stream() : base(DEC) {}

    O_Stream& operator<< (unsigned char c) {
        put(c);
        return *this;
    }

    O_Stream& operator<< (char c) {
        put(c);
        return *this;
    }

		O_Stream& operator<< (unsigned short number){
        put(number);
        return *this;
    }
		O_Stream& operator<< (short number){
        put(number);
        return *this;
    }
		O_Stream& operator<< (unsigned int number){
        put(number);
        return *this;
    }
		O_Stream& operator<< (int number){
        put(number);
        return *this;
    }
		O_Stream& operator<< (unsigned long number){
        put(number);
        return *this;
    }
		O_Stream& operator<< (long number){
        put(number);
        return *this;
    }

    void flush() override {
        // Implement this method in a derived class
    }

    void setBase(NumberBase base) {
        this->base = base;
    }

    NumberBase getBase() const {
        return base;
    }
		/* Add your code here */ 

		O_Stream& operator<< (void* pointer) {
			NumberBase oldBase = base;
			base = HEX;
			*this << reinterpret_cast<uintptr_t>(pointer);
			base = oldBase;
			return *this;
		}

		O_Stream& operator<< (char* text) {
			while (*text) {
				put(*text++);
			}
			return *this;
		}

    O_Stream& operator<< (O_Stream& (*fkt) (O_Stream&)) {
        return fkt(*this);
    }
};

	/*---------------------------------------------------------------------------*/
	/*                                                                           */
	/*                          M A N I P U L A T O R S                          */
	/*                                                                           */
	/*---------------------------------------------------------------------------*/
	/* The functions below all receive and return a reference to an O_Stream     */
	/* object. Because class O_Stream defines an operator<< for functions with   */
	/* this signature, they can be called in this operator's implementation and  */
	/* even be embedded in a "stream" of outputs. A manipulator's task is to     */
	/* influence subsequent output, e.g. by switching to a different number      */
	/* system.                                                                   */
	/*---------------------------------------------------------------------------*/

	// ENDL: inserts a newline in the output and flushes the buffer
	/* Add your code here */ 
O_Stream& endl(O_Stream& os);

O_Stream& bin(O_Stream& os);

O_Stream& oct(O_Stream& os);

O_Stream& dec(O_Stream& os);

O_Stream& hex(O_Stream& os);
#endif
