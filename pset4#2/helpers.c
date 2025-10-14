#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through each row
    for (int x = 0; x < height; x++)
    {
        // loop through each column
        for (int y = 0; y < width; y++)
        {
            // calculating avg.intensity of the pixel (obtaining floating-point result)
            float avg_intensity = (image[x][y].rgbtRed + image[x][y].rgbtBlue + image[x][y].rgbtGreen) / 3.0;
            int average = round(avg_intensity);

            // Setting value of RGB to average pixel value
            image[x][y].rgbtRed = average;
            image[x][y].rgbtBlue = average;
            image[x][y].rgbtGreen = average;
        }
    }
}

// Helper function - returns the lesser of two integers
int find_minimum(int a, int b)
{
    return (a < b) ? a : b;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            // Calculate new values using given algorithm
            int sepiaRed = round(0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
            int sepiaGreen = round(0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
            int sepiaBlue = round(0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);


            image[x][y].rgbtRed = find_minimum(sepiaRed, 255); // find_minimum <-- calling the function on top
            image[x][y].rgbtGreen = find_minimum(sepiaGreen, 255);
            image[x][y].rgbtBlue = find_minimum(sepiaBlue, 255);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < (width / 2); y++) //Because we only need to exchange the pixels until we reach the midpoint of each row.
        {
            RGBTRIPLE temp_variable = image[x][y];
            image[x][y] = image[x][width - y - 1]; // to avoid segmentation fault
            image[x][width - y - 1] = temp_variable;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE imageCopy[height][width];

    // Copy pixel values from image to copy
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            imageCopy[x][y] = image[x][y];
        }
    }

    // Implementing box blur to each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            float count = 0;

            // Iterate over the surrounding pixels in a 3x3 box
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int column = j + l;

                    // Check if the surrounding pixel is within the image bounds
                    if (row >= 0 && row < height && column >= 0 && column < width)
                    {
                        sumRed += imageCopy[row][column].rgbtRed;
                        sumGreen += imageCopy[row][column].rgbtGreen;
                        sumBlue += imageCopy[row][column].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average values and assign them to the original image
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }
}
