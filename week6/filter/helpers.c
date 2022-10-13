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
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){
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
        rw = width;
        for (int w = 0; w < rw; w++){
            temp = image[h][w];
            image[h][w] = image[h][rw];
            image[h][rw] = temp;
            rw--;
            printf("h: %i, w: %i, rw: %i, Height: %i, Width: %i\n", h, w, rw, height, width);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create rgbtriples for the surrounding pixels
    RGBTRIPLE ne, nn, nw, ww, ee, se, ss, sw;
    // loop over each pixel
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){
             // take the average of the surrounding pixels depending on the location of the pixel
             // if it's in a corner of around the edge, there are less surrounding pixels
             if (h == 0){
                 if (w == 0){
                     ee = image[h][w+1];
                     ss = image[h+1][w];
                     se = image[h+1][w+1];
                     image[h][w].rgbtRed = round((ee.rgbtRed + ss.rgbtRed + se.rgbtRed) / 3);
                     image[h][w].rgbtGreen = round((ee.rgbtGreen + ss.rgbtGreen + se.rgbtGreen) / 3);
                     image[h][w].rgbtBlue = round((ee.rgbtBlue + ss.rgbtBlue + se.rgbtBlue) / 3);
                 }
                 else if (w == width){
                     sw = image[h+1][w-1];
                     ww = image[h][w-1];
                     ss = image[h+1][w];
                     image[h][w].rgbtRed = round((sw.rgbtRed + ss.rgbtRed + ww.rgbtRed) / 3);
                     image[h][w].rgbtGreen = round((sw.rgbtGreen + ss.rgbtGreen + ww.rgbtGreen) / 3);
                     image[h][w].rgbtBlue = round((sw.rgbtBlue + ss.rgbtBlue + ww.rgbtBlue) / 3);
                 }
                 else {
                     ee = image[h][w+1];
                     se = image[h+1][w+1];
                     ss = image[h+1][w];
                     sw = image[h+1][w-1];
                     ww = image[h][w-1];
                     image[h][w].rgbtRed = round((ee.rgbtRed + se.rgbtRed + ss.rgbtRed + sw.rgbtRed + ww.rgbtRed) / 5);
                     image[h][w].rgbtGreen = round((ee.rgbtGreen + se.rgbtGreen + ss.rgbtGreen + sw.rgbtGreen + ww.rgbtGreen) / 5);
                     image[h][w].rgbtBlue = round((ee.rgbtBlue + se.rgbtBlue + ss.rgbtBlue + sw.rgbtBlue + ww.rgbtBlue) / 5);
                 }
             }
             else if (h == height){
                 if (w == 0){
                     nn = image[h-1][w];
                     ne = image[h-1][w+1];
                     ee = image[h][w+1];
                     image[h][w].rgbtRed = round((nn.rgbtRed + ne.rgbtRed + ee.rgbtRed) / 2);
                     image[h][w].rgbtGreen = round((nn.rgbtGreen + ne.rgbtGreen + ee.rgbtGreen) / 3);
                     image[h][w].rgbtBlue = round((nn.rgbtBlue + ne.rgbtBlue + ee.rgbtBlue) / 3);
                 }
                 else if (w == width){
                     ww = image[h][w-1];
                     nw = image[h-1][w-1];
                     nn = image[h-1][w];
                     image[h][w].rgbtRed = round((ww.rgbtRed + nw.rgbtRed + nn.rgbtRed) / 3);
                     image[h][w].rgbtGreen = round((ww.rgbtGreen + nw.rgbtGreen + nn.rgbtGreen) / 3);
                     image[h][w].rgbtBlue = round((ww.rgbtBlue + nw.rgbtBlue + nn.rgbtBlue) / 3);
                 }
                 else {
                     ee = image[h][w+1];
                     ne = image[h-1][w+1];
                     nn = image[h-1][w];
                     nw = image[h-1][w-1];
                     ww = image[h][w-1];
                     image[h][w].rgbtRed = round((ee.rgbtRed + ne.rgbtRed + nn.rgbtRed + nw.rgbtRed + ww.rgbtRed) / 5);
                     image[h][w].rgbtGreen = round((ee.rgbtGreen + ne.rgbtGreen + nn.rgbtGreen + nw.rgbtGreen + ww.rgbtGreen) / 5);
                     image[h][w].rgbtBlue = round((ee.rgbtBlue + ne.rgbtBlue + nn.rgbtBlue + nw.rgbtBlue + ww.rgbtBlue) / 5);
                 }

             }
             else {
                 if (w == 0){
                     nn = image[h-1][w];
                     ne = image[h-1][w+1];
                     ss = image[h+1][w];
                     se = image[h+1][w+1];
                     ee = image[h][w+1];
                     image[h][w].rgbtRed = round((nn.rgbtRed + ne.rgbtRed + ss.rgbtRed + se.rgbtRed + ee.rgbtRed) / 5);
                     image[h][w].rgbtGreen = round((nn.rgbtGreen + ne.rgbtGreen + ss.rgbtGreen + se.rgbtGreen + ee.rgbtGreen) / 5);
                     image[h][w].rgbtBlue = round((nn.rgbtBlue + ne.rgbtBlue + ss.rgbtBlue + se.rgbtBlue + ee.rgbtBlue) / 5);
                 }
                 else if (w == width){
                     sw = image[h+1][w-1];
                     ww = image[h][w-1];
                     ss = image[h+1][w];
                     image[h][w].rgbtRed = round((sw.rgbtRed + ss.rgbtRed + ww.rgbtRed) / 3);
                     image[h][w].rgbtGreen = round((sw.rgbtGreen + ss.rgbtGreen + ww.rgbtGreen) / 3);
                     image[h][w].rgbtBlue = round((sw.rgbtBlue + ss.rgbtBlue + ww.rgbtBlue) / 3);
                 }
                 else {
                     ee = image[h][w+1];
                     se = image[h+1][w+1];
                     ss = image[h+1][w];
                     sw = image[h+1][w-1];
                     ww = image[h][w-1];
                     nn = image[h-1][w];
                     nw = image[h-1][w-1];
                     image[h][w].rgbtRed = round((nn.rgbtRed + nw.rgbtRed + ss.rgbtRed + sw.rgbtRed + ww.rgbtRed + se.rgbtRed + ee.rgbtRed + ne.rgbtRed) / 8);
                     image[h][w].rgbtGreen = round((nn.rgbtGreen + nw.rgbtGreen + ss.rgbtGreen + sw.rgbtGreen + ww.rgbtGreen + se.rgbtGreen + ee.rgbtGreen + ne.rgbtGreen) / 8);
                     image[h][w].rgbtBlue = round((nn.rgbtBlue + nw.rgbtBlue + ss.rgbtBlue + sw.rgbtBlue + ww.rgbtBlue + se.rgbtBlue + ee.rgbtBlue + ne.rgbtBlue) / 8);

                 }
             }
        }
    }
    return;
}
