#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Prototype
void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

  // Iterate over each row
  for (int i = 0; i < height; i++)
    {
      // Iterate over each pixel in row
      for (int j = 0; j < width; j++)
	{
	  // Calculate average value from pixel RGB values
	  int average = round(((double) image[i][j].rgbtRed + (double) image[i][j].rgbtGreen + (double) image[i][j].rgbtBlue) / 3);
	  
	  // Set the original RGB values to greyscale value
	  image[i][j].rgbtBlue = average;
	  image[i][j].rgbtGreen = average;
	  image[i][j].rgbtRed = average;
	}
    }
  // Success
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  
  BYTE originalRed;
  BYTE originalBlue;
  BYTE originalGreen;
	  
  int sepiaRed;
  int sepiaGreen;
  int sepiaBlue;

  // Iterate over each row
  for (int i = 0; i < height; i++)
    {
      // Iterate over each pixel in row
      for (int j = 0; j < width; j++)
	{
	  // Calculate the sepia RGB values for this pixel
	  sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
			   .189 * image[i][j].rgbtBlue);
	  sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
			     .168 * image[i][j].rgbtBlue);
	  sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
			    .131 * image[i][j].rgbtBlue);
	  
	  // If sepia value is greater than 255, return 255
	  // image[i][j].rgbtRed = fmin(255, sepiaRed);
	  // image[i][j].rgbtGreen = fmin(255, sepiaGreen);
	  // image[i][j].rgbtBlue = fmin(255, sepiaBlue);

	  // Red
	  if (sepiaRed > 255)
	    {
	      image[i][j].rgbtRed = 255;
	    }
	  else
	    {
	      image[i][j].rgbtRed = sepiaRed; 
	    }
	  
	  // Blue
	  if (sepiaBlue > 255)
	    {
	      image[i][j].rgbtBlue = 255;
	    }
	  else
	    {
	      image[i][j].rgbtBlue = sepiaBlue;
	    }

	  //Green
	  if (sepiaGreen > 255)
	    {
	      image[i][j].rgbtGreen = 255;
	    }
	  else
	    {
	      image[i][j].rgbtGreen = sepiaGreen;
	    }
	}
    }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE temporary_image[height][width];

  // Put pixel values into temporary image in reversed order
  // Iterate over each row
  for (int i = 0; i < height; i++)
    {
      // Iterate over each pixel in first half of row
      for (int j = 0; j < width; j++)
	{
	  // E.g. First pixel's location becomes last pixel's location in row
	  temporary_image[i][width - j - 1] = image[i][j];
	    }
	}
  
  // Convert temporary image pixel values to original image
  // Iterate over each row
  for (int i = 0; i < height; i++)
    {
      // Iterate over each pixel
      for (int j = 0; j < width; j++)
	{
	  image[i][j] = temporary_image[i][j];
	}
    }

  // Success 
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  float count = 0.0;
  RGBTRIPLE temporary_image[height][width];
  
  // Iterate over each row
  for (int i = 0; i < height; i++)
    {
      // Iterate over each column / each pixel
      for (int j = 0; j < width; j++)
	{
	  int total_red = 0;
	  int total_blue = 0;
	  int total_green = 0;
	  count = 0.0;

	  // Get the amount and RGB values of pixels around pixel that are within boundaries of image
	  // Iterate over the row below and above pixel 
	  for (int k = i - 1; k <= i + 1; k++)
	    {
	      // Iterate over the column on left and right of pixel
	      for (int l = j - 1; l <= j + 1; l++)
		{
		  // Sum up total pixel RGB values from neighbouring pixels within borders of image 
		  if (k >= 0 && k < height && l >= 0 && l < width)
		    {
		      total_red = total_red + image[k][l].rgbtRed;
		      total_blue = total_blue + image[k][l].rgbtBlue;
		      total_green = total_green + image[k][l].rgbtGreen;

		      // Keep track of amount of valid pixels around pixel
		      count++;
		    }
		}
	    }

	    // Calculate average RGB values of surrounding pixels to define pixel RGB values
	    temporary_image[i][j].rgbtBlue = round(total_blue / count);
	    temporary_image[i][j].rgbtRed = round(total_red / count);
	    temporary_image[i][j].rgbtGreen = round(total_green / count);
	}
    }
  // Convert temporary image RGB pixel values to original image
  for (int i = 0; i < height; i++)
    {
      // Iterate over each pixel
      for (int j = 0; j < width; j++)
	{
	  image[i][j].rgbtBlue = temporary_image[i][j].rgbtBlue;
	  image[i][j].rgbtRed = temporary_image[i][j].rgbtRed;
	  image[i][j].rgbtGreen = temporary_image[i][j].rgbtGreen;
	}
    }

  // Success
  return;
}

// this function swaps values by swapping their adresses
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
  RGBTRIPLE tmp = *a;
  *a = *b;
  *b = tmp;
}
