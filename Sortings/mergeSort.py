import matplotlib.pyplot as plot

inputSize = [10000, 20000, 30000, 40000, 50000]
mergeSortTimeTaken = [ 4, 8, 13, 18, 22]


plot.plot(inputSize, mergeSortTimeTaken,"g--", label="Merge Sort")

plot.xlabel = "Input size"
plot.ylabel = "Time taken in ms"

plot.legend()
plot.show()
