
#include <stdio.h>

#define WORD_SIZE sizeof(size_t)

void SetChunk(unsigned char *buffer, int c);
void *MemSet(void *dest, int c, size_t n);
int IsAligned(void *s);

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


int main()
{
  char src[11] = "almogalmog";
  char dest[18] = "12345671234512345";
  

    
MemMove(dest, src, 1);
printf ("dest: %s\n", dest);
MemSet(dest, '$', 8);
printf ("dest: %s\n", dest);
  printf ("is IsAligned: %d\n", IsAligned(dest));


  return 0;
}


