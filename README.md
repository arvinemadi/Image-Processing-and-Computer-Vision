## Image Processing and Computer Vision

### Hand Gesture Detector
Data from Kaggle: [https://www.kaggle.com/datasets/datamunge/sign-language-mnist](https://www.kaggle.com/datasets/datamunge/sign-language-mnist)

Simple CNN using Keras Functional API.

### Happy Detector
Data from Kaggle: [[https://www.kaggle.com/datasets/datamunge/sign-language-mnist]](https://www.kaggle.com/datasets/iarunava/happy-house-dataset?resource=download)

Simple CNN using Keras Sequential API.

### Alpaca Detector
Data from Kaggle: https://www.kaggle.com/datasets/sid4sal/alpaca-dataset-small

Transfer learning using MobileNetV2 to make a Alpaca Detector. Keras Functional API. 

### Unsupervised Image Processing with K-means
K-means is applied for two applications:
- Image classification
- Labeling an unlabeled dataset
The limitations and applications are discussed.

### Image classification using pytorch
Example of image classification using pytorch. The notebook also uses sklearn to visualize the metric of ROC curve and confusion matrix.

### Transfer learning using ResNet18 for CIFAR10 dataset:
[CIFAR10](https://www.cs.toronto.edu/~kriz/cifar.html) dataset is a dataset of 60,000 images in 10 classes.
This notebook makes an image classifier using transfer learning on [ResNet18](https://www.sciencedirect.com/topics/computer-science/residual-network#:~:text=ResNet18%20is%20a%2072%2Dlayer,a%20degradation%20of%20the%20output.) pre-trained weights that are available for download from [torchvision.models](https://pytorch.org/vision/stable/models.html)

## Image classification for unbalanced datasets
I am working on a medical imaging projects that has highly unbalanced dataset. To test some first ideas and creating a pipeline for evaluating the results I am doing this exercise to transform MNIST data into a binary classification problem by choosing only one of the digits.
As the first idea, Linear SVM and Random Forrest on tried and compared on this unbalanced dataset.

## Dog breed detector
This is an end-to-end example of doing deep learning image classification on AWS.

A pre-trained DNN model (ResNet18) is loaded. Hyper-parameter tuning is done. Next, the model is trained using the best hyper-parameters. For the training job, debugger and profilers are created to monitor the performance. During the model development these been used to debug and fix the issues.

After the model with satisfactory performance is trained, the model is deployed to an endpoint. As shown in previous examples, model monitors like DataCapture can be created to monitor the model during the inference, but those were skipped here.

The deployed model is tested by sending some dog images that were not seen during the training and output is visualized.

The notebook shows the steps for this script mode training, and the script codes are in the folder "Dog Breed Detector"

Reference from AWS on CIFAR10 dataset: [Extend a pre-built container](https://docs.aws.amazon.com/sagemaker/latest/dg/prebuilt-containers-extend.html)
