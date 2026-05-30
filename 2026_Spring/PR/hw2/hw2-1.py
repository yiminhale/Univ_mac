#2022110327 이민석
#scikit learn, numpy, matplotlib
### doc 명세
"""
Customized from Arthur Mensch's implementation of
MNIST classification with L1 sparse logistic classification.
source: https://scikit-learn.org/stable/auto_examples/linear_model/plot_sparse_logistic_regression_mnist.html
"""
###
import time
import random
import matplotlib.pyplot as plt
import numpy as np

from sklearn.datasets import fetch_openml
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.utils import check_random_state
### 과제 위해 필요함
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
### 과제 명시
random.seed(a=0,version=2)
np.random.seed(seed=0)
###
#t0 = time.time()
train_samples = 5000

# Load data from https://www.openml.org/d/554
X, y = fetch_openml("mnist_784", version=1, return_X_y=True, as_frame=False)

random_state = check_random_state(0)## 코드에 원래 들어있는 sklearn seed
permutation = random_state.permutation(X.shape[0])
X = X[permutation]
y = y[permutation]
X = X.reshape((X.shape[0], -1))
###
X_train, X_test, y_train, y_test = train_test_split(
    X, y, train_size=train_samples, test_size=10000, random_state=0
)
###
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
###
print("================================================================")
print("MNIST classification using KNN, Gaussian Naive Bayes , SVM")
print("================================================================")
print(__doc__)
print("----------------------------------------------------------------")
print(f"X_train and y_train shapes = {X_train.shape} {y_train.shape}")
print(f"X_test and y_test shapes = {X_test.shape} {y_test.shape}")
print("----------------------------------------------------------------")
### 1. GNB
t0 = time.time()
clf = GaussianNB()
clf.fit(X_train, y_train)

score = clf.score(X_test,y_test)
print("Test score with Gaussian Naive Bayes: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
### 2. knn k=5
t0 = time.time()
clf = KNeighborsClassifier(n_neighbors=5)
clf.fit(X_train, y_train)

score = clf.score(X_test,y_test)
print("Test score with k-nearest neighbors(5): %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
### 3. linear SVM C=1
t0 = time.time()
clf = SVC(kernel='linear',C=1)
clf.fit(X_train, y_train)

score = clf.score(X_test,y_test)
print("Test score with Linear SVM C=1: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
### 4. RBF SVM C=1, gamma=0.01
t0 = time.time()
clf = SVC(kernel='rbf',C=1,gamma=0.01)
clf.fit(X_train, y_train)

score = clf.score(X_test,y_test)
print("Test score with RBF SVM C=1 gamma=0.01: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )