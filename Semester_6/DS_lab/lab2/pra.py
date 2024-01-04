#practice 

#1)
# import pandas as pd 
# import numpy as np 
# s = pd.Series([3, 9, -2, 10, 5])
# print(s.sum())
# print(s.min())
# print(s.max())

#2) Creating a DataFrame
# import pandas as pd 
# data=[['Dinesh', 10], ['Nithya', 12], ['Ray', 13]]
# df = pd.DataFrame(data, columns = ['Name', 'Age'])
# print(df)

#3) Indexed DataFrame
# import pandas as pd 
# data = {'Name': ['Kavitha', 'Sudha', 'Raju', 'Vignesh'], 'Age': [28, 34, 29, 42]}
# df = pd.DataFrame(data, index= ['rank1', 'rank2', 'rank3', 'rank4'])
# print(df)

#4) Creating a DataFrame using Dictionary
import pandas as pd 
df1 = pd.DataFrame({'A': pd.Timestamp('20130102'), 'B': np.array([3]*4, dtype='int32'), 'C': pd.Categorical(['Male', 'Female', 'Male', 'Female'])})