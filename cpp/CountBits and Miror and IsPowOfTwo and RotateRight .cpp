size_t CountBits(unsigned char bit)
{
size_t count = 0;
    while(bit)
    {
        count += (bit & 1);

        
        bit >>= 1;
    }
    
    return count;
}


void Miror(unsigned char *bit)
{
    unsigned char res = *bit;
    unsigned char reversed = 0;
    
    while(res)
    {
        if((res & 1) == 1)
        {
            reversed <<= 1;
            reversed |= 1;
        }
        else
        {
            reversed <<= 1;
        }
        
        res >>= 1;
    }
    
    *bit = reversed;
}


bool IsPowOfTwo(int num)
{
    if (num < 0) 
    {
        return false;
    }
    
    return (num & (num - 1)) == 0;
}



unsigned char RotateRight(unsigned char num, int n)
{
    while(n)
    {
        
        unsigned char lsb = num & 1;
        
        num = (num >> 1) | (lsb << 7);
        --n;
    }
    
    return num;
}
