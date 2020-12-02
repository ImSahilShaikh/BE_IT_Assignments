#Name : Sahil Shaikh
#Roll no: 43365
#Problem Statement: Principal Component Analysis-Finding Principal Components, Variance and Standard Deviation calculations of principal components.(Using R)

#importing dataset
df = read.csv("C:\\Users\\ImSahil\\OneDrive\\Desktop\\BE_IT_Assignments\\BE_IT\\CL-7\\Part B - MLA\\Assignment 8\\winequalityN.csv")

#View dataframe
View(df)

#attach function to use all the features
attach(df)

#lets see names of all available features
names(df)

#to keep data numeric lets remove the first value
df <- df[,2:13]

#check for na values
colSums(is.na(df))

#removing all na values
df $ fixed.acidity [is.na(df $ fixed.acidity)] <- mean(df$fixed.acidity,na.rm = TRUE)
df$volatile.acidity[is.na(df$volatile.acidity)] <- mean(df$volatile.acidity,na.rm = TRUE)
df$citric.acid[is.na(df$citric.acid)] <- mean(df$citric.acid,na.rm = TRUE)
df$residual.sugar[is.na(df$residual.sugar)] <- mean(df$residual.sugar,na.rm = TRUE)
df$chlorides[is.na(df$chlorides)] <- mean(df$chlorides,na.rm = TRUE)
df$pH[is.na(df$pH)] <- mean(df$pH,na.rm = TRUE)
df$sulphates[is.na(df$sulphates)] <- mean(df$sulphates,na.rm = TRUE)

#confirming no na values are remaining
colSums(is.na(df))
sum(is.finite(as.matrix(df)))

#lets check if we have all numeric data now
str(df)
is.numeric(as.matrix(df))

#Performs a principal components analysis on the given data matrix and returns the results as an object of class prcomp
pca <- prcomp(df,scale. = TRUE)

#we are squaring the std deviation to calculate how much variation in original data each principal component does
pca.var <- pca $ sdev ^ 2

#converting the variation into percentage
pca.var.per <- round(pca.var/sum(pca.var)*100,1)

#Visualization
barplot(pca.var.per, main = "Bar plot", xlab = "Principal component", ylab = "Percentage Variation")
biplot(pca)
plot(pca,type="l")

#summary of pca consist std deviation, variance and cumulative proportion for each component
summary(pca)
