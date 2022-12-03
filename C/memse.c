.C

#include <stdio.h> /*size_t*/

#include "ws9.h"

#define WORD_SIZE sizeof(size_t)

static void WriteChunk (void *dest, void *src);
static void SetChunk(unsigned char *buffer, int c);
static int IsAligned(void *s);

void *MemSet(void *dest, int c, size_t n)
{
    unsigned char *p_char = (unsigned char *)dest;
    unsigned char buffer[8];
    unsigned char data = (unsigned char)c;
    
    if (n > WORD_SIZE)
    {
        SetChunk(buffer, c);
    }

    while(0 != n)
    {
        if((n > WORD_SIZE) && (1 == IsAligned(dest)))
        {
            dest = buffer;
            n -= WORD_SIZE;
            dest += WORD_SIZE;
        }
        else
        {
            *(unsigned char *)dest = data;
            ++dest;
            --n; 
        }
    }
}

void SetChunk(unsigned char *buffer, int c)
{
    size_t i = 0;
    unsigned char data = (unsigned char)c;

    for(i = 0; i < WORD_SIZE; ++i)
    {
        *buffer = data;
        ++buffer;
    }
    printf("buffer ready %s!\n", buffer);
}

void WriteChunk (void *dest, void *src)
{
  unsigned char *src1 = src;
  unsigned char *dest1 = dest;

  *(size_t *) dest1 = *(size_t *) src1;
    puts("Write chunk active\n");

}

int IsAligned(void *s)
{
  if (0 == ((size_t)s % WORD_SIZE))
    {
      return 1;
    }
    
  return 0;
}

void *MemCpy(void *dest, const void *src, size_t n)
{
    unsigned char *p_dest = (unsigned char *)dest;
    unsigned char *p_src = (unsigned char *)src;

    while(0 != n)
    {
        if ((n > WORD_SIZE) && (1 == IsAligned(dest)))
        {
            *(size_t *) dest = *(size_t *) src;
            dest += WORD_SIZE;
            src += WORD_SIZE;
            n -= WORD_SIZE;
        }
        else
        {
            *(unsigned char *)dest = *(unsigned char *)src;
            ++src;
            ++dest;
            --n;    
        }
    }
}

void *MemMove(void *dest, const void *src, size_t n)
{
    /*start copy from the end, to avoid overlap*/
    src += n - 1;
    dest += n - 1;
    while(0 != n)
    {
        /*cast to unsigned char and copy byte-byte*/
        *(unsigned char *)dest = *(unsigned char *)src;
        --src;
        --dest;
        --n;    
    }
}

test.c 
/***********************************
* Date: 2/12/22
* Authour: Almog 
* Reviewer: Nadav 
*************************************/
#include <stdio.h> /* printf */
#include <string.h> /*memove,memcpy,memset */

#include "ws9.h"

#define RESET   "\033[0m"           /* Reset color */
#define RED     "\033[1m\033[31m"   /* Bold Red */
#define GREEN   "\033[1m\033[32m"   /* Bold Green */


void FuncTestChar(unsigned char *out, unsigned char *e_out, const char *name)
{
    if (*out != *e_out)
    {
        printf("%s "RED" FAILED "RESET" output: %s, expected output: %s  \n",
        name ,out ,e_out);
    }
}

void TestMemFuncs()
{
  unsigned char src[33] = "DataDataDataDataDataDataDataData";
  unsigned char dest[33] = "12341234123412341234123412341234";
  unsigned char copy_src[33] = "DataDataDataDataDataDataDataData";
  unsigned char copy_dest[33] = "12341234123412341234123412341234";

    MemMove(dest, src, 10);
    memmove(copy_dest, copy_src, 10);
    FuncTestChar(copy_dest, dest, "MemMove");

    MemCpy(dest, src, 10);
    memcpy(copy_dest, copy_src, 10);
    FuncTestChar(copy_dest, dest, "MemCpy");

    MemSet(dest, '$', 3);
    memset(copy_dest, '$', 3);
    FuncTestChar(copy_dest, dest, "MemSet");


}


int main()
{
    TestMemFuncs();
    return 0;
}

.h
#ifndef __WS9_H__
#define __WS9_H__

#include<stddef.h>
/******************************************************************************
* Date: 1/12/22
* Authour: Almog 
* Reviewer: Nadav
*******************************************************************************/

/******************************************************************************
    memset - fill memory with a constant byte
    The  memset()  function  fills  the  first  n  bytes of the memory area
    pointed to by s with the constant byte c.
    returns a pointer to the memory area s.
*******************************************************************************/
void *MemCpy(void *dest, const void *src, size_t n);


/******************************************************************************
    memset - fill memory with a constant byte
    The  memset()  function  fills  the  first  n  bytes of the memory area
    pointed to by s with the constant byte c.
    returns a pointer to the memory area s.
*******************************************************************************/
void *MemSet(void *dest, int c, size_t n);


/******************************************************************************
    MemMove - copy memory area
    copies n bytes from memory area src to memory
    area dest.  The memory areas may overlap: copying takes place as though
    the  bytes in src are first copied into a temporary array that does not
    overlap src or dest, and the bytes are then copied from  the  temporary
    array to dest.
    returns a pointer to dest.
*******************************************************************************/
void *MemMove(void *dest, const void *src, size_t n);

#endif /* __WS9_H__ */






