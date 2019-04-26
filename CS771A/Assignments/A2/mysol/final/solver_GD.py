import numpy as np
from scipy.sparse import csr_matrix
import sys
from sklearn.datasets import load_svmlight_file
import random
import math
from datetime import datetime

def main():
	traindatafile = sys.argv[1];
	n_iter = int(sys.argv[2]);
	spacing = int(sys.argv[3]);
	tr_data = load_svmlight_file(traindatafile);
	Xtr = tr_data[0];
	Ytr = tr_data[1];

	n, d = Xtr.get_shape();

	Ytr = 2*(Ytr - 1.5);
	Ytr = csr_matrix(Ytr.reshape(1,n));

	w = csr_matrix((1, d));
	wbar = csr_matrix((1, d));

	time_elapsed = np.zeros(math.ceil(n_iter/spacing));
	tick_vals = np.zeros(math.ceil(n_iter/spacing));
	obj_val = np.zeros(math.ceil(n_iter/spacing));
		
	tick = 0;
	
	ttot = 0.0;
	t_start = datetime.now();

	for t in range(n_iter):
		y_w_x = csr_matrix(Ytr.transpose().multiply(Xtr*w.transpose()));
		g = w - Ytr.multiply((y_w_x.transpose() < 1).astype(int))*Xtr;
		eta = -10/(math.sqrt(t+1)*n);
		w = w + eta*g;
		wbar = (1/(t+1))*(t*wbar + w)

		if t%spacing == 0:
			t_now = datetime.now();
			delta = t_now - t_start;

			time_elapsed[tick] = ttot + delta.total_seconds();
			ttot = time_elapsed[tick];
			tick_vals[tick] = tick;
			
			loss = csr_matrix(1 - y_w_x.toarray());
			hingeloss = loss.multiply(( loss > 0 ).astype(int)).sum(); 
			obj_val[tick] = 0.5*(w*w.transpose()).sum() + hingeloss;
			#print(obj_val[tick]," , ",ttot);
			tick = tick+1;
			t_start = datetime.now();
	
	

	loss = csr_matrix(1 - csr_matrix(Ytr.transpose().multiply(Xtr*wbar.transpose())).toarray());
	hingeloss = loss.multiply(( loss > 0 ).astype(int)).sum(); 
	val = 0.5*(wbar*wbar.transpose()).sum() + hingeloss;
	if val < obj_val[tick-1]:
		w_final = wbar.toarray();
	else:
		w_final = w.toarray();
	np.save("model_GD.npy", w_final);

if __name__ == '__main__':
	main();
