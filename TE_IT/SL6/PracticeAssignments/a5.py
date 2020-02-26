#doing random stuff to learn syntax and functions of python for data science 

import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("DataSets/dataset_Facebook.csv",sep=';')

#printing the summary of input dataset
print("------------------------Data Summary------------------------")
print(df)

#slicing data w.r.t print Comments
print('Summary of Comments\n')
b=(df[0:5]['comment'])

#slicing data w.r.t print Likes

#print('Summary of Likes\n')
a = (df[0:5]['like'])
plt.plot(a,b,color='red',linestyle='dashed',linewidth=1.1)

#slicing for multiple labels
print(df.loc[1:6,['Post Month','Paid','Post Weekday']])

plt.xlabel("X-Axis")
plt.ylabel("Y-Axis")
plt.title("First Plot in Python")
plt.legend()
plt.show()
