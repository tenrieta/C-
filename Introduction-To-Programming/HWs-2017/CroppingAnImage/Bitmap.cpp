
#include "Bitmap.h"

#include <iostream>


unsigned int* resizeImage(unsigned int* image, unsigned int& width, unsigned int& height,unsigned int* image2, unsigned int& len)
{
    unsigned long cntWhite = 0;
    unsigned long balanceLeft = 0, balanceRight = 0, balanceTop = 0, balanceBottom = 0;
    bool flag = true;
    unsigned int s;
    unsigned int nW=width;
    unsigned int nH = height;
    for(int i=0; i<height; i++)
    {
        s = i*width;
        for(int j=s; j<s+width; j++)
        {
            if(image[j] == 0xFFFFFFFF)
            {
                cntWhite++;
            }
        }
        if(flag == true)
        {
            if(cntWhite == width)
            {
                balanceTop++;
            }
            else
            {
                flag = false;
            }
        }
        else
        {
            if(cntWhite == width)
            {
                balanceBottom++;
            }
        }
        cntWhite = 0;
    }
    flag = true;
    for(int i=0; i<width; i++)
    {
        for(int j=i; j<width*height; j++)
        {
            if(image[j] == 0xFFFFFFFF)
            {
                cntWhite++;
            }
            j += width-1;
        }
        if(flag == true)
        {
            if(cntWhite == height)
            {
                balanceLeft++;
            }
            else
            {
                flag = false;
            }
        }
        else
        {
            if(cntWhite == height)
            {
                balanceRight++;
            }
        }
        cntWhite = 0;
    }
    unsigned int newWidth = width - (balanceLeft + balanceRight);
    unsigned int newHeight = height - (balanceTop + balanceBottom);
    unsigned int* newImage = new unsigned int[len];
    unsigned long k, p;
    unsigned int idx = 0;
    bool flag2 = false;
    for(unsigned long i=balanceTop; i<height-balanceBottom; i++)
    {
        k = (i*width) + balanceLeft;
        p = k +(width-balanceRight-balanceLeft);
        for(unsigned long j=k; j<p; j++)
        {
            newImage[idx] = image[j];
            idx++;
        }
    }
    len = idx;
    width = newWidth;
    height = newHeight;
    int rval = SaveBitmap("test_new.bmp", newImage, width, height);
return image2;
}

int main()
{
	const size_t MAX_SIZE = 100000; // You can change the size of the image depending on the image you are working with.

	unsigned int width, height, image[MAX_SIZE];

	int rval;

	// In the last three parameters the function returns the image and its size

	rval = LoadBitmap("test.bmp", image, MAX_SIZE, width, height);

	if (rval != ALL_OK)
	{
		std::cerr << "Cannot load image data from test.bmp! Error code " << rval << "\n";
		return 1;
	}
    //std::cout<<width<<" "<<height<<std::endl;

	// Below the result of the process is written to the array-image
	// and the width and height are changed the way that they will include the size of the cropped image

    unsigned int len = width*height;
	unsigned int *newImage = new unsigned int[len];
    resizeImage(image, width, height, newImage,len);
    unsigned int* tmp = new unsigned int[len];

	if (rval != ALL_OK)
	{
		std::cerr << "Cannot save image data to test_new.bmp! Error code " << rval << "\n";
		return 2;
	}

    return 0;
}
