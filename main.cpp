#include <opencv2/opencv.hpp>



int main(int argc, char *argv[])
{
    std::string fileName;

    //check for additional argument
    if (argc == 1) {
        //if not given try to read the default image
        fileName = "Spielsteine.png";
    } else if (argc == 2) {
        //read given image
        fileName = argv[1];
    }

    //cv::Mat is the class for handling images in opencv 
    cv::Mat in = cv::imread(fileName, CV_LOAD_IMAGE_GRAYSCALE);
    //check whether image could be read
    if (in.rows*in.cols <= 0) {
        std::cout << "Image " << fileName << " is empty or cannot be found\n";
        return(0);
    }
    
    //copy in image to out image
    cv::Mat out = in.clone();
    
    //save image
    cv::imwrite("result.png", out);
    
    //show the images
    cv::imshow("orig", in);
    cv::imshow("result", out);
    
    bool go = true;
    while(go) {
        char c = (char) cv::waitKey(1);
        switch(c) {
            case 'q':
            case 'Q':
                go = false;
                break;
        }        
    }
    
    return(0);
}
