import matplotlib.pyplot as plot

inputSize = [10000, 20000, 30000, 40000, 50000]
timeTaken = [ 212, 832, 1838, 3276, 5136]

plot.plot(inputSize, timeTaken, "g--")
plot.xlabel = "Input size"
plot.ylabel = "Time taken in ms"

plot.show()
