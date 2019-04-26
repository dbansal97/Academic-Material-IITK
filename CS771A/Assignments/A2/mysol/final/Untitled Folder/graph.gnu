#!/usr/bin/gnuplot


clear
reset
unset key
set key


#set yrange[175000:220000]
#set xrange[600:161838]

#set xtics 2000,1000,160000

set datafile separator ","


#plot 'res1.dat' using 1:2 with lines t 'GD' lc rgb "red"

plot "res3.csv" using 2:1 "%lf,%lf" title "SCD" with lines lc rgb "red",\
	 "res1.csv" using 2:1 "%lf,%lf" with lines t 'GD' lc rgb "purple"

#set terminal aquaterm size 500,500

#, '' using 2:3

set xlabel "time elapsed(s)"
set ylabel "f(w)"
set title "Comparision b/w GD and SCD"


set term png
set output "q4.png"
replot


#Deepanshu Bansal(150219)
