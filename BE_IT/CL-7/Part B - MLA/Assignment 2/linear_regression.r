#Name : Sahil Shaikh
#Roll no: 43365
#Problem Statement: Supervised Learning - Regression (Using R)

#import dataset
df <- read.delim("C:/Users/ImSahil/OneDrive/Desktop/BE_IT_Assignments/BE_IT/CL-7/Part B - MLA/Assignment 2/LungCapData.txt",header = TRUE, sep = '\t')

#for random splitting using set seed function
set.seed(10)

#using attach to use the object of the dataset can be accessed simply by using their names
attach(df)

#view dataset
View(df)

#get number or records in the dataset
n = nrow(df)
#print(n) #print to cross check

#train-test split

train_index <- sample(1:n, size = (0.8 * n), replace = FALSE)

train <- df[train_index,]
test <- df[-train_index,]

#print(nrow(train)) #print to cross check
#print(nrow(test)) #print to cross check

#display head of the dataset
head(df)

#check if there is any correlation between lung capacity and age
names(df)
print(paste0("The correlation between Age and LungCapacity is ",cor(Age,LungCap)))
print(paste0("The correlation between Age and LungCapacity is ",cor(Height,LungCap)))

#training the model using age
Age_Model <- lm(LungCap ~ Age, data = train)

#training the model using height
Height_Model <- lm(LungCap ~ Height, data = train)

#summary of both fits
summary(Age_Model)
summary(Height_Model)

#predict using Age model
Age_test_pred <- predict(Age_Model,test)
Age_train_pred <- predict(Age_Model,train)

Height_test_pred <- predict(Height_Model,test)
Height_train_pred <- predict(Height_Model,train)

#rmse
#install.packages("Metrics")
library(Metrics)

test_age_rmse = rmse(test$LungCap,Age_test_pred)
print(paste0("Test Age RMSE: ",test_age_rmse))

train_age_rmse = rmse(train$LungCap,Age_train_pred)
print(paste0("Train Age RMSE: ",train_age_rmse))

test_height_rmse = rmse(test$LungCap,Height_test_pred)
print(paste0("Test Height RMSE: ",test_height_rmse))

train_height_rmse = rmse(train$LungCap,Height_train_pred)
print(paste0("Train Height RMSE: ",train_height_rmse))

#draw scatterplot with regression line
plot(Age,LungCap,main="ScatterPlot")
abline(Age_Model,col="red", lwd = 2)

plot(Height,LungCap,main = "Scatterplot")
abline(Height_Model,col='blue',lwd=2)


#Bar plot

xla = c("TrainError","TestError")
vec = c(train_age_rmse,test_age_rmse)

barplot(names.arg =xla,vec, xlab = "Errors", main="Age: Testing Error")

xlb = c("TrainError","TestError")
vec1 = c(train_height_rmse,test_height_rmse)

barplot(names.arg =xlb,vec1, xlab = "Errors", main="Height: Testing Error")