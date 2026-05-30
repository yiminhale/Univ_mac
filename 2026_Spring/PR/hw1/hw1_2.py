#2022110327/이민석
#Numpy, Scikit Learn
import numpy as np
from sklearn import datasets
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import StratifiedKFold
#iris
B=datasets.load_iris()
X=B.data
y=B.target
    #split
from sklearn.model_selection import StratifiedKFold
skf = StratifiedKFold(n_splits=5,shuffle=True,random_state=0)
print("****[[SKLEARN iris: 3 classes]]*****")
print("+ 5-fold cross validation, Gaussian Naive Bayes")
    #train data using GNB
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=GaussianNB().fit(X_tr,y_tr)
    total_miss+=sum(model.predict(X_te)!=y_te)
    total_samples+=len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold+=1
    #train data using 5CV
print("5-fold CV, total miss %d/%d (%.2f%%)"%(total_miss,total_samples,100*(total_miss/total_samples)))
print("\n+ 5-fold cross validation, kNN with k=5")
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    total_miss += sum(model.predict(X_te) != y_te)
    total_samples += len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold +=1
print("5-fold CV, total miss %d/%d (%.2f%%)\n"%(total_miss,total_samples,100*(total_miss/total_samples)))
####################################################################################
#wine
B=datasets.load_wine()
X=B.data
y=B.target
    #split
from sklearn.model_selection import StratifiedKFold
skf = StratifiedKFold(n_splits=5,shuffle=True,random_state=0)
print("****[[SKLEARN wine: 3 classes]]*****")
print("+ 5-fold cross validation, Gaussian Naive Bayes")
    #train data using GNB
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=GaussianNB().fit(X_tr,y_tr)
    total_miss+=sum(model.predict(X_te)!=y_te)
    total_samples+=len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold+=1
    #train data using 5CV
print("5-fold CV, total miss %d/%d (%.2f%%)"%(total_miss,total_samples,(100*total_miss/total_samples)))
print("\n+ 5-fold cross validation, kNN with k=5")
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    total_miss += sum(model.predict(X_te) != y_te)
    total_samples += len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold +=1
print("5-fold CV, total miss %d/%d (%.2f%%)\n"%(total_miss,total_samples,100*(total_miss/total_samples)))
####################################################################################
#breast_cancer
B=datasets.load_breast_cancer()
X=B.data
y=B.target
    #split
from sklearn.model_selection import StratifiedKFold
skf = StratifiedKFold(n_splits=5,shuffle=True,random_state=0)
print("****[[SKLEARN breast_cancer: 2 classes]]*****")
print("+ 5-fold cross validation, Gaussian Naive Bayes")
    #train data using GNB
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=GaussianNB().fit(X_tr,y_tr)
    total_miss+=sum(model.predict(X_te)!=y_te)
    total_samples+=len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold+=1
    #train data using 5CV
print("5-fold CV, total miss %d/%d (%.2f%%)"%(total_miss,total_samples,100*(total_miss/total_samples)))
print("\n+ 5-fold cross validation, kNN with k=5")
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    total_miss += sum(model.predict(X_te) != y_te)
    total_samples += len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold +=1
print("5-fold CV, total miss %d/%d (%.2f%%)\n"%(total_miss,total_samples,100*(total_miss/total_samples)))
####################################################################################
#digits
B=datasets.load_digits()
X=B.data
y=B.target
    #split
from sklearn.model_selection import StratifiedKFold
skf = StratifiedKFold(n_splits=5,shuffle=True,random_state=0)
print("****[[SKLEARN digits: 10 classes]]*****")
print("+ 5-fold cross validation, Gaussian Naive Bayes")
    #train data using GNB
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=GaussianNB().fit(X_tr,y_tr)
    total_miss+=sum(model.predict(X_te)!=y_te)
    total_samples+=len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold+=1
    #train data using 5CV
print("5-fold CV, total miss %d/%d (%.2f%%)"%(total_miss,total_samples,100*(total_miss/total_samples)))
print("\n+ 5-fold cross validation, kNN with k=5")
total_miss=0
total_samples=0
fold=0
for train_index, test_index in skf.split(X,y):
    X_tr, X_te = X[train_index], X[test_index]
    y_tr, y_te = y[train_index], y[test_index]
    model=KNeighborsClassifier(n_neighbors=5).fit(X_tr,y_tr)
    total_miss += sum(model.predict(X_te) != y_te)
    total_samples += len(y_te)
    #print
    print("CV %d: miss %d/%d (%.2f%%)"%(fold,sum(model.predict(X_te)!=y_te),len(y_te),100*sum(model.predict(X_te)!=y_te)/len(y_te))   )
    fold +=1
print("5-fold CV, total miss %d/%d (%.2f%%)"%(total_miss,total_samples,100*(total_miss/total_samples)))