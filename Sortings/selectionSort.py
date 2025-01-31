import matplotlib.pyplot as plot

inputSize = [10000, 20000, 30000, 40000, 50000]
selectionSortTimeTaken = [ 212, 832, 1838, 3276, 5136]

plot.plot(inputSize, selectionSortTimeTaken, "b--", label="Selection Sort")

plot.xlabel = "Input size"
plot.ylabel = "Time taken in ms"

plot.legend()
plot.show()
