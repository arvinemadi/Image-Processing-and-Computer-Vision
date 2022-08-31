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
