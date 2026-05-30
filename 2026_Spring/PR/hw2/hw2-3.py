#2022110327 이민석
#scikit learn, numpy
###doc 명세
"""

Customized from Arthur Mensch's implementation of
MNIST classification with L1 sparse logistic classification.
sources: https://scikit-learn.org/stable/modules/generated/sklearn.model_selection.cross_val_score.html

"""
### print 일반
print(__doc__)
###
import time
import random
import numpy as np

from sklearn.datasets import fetch_openml
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.utils import check_random_state
### 과제 위해 필요함
from sklearn.decomposition import PCA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.model_selection import cross_val_score
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
### store
result=[]
### None
X_train_none = X_train
X_test_none = X_test
print("----------------------------------------------------------------")
print(f"None: X_train and X_test shapes = {X_train_none.shape} {X_test_none.shape}")
print("----------------------------------------------------------------")
####### knn
for k in [3,5,7]:
    clf = KNeighborsClassifier(n_neighbors=k)
    score=cross_val_score(clf,X_train_none,y_train,cv=5).mean()
    print({'trans_name': 'None','method':'knn', 'k': k, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'None','method':'knn', 'k': k, 'cv': 5}
    result.append({
        'config':config,
        'score': score,
        'clf':clf,
        'X_train':X_train_none,
        'X_test':X_test_none
    })
####### svm lin
for C in [1,10]:
    clf=SVC(kernel='linear',C=C)
    score=cross_val_score(clf,X_train_none,y_train,cv=5).mean()
    print({'trans_name': 'None','method':'svmlinear', 'C': C, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'None','method':'svmlinear', 'C': C, 'cv': 5}
    result.append({
        'config': config,
        'score': score,
        'clf': clf,
        'X_train': X_train_none,
        'X_test': X_test_none
    })
####### svm rbf
for g in [0.0001,0.001,0.01,0.1]:
    for C in [1,10,100]:
        clf=SVC(kernel='rbf',C=C,gamma=g)
        score=cross_val_score(clf,X_train_none,y_train,cv=5).mean()
        print({'trans_name': 'None','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5})
        print(f"score {score:.6f}")
        config = {'trans_name': 'None','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5}
        result.append({
            'config': config,
            'score': score,
            'clf': clf,
            'X_train': X_train_none,
            'X_test': X_test_none
        })
### PCA32
pca = PCA(n_components=32)
X_train_pca32 = pca.fit_transform(X_train)
X_test_pca32 = pca.transform(X_test)
print("----------------------------------------------------------------")
print(f"PCA32: X_train and X_test shapes = {X_train_pca32.shape} {X_test_pca32.shape}")
print("----------------------------------------------------------------")
####### knn
for k in [3,5,7]:
    clf = KNeighborsClassifier(n_neighbors=k)
    score=cross_val_score(clf,X_train_pca32,y_train,cv=5).mean()
    print({'trans_name': 'PCA32','method':'knn', 'k': k, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'PCA32','method':'knn', 'k': k, 'cv': 5}
    result.append({
        'config': config,
        'score': score,
        'clf': clf,
        'X_train': X_train_pca32,
        'X_test': X_test_pca32
    })
####### svm lin
for C in [1,10]:
    clf=SVC(kernel='linear',C=C)
    score=cross_val_score(clf,X_train_pca32,y_train,cv=5).mean()
    print({'trans_name': 'PCA32','method':'svmlinear', 'C': C, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'PCA32','method':'svmlinear', 'C': C, 'cv': 5}
    result.append({
        'config': config,
        'score': score,
        'clf': clf,
        'X_train': X_train_pca32,
        'X_test': X_test_pca32
    })
####### svm rbf
for g in [0.0001,0.001,0.01,0.1]:
    for C in [1,10,100]:
        clf=SVC(kernel='rbf',C=C,gamma=g)
        score=cross_val_score(clf,X_train_pca32,y_train,cv=5).mean()
        print({'trans_name': 'PCA32','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5})
        print(f"score {score:.6f}")
        config = {'trans_name': 'PCA32','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5}
        result.append({
            'config': config,
            'score': score,
            'clf': clf,
            'X_train': X_train_pca32,
            'X_test': X_test_pca32
        })
### LDA
lda = LinearDiscriminantAnalysis(n_components=9)
X_train_lda=lda.fit_transform(X_train,y_train)
X_test_lda=lda.transform(X_test)
print("----------------------------------------------------------------")
print(f"LDA: X_train and X_test shapes = {X_train_lda.shape} {X_test_lda.shape}")
print("----------------------------------------------------------------")
####### knn
for k in [3,5,7]:
    clf = KNeighborsClassifier(n_neighbors=k)
    score=cross_val_score(clf,X_train_lda,y_train,cv=5).mean()
    print({'trans_name': 'LDA','method':'knn', 'k': k, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'LDA','method':'knn', 'k': k, 'cv': 5}
    result.append({
        'config': config,
        'score': score,
        'clf': clf,
        'X_train': X_train_lda,
        'X_test': X_test_lda
    })
####### svm lin
for C in [1,10]:
    clf=SVC(kernel='linear',C=C)
    score=cross_val_score(clf,X_train_lda,y_train,cv=5).mean()
    print({'trans_name': 'LDA','method':'svmlinear', 'C': C, 'cv': 5})
    print(f"score {score:.6f}")
    config = {'trans_name': 'LDA','method':'svmlinear', 'C': C, 'cv': 5}
    result.append({
        'config': config,
        'score': score,
        'clf': clf,
        'X_train': X_train_lda,
        'X_test': X_test_lda
    })
####### svm rbf
for g in [0.0001,0.001,0.01,0.1]:
    for C in [1,10,100]:
        clf=SVC(kernel='rbf',C=C,gamma=g)
        score=cross_val_score(clf,X_train_lda,y_train,cv=5).mean()
        print({'trans_name': 'LDA','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5})
        print(f"score {score:.6f}")
        config = {'trans_name': 'LDA','method':'svmrbf', 'C': C,'gamma': g, 'cv': 5}
        result.append({
            'config': config,
            'score': score,
            'clf': clf,
            'X_train': X_train_lda,
            'X_test': X_test_lda
        })
### Conclusion
Max= max(result,key=lambda r: r["score"])
t0 = time.time()
Max['clf'].fit(Max["X_train"],y_train)
test_score=Max["clf"].score(Max["X_test"],y_test)
run_time=time.time() - t0
print(f"Max validation score = {Max['score']:.5f}")
print(f"Test score with {Max['config']} : {test_score:.5f}")
print(f"Elapsed time in {run_time:.4f} s")