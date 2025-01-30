import matplotlib.pyplot as plot

inputSize = [10000, 20000, 30000, 40000, 50000]
timeTaken = [ 1, 5, 7, 10, 14]

plot.plot(inputSize, timeTaken, "r--")
plot.xlabel = "Input size"
plot.ylabel = "Time taken in ms"

plot.show()
