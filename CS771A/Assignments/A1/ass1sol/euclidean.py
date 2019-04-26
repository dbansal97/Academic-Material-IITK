from sklearn.datasets import load_svmlight_file
import numpy as np
import sys

traindatafile = sys.argv[1] #train.dat
testdatafile = sys.argv[2] #test.dat
k = int(sys.argv[3]) #value of k

tr_data = load_svmlight_file(traindatafile)
ts_data = load_svmlight_file(testdatafile)

Xtr = tr_data[0].toarray()
Xts = ts_data[0].toarray()

Ytr = tr_data[1]
Yts = ts_data[1]

Yts_pred = []

print("Test accuracy for %d-nn" % (k))

for i in range(Xts.shape[0]):
	if i % 200 == 0 and i:
		corrTill = np.sum(Yts[0:i] == Yts_pred)
		print("Accuracy till %d test cases : %g, Correct : %d" % (i, np.float(corrTill)/i, corrTill))
	kLabels = Ytr[np.argsort(np.sqrt(np.sum(np.square(Xts[i] - Xtr), 1)))[0:k]]
	Yts_pred.append(np.argmax((-1, np.sum(kLabels == 1), np.sum(kLabels == 2), np.sum(kLabels == 3))))

finalCorr = np.sum(Yts == Yts_pred)

print("Final Accuracy after 20000 test cases: %g, Correct : %d" % (np.float(finalCorr)/20000, finalCorr))
