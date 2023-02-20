

#define XSIZE 8
#define YSIZE 8


typedef enum status
{
    NOT_FOUND = 0,
    FOUND = 1
} status_ty;


status_ty FindKnightTour(int x, int y, int path[128])
{
  int chess_board[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},   /* set the first board setup. */
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}}
    
    int cnt = 0;
    int status = 0;
    
    status = FindKnightTourIML(&chess_board, x, y, cnt);
    
    if (FOUND == status)
    {
        UpadtePath(chess_board ,&path);
    }
    
    return status;
}

status_ty FindKnightTourIML(int chess_board[8][8],int x, int y, int cnt)
{
    if (64 == cnt)
    {
        return FOUND;
    }
    
    if (0 == NumOfOptions(chess_board[8][8],x, y))
    {
        FindMoveIdx(chess_board[8][8], &x, &y, cnt - 1); /* second min value!!! */
        
        FindKnightTourIML(chess_board[8][8], x, y, cnt - 1);
    }
    
    FindNextMoveIdx(chess_board[8][8], &x, &y, cnt);
    
    chess_board[x][y] = cnt + 1;
    
    FindKnightTourIML(chess_board[8][8], &x, &y, cnt);
}

void FindNextMoveIdx(int chess_board[8][8],int *x, int *y, int cnt)
{
    int numofoptions[8] = {9,9,9,9,9,9,9,9};
    int index = 0;
    int x0 = 1, x1 = 1, x2 = -1, x3 = -1, x4 = 2, x5 = 2, x6 = -2, x7 = -2;
    int y0 = 2, y1 = -2, y2 = 2, y3 = -2, y4 = 1, y5 = -1, y6 = +1, y7 = -1;
    
    /* 0 */
    if ((*x + 1) < XSIZE) && ((*y + 2) < YSIZE) 
    {
         numofoptions[0] = NumOfOptions(chess_board[8][8],*x + 1, *y + 2);
    }
    /* 1 */
    if ((*x + 1) < XSIZE) && ((*y - 2) > YSIZE) 
    {
         numofoptions[1]  = NumOfOptions(chess_board[8][8],*x + 1, *y - 2);
    }
    /* 2 */
    if ((x - 1) > XSIZE) && ((y + 2) < YSIZE) 
    {
         numofoptions[2] = NumOfOptions(chess_board[8][8],*x - 1, *y + 2);
    }
    /* 3 */
    if ((*x - 1) > XSIZE) && ((*y - 2) > YSIZE) 
    {
         numofoptions[3] = NumOfOptions(chess_board[8][8], *x - 1, *y - 2);
    }
    /* 4 */
    if ((*x + 2) < XSIZE) && ((*y + 1) < YSIZE) 
    {
         numofoptions[4] = NumOfOptions(chess_board[8][8],*x + 2, *y + 1);
    }
    /* 5 */
    if ((*x + 2) < XSIZE) && ((*y - 1) > YSIZE) 
    {
         numofoptions[5] = NumOfOptions(chess_board[8][8],*x + 2, *y - 1);
    }
    /* 6 */
    if ((*x - 2) > XSIZE) && ((*y + 1) < YSIZE) 
    {
         numofoptions[6] = NumOfOptions(chess_board[8][8],*x - 2, *y + 1);
    }
    /* 7 */
    if ((*x - 2) > XSIZE) && ((*y - 1) > YSIZE) 
    {
         numofoptions[7] = NumOfOptions(chess_board[8][8],*x - 2, *y - 1);
    }
    
    index = FindMinInx(numofoptions, 8);
    
    switch(index)
    {
    case 0:
        *x = x0;
        *y = y0;
        break;
    case 1:
        *x = x1;
        *y = y1;
        break;
    case 2:
        *x = x2;
        *y = y2;
        break;
    case 3:
        *x = x3;
        *y = y3;
        break;
    case 4:
        *x = x4;
        *y = y4;
        break;
    case 5:
        *x = x5;
        *y = y5;
        break;
    case 6:
        *x = x6;
        *y = y6;
        break;
    case 7:
        *x = x7;
        *y = y7;
        break;
    default:
        break;
}



int NumOfOptions(int chess_board[8][8],int x, int y)
{
    int cnt_possible = 0;
    
    if ((x + 1) < XSIZE) && ((y + 2) < YSIZE) 
    {
        if ((chess_board[x + 1][y + 2]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x + 1) < XSIZE) && ((y - 2) > YSIZE) 
    {
        if ((chess_board[x + 1][y - 2]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x - 1) > XSIZE) && ((y + 2) < YSIZE) 
    {
        if ((chess_board[x - 1][y + 2]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x - 1) > XSIZE) && ((y - 2) > YSIZE) 
    {
        if ((chess_board[x - 1][y - 2]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x + 2) < XSIZE) && ((y + 1) < YSIZE) 
    {
        if ((chess_board[x + 2][y + 1]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x + 2) < XSIZE) && ((y - 1) > YSIZE) 
    {
        if ((chess_board[x + 2][y - 1]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x - 2) > XSIZE) && ((y + 1) < YSIZE) 
    {
        if ((chess_board[x - 2][y + 1]) == 0 )
        {
            ++cnt_possible;
        }
    }
    if ((x - 2) > XSIZE) && ((y - 1) > YSIZE) 
    {
        if ((chess_board[x - 2][y - 1]) == 0 )
        {
            ++cnt_possible;
        }
    }
    
    return cnt_possible;
}

static int FindMinInx(int *arr, size_t size)
{
    size_t i = 0;
    int index = 0;
    int min_value = 9;
    
    for(i = 0; i < size; ++i)
    {
        if ((arr[i] < min_value) && (0 != arr[i])) 
        {
            index = i;
            min_value = arr[i];
        }
    }
    
    return index;
}
