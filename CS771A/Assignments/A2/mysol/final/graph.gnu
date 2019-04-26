#!/usr/bin/gnuplot


clear
reset
unset key
set key


#set yrange[175000:220000]
#set xrange[0:100]

plot 'res3.csv' using 0:1 with lines t 'SCD' lc rgb "red",\
	'res1.csv' using 0:1 with lines t 'Vanilla GD' lc rgb "green"


#, '' using 2:3

set xlabel "time\_ elapsed(s)"
set ylabel "f(w)"
set title "Comparision b/w GD and SCD"


set term png
set output "q4.png"
replot


#Deepanshu Bansal(150219)
