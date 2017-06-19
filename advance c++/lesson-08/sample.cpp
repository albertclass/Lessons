#include "header.h"
#include <cstdlib>

static int item = 0;

struct sample
{
	sample()
	{
		item = 1;
	}
};

static sample s;

class A
{
public:
	A( std::string s )
		: m_str( s )
	{

	}

	std::string f()const
	{
		return m_str;
	}

	std::string m_str;
};

class B : public A
{
public:
	B() : A( s = f() )
	{

	}

	std::string s;
};

// 无法内嵌汇编，只能通过调试来看 RBP寄存器的值
void do_lesson( int rows, int cols )
{
	printw( "C++启动\n" );

	char cstr[256];
	char astr[] = "1234567890";
	strcpy( cstr, astr );
	memcpy( cstr, astr, sizeof(astr) );

	try
	{
		throw( 0 );
	}
	catch( ... )
	{
		printw( "error" );
	}

	wait_key( 13 );

	B b;
	b.f();
}

/*
mov     r11, rcx
strcat_copy:
___entry_from_strcat_in_strcpy=strcat_copy
; align the SOURCE so we never page fault
; dest pointer alignment not important
sub     rcx, rdx ; combine pointers
test    dl, 7
jz      qword_loop_entrance

copy_head_loop_begin:
mov     al, [rdx]
mov     [rdx+rcx], al
test    al, al
jz      byte_exit
inc     rdx
test    dl, 7
jnz     copy_head_loop_begin
jmp     qword_loop_entrance

byte_exit:
mov     rax, r11
ret

qword_loop_begin:
mov     [rdx+rcx], rax
add     rdx, 8
qword_loop_entrance:
mov     rax, [rdx]
mov     r9, 7efefefefefefeffh
add     r9, rax
mov     r10, rax
xor     r10, -1
xor     r10, r9
mov     r9, 8101010101010100h
test    r10, r9
jz      qword_loop_begin

qword_loop_end:
test    al, al
mov     [rdx+rcx], al
jz      strcat_exit
inc     rdx
test    ah, ah
mov     [rdx+rcx], ah
jz      strcat_exit
inc     rdx
shr     rax, 16
test    al, al
mov     [rdx+rcx], al
jz      strcat_exit
inc     rdx
test    ah, ah
mov     [rdx+rcx], ah
jz      strcat_exit
inc     rdx
shr     rax, 16
test    al, al
mov     [rdx+rcx], al
jz      strcat_exit
inc     rdx
test    ah, ah
mov     [rdx+rcx], ah
jz      strcat_exit
inc     rdx
shr     eax, 16
test    al, al
mov     [rdx+rcx], al
jz      strcat_exit
inc     rdx
test    ah, ah
mov     [rdx+rcx], ah
jz      strcat_exit
inc     rdx
jmp     qword_loop_entrance

strcat_exit:
mov     rax, r11
ret

LEAF_END strcpy, _TEXT

end
*/
