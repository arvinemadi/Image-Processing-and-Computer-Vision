
#ifndef FILTERING
#define FILTERING

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <unordered_map>
#include <time.h>

using namespace std;

class ContourFinder
{
public:
	cv::Mat image;
	cv::Mat imageROI;
	cv::Mat median_Filtered_image;
	cv::Mat edges;
	cv::Mat contourImage;
	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> hierachy;
	int ROI_x_min, ROI_x_max, ROI_y_min, ROI_y_max;

	//constructor initialized the image for processing
	ContourFinder(cv::Mat inputImage_)
	{
		image = inputImage_;
		imageROI = image;
		ROI_x_min = 0;
		ROI_y_min = 0;
		ROI_x_max = image.size().width;
		ROI_y_max = image.size().height;

		//make result contour image color so that colorful contours can be shown
		contourImage = image;
		cv::cvtColor(contourImage, contourImage, cv::COLOR_GRAY2RGB);
	}

	//Function to set the ROI
	void setROI(int x_min, int x_max, int y_min, int y_max)
	{
		ROI_x_min = max(0, x_min);
		ROI_y_min = max(0, y_min);
		ROI_x_max = min(image.size().width, x_max);
		ROI_y_max = min(image.size().height, y_max);

		imageROI = image(cv::Range(y_min, y_max), cv::Range(x_min, x_max));
	}

	//Method to do median Filtering to the Image
	cv::Mat applyMedianFiltering(int kernel_size)
	{
		cv::Mat medianFilteredImage;
		cv::medianBlur(image, medianFilteredImage, kernel_size);
		return medianFilteredImage;
	}

	//Method to update the image - e.g. when the filtering is accepted by user filtered image is set
	void updateImage(cv::Mat updatedImage)
	{
		image = updatedImage;
		contourImage = image;
		cv::cvtColor(contourImage, contourImage, cv::COLOR_GRAY2RGB);
		setROI(ROI_x_min, ROI_x_max, ROI_y_min, ROI_y_max);
	}

	//Detected the edges using Canny algorithm: https://docs.opencv.org/4.x/da/d22/tutorial_py_canny.html
	//Then dilate the edges: https://docs.opencv.org/3.4/db/df6/tutorial_erosion_dilatation.html
	//Dilation is need to have consistent edges covering the entire objects (instead of incomplete broken pieces) This help later in finding the hierachy of contours
	//Parameters define the thresholds for the cannry algorithm, and also level of dilation of the resulting edges
	void detectEdges(int canny_threshold1, int canny_threshold2, int aperture_size, int dilation_kernel_size = 0, int dilation_iterations = 0)
	{
		cv::Canny(imageROI, edges, canny_threshold1, canny_threshold2, aperture_size);

		if (dilation_iterations > 0 && dilation_kernel_size > 0)
		{
			cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilation_kernel_size, dilation_kernel_size));
			cv::dilate(edges, edges, kernel, cv::Point(-1, -1), 1);
		}
	}

	//Using the find contour method: https://docs.opencv.org/3.4/d3/dc0/group__imgproc__shape.html#ga17ed9f5d79ae97bd4c7cf18403e1689a
	//First find the contours
	//Then do a DFS based on hierachy found and draw the contour with a new color based on the level of contour on the filtered image
	//The contours at each level will have different colors
	void findContours()
	{
		cv::findContours(edges, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

		unordered_map<int, bool> drawn;

		// Perform a DFS on the contours and each level change color
		for (int index = 0; index < contours.size(); index++)
		{
			if (drawn.find(index) != drawn.end())
			{
				continue;
			}

			//Create new color for this level of contours
			int red = getRandom(0, 255);
			int green = getRandom(0, 255);
			int blue = getRandom(0, 255);
			cv::Scalar color = cv::Scalar(red, green, blue);

			int contour = index;
			while (contour != -1)
			{
				cv::drawContours(contourImage, contours, contour, color, 3, cv::LINE_8, hierachy, 0, cv::Point(ROI_x_min, ROI_y_min));
				contour = hierachy[contour][0];
				drawn[contour] = true;
			}
		}
	}

	//Generate a psuedo random number for each level of contours
	int getRandom(int range_start, int range_end)
	{
		int random_number = range_start + (rand() % (range_end - range_start + 1));
		return random_number;
	}

};


#endif
