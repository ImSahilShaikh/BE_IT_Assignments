#Name : Sahil Shaikh
#Roll no: 43365
#Problem Statement: Association rules - Market Basket Analysis (Using R)

#including all required libraries
#install.packages("arules")
#install.packages("arulesViz")

library(arules)
library(arulesViz)

#importing dataset of titanic into dataframe
df <- read.csv2("C:/Users/ImSahil/OneDrive/Desktop/BE_IT_Assignments/BE_IT/CL-7/Part B - MLA/Assignment 3/titanic.csv",header = TRUE,sep=",")

#viewing dataframe
View(df)

#display 10 entries of the dataframe
head(df,10)

#summarizing dataframe
summary(df)

#Checking suvival data from dataframe
table(df$Age,df$Survived)

#creating set of rules based on survival with support of 0.001 and confidence of 0.8
rule <- apriori(df,parameter=list(minlen=2,supp=0.001,conf=0.8),appearance = list(default="lhs",rhs=c("Survived=Yes","Survived=No")))

#inspecting rules
inspect(rule)

#summarizing rules
summary(rule)

#sorting the rules by lift
sort.rule <- sort(rule,by="lift")

#plotting the plots using various methods

plot(sort.rule,method="graph",control=list(nodeCol="red",edgeCol="blue"))
plot(sort.rule, method = "paracoord")
plot(sort.rule, method = "matrix", control = list(reorder = "none"))

#creating set of rules on age with support of 0.001 and confidence of 0.8
rule1 <- apriori(df,parameter=list(minlen=2, supp=0.001, conf=0.001), appearance = list(lhs=c("Age=Child","Age=Adult"), rhs=c("Survived=Yes")))

#inspecting rule1
inspect(rule1)

#sorting rule1 by life
sort.rule1 <- sort(rule1,by="lift")

#plotting tge plots using various methods
plot(sort.rule1, method="graph", control=list(nodeCol="red", edgeCol="blue"))
plot(sort.rule1, method = "paracoord")
plot(sort.rule1, method = "matrix", control = list(reorder = "none"))
