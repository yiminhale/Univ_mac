#2022110327/이민석
#Numpy, Scikit Learn
import numpy as np
from sklearn import datasets
''' 2번 파트
B = datasets.load_wine()
X=B.data
y=B.target
print(X.shape,y.shape)
print(y)
print([int(sum(y==0)), int(sum(y==1)), int(sum(y==2))])
'''
'''3번 파트
B = datasets.load_wine()
X=B.data
y=B.target
from sklearn.naive_bayes import GaussianNB
model = GaussianNB().fit(X,y)
print('nmisses = %d' %sum(model.predict(X)!=y))

from sklearn.neighbors import KNeighborsClassifier
model = KNeighborsClassifier(n_neighbors=1).fit(X,y)
print('nmisses = %d'%sum(model.predict(X)!=y))

from sklearn.neighbors import KNeighborsClassifier
model = KNeighborsClassifier(n_neighbors=2).fit(X,y)
print('nmisses = %d'%sum(model.predict(X)!=y))
'''
#iris
    #data load : iris
B=datasets.load_iris()
X=B.data
y=B.target
    #split data
from sklearn.model_selection import train_test_split
X_tr, X_te, y_tr, y_te = train_test_split(X,y,test_size=0.2,stratify=y,random_state=0)
    #train data using GNB
from sklearn.naive_bayes import GaussianNB
model = GaussianNB().fit(X_tr,y_tr)
    #print
print("****[[SKLEARN iris: 3 classes]]*****")
print("+ 1 : 4 holdout validation, Gaussian  Naive Bayes ")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
    #train data using KNN
from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    #print
print("+ 1 : 4 holdout validation, kNN with k=5")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
##############################################################################
#wine
    #data load: wine
B=datasets.load_wine()
X=B.data
y=B.target
    #split data
from sklearn.model_selection import train_test_split
X_tr, X_te, y_tr, y_te = train_test_split(X,y,test_size=0.2,stratify=y,random_state=0)
    #train data using GNB
from sklearn.naive_bayes import GaussianNB
model = GaussianNB().fit(X_tr,y_tr)
    #print
print("****[[SKLEARN wine: 3 classes]]*****")
print("+ 1 : 4 holdout validation, Gaussian  Naive Bayes ")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
    #train data using KNN
from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    #print
print("+ 1 : 4 holdout validation, kNN with k=5")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
##############################################################################
#breast_cancer
B=datasets.load_breast_cancer()
X=B.data
y=B.target
    #split data
from sklearn.model_selection import train_test_split
X_tr, X_te, y_tr, y_te = train_test_split(X,y,test_size=0.2,stratify=y,random_state=0)
    #train data using GNB
from sklearn.naive_bayes import GaussianNB
model = GaussianNB().fit(X_tr,y_tr)
    #print
print("****[[SKLEARN breast_cancer: 2 classes]]*****")
print("+ 1 : 4 holdout validation, Gaussian  Naive Bayes ")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
    #train data using KNN
from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    #print
print("+ 1 : 4 holdout validation, kNN with k=5")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
##############################################################################
#digits
B=datasets.load_digits()
X=B.data
y=B.target
    #split data
from sklearn.model_selection import train_test_split
X_tr, X_te, y_tr, y_te = train_test_split(X,y,test_size=0.2,stratify=y,random_state=0)
    #train data using GNB
from sklearn.naive_bayes import GaussianNB
model = GaussianNB().fit(X_tr,y_tr)
    #print
print("****[[SKLEARN digits: 10 classes]]*****")
print("+ 1 : 4 holdout validation, Gaussian  Naive Bayes ")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))
    #train data using KNN
from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    #print
print("+ 1 : 4 holdout validation, kNN with k=5")
print("Holdout with testratio=0.2 total miss %d/%d (%.2f%%)\n"%(sum(model.predict(X_te)!=y_te), len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te)))