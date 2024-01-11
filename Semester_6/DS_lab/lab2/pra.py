#practice 


import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 

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
# import pandas as pd 
# import numpy as np 
# df1= pd.DataFrame({'A': pd.Timestamp('20130102'), 'B':np.array([3]*4, dtype = 'int32'), 'C':pd.Categorical(['Male', 'Female', 'Male', 'Female'])})
# df1.shape
# df1.head()
# df1.tail()
# #df1.summary()
# df1.T
# print(df1)
# import pandas as pd
# import numpy as np
# dates=pd.date_range('20130101', periods=100)
# df = pd.DataFrame(np.random.randn(100,4), index=dates, columns=list('ABCD'))
# df.head()
# print(df)
# df.index
# print(df)
# df.tail()
# print(df)
# df.columns
# print(df)
# df.T
# print(df)
# df.sort_index(axis=1, ascending= False)
# print(df)
# df.sort_values(by = 'B')
# print(df)
# df[0:3]
# print(df)
# df['20130105':'20130110']
# print(df)
# df.iloc[0]
# print(df)
# df.iloc[0, :2]
# print(df)
# df.iloc[0, 0]
# print(df)
# df['A']
# print(df)
# df[['A', 'B']]
# print(df)
# df[['A', 'B']][:5]
# print(df)
# df.loc['20130101': '20130105', ['A', 'B']][:5]
# print(df)


# Reading CSV file and xls file format

# df = pd.read_csv('required_files/xyz.csv', header=None)
# print(df.head())
# print(df.tail())
# df.columns=['preg','glu','bp','sft','ins','bmi','dpf','age','class']
# plt.scatter(df['bmi'], df['glu'])
# plt.xlabel('bmi')
# plt.ylabel('Glucose')
# df['age'].hist()

# Excel File

# W=pd.read_excel('required_files/xyz.xls', sheet_name='Sheet1')
# print(W.head())

# Reading a TXT file format
H = pd.read_table('required_files/HR.txt')
print(H.head())
f=H['Department'].value_counts()
f.plot(kind='pie')
plt.show()