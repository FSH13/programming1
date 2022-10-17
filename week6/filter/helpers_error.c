/*************************************
 * Fleur 
 * filter.c
 * apply filter options; grayscale, sepia, flip and blur
*************************************/

#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){
            image[h][w].rgbtBlue = ceil((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3.0);
            image[h][w].rgbtGreen = image[h][w].rgbtBlue;
            image[h][w].rgbtRed = image[h][w].rgbtBlue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){

            // calculate the new RGB the current pixel using the sepia rules
            int new_blue = round((image[h][w].rgbtBlue * .131) + (image[h][w].rgbtGreen * .534) + (image[h][w].rgbtRed * .272));
            int new_green = round((image[h][w].rgbtBlue * .168) + (image[h][w].rgbtGreen * .686) + (image[h][w].rgbtRed * .349));
            int new_red = round((image[h][w].rgbtBlue * .189) + (image[h][w].rgbtGreen * .769) + (image[h][w].rgbtRed * .393));

            // check if the new RGB is between 0 and 255 before entering either 0, 255 or the new RGB
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
    // create variable opposite width and a temp rgbtripple to store the opposite pixel
    int rw = width;
    RGBTRIPLE temp;

    // loop over each pixel and swap with the opposing pixel the loop stops if we reach the middle
    for (int h = 0; h < height; h++){
        rw = width-1;
        for (int w = 0; w <= rw; w++){
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
    // create rgbtriples for the surrounding pixels
    RGBTRIPLE ne, nn, nw, ww, ee, se, ss, sw;
    int max_h = height - 1, max_w = width - 1;
    RGBTRIPLE original_image[height][width];
    for (int cr = 0; cr <= max_h; cr++){
        for (int cw = 0; cw <= max_w; cw++){
            original_image[cr][cw] = image[cr][cw];
        }
    }

    // loop over each pixel
    for (int h = 0; h <= max_h; h++){
        for (int w = 0; w <= max_w; w++){
             // take the average of the surrounding pixels depending on the location of the pixel
             // if it's in a corner of around the edge, there are less surrounding pixels bottom right is 0-0
             if (h == 0){
                 if (w == 0){
                     nn = original_image[h+1][w];
                     nw = original_image[h+1][w+1];
                     ww = original_image[h][w+1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + nn.rgbtRed + nw.rgbtRed + ww.rgbtRed) / 4.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + nn.rgbtGreen + nw.rgbtGreen + ww.rgbtGreen) / 4.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + nn.rgbtBlue + nw.rgbtBlue + ww.rgbtBlue) / 4.0);
                 }
                 else if (w == max_w){
                     nn = original_image[h+1][w];
                     ne = original_image[h+1][w-1];
                     ee = original_image[h][w-1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + nn.rgbtRed + ne.rgbtRed + ee.rgbtRed) / 4.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + nn.rgbtGreen + ne.rgbtGreen + ee.rgbtGreen) / 4.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + nn.rgbtBlue + ne.rgbtBlue + ee.rgbtBlue) / 4.0);
                 }
                 else {
                     ee = original_image[h][w-1];
                     ne = original_image[h+1][w-1];
                     nn = original_image[h+1][w];
                     nw = original_image[h+1][w+1];
                     ww = original_image[h][w+1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + ee.rgbtRed + ne.rgbtRed + nn.rgbtRed + nw.rgbtRed + ww.rgbtRed) / 6.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + ee.rgbtGreen + ne.rgbtGreen + nn.rgbtGreen + nw.rgbtGreen + ww.rgbtGreen) / 6.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + ee.rgbtBlue + ne.rgbtBlue + nn.rgbtBlue + nw.rgbtBlue + ww.rgbtBlue) / 6.0);
                 }
             }
             else if (h == max_h){
                 if (w == 0){
                     ss = original_image[h-1][w];
                     sw = original_image[h-1][w+1];
                     ww = original_image[h][w+1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + nn.rgbtRed + ne.rgbtRed + ee.rgbtRed) / 4.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + nn.rgbtGreen + ne.rgbtGreen + ee.rgbtGreen) / 4.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + nn.rgbtBlue + ne.rgbtBlue + ee.rgbtBlue) / 4.0);
                 }
                 else if (w == max_w){
                     ee = original_image[h][w-1];
                     se = original_image[h-1][w-1];
                     ss = original_image[h-1][w];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + ww.rgbtRed + nw.rgbtRed + nn.rgbtRed) / 4.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + ww.rgbtGreen + nw.rgbtGreen + nn.rgbtGreen) / 4.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + ww.rgbtBlue + nw.rgbtBlue + nn.rgbtBlue) / 4.0);
                 }
                 else {
                     ee = original_image[h][w-1];
                     se = original_image[h-1][w-1];
                     ss = original_image[h-1][w];
                     sw = original_image[h-1][w+1];
                     ww = original_image[h][w+1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + ee.rgbtRed + ne.rgbtRed + nn.rgbtRed + nw.rgbtRed + ww.rgbtRed) / 6.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + ee.rgbtGreen + ne.rgbtGreen + nn.rgbtGreen + nw.rgbtGreen + ww.rgbtGreen) / 6.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + ee.rgbtBlue + ne.rgbtBlue + nn.rgbtBlue + nw.rgbtBlue + ww.rgbtBlue) / 6.0);
                 }

             }
             else {
                 if (w == 0){
                     nn = original_image[h+1][w];
                     nw = original_image[h+1][w+1];
                     ss = original_image[h-1][w];
                     sw = original_image[h-1][w+1];
                     ww = original_image[h][w+1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + nn.rgbtRed + ne.rgbtRed + ss.rgbtRed + se.rgbtRed + ee.rgbtRed) / 6.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + nn.rgbtGreen + ne.rgbtGreen + ss.rgbtGreen + se.rgbtGreen + ee.rgbtGreen) / 6.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + nn.rgbtBlue + ne.rgbtBlue + ss.rgbtBlue + se.rgbtBlue + ee.rgbtBlue) / 6.0);
                 }
                 else if (w == max_w){
                     ss = original_image[h-1][w];
                     se = original_image[h-1][w-1];
                     ee = original_image[h][w-1];
                     ne = original_image[h+1][w-1];
                     nn = original_image[h+1][w];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + ss.rgbtRed + se.rgbtRed + ee.rgbtRed + ne.rgbtRed + nn.rgbtRed) / 6.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + ss.rgbtGreen + se.rgbtGreen + ee.rgbtGreen + ne.rgbtGreen + nn.rgbtGreen) / 6.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + ss.rgbtBlue + se.rgbtBlue + ee.rgbtBlue + ne.rgbtBlue + nn.rgbtBlue) / 6.0);
                 }
                 else {
                     ee = original_image[h][w-1];
                     se = original_image[h-1][w-1];
                     ss = original_image[h-1][w];
                     sw = original_image[h-1][w+1];
                     ww = original_image[h][w+1];
                     nn = original_image[h+1][w];
                     nw = original_image[h+1][w+1];
                     ne = original_image[h+1][w-1];
                     image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + nn.rgbtRed + nw.rgbtRed + ss.rgbtRed + sw.rgbtRed + ww.rgbtRed + se.rgbtRed + ee.rgbtRed + ne.rgbtRed) / 9.0);
                     image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + nn.rgbtGreen + nw.rgbtGreen + ss.rgbtGreen + sw.rgbtGreen + ww.rgbtGreen + se.rgbtGreen + ee.rgbtGreen + ne.rgbtGreen) / 9.0);
                     image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + nn.rgbtBlue + nw.rgbtBlue + ss.rgbtBlue + sw.rgbtBlue + ww.rgbtBlue + se.rgbtBlue + ee.rgbtBlue + ne.rgbtBlue) / 9.0);
                 }
             }
        }
    }
    return;
}
