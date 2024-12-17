import matplotlib.pyplot as plt

size =   [100, 200, 400, 800, 1600] 

data_1 = [0.098165, 0.379011, 1.488077, 5.970829, 23.862189]
data_2 = [0.000589, 0.304908, 0.986759, 3.399527, 13.205604]
data_4 = [0.000922, 0.578734, 1.584969, 2.479276, 7.460458]

plt.plot(size, data_1, label = "Non parallel")
plt.plot(size, data_2, label = "2 - threads")
plt.plot(size, data_4, label = "4 - threads")

data_2_boost = [0, 0, 0, 0, 0]
data_4_boost = [0, 0, 0, 0, 0]

for i in range(5):
    data_2_boost[i] = data_1[i] / data_2[i] / 2 
    data_4_boost[i] = data_1[i] / data_4[i] / 4

"""
plt.plot(size, data_2_boost, label = "2 - threads")
plt.plot(size, data_4_boost, label = "4 - threads")
"""
plt.legend()
plt.grid()

plt.show()