#2022110327/이민석
#Numpy, Scikit Learn
import numpy as np
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import StratifiedKFold, LeaveOneOut, train_test_split

#iris
B = datasets.load_iris()
X = B.data
y = B.target
    #outer split
X_tr, X_te, y_tr, y_te = train_test_split(X, y, test_size=0.2, stratify=y, random_state=0)
print("****[[SKLEARN iris: 3 classes]]****")
    #inner 5-fold CV
print("+ 3-way split, KNN")
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=0)
CV_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in skf.split(X_tr, y_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    CV_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100*miss_total/len(y_tr)))
best_k=np.argmin(CV_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, 5-fold CV, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
    #inner Loo
print("+ 3-way split, LOO, KNN")
loo=LeaveOneOut()
LOO_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in loo.split(X_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    LOO_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100 * miss_total / len(y_tr)))
best_k=np.argmin(LOO_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, LOO, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
####################################################################################
#wine
B = datasets.load_wine()
X = B.data
y = B.target
    #outer split
X_tr, X_te, y_tr, y_te = train_test_split(X, y, test_size=0.2, stratify=y, random_state=0)
print("****[[SKLEARN wine: 3 classes]]****")
    #inner 5-fold CV
print("+ 3-way split, KNN")
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=0)
CV_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in skf.split(X_tr, y_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    CV_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100*miss_total/len(y_tr)))
best_k=np.argmin(CV_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, 5-fold CV, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
    #inner Loo
print("+ 3-way split, LOO, KNN")
loo=LeaveOneOut()
LOO_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in loo.split(X_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    LOO_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100 * miss_total / len(y_tr)))
best_k=np.argmin(LOO_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, LOO, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
####################################################################################
#breast_cancer
B = datasets.load_breast_cancer()
X = B.data
y = B.target
    #outer split
X_tr, X_te, y_tr, y_te = train_test_split(X, y, test_size=0.2, stratify=y, random_state=0)
print("****[[SKLEARN breast_cancer: 2 classes]]****")
    #inner 5-fold CV
print("+ 3-way split, KNN")
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=0)
CV_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in skf.split(X_tr, y_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    CV_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100*miss_total/len(y_tr)))
best_k=np.argmin(CV_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, 5-fold CV, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
    #inner Loo
print("+ 3-way split, LOO, KNN")
loo=LeaveOneOut()
LOO_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in loo.split(X_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    LOO_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100 * miss_total / len(y_tr)))
best_k=np.argmin(LOO_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, LOO, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
####################################################################################
#digits
B = datasets.load_digits()
X = B.data
y = B.target
    #outer split
X_tr, X_te, y_tr, y_te = train_test_split(X, y, test_size=0.2, stratify=y, random_state=0)
print("****[[SKLEARN digits: 10 classes]]****")
    #inner 5-fold CV
print("+ 3-way split, KNN")
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=0)
CV_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in skf.split(X_tr, y_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    CV_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100*miss_total/len(y_tr)))
best_k=np.argmin(CV_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, 5-fold CV, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))
    #inner Loo
print("+ 3-way split, LOO, KNN")
loo=LeaveOneOut()
LOO_misses = []
for k in range(1, 10):
    miss_total = 0
    for inner_tr_idx, inner_val_idx in loo.split(X_tr):
        X_inner_tr, X_inner_val = X_tr[inner_tr_idx], X_tr[inner_val_idx]
        y_inner_tr, y_inner_val = y_tr[inner_tr_idx], y_tr[inner_val_idx]
        model = KNeighborsClassifier(n_neighbors=k).fit(X_inner_tr, y_inner_tr)
        miss_total += sum(model.predict(X_inner_val) != y_inner_val)
    LOO_misses.append(miss_total)
    print("knn%d: training samples miss %d / %d (%.2f%%)" % (k, miss_total, len(y_tr), 100 * miss_total / len(y_tr)))
best_k=np.argmin(LOO_misses)+1
model=KNeighborsClassifier(n_neighbors=best_k).fit(X_tr,y_tr)
print("1:4 TVT, LOO, model knn%d, total miss %d/%d (%.2f%%)\n"%(best_k,sum(model.predict(X_te)!=y_te),len(y_te), 100*sum(model.predict(X_te)!=y_te)/len(y_te) ))