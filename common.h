#ifndef COMMON_H
#define COMMON_H

/*
 * TO DO:
 * number of squares should be always 24 tall and 32 wide
 * size of square in pixels depends on resolution
 * resolution should be modified by the program to fit 24 by 32 squares
 */

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define OUTER_SQUARE_SIZE   20
#define INNER_SQUARE_SIZE   16
#define SQUARE_WIDTH        ((WINDOW_WIDTH / OUTER_SQUARE_SIZE))
#define SQUARE_HEIGHT       ((WINDOW_HEIGHT / OUTER_SQUARE_SIZE))
#define PIXEL_DELTA         (((OUTER_SQUARE_SIZE - INNER_SQUARE_SIZE) / 2))

#endif
