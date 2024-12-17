import matplotlib.pyplot as plt

size =   [100, 200, 400, 600, 800, 1000] 

data_1 = [0.000939, 0.003046, 0.005014, 0.008863, 0.016672, 0.025079]
data_2 = [0.000854, 0.002124, 0.003105, 0.004853, 0.009492, 0.013137]
data_4 = [0.000963, 0.001788, 0.002159, 0.002999, 0.005751, 0.010709]

plt.xlabel('Размер')

#plt.ylabel('Время выполнения', rotation=90)
#plt.plot(size, data_1, label = "Non parallel")
#plt.plot(size, data_2, label = "2 - threads")
#plt.plot(size, data_4, label = "4 - threads")

data_2_boost = [0, 0, 0, 0, 0, 0]
data_4_boost = [0, 0, 0, 0, 0, 0]

for i in range(6):
    data_2_boost[i] = data_1[i] / data_2[i] 
    data_4_boost[i] = data_1[i] / data_4[i]

plt.ylabel('Ускорение', rotation=90)
plt.plot(size, data_2_boost, label = "2 - threads")
plt.plot(size, data_4_boost, label = "4 - threads")

plt.legend()
plt.grid()

plt.show()