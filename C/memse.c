
#include <stdio.h>

#define WORD_SIZE sizeof(size_t)

void SetChunk(char *buffer, int c);
void *MemSet(void *dest, int c, size_t n);
int IsAligned(void *s);

void *MemSet(void *dest, int c, size_t n)
{
    unsigned char *p_char = (unsigned char *)dest;
    char buffer[8];
    unsigned char data = (unsigned char)c;
    size_t i = 0;
    

    if (n > WORD_SIZE)
    SetChunk(buffer, c);


    puts("befre while  \n");

    while(0 != n)
    {
        if((n > WORD_SIZE) && (1 == IsAligned(dest)))
        {
            puts("im here \n");
            dest = buffer;
            n -= WORD_SIZE;
            dest += WORD_SIZE;
            puts("im here\n");
        }
        else
        {
            printf("else %ld\n", n);
            *(unsigned char *)dest = c;
            ++dest;
            --n; 
        }
    }
/*
    while((n > WORD_SIZE) && (1 == IsAligned(dest)))
    {
        puts("im here \n");
        dest = buffer;
        n -= WORD_SIZE;
        dest += WORD_SIZE;
    }

    while(0 != n)
    {
        *p_char = c;
        ++p_char;
        --n;
    }*/
}

void SetChunk(char *buffer, int c)
{
    size_t i = 0;
    for(i = 0; i < WORD_SIZE; ++i)
    {
        *buffer = c;
    }
    puts("set chunk active\n");
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

int main()
{
  char src[11] = "almogalmog";
  char dest[18] = "12345671234512345";
  /*
  MemSet(dest, '$', 9);
    */
    MemCpy(dest, src, 9);
  printf ("dest: %s\n", dest);

  printf ("is IsAligned: %d\n", IsAligned(dest));


  return 0;
}


