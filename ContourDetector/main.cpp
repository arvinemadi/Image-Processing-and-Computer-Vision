#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "ContourDetector.cpp"
#include <unordered_map>

using namespace std;


int main(int argc, char** argv)
{
    namedWindow("Noisy Image", cv::WINDOW_AUTOSIZE);
    namedWindow("Median Image", cv::WINDOW_AUTOSIZE);
    namedWindow("Edges", cv::WINDOW_AUTOSIZE);
    namedWindow("Contours", cv::WINDOW_AUTOSIZE);
    namedWindow("Contours ROI", cv::WINDOW_AUTOSIZE);

    //Read the image given by args
    cv::Mat original_source = cv::imread(argv[1]);

    //Transform to Gray
    cv::cvtColor(original_source, original_source, cv::COLOR_BGR2GRAY);

    //Output basic dimensional information about the image
    cout << "Image Height: " << original_source.size().height << " Image Width: " << original_source.size().width << endl;

    //Initialize contour finder
    ContourFinder contourFinder(original_source);
    cv::imshow("Noisy Image", contourFinder.image);


    //Apply Median Filtering with a kernel size of 3x3, then save the image
    cv::Mat filtered_image = contourFinder.applyMedianFiltering(3);
    contourFinder.updateImage(filtered_image);
    cv::imshow("Median Image", contourFinder.image);
    cout << "Saving the denoised image" << endl;
    cv::imwrite("denoised_image.PNG", contourFinder.image);

    //Detect Edges with no hierachy and then save an image that shows the detected edges
    contourFinder.detectEdges(250, 700, 3, 7, 1);
    cv::imshow("Edges", contourFinder.edges);
    cout << "Saving the detected edges" << endl;
    cv::imwrite("detected_edges.PNG", contourFinder.edges);


    //Find the first layer contours - no image is saved at this stage
    contourFinder.findContours();
    cv::imshow("Contours", contourFinder.contourImage);

    //Crop the image based on the first contour
    contourFinder.setROI(100, 500, 80, 320);

    //Find new edges
    contourFinder.detectEdges(250, 700, 3, 7, 1);

    //Find new contours - and save the contour image
    contourFinder.findContours();
    cv::imshow("Contours ROI", contourFinder.contourImage);
    cout << "Saving the contours image" << endl;
    cv::imwrite("contours_image.PNG", contourFinder.contourImage);


    //wait for a key to close
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
