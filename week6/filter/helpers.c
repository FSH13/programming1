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
            image[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3.0);
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
    RGBTRIPLE temp;

    // loop over each pixel and swap with the opposing pixel the loop stops if we reach the middle
    for (int h = 0; h < height; h++){
        int rw = width-1;
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
    // create a copy of the image to retain the original pixels
    int max_h = height - 1, max_w = width - 1;
    RGBTRIPLE original_image[height][width];
    for (int cr = 0; cr <= max_h; cr++){
        for (int cw = 0; cw <= max_w; cw++){
            original_image[cr][cw] = image[cr][cw];
        }
    }

    // loop over each pixel
    for (int h = 0; h < height; h++){
	for (int w = 0; w < width; w++){
		// height is  0 aka bottom of the image
		if (h == 0){
			if (w == 0){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w+1].rgbtRed + original_image[h][w+1].rgbtRed)/4.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w+1].rgbtGreen + original_image[h][w+1].rgbtGreen)/4.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[+1][w+1].rgbtBlue + original_image[h][w+1].rgbtBlue) / 4.0);
			}
			else if (w == width-1){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w-1].rgbtRed + original_image[h][w-1].rgbtRed) / 4.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w-1].rgbtGreen + original_image[h][w-1].rgbtGreen) / 4.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[h+1][w-1].rgbtBlue + original_image[h][w-1].rgbtBlue) / 4.0);
			}
			else {
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h][w+1].rgbtRed + original_image[h+1][w+1].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w-1].rgbtRed + original_image[h][w-1].rgbtRed) / 6.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h][w+1].rgbtGreen + original_image[h+1][w+1].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w-1].rgbtGreen + original_image[h][w-1].rgbtGreen) / 6.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h][w+1].rgbtBlue + original_image[h+1][w+1].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[h+1][w-1].rgbtBlue + original_image[h][w-1].rgbtBlue) / 6.0);
			}
		}

		// max height aka top of the image
		else if (h == height-1){
			if (w == 0){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h][w+1].rgbtRed + original_image[h-1][w+1].rgbtRed + original_image[h-1][w].rgbtRed)/4.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h][w+1].rgbtGreen + original_image[h-1][w+1].rgbtGreen + original_image[h-1][w].rgbtGreen)/4.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h][w+1].rgbtBlue + original_image[h-1][w+1].rgbtBlue + original_image[h-1][w].rgbtBlue) / 4.0);
			}
			else if (w == width-1){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h][w-1].rgbtRed + original_image[h-1][w-1].rgbtRed + original_image[h][w-1].rgbtRed)/4.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h][w-1].rgbtGreen + original_image[h-1][w-1].rgbtGreen + original_image[h][w-1].rgbtGreen)/4.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h][w-1].rgbtBlue + original_image[h-1][w-1].rgbtBlue + original_image[h][w-1].rgbtBlue) / 4.0);
			}
			else {
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h][w+1].rgbtRed + original_image[h-1][w+1].rgbtRed + original_image[h-1][w].rgbtRed + original_image[h-1][w-1].rgbtRed + original_image[h][w-1].rgbtRed) / 6.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h][w+1].rgbtGreen + original_image[h-1][w+1].rgbtGreen + original_image[h-1][w].rgbtGreen + original_image[h-1][w-1].rgbtGreen + original_image[h][w-1].rgbtGreen) / 6.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h][w+1].rgbtBlue + original_image[h-1][w+1].rgbtBlue + original_image[h-1][w].rgbtBlue + original_image[h-1][w-1].rgbtBlue + original_image[h][w-1].rgbtBlue) / 6.0);
			}
		}
		// Height is neither 0 nor max
		else {
			if (w == 0){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w+1].rgbtRed + original_image[h][w+1].rgbtRed + original_image[h-1][w+1].rgbtRed + original_image[h-1][w].rgbtRed)/6.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w+1].rgbtGreen + original_image[h][w+1].rgbtGreen + original_image[h-1][w+1].rgbtGreen + original_image[h-1][w].rgbtGreen)/ 6.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[h+1][w+1].rgbtBlue + original_image[h][w+1].rgbtBlue + original_image[h-1][w+1].rgbtBlue + original_image[h-1][w].rgbtBlue)/ 6.0);
			}
			else if (w == width-1){
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w-1].rgbtRed + original_image[h][w-1].rgbtRed + original_image[h-1][w-1].rgbtRed + original_image[h-1][w].rgbtRed) / 6.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w-1].rgbtGreen + original_image[h][w-1].rgbtGreen + original_image[h-1][w-1].rgbtGreen + original_image[h-1][w].rgbtGreen) / 6.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[h+1][w-1].rgbtBlue + original_image[h][w-1].rgbtBlue + original_image[h-1][w-1].rgbtBlue + original_image[h-1][w].rgbtBlue) / 6.0);
			}
			else {
				image[h][w].rgbtRed = round((original_image[h][w].rgbtRed + original_image[h][w-1].rgbtRed + original_image[h-1][w-1].rgbtRed + original_image[h-1][w].rgbtRed + original_image[h-1][w+1].rgbtRed + original_image[h][w+1].rgbtRed + original_image[h+1][w+1].rgbtRed + original_image[h+1][w].rgbtRed + original_image[h+1][w-1].rgbtRed) / 9.0);
				image[h][w].rgbtGreen = round((original_image[h][w].rgbtGreen + original_image[h][w-1].rgbtGreen + original_image[h-1][w-1].rgbtGreen + original_image[h-1][w].rgbtGreen + original_image[h-1][w+1].rgbtGreen + original_image[h][w+1].rgbtGreen + original_image[h+1][w+1].rgbtGreen + original_image[h+1][w].rgbtGreen + original_image[h+1][w-1].rgbtGreen) / 9.0);
				image[h][w].rgbtBlue = round((original_image[h][w].rgbtBlue + original_image[h][w-1].rgbtBlue + original_image[h-1][w-1].rgbtBlue + original_image[h-1][w].rgbtBlue + original_image[h-1][w+1].rgbtBlue + original_image[h][w+1].rgbtBlue + original_image[h+1][w+1].rgbtBlue + original_image[h+1][w].rgbtBlue + original_image[h+1][w-1].rgbtBlue) / 9.0);
			}
		}
	}
    }
    return;
}
