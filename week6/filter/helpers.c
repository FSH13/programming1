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
  RGBTRIPLE temp_image[height][width];

  // loop over each row and column (pixel)
  for (int h = 0; h < height; h++){
    for (int w = 0; w < width; w++){
      int c_red = 0;
      int c_green = 0;
      int c_blue = 0;
      float count = 0.0;

      // Loop over the row below and above and column to the sides of the pixel
      // within the borders of the image
      for (int i = h - 1; i <= h + 1; i++){
        for (int j = w - 1; j <= w + 1; j++){

          // Add up the total RGBvalue of the surrounding and original pixel
          if (i >= 0 && i < height && j >= 0 && j < width){
               c_red = c_red + image[i][j].rgbtRed;
               c_green = c_green + image[i][j].rgbtGreen;
               c_blue = c_blue + image[i][j].rgbtBlue;
               count++;
          }
        }
      }

    // add the new blurred value to the temporary image location
      temp_image[h][w].rgbtRed = round(c_red / count);
      temp_image[h][w].rgbtGreen = round(c_green / count);
      temp_image[h][w].rgbtBlue = round(c_blue / count);
    }
  }

  // copy the values from the temp image to the original
  for (int h = 0; h < height; h++){
    for (int w = 0; w < width; w++){
      image[h][w].rgbtRed = temp_image[h][w].rgbtRed;
      image[h][w].rgbtGreen = temp_image[h][w].rgbtGreen;
      image[h][w].rgbtBlue = temp_image[h][w].rgbtBlue;
    }
  }
  return;
}
