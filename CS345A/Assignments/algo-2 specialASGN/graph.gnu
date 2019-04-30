#!/usr/bin/gnuplot


clear
reset
unset key
#set key


#set yrange[175000:220000]
#set xrange[600:161838]

#set xtics 2000,1000,160000

set datafile separator ","


#plot 'res1.dat' using 1:2 with lines t 'quad' lc rgb "red"

#plot "data_linear.csv" using 1:2 with lines lc rgb "red",\

plot "data_quad.csv" using 1:2 with lines

#set terminal aquaterm size 500,500

#"%lf,%lf"

#, '' using 2:3

set xlabel "input size n"
set ylabel "running time(s)"
set title "Efficient randomized algorithm "


set term png
set output "final.png"
replot


#Deepanshu Bansal(150219)
