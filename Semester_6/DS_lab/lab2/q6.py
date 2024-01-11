# 16. Create a data frame with column- Name, Quiz_1 /10, In-Sem_1 /15, Quiz_2 /10 and In-Sem_2 /15. Now insert a column
# Total and find the total and mean as given in the below table.

import pandas as pd 
list1=[8.0, 9.0, 7.5, 8.5, 6.5]
list2=[11.5, 14.0, 14.5, 13.0, 12.5]
list3=[9.5, 6.5, 8.5, 9.0, 9.0]
list4=[12.5, 13.5, 14.5, 15.0, 13.0]
df=pd.DataFrame({'Name':pd.Categorical(['Annie', 'Diya', 'Charles', 'James', 'Emily']),
	'Quiz_1/10':list1, 
	'In-sem_1/15':list2, 
	'Quiz_2/10':list3, 
	'In-sem_2/15':list4})

df['Total']=df.iloc[:, 1:].sum(axis=1)
df_mean= df.select_dtypes(include=['float64', 'int64']).mean()
df_mean.name='Mean'
df_new=pd.concat([df, df_mean.to_frame().T])
print(df_new)
