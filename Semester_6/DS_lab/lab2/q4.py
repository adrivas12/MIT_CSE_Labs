# 14)Define a dictionary containing Students data {Name, Height, Qualification}.
# a) Convert the dictionary into DataFrame
# b) Use DataFrame.insert() to add a column and display the result.


import pandas as pd 
df=pd.DataFrame({'Name':pd.Categorical(['rob', 'John', 'sam']), 
	'Height':pd.Categorical([160, 170, 180]), 
	'Qualification':pd.Categorical(['10th', '12th', '11th'])})
list =['home1', 'home2', 'home3']

df.insert(3, 'add', list)

print(df)
