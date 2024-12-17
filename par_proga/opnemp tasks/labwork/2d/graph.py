import matplotlib.pyplot as plt

size =   [100, 200, 400, 600, 800, 1000] 

data_1 = [0.000280, 0.001124, 0.004625, 0.010350, 0.019645, 0.030615]
data_2 = [0.000589, 0.001263, 0.004022, 0.008178, 0.014152, 0.023144]
data_4 = [0.000922, 0.001543, 0.004304, 0.007750, 0.012815, 0.019102]

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