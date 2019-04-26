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

	d_alpha = np.zeros((n,));

	time_elapsed = np.zeros(math.ceil(n_iter/spacing));
	tick_vals = np.zeros(math.ceil(n_iter/spacing));
	obj_val = np.zeros(math.ceil(n_iter/spacing));

	tick = 0;
	ttot = 0.0;
	t_start = datetime.now();

	for t in range(n_iter):
		i_rand = random.randint(1,n-1);

		d_alpha_old = d_alpha[i_rand];
		
		g = (Ytr.getcol(i_rand)*Xtr.getrow(i_rand)*w.transpose()).sum() - 1;
		# calculating g takes O(d) time.
		if d_alpha_old == 0:
			pg = min(0,g);
		elif d_alpha_old == 1:
			pg = max(0,g);
		else:
			pg = g;

		if pg != 0:
			q_i_i = (Xtr.getrow(i_rand)*Xtr.getrow(i_rand).transpose()).sum();
			d_alpha[i_rand] = min(max(d_alpha_old - g/q_i_i,0),1);
			w = w + (d_alpha[i_rand] - d_alpha_old)*Ytr.getcol(i_rand)*Xtr.getrow(i_rand);


		if t%spacing == 0:
			t_now = datetime.now();
			delta = t_now - t_start;
			time_elapsed[tick] = ttot + delta.total_seconds();
			ttot = time_elapsed[tick];
			tick_vals[tick] = tick;

			y_w_x = csr_matrix(Ytr.transpose().multiply(Xtr*w.transpose()));
			loss = csr_matrix(1 - y_w_x.toarray());
			hingeloss = loss.multiply(( loss > 0 ).astype(int)).sum(); 

			obj_val[tick] = 0.5*(w*w.transpose()).sum() + hingeloss;

			#print(obj_val[tick]," , ",ttot);           
			tick = tick+1;
			t_start = datetime.now();

	w_final = w.toarray();
	np.save("model_SCD.npy", w_final);



if __name__ == '__main__':
	main();
