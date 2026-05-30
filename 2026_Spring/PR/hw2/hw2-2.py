#2022110327 이민석
#scikit learn, numpy, matplotlib
###doc 명세
"""

Customized from Arthur Mensch's implementation of
MNIST classification with L1 sparse logistic classification.
sources: https://scikit-learn.org/stable/auto_examples/linear_model/plot_sparse_logistic_regression_mnist.html
    https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.PCA.html
    https://scikit-learn.org/stable/modules/generated/sklearn.discriminant_analysis.LinearDiscriminantAnalysis.html

"""
### print 일반
print("================================================================")
print("MNIST classification using KNN, Gaussian Naive Bayes, SVM with PCA and LDA transformations")
print("================================================================")
print(__doc__)
###
import time
import random
import matplotlib.pyplot as plt
import numpy as np

from sklearn.datasets import fetch_openml
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.utils import check_random_state
### 과제 위해 필요함
from sklearn.decomposition import PCA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
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

### PCA
pca = PCA(n_components=32)
X_train_pca = pca.fit_transform(X_train)
X_test_pca = pca.transform(X_test)
print("----------------------------------------------------------------")
print(f"PCA: X_train_pca and X_test_pca shapes = {X_train_pca.shape} {X_test_pca.shape}")
print("----------------------------------------------------------------")
####### GNB
t0 = time.time()
clf = GaussianNB()
clf.fit(X_train_pca, y_train)

score = clf.score(X_test_pca,y_test)
print("Test score with Gaussian Naive Bayes: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### 5-nn
t0 = time.time()
clf = KNeighborsClassifier(n_neighbors=5)
clf.fit(X_train_pca, y_train)

score = clf.score(X_test_pca,y_test)
print("Test score with k-nearest neighbors(5): %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### Lin SVM
t0 = time.time()
clf = SVC(kernel='linear',C=1)
clf.fit(X_train_pca, y_train)

score = clf.score(X_test_pca,y_test)
print("Test score with Linear SVM C=1: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### RBF SVM
t0 = time.time()
clf = SVC(kernel='rbf',C=1,gamma=0.01)
clf.fit(X_train_pca, y_train)

score = clf.score(X_test_pca,y_test)
print("Test score with RBF SVM C=1 gamma=0.01: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
### LDA
lda=LinearDiscriminantAnalysis(n_components=9)
X_train_lda=lda.fit_transform(X_train,y_train)
X_test_lda=lda.transform(X_test)
print("----------------------------------------------------------------")
print(f"LDA: X_train_lda and X_test_lda shapes = {X_train_lda.shape} {X_test_lda.shape}")
print("----------------------------------------------------------------")
####### GNB
t0 = time.time()
clf = GaussianNB()
clf.fit(X_train_lda, y_train)

score = clf.score(X_test_lda,y_test)
print("Test score with Gaussian Naive Bayes: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### 5-nn
t0 = time.time()
clf = KNeighborsClassifier(n_neighbors=5)
clf.fit(X_train_lda, y_train)

score = clf.score(X_test_lda,y_test)
print("Test score with k-nearest neighbors(5): %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### Lin SVM
t0 = time.time()
clf = SVC(kernel='linear',C=1)
clf.fit(X_train_lda, y_train)

score = clf.score(X_test_lda,y_test)
print("Test score with Linear SVM C=1: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )
####### RBF SVM
t0 = time.time()
clf = SVC(kernel='rbf',C=1,gamma=0.01)
clf.fit(X_train_lda, y_train)

score = clf.score(X_test_lda,y_test)
print("Test score with RBF SVM C=1 gamma=0.01: %.4f"%score)
run_time = time.time() - t0
print("Elapsed time in %.2f s" % run_time )