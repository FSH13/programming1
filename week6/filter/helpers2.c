/*************************************
 * Fleur
 * filter.c
 * apply filter options; grayscale, sepia, flip and blur
*************************************/

#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // h = height(row), w = width(column) of the picture pixel

    for (int h = 0; h < height - 1; h++){
        for (int w = 0; w < width - 1; w++){
            image[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3);
            image[h][w].rgbtGreen = image[h][w].rgbtBlue;
            image[h][w].rgbtRed = image[h][w].rgbtBlue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++){
        for (int w = 0; w < width - 1; w++){
            int new_blue = round((image[h][w].rgbtBlue * .131) + (image[h][w].rgbtGreen * .534) + (image[h][w].rgbtRed * .272));
            int new_green = round((image[h][w].rgbtBlue * .168) + (image[h][w].rgbtGreen * .686) + (image[h][w].rgbtRed * .349));
            int new_red = round((image[h][w].rgbtBlue * .189) + (image[h][w].rgbtGreen * .769) + (image[h][w].rgbtRed * .393));
            if (new_blue > 255){
                image[h][w].rgbtBlue = 255;
            }
            else if (new_blue < 0){
                image[h][w].rgbtBlue = 0;
            }
            else {
                image[h][w].rgbtBlue = new_blue;
            }

            if (new_green > 255){
                image[h][w].rgbtGreen = 255;
            }
            else if (new_green < 0){
                image[h][w].rgbtGreen = 0;
            }
            else {
                image[h][w].rgbtGreen = new_green;
            }

            if (new_red > 255){
                image[h][w].rgbtRed = 255;
            }
            else if (new_red < 0){
                image[h][w].rgbtRed = 0;
            }
            else {
                image[h][w].rgbtRed = new_red;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int rw = width;
    RGBTRIPLE temp;

    for (int h = 0; h < height - 1; h++){
        rw = width;
        for (int w = 0; w < rw - 1; w++){
            temp = image[h][w];
            image[h][w] = image[h][rw];
            image[h][rw] = temp;
            rw--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height - 1; h++){
        for (int w = 0; w < width - 1; w++){
             RGBTRIPLE ne = image[h-1][w-1], nn = image[h-1][w], nw = image[h-1][w+1], ww = image[h][w+1];
             RGBTRIPLE ee = image[h][w-1], se = image[h+1][w-1], ss = image[h+1][w], sw = image[h+1][w+1];
             if (h == 0){
                 if (w == 0){
                     image[h][w] = round((ww + ss + sw) / 3);
                 }
                 else {
                     image[h][w] = round((ee + se + ss + sw + ww) / 5);
                 }
             }
             else {
                 if (w == 0){
                     image[h][w] = round((nn + nw + ww + sw + ss) / 5);
                 }
                 else {
                     image[h][w] = round((ee + se + ss + sw + ww + nw + nn + ne) / 8);
                 }
             }
        }
    }
    return;
}
