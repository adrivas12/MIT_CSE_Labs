# #13. Define a dictionary containing Students data {Name, Height, Qualification}.
# a) Convert the dictionary into DataFrame
# b) Declare a list that is to be converted into a new column (Address}
# c) Using 'Address' as the column name and equate it to the list and display the result.

import pandas as pd 
list =['home1', 'home2', 'home3']

df=pd.DataFrame({'Name':pd.Categorical(['rob', 'John', 'sam']), 
	'Height':pd.Categorical([160, 170, 180]), 
	'Qualification':pd.Categorical(['Btech', 'BA', 'Mtech']),
	'Address':list})
print(df)
