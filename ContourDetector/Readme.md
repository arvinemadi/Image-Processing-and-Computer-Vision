Input image is a gray scale image with high level of salt and pepper noise.

<img src="media/image_salt_and_pepper.png" width="450" height="320" />

There are many techniques for removal of salt and pepper noise such as median filters, bilateral filter, and more advanced techniques based on adaptive edge detection and deep learning. For this particular image median filter with a kernel size of 3x3 just worked fine.

Image after applying median blur:
<img src="media/denoised_image.PNG" width="450" height="320" />
