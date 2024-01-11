# 15. a) Create two data frames df1 and df2. 
# df1 contains one column ‘Name’ and df2 contains 4 columns ‘Maths’,
# ‘Physics’, ‘Chemistry’ and ‘Biology’ .
# b) Concatenate two data frames df1 and df2. Now insert one column ‘Total’ to the new data frame df_new
# and find the sum of all marks.cxv

import pandas as pd 
df1=pd.DataFrame({'Name':pd.Categorical(['Ram', 'Diya', 'Chandan', 'James', 'Alice'])})
print(df1)
df2=pd.DataFrame({'Maths':pd.Categorical([80.0, 90.0, 77.5, 87.5, 86.5]), 
	'Physics':pd.Categorical([81.0, 94.0, 74.5, 83.0, 82.5]), 
	'Chemistry':pd.Categorical([91.5, 86.5, 85.5, 90.0, 82.5]), 
	'Biology':pd.Categorical([82.5, 83.5, 84.5, 85.0, 93.0])})
print(df2)
df_new=pd.concat([df1, df2], axis=1)
df_new['Total']=df2.sum(axis=1)
print(df_new)
