import pandas as pd

df = pd.read_csv("DataSets/dataset_Facebook.csv",sep=';')

#printing the summary of input dataset
print("------------------------Data Summary------------------------")
print(df)

#slicing data w.r.t print Comments
print('Summary of Comments\n')
print(df[0:5]['comment'])

#slicing data w.r.t print Likes

print('Summary of Likes\n')
print(df[0:5]['like'])